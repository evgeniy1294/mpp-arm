/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /include/mpp/stm32f407xx.hpp
  @brief  Main header file for stm32f407xx mcu 
  ***********************************************************
**/

#pragma once

//___________________DEFINITION___________________//
#define VENDOR_HEADER_FILE   <stm32f407xx.h>
#define STM32F407xx          (1ul)

//____________________INCLUDE_____________________//
#include "utils.hpp"
#include "../../src/core/cortex_m.hpp"
#include "../../src/clk/st/stm32f407xx_clk.hpp"
#include "../../src/flash/st/stflash4f.hpp"
#include "../../src/gpio/st/stgpiof4.hpp"
