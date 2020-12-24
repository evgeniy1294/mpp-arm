cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)
project(blink CXX C ASM)


option(TARGET_STM32f407G_DISCO "Build for stm32f407g-disco" ON)
option(TARGET_STM32G071_NUCLEO "Build for stm32g071-nucleo" ON)
option(TARGET_BLUE_PILL        "Build for blue pill"        ON)
option(TARGET_LAUNCHXL_CC1352P "Build for launchxl_cc1352p" OFF)




# Interface Library {{{


  # Compile Definitions {{{
    add_library("common_interface_lib" INTERFACE)
  
    target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>")
    target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>")
    target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-specs=nosys.specs>")
    target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-specs=nano.specs>")
    target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-Os>")
    target_compile_options("common_interface_lib" INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:-Wl, --gc-sections>")
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
    
  # }}}
  
  
# }}}











# stm32f407g_disco {{{
  if(TARGET_STM32f407G_DISCO)
    
    add_executable("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf")
    
    
    # Compile Definitions {{{
      target_compile_options("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf" PRIVATE "-mcpu=cortex-m4" "-mthumb" "-mfloat-abi=hard" "-mfpu=fpv4-sp-d16" "-ggdb3")#"--pedantic")
      target_link_options   ("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf" PRIVATE "-T${CMAKE_CURRENT_LIST_DIR}/bsp/stm32f407g_disco/memory.ld" "-Wl,-Map=${CMAKE_PROJECT_NAME}_stm32f407_disco.map" "-Wl,--cref")
      target_link_options   ("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf" PRIVATE "-mcpu=cortex-m4" "-specs=nosys.specs" "-specs=nano.specs" "-mfloat-abi=hard" "-mfpu=fpv4-sp-d16" )
      target_link_libraries ("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf" PRIVATE "common_interface_lib")
    # }}}
    



    # Language standart {{{
    set_target_properties("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf"
                          PROPERTIES
                            C_STANDARD 11
                            CXX_STANDARD 17
                            CXX_STANDARD_REQUIRED YES)
    # }}}




    # Target Source {{{
      target_include_directories ("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf"
                                   PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src"
	    							       "${CMAKE_CURRENT_LIST_DIR}/bsp/stm32f407g_disco")
								 
      target_sources("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf"
                      PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
	  				          "${CMAKE_CURRENT_LIST_DIR}/../../src/core/cortex_m.cpp"
                              "${CMAKE_CURRENT_LIST_DIR}/bsp/stm32f407g_disco/startup_gcc.cpp"
	  				          "${CMAKE_CURRENT_LIST_DIR}/bsp/stm32f407g_disco/bsp.cpp")
    # }}}	
  
  
  
  
    # Libraries {{{
   
      if(DEFINED ENV{CMSIS_STM32F4_PATH})
        target_include_directories ("${CMAKE_PROJECT_NAME}_stm32f407_disco.elf"
                                    PRIVATE "$ENV{CMSIS_STM32F4_PATH}")
      endif()
	
    # }}} 

	
	
    # Post build command {{{
      add_custom_command(TARGET ${CMAKE_PROJECT_NAME}_stm32f407_disco.elf
                           POST_BUILD
                             COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_PROJECT_NAME}_stm32f407_disco.elf ${CMAKE_PROJECT_NAME}_stm32f407_disco.bin
                             COMMAND ${CMAKE_OBJCOPY} -Oihex   ${CMAKE_PROJECT_NAME}_stm32f407_disco.elf ${CMAKE_PROJECT_NAME}_stm32f407_disco.hex
                             COMMAND ${CMAKE_SIZE_UTIL} ${CMAKE_PROJECT_NAME}_stm32f407_disco.elf 
							 COMMAND echo)
    #}}}
	
	
  endif() # TARGET_STM32f407G_DISCO
# }}}










