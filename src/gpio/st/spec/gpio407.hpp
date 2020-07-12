/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/st/spec/gpio407.hpp
  @brief  Сompatibility with target: STM32F405xx, STM32F407xx,
          STM32F415xx, STM32F417xx              
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>
#include "target.h"
 


namespace mpp::gpio
{
  inline namespace gpio407
  {
	enum class Port
	{
	  A = GPIOA_BASE,
	  B = GPIOB_BASE,
      C = GPIOC_BASE,
      D = GPIOD_BASE,
      E = GPIOE_BASE,
      F = GPIOF_BASE,
      G = GPIOG_BASE,
      H = GPIOH_BASE,
      I = GPIOI_BASE
	};
	  
	  
	enum class Af
	{
      // Alternate function 0
        system_af0    = 0ul,          /// Example, MCO
  		
  	  // Alternate function 1
        tim1_af1      = 1ul,
        tim2_af1      = 1ul,
  		
  	  // Alternate function 2
        tim3_af2      = 2ul,
        tim4_af2      = 2ul,
        tim5_af2      = 2ul,
  		
        // Alternate function 3
        tim8_af3      = 3ul,
        tim9_af3      = 3ul,
        tim10_af3     = 3ul,
        tim11_af3     = 3ul,
  		
        // Alternate function 4
        i2c1_af4      = 4ul,
        i2c2_af4      = 4ul,
        i2c3_af4      = 4ul,
  		
  	  // Alternate function 5
        spi1_af5      = 5ul,
        spi2_af5      = 5ul,
  		
  	  // Alternate function 6
        spi3_af6      = 6ul,
  		
  	  // Alternate function 7
        usart1_af7    = 7ul,
        usart2_af7    = 7ul,
        usart3_af7    = 7ul,
  		
  	  // Alternate function 8
        usart4_af8    = 8ul,
        usart5_af8    = 8ul,
        usart6_af8    = 8ul,
  		
  	  // Alternate function 9
        can1_af9      = 9ul,
        can2_af9      = 9ul,
        tim12_af9     = 9ul,
        tim13_af9     = 9ul,
        tim14_af9     = 9ul,
  		
  	  // Alternate function 10
        otg_fs_af10   = 10ul,
        otg_hs_af10   = 10ul,
  		
  	  // Alternate function 11
        eth_af11      = 11ul,
  		
  	  // Alternate function 12
        fsmc_af12     = 12ul,
        sdio_af12     = 12ul,
        otg_hs_af12   = 12ul,       /// Configured in FS
  		
  	  // Alternate function 13
        dcmi_af13     = 13ul,
  		
  		
  	  // Alternate function 15
        eventout_af15 = 15ul, 
	};
  } // inline namespace gpio407
} // namespace mpp::gpio