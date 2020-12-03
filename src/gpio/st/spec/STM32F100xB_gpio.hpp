/**
  ***********************************************************
  @file   /src/gpio/st/spec/STM32F100xB_gpio.hpp
  @brief  For STM32F100C4, STM32F100R4, STM32F100C6, 
              STM32F100R6, STM32F100C8, STM32F100R8,
			  STM32F100V8, STM32F100CB, STM32F100RB and STM32F100VB       
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (STM32F100C4)||(STM32F100R4)||(STM32F100C6)||(STM32F100R6)|| \
            (STM32F100C8)||(STM32F100R8)||(STM32F100V8)||(STM32F100CB)|| \
            (STM32F100RB)||(STM32F100VB) 
  #include "stm32f100xb.h"
#else
  #error "You must define supported target"
#endif



namespace mpp::gpio
{
  inline namespace STM32F100xB_gpio
  {
    enum class Port { 
      A = GPIOA_BASE,
      B = GPIOB_BASE,
      C = GPIOC_BASE,
      D = GPIOD_BASE,
      E = GPIOE_BASE,
    };

    template< typename IO >
    constexpr bool IsValidIo()
    {
      switch(IO::kPort)
      { 
        case Port::A: return IO::kPin < 16u;
        case Port::B: return IO::kPin < 16u;
        case Port::C: return IO::kPin < 16u;
        case Port::D: return IO::kPin < 16u;
        case Port::E: return IO::kPin < 16u;

        default: return false;
      }
    }
  } // inline namespace 
} // namespace mpp::gpio 
  
