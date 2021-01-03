/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /include/mpp/gd32vf103.hpp
  @brief  Main header file for GD32VF103xx mcu 
  ***********************************************************
**/

#pragma once



//___________________DEFINITION___________________//
#define GD32VF103xx          (1ul)
#define HXTAL_VALUE          (8000000ul)

//____________________INCLUDE_____________________//
#include "gd32vf103.h"

#include "../../src/utils/ioutils.hpp"
#include "../../src/utils/timutils.hpp"
#include "../../src/utils/binutils.hpp"
#include "../../src/core/bamblebee_n200.hpp"
#include "../../src/irq/gigadevice/gd32v_irq_v1.hpp"
#include "../../src/gpio/gigadevice/gdgpio_v1.hpp"
#include "../../src/crypto/crc_logic.hpp"
#include "../../src/crypto/crc_models.hpp"

 
