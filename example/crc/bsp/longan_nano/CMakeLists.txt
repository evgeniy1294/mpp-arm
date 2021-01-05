cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)
project(crc CXX C ASM)


include($ENV{LIBMPP_PATH}/example/cmake/riscv_gcc_toolchain.cmake)


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
    
  # }}}
  
  
# }}}






# Longan Nano {{{
  add_executable("${CMAKE_PROJECT_NAME}.elf")
  
  
  # Compile Definitions {{{
    target_compile_options("${CMAKE_PROJECT_NAME}.elf" PRIVATE "-march=rv32imac" "-ggdb3" )
    target_link_options   ("${CMAKE_PROJECT_NAME}.elf" PRIVATE "-T${CMAKE_CURRENT_LIST_DIR}/memory.ld" "-Wl,-Map=${CMAKE_PROJECT_NAME}.map" "-Wl,--cref")
    target_link_options   ("${CMAKE_PROJECT_NAME}.elf" PRIVATE "-march=rv32imac"  "-fno-lto")
    target_link_libraries ("${CMAKE_PROJECT_NAME}.elf" PRIVATE "common_interface_lib")
  # }}}
  
  # Language standart {{{
  set_target_properties("${CMAKE_PROJECT_NAME}.elf"
                        PROPERTIES
                          C_STANDARD 11
                          CXX_STANDARD 17
                          CXX_STANDARD_REQUIRED YES)
  # }}
  # Target Source {{{
    target_include_directories ("${CMAKE_PROJECT_NAME}.elf"
                                 PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../../src"
                                         "${CMAKE_CURRENT_LIST_DIR}")
                               
    target_sources("${CMAKE_PROJECT_NAME}.elf"
                    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../../src/main.cpp"
                            "$ENV{LIBMPP_PATH}/src/core/bamblebee_n200.cpp"
                            "${CMAKE_CURRENT_LIST_DIR}/startup_gcc.cpp"
                            "${CMAKE_CURRENT_LIST_DIR}/bsp.cpp")
  # }}}   




  # Libraries {{{
 
    if(DEFINED ENV{RISCV_GD32VF103_PATH})
      target_include_directories ("${CMAKE_PROJECT_NAME}.elf"
                                  PRIVATE "$ENV{RISCV_GD32VF103_PATH}")
    endif()
    
    
    if(DEFINED ENV{RISCV_N200_CORE_PATH})
      target_include_directories ("${CMAKE_PROJECT_NAME}.elf"
                                  PRIVATE "$ENV{RISCV_N200_CORE_PATH}")
    endif()
  
  # }}} 

  
  
  # Post build command {{{
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME}.elf
                         POST_BUILD
                           COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.bin
                           COMMAND ${CMAKE_OBJCOPY} -Oihex   ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.hex
                           COMMAND ${CMAKE_SIZE_UTIL} ${CMAKE_PROJECT_NAME}.elf 
                           COMMAND echo)
  #}}}
  
# }}}



