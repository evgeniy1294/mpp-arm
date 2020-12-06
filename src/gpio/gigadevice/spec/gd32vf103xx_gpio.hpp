/**
  ***********************************************************
  @file   /src/gpio/gigadevice/spec/gd32vf103xx_gpio.hpp
  @brief  Support gd32vf103 series 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (GD32VF103xx)
  #include "gd32vf103.h"
#else
  #error "You must define supported target"
#endif



namespace mpp::gpio
{
  inline namespace gd32vf103xx
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
   
