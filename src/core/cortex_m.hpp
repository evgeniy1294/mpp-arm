/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/core/cortex_m.hpp
  @brief  Compatible with cortex-m family
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include VENDOR_HEADER_FILE

namespace mpp::utils
{
  inline namespace cortex_m {
    class Cover
    {
      public:
        void Protect()
        {
          __disable_irq(); 
          Sync(); 
        }
        
        void Unprotect()
        { 
          Unsync();
          __enable_irq();
        }

        void Sync()   { __asm__ volatile("": : :"memory"); }
        void Unsync() { __asm__ volatile("": : :"memory"); }
    };
      
  } // inline namespace 
}



namespace mpp::core {
	
  namespace __private { std::uint32_t GetTick(); void IncTick(); } // namespace __private
	
  inline namespace cortex_m {
    
    template< class ClockSystem >
    class Systick {
      public:
        constexpr static std::uint32_t TickPerSec = 1000u;
        
        inline static void Init() { SysTick_Config(ClockSystem::kSysTickClkHz / 1000u); }
        inline static std::uint32_t GetTick() { return __private::GetTick(); }
        static void Interrupt() { __private::IncTick(); }         
    };
    
    template< class ClockSystem >
    class ClockCounter {
      public:
		constexpr static std::uint32_t TickPerSec = ClockSystem::kSysClkHz;
		
		inline static void Init() { 
          CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
          DWT->CTRL |=  DWT_CTRL_CYCCNTENA_Msk;
		}
		
        inline static std::uint32_t GetTick() { 
          DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
          std::uint32_t tmp = DWT->CYCCNT; 
          DWT->CTRL |=  DWT_CTRL_CYCCNTENA_Msk;

          return tmp;
		}
	};
		
  } // inline namespace
}
