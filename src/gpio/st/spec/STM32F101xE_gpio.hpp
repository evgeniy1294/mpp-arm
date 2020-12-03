/**
  ***********************************************************
  @file   /src/gpio/st/spec/STM32F101xE_gpio.hpp
  @brief  Support: STM32F101RC, STM32F101VC, STM32F101ZC, 
          STM32F101RD, STM32F101VD, STM32F101ZD, 
		  STM32F101RE, STM32F101VE and STM32F101ZE      
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (STM32F101xE)
  #include "stm32f101xE.h"
#else
  #error "You must define supported target"
#endif



namespace mpp::gpio
{
  inline namespace STM32F101xE_gpio
  {
    enum class Port { 
      A = GPIOA_BASE,
      B = GPIOB_BASE,
      C = GPIOC_BASE,
      D = GPIOD_BASE,
      E = GPIOE_BASE,
      F = GPIOF_BASE,
      G = GPIOG_BASE,
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
        case Port::F: return IO::kPin < 16u;
        case Port::G: return IO::kPin < 16u;

        default: return false;
      }
    }
  } // inline namespace 
} // namespace mpp::gpio 
  

 
