/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /include/mpp/stm32g071xx.hpp
  @brief  Main header file for stm32g071 mcu 
  ***********************************************************
**/

#pragma once

//___________________DEFINITION___________________//
#define STM32G071xx          (1ul)

//____________________INCLUDE_____________________//
#include <cstdint>
#include "stm32g071xx.h"
#include "../../src/utils/ioutils.hpp"
#include "../../src/utils/timutils.hpp"
#include "../../src/utils/binutils.hpp"
#include "../../src/core/cortex_m.hpp"
#include "../../src/gpio/st/stgpiof4.hpp"
#include "../../src/crypto/st/stcrc_v2_2.hpp"
#include "../../src/crypto/crc_logic.hpp"
#include "../../src/crypto/crc_models.hpp"
