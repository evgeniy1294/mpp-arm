/**
  ***********************************************************
  @file   /src/gpio/st/spec/STM32F103xE_gpio.hpp
  @brief  Support: STM32F103RC, STM32F103VC, STM32F103ZC, 
          STM32F103RD, STM32F103VD, STM32F103ZD, 
		  STM32F103RE, STM32F103VE and STM32F103ZE 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (STM32F103xE)
  #include "stm32f103xe.h"
#else
  #error "You must define supported target"
#endif



namespace mpp::gpio
{
  inline namespace STM32F103xE_gpio
  {
    enum class Port { 
      A = GPIOA_BASE,
      B = GPIOB_BASE,
      C = GPIOC_BASE,
      D = GPIOD_BASE,
      E = GPIOE_BASE,
      F = GPIOE_BASE,
      G = GPIOE_BASE,
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
  

