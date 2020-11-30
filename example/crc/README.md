## Supported boards:
STM32F407G-DISCO
NUCLEO-G071RB

## Requaried:
1. GCC with full support C++17
2. CMake 3.11 or greater
3. (optional)OpenOCD for download and debug firmware

## How build this:
1. Set environment variables:
  * LIBMPP_PATH - path to mpp library
  * CMSIS_CORE_PATH - path to CMSIS/Core library (example /home/evgen/bin/ST/CubeMxRepo/STM32Cube_FW_F4_V1.24.2/Drivers/CMSIS/Core/Include)   
  * CMSIS_STM32F4_PATH - path to CMSIS/Device/ST/STM32F4xx library (example /home/user/bin/ST/CubeMxRepo/STM32Cube_FW_F4_V1.24.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include)
  * CMSIS_STM32G0_PATH - path to CMSIS/Device/ST/STM32F4xx library (example /home/user/bin/ST/CubeMxRepo/STM32Cube_FW_F4_V1.24.2/Drivers/CMSIS/Device/ST/STM32G0xx/Include)

2. Run build.sh script

