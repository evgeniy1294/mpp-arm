/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /include/mpp/stm32f407xx.hpp
  @brief  Main header file for stm32f407xx mcu 
  ***********************************************************
**/

#pragma once

//___________________DEFINITION___________________//
#define STM32F407xx          (1ul)

//____________________INCLUDE_____________________//
#include <cstdint>
#include "stm32f407xx.h"
#include "../../src/utils/ioutils.hpp"
#include "../../src/utils/timutils.hpp"
#include "../../src/utils/binutils.hpp"
#include "../../src/core/cortex_m.hpp"
#include "../../src/clk/st/stm32f407xx_clk.hpp"
#include "../../src/flash/st/stflash4f.hpp"
#include "../../src/gpio/st/stgpiof4.hpp"
#include "../../src/crypto/st/stcrc_v1.hpp"
#include "../../src/crypto/crc_logic.hpp"
#include "../../src/crypto/crc_models.hpp"
