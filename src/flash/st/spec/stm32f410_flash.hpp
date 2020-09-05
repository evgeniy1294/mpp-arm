/**
  ***********************************************************
  @file   /src/flash/st/spec/stm32f410_flash.hpp
  @brief  
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (STM32F410cx)
  #include "stm32f410cx.h"
#elif defined (STM32F410rx)
  #include "stm32f410rx.h"
#elif defined (STM32F410tx)
  #include "stm32f410tx.h"
#elif defined (STM32F411xe)
  #include "stm32f411xe.h"
#elif defined (STM32F412cx)
  #include "stm32f412cx.h"
#elif defined (STM32F412rx)
  #include "stm32f412rx.h"
#elif defined (STM32F412vx)
  #include "stm32f412vx.h"
#elif defined (STM32F412zx)
  #include "stm32f412zx.h"
#else
  #error "You must define supported target"
#endif


namespace mpp::flash
{
  inline namespace stm32f401xx
  {
    #if defined (STM32F410cx) || (STM32F410rx) || (STM32F410tx)
      constexpr std::uint32_t kFlashMaxSectorInBank = 5u;
    #elif defined (STM32F411xe)
      constexpr std::uint32_t kFlashMaxSectorInBank = 8u;
	#else
      constexpr std::uint32_t kFlashMaxSectorInBank = 12u;
    #endif
	  
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
            ws = ClockHz / 24'000'001ul;
          else
              ws = ( ClockHz <= 30'000'000u ) ? 0u :
                     ( ClockHz <= 64'000'000u ) ? 1u :
                       ( ClockHz <= 90'000'000u ) ? 2u : 3u;
        
      return ws > kFlashWaitStateMax ? kFlashWaitStateMax : ws;   
    }
      
    
      
  }  // inline namespace
}  // namespace mpp::flash





 