# launchxl_cc1352p {{{  
  if(TARGET_LAUNCHXL_CC1352P)
  
    add_executable("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf")


    # Compile Definitions {{{
      target_compile_options("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf" PRIVATE "-mcpu=cortex-m4" "-mthumb" "-ggdb3")
      target_link_options   ("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf" PRIVATE "-T${CMAKE_CURRENT_LIST_DIR}/bsp/launchxl_cc1352p/cc26x2r1f.lds" "-Wl,-Map=launchxl_cc1352p.map" "-Wl,--cref")
      target_link_options   ("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf" PRIVATE "-mcpu=cortex-m4" "-specs=nosys.specs" "-specs=nano.specs" )
      target_link_libraries ("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf" PRIVATE "common_interface_lib")
    # }}} 



    # Language standart {{{
    set_target_properties("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf"
                          PROPERTIES
                            C_STANDARD 11
                            CXX_STANDARD 17
                            CXX_STANDARD_REQUIRED YES)
    # }}}
  
  
  
    # Target Source {{{
      target_include_directories ("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf"
                                   PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src"
								           "${CMAKE_CURRENT_LIST_DIR}/bsp/launchxl_cc1352p")
								 
      target_sources("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf"
                      PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
					          "${CMAKE_CURRENT_LIST_DIR}/../../src/core/cortex_m.cpp"
		   			          "${CMAKE_CURRENT_LIST_DIR}/bsp/launchxl_cc1352p/startup_gcc.cpp"					        
                              "${CMAKE_CURRENT_LIST_DIR}/bsp/launchxl_cc1352p/ccfg.c"
							  "${CMAKE_CURRENT_LIST_DIR}/bsp/launchxl_cc1352p/bsp.cpp")
    # }}} 
  
  
  
  
    # Libraries {{{
  
      if(DEFINED ENV{DRIVERLIB_CC26x2_PATH})
        target_compile_definitions("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf" PUBLIC "DeviceFamily_CC26X2=1")
        target_include_directories ("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf"
                                     PRIVATE "$ENV{DRIVERLIB_CC26x2_PATH}"
                                             "$ENV{DRIVERLIB_CC26x2_PATH}/../../../../"
								             "$ENV{DRIVERLIB_CC26x2_PATH}/../inc")
								   
	    aux_source_directory("$ENV{DRIVERLIB_CC26x2_PATH}" TI_DRIVERLIB)
        target_sources("${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf" PRIVATE ${TI_DRIVERLIB})
      endif()
  
    # }}}
  
  
  
  
    # launchxl_cc1352p {{{
      add_custom_command(TARGET launchxl_cc1352p.elf
                           POST_BUILD
                             COMMAND ${CMAKE_OBJCOPY} -Oihex   ${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf ${CMAKE_PROJECT_NAME}_launchxl_cc1352p.hex
                             COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_PROJECT_NAME}_launchxl_cc1352p.elf ${CMAKE_PROJECT_NAME}_launchxl_cc1352p.bin)
    #}}} 
  
  endif() #TARGET_LAUNCHXL_CC1352P
# }}}








