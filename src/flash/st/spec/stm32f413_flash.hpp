/**
  ***********************************************************
  @file   /src/flash/st/spec/stm32f413_flash.hpp
  @brief         
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (STM32F413xx)
  #include "stm32f413xx.h"
#elif defined (STM32F423xx)
  #include "stm32f423xx.h"
#else
  #error "You must define supported target"
#endif


namespace mpp::flash
{
  inline namespace stm32f401xx
  {
    constexpr std::uint32_t kFlashMaxSectorInBank = 16u;
    constexpr std::uint32_t kFlashWaitStateMax = 15u;
      
    constexpr std::uint32_t GetWaitState( std::uint32_t ClockHz , float VoltageMin ) noexcept ( true )
    {
      std::uint32_t ws = kFlashWaitStateMax;
        
      if ( VoltageMin < 2.1f )
        ws = ClockHz / 16'000'001ul;
      else 
        if ( VoltageMin < 2.4f )
          ws = ClockHz / 18'000'001ul;
        else
          if ( VoltageMin < 2.7f )
            ws = ClockHz / 20'000'001ul;
          else
              ws = ClockHz / 25'000'001ul;
        
      return ws > kFlashWaitStateMax ? kFlashWaitStateMax : ws;   
    }
      
    
      
  }  // inline namespace
}  // namespace mpp::flash





 
