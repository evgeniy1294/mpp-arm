/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /include/mpp/stm32f103xb.hpp
  @brief  Main header file for STM32F103xB mcu 
  ***********************************************************
**/

#pragma once

// STM32F103xB <--- STM32F103C8, STM32F103R8, STM32F103T8, STM32F103V8, STM32F103CB, STM32F103RB, STM32F103TB and STM32F103VB 


//___________________DEFINITION___________________//
#define STM32F103xB          (1ul)

//____________________INCLUDE_____________________//
#include "stm32f103xb.h"
#include "../../src/utils/ioutils.hpp"
#include "../../src/utils/timutils.hpp"
#include "../../src/utils/binutils.hpp"
#include "../../src/core/bamblebee_n200.hpp"
#include "../../src/gpio/gigadevice/gdgpio_v1.hpp"
#include "../../src/crypto/crc_logic.hpp"
#include "../../src/crypto/crc_models.hpp"

 