# stm32g071_nucleo {{{
  if(TARGET_STM32G071_NUCLEO)
    
    add_executable("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf")
    
    
    # Compile Definitions {{{
      target_compile_options("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf" PRIVATE "-mcpu=cortex-m0plus"   "-mthumb"   "-mfloat-abi=soft"  "-ggdb3" )
      target_link_options   ("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf" PRIVATE "-T${CMAKE_CURRENT_LIST_DIR}/bsp/nucleo_g071rb/memory.ld" "-Wl,-Map=${CMAKE_PROJECT_NAME}_stm32g071_nucleo.map" "-Wl,--cref")
      target_link_options   ("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf" PRIVATE "-mcpu=cortex-m0plus"   "-specs=nosys.specs"   "-specs=nano.specs"   "-mfloat-abi=soft"  )
      target_link_libraries ("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf" PRIVATE "common_interface_lib")
    # }}}
    



    # Language standart {{{
    set_target_properties("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf"
                          PROPERTIES
                            C_STANDARD 11
                            CXX_STANDARD 17
                            CXX_STANDARD_REQUIRED YES)
    # }}}




    # Target Source {{{
      target_include_directories ("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf"
                                   PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src"
	    							       "${CMAKE_CURRENT_LIST_DIR}/bsp/nucleo_g071rb")
								 
      target_sources("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf"
                      PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
	  				          "${CMAKE_CURRENT_LIST_DIR}/../../src/core/cortex_m.cpp"
                              "${CMAKE_CURRENT_LIST_DIR}/bsp/nucleo_g071rb/startup_gcc.cpp"
	  				          "${CMAKE_CURRENT_LIST_DIR}/bsp/nucleo_g071rb/bsp.cpp")
    # }}}	
  
  
  
  
    # Libraries {{{
   
      if(DEFINED ENV{CMSIS_STM32G0_PATH})
        target_include_directories ("${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf"
                                    PRIVATE "$ENV{CMSIS_STM32G0_PATH}")
      endif()
	
    # }}} 
  
 
	
	
    # Post build command {{{
      add_custom_command(TARGET ${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf
                           POST_BUILD
                             COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf ${CMAKE_PROJECT_NAME}_stm32g071_nucleo.bin
                             COMMAND ${CMAKE_OBJCOPY} -Oihex   ${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf ${CMAKE_PROJECT_NAME}_stm32g071_nucleo.hex
                             COMMAND ${CMAKE_SIZE_UTIL} ${CMAKE_PROJECT_NAME}_stm32g071_nucleo.elf 
							 COMMAND echo)
    #}}}
	
	
  endif() # TARGET_STM32G071_NUCLEO
# }}}






# blue pill {{{
  if(TARGET_BLUE_PILL)
    
    add_executable("${CMAKE_PROJECT_NAME}_blue_pill.elf")
    
    
    # Compile Definitions {{{
      target_compile_options("${CMAKE_PROJECT_NAME}_blue_pill.elf" PRIVATE "-mcpu=cortex-m3"   "-mthumb"   "-mfloat-abi=soft"  "-ggdb3" )
      target_link_options   ("${CMAKE_PROJECT_NAME}_blue_pill.elf" PRIVATE "-T${CMAKE_CURRENT_LIST_DIR}/bsp/blue_pill/memory.ld" "-Wl,-Map=${CMAKE_PROJECT_NAME}_blue_pill.map" "-Wl,--cref")
      target_link_options   ("${CMAKE_PROJECT_NAME}_blue_pill.elf" PRIVATE "-mcpu=cortex-m0plus"   "-specs=nosys.specs"   "-specs=nano.specs"   "-mfloat-abi=soft"  )
      target_link_libraries ("${CMAKE_PROJECT_NAME}_blue_pill.elf" PRIVATE "common_interface_lib")
    # }}}
    



    # Language standart {{{
    set_target_properties("${CMAKE_PROJECT_NAME}_blue_pill.elf"
                          PROPERTIES
                            C_STANDARD 11
                            CXX_STANDARD 17
                            CXX_STANDARD_REQUIRED YES)
    # }}}




    # Target Source {{{
      target_include_directories ("${CMAKE_PROJECT_NAME}_blue_pill.elf"
                                   PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src"
	    							       "${CMAKE_CURRENT_LIST_DIR}/bsp/blue_pill")
								 
      target_sources("${CMAKE_PROJECT_NAME}_blue_pill.elf"
                      PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
	  				          "${CMAKE_CURRENT_LIST_DIR}/../../src/core/cortex_m.cpp"
                              "${CMAKE_CURRENT_LIST_DIR}/bsp/blue_pill/startup_gcc.cpp"
	  				          "${CMAKE_CURRENT_LIST_DIR}/bsp/blue_pill/bsp.cpp")
    # }}}	
  
  
  
  
    # Libraries {{{
   
      if(DEFINED ENV{CMSIS_STM32F1_PATH})
        target_include_directories ("${CMAKE_PROJECT_NAME}_blue_pill.elf"
                                    PRIVATE "$ENV{CMSIS_STM32F1_PATH}")
      endif()
	
    # }}} 
  
 
	
	
    # Post build command {{{
      add_custom_command(TARGET ${CMAKE_PROJECT_NAME}_blue_pill.elf
                           POST_BUILD
                             COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_PROJECT_NAME}_blue_pill.elf ${CMAKE_PROJECT_NAME}_blue_pill.bin
                             COMMAND ${CMAKE_OBJCOPY} -Oihex   ${CMAKE_PROJECT_NAME}_blue_pill.elf ${CMAKE_PROJECT_NAME}_blue_pill.hex
                             COMMAND ${CMAKE_SIZE_UTIL} ${CMAKE_PROJECT_NAME}_blue_pill.elf 
							 COMMAND echo)
    #}}}
	
	
  endif() # TARGET_BLUE_PILL
# }}}



