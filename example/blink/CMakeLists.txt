cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)
project(blink CXX C ASM)




# Project targets {{{
  add_executable("blink_stm32f407_disco.elf")
# }}}






# Target language standart {{{
  set_target_properties("blink_stm32f407_disco.elf" 
                        PROPERTIES
                          C_STANDARD 11
                          CXX_STANDARD 17
                          CXX_STANDARD_REQUIRED YES)
# }}}






# Target Compile Definitions {{{
  add_library("common_interface_lib" INTERFACE)
  target_compile_options    ("common_interface_lib"
                              INTERFACE
                                "-mcpu=cortex-m4" "-mthumb" "-mfloat-abi=hard" "-mfpu=fpv4-sp-d16" "-ggdb3")

  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>")
  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>")
  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-specs=nosys.specs>")
  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-specs=nano.specs>")
  target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-Os>")

  # stm32f407g-disco {{{
    target_link_options  ("blink_stm32f407_disco.elf" PRIVATE "-T${CMAKE_CURRENT_LIST_DIR}/board/stm32f407g_disco/memory.ld" "-Wl,-Map=blink_stm32f407_disco.map" "-Wl,--cref")
    target_link_options  ("blink_stm32f407_disco.elf" PRIVATE "-mcpu=cortex-m4" "-specs=nosys.specs" "-specs=nano.specs" "-mfloat-abi=hard" "-mfpu=fpv4-sp-d16")
    target_link_libraries("blink_stm32f407_disco.elf" PRIVATE "common_interface_lib")
  # }}}
  
  # launchxl_cc1352p {{{

  # }}} 
  
# }}}







# Target project source {{{
  target_sources("common_interface_lib" INTERFACE "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
                                                  "${CMAKE_CURRENT_LIST_DIR}/../../src/core/cortex_m.cpp")
  
  # stm32f407g-disco {{{
    target_include_directories ("blink_stm32f407_disco.elf"
                                 PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src"
								         "${CMAKE_CURRENT_LIST_DIR}/board/stm32f407g_disco")
								 
    target_sources("blink_stm32f407_disco.elf"
                    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/board/stm32f407g_disco/startup_gcc.cpp")
  # }}}	
  
  
  # launchxl_cc1352p {{{

  # }}} 
  
# }}}




# Libraries {{{

  # stm32f407g-disco {{{
  
    if(DEFINED ENV{CMSIS_STM32F4_PATH})
      target_include_directories ("blink_stm32f407_disco.elf"
                                  PRIVATE "$ENV{CMSIS_STM32F4_PATH}")
    endif()
  
  
    if(DEFINED ENV{CMSIS_CORE_PATH})
      target_include_directories ("blink_stm32f407_disco.elf"
                                   PRIVATE "$ENV{CMSIS_CORE_PATH}")
    endif()
  
    if(DEFINED ENV{LIBMPP_PATH})
      target_include_directories ("blink_stm32f407_disco.elf"
                                   PRIVATE "$ENV{LIBMPP_PATH}/include")
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
  
#}}}







