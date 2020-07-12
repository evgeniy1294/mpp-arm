/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/st/spec/gpio410.hpp
  @brief  Сompatibility target: STM32F410cx, STM32F410rx,
          STM32F410tx             
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>
#include "target.h"
 


namespace mpp::gpio
{
  inline namespace gpio410
  {
	enum class Port
	{
	  A = GPIOA_BASE,
      B = GPIOB_BASE,
      C = GPIOC_BASE,
      H = GPIOH_BASE,
	};
	  
	  
	enum class Af
	{
      // Alternate function 0
        system_af0     = 0ul,
  		
  	  // Alternate function 1
        tim1_af1       = 1ul,
        lptim1_af1     = 1ul,
  	  
  	  // Alternate function 2
        tim5_af2       = 2ul,
  		
  	  // Alternate function 3
        tim9_af3       = 3ul,
        tim11_af3      = 3ul,
  	 
  	  // Alternate function 4
        i2c1_af4       = 4ul,
        i2c2_af4       = 4ul,
        i2c4_af4       = 4ul,
  		
  	  // Alternate function 5
        spi1_af5       = 5ul,
        spi2_af5       = 5ul,
  	
  	  // Alternate function 6
  	    spi1_af6       = 6ul,
  	    spi2_af6       = 6ul,
  	    spi5_af6       = 6ul,
  		
  	  // Alternate function 7
        usart1_af7     = 7ul,
        usart2_af7     = 7ul,
  		
  	  // Alternate function 8
        usart6_af8     = 8ul,
  		
  	  // Alternate function 9
        i2c2_af9       = 9ul,
        i2c4_af9       = 9ul,
  
  	  // Alternate function 15
        eventout_af15  = 15ul,
	};
  } // inline namespace gpio410
} // namespace mpp::gpio
