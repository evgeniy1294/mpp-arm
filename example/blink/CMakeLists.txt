cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)
project(blink CXX C ASM)




# Project targets {{{
  add_executable("blink_stm32f407_disco.elf")
  add_executable("launchxl_cc1352p.elf")
# }}}






# Target language standart {{{
  set_target_properties("blink_stm32f407_disco.elf" "launchxl_cc1352p.elf"
                        PROPERTIES
                          C_STANDARD 11
                          CXX_STANDARD 17
                          CXX_STANDARD_REQUIRED YES)
# }}}






# Target Compile Definitions {{{
  add_library("common_interface_lib" INTERFACE)

  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>")
  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>")
  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-specs=nosys.specs>")
  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-specs=nano.specs>")
  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-Os>")

  # stm32f407g-disco {{{
    target_compile_options("blink_stm32f407_disco.elf" PRIVATE "-mcpu=cortex-m4" "-mthumb" "-mfloat-abi=hard" "-mfpu=fpv4-sp-d16" "-ggdb3")
    target_link_options   ("blink_stm32f407_disco.elf" PRIVATE "-T${CMAKE_CURRENT_LIST_DIR}/board/stm32f407g_disco/memory.ld" "-Wl,-Map=blink_stm32f407_disco.map" "-Wl,--cref")
    target_link_options   ("blink_stm32f407_disco.elf" PRIVATE "-mcpu=cortex-m4" "-specs=nosys.specs" "-specs=nano.specs" "-mfloat-abi=hard" "-mfpu=fpv4-sp-d16")
    target_link_libraries ("blink_stm32f407_disco.elf" PRIVATE "common_interface_lib")
  # }}}
  
  # launchxl_cc1352p {{{
    target_compile_options("launchxl_cc1352p.elf" PRIVATE "-mcpu=cortex-m4" "-mthumb" "-ggdb3")
    target_link_options   ("launchxl_cc1352p.elf" PRIVATE "-T${CMAKE_CURRENT_LIST_DIR}/board/launchxl_cc1352p/cc26x2r1f.lds" "-Wl,-Map=launchxl_cc1352p.map" "-Wl,--cref")
    target_link_options   ("launchxl_cc1352p.elf" PRIVATE "-mcpu=cortex-m4" "-specs=nosys.specs" "-specs=nano.specs")
    target_link_libraries ("launchxl_cc1352p.elf" PRIVATE "common_interface_lib")
  # }}} 
  
# }}}







# Target project source {{{  
  # stm32f407g-disco {{{
    target_include_directories ("blink_stm32f407_disco.elf"
                                 PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src"
								         "${CMAKE_CURRENT_LIST_DIR}/board/stm32f407g_disco")
								 
    target_sources("blink_stm32f407_disco.elf"
                    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
					        "${CMAKE_CURRENT_LIST_DIR}/../../src/core/cortex_m.cpp"
                            "${CMAKE_CURRENT_LIST_DIR}/board/stm32f407g_disco/startup_gcc.cpp"
					        "${CMAKE_CURRENT_LIST_DIR}/board/stm32f407g_disco/board.cpp")
  # }}}	
  
  
  # launchxl_cc1352p {{{
    target_include_directories ("launchxl_cc1352p.elf"
                                 PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src"
								         "${CMAKE_CURRENT_LIST_DIR}/board/launchxl_cc1352p")
								 
    target_sources("launchxl_cc1352p.elf"
                    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
					        "${CMAKE_CURRENT_LIST_DIR}/../../src/core/cortex_m.cpp"
		   			        "${CMAKE_CURRENT_LIST_DIR}/board/launchxl_cc1352p/startup_gcc.cpp"					        
                            "${CMAKE_CURRENT_LIST_DIR}/board/launchxl_cc1352p/ccfg.c"
							"${CMAKE_CURRENT_LIST_DIR}/board/launchxl_cc1352p/board.cpp")
  # }}} 
  
# }}}




# Libraries {{{

  if(DEFINED ENV{LIBMPP_PATH})
    target_include_directories ("common_interface_lib"
                                 INTERFACE "$ENV{LIBMPP_PATH}/include")
  endif()
	
  if(DEFINED ENV{CMSIS_CORE_PATH})
    target_include_directories ("common_interface_lib"
                                 INTERFACE "$ENV{CMSIS_CORE_PATH}")
  endif()
	
	
	
	
  # stm32f407g-disco {{{
  
    if(DEFINED ENV{CMSIS_STM32F4_PATH})
      target_include_directories ("blink_stm32f407_disco.elf"
                                  PRIVATE "$ENV{CMSIS_STM32F4_PATH}")
    endif()
	
  # }}} 
  
  
  
  # launchxl_cc1352p {{{
  
    if(DEFINED ENV{DRIVERLIB_CC26x2_PATH})
      target_compile_definitions("launchxl_cc1352p.elf" PUBLIC "DeviceFamily_CC26X2=1")
      target_include_directories ("launchxl_cc1352p.elf"
                                   PRIVATE "$ENV{DRIVERLIB_CC26x2_PATH}"
                                           "$ENV{DRIVERLIB_CC26x2_PATH}/../../../../"
								           "$ENV{DRIVERLIB_CC26x2_PATH}/../inc")
								   
	  aux_source_directory("$ENV{DRIVERLIB_CC26x2_PATH}" TI_DRIVERLIB)
      target_sources("launchxl_cc1352p.elf" PRIVATE ${TI_DRIVERLIB})
    endif()
  
  # }}}
  
  
  
  
  
# }}}





#Post build command {{{

  # stm32f407g-disco {{{
    add_custom_command(TARGET blink_stm32f407_disco.elf
                         POST_BUILD
                           COMMAND ${CMAKE_OBJCOPY} -Oihex   blink_stm32f407_disco.elf blink_stm32f407_disco.hex
                           COMMAND ${CMAKE_OBJCOPY} -Obinary blink_stm32f407_disco.elf blink_stm32f407_disco.bin)
 #}}}
  
  
  # launchxl_cc1352p {{{
    add_custom_command(TARGET launchxl_cc1352p.elf
                         POST_BUILD
                           COMMAND ${CMAKE_OBJCOPY} -Oihex   launchxl_cc1352p.elf launchxl_cc1352p.hex
                           COMMAND ${CMAKE_OBJCOPY} -Obinary launchxl_cc1352p.elf launchxl_cc1352p.bin)
  #}}} 
  
#}}}







