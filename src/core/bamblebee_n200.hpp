/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/core/bamblebee_n200.hpp
  @brief  Compatible with gd32f103 family and based on 
          RISC-V N200 core chip
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#define TIMER_MTIME_LO           (TIMER_MTIME)
#define TIMER_MTIME_HI           (TIMER_MTIME + 4)
#define TIMER_MTIMECMP_LO        (TIMER_MTIMECMP)
#define TIMER_MTIMECMP_HI        (TIMER_MTIMECMP + 4)
#define TIMER_MSTOP              (0xFF8)


namespace mpp::core {
    
  namespace __private { std::uint32_t GetTick(); void IncTick(); void ResetTick() } // namespace __private
    
    
    
  inline namespace n2000 {
    
    template< class ClockSystem >
    class Systick {
      public:
        constexpr static std::uint32_t TickPerSec = 1000u;
        constexpr static std::uint32_t TimeCmp    = ClockSystem::kSysTickClkHz / 1000u;
      
        inline static std::uint32_t GetTick() { return __private::GetTick(); }
        
      
        inline static void Init() { 
          TIMER_REG(TIMER_MSTOP) = 1u;
          TIMER_REG(TIMER_MTIME_LO) = 0;
          TIMER_REG(TIMER_MTIME_HI) = 0;
          TIMER_REG(TIMER_MTIMECMP_LO) = TimeCmp;
          TIMER_REG(TIMER_MTIMECMP_HI) = 0;
          
          ResetTick();
          TIMER_REG(TIMER_MSTOP) = 0u;
        }
      
      
        static void Interrupt() { 
          TIMER_REG(TIMER_MSTOP) = 1u;
          TIMER_REG(TIMER_MTIME_LO) = 0;
          TIMER_REG(TIMER_MTIME_HI) = 0;
          
          __private::IncTick();
          TIMER_REG(TIMER_MSTOP) = 0u;
        }         
    };
    
      
      
      
   /*
    template< class ClockSystem >
    class ClockCounter {
      public:
        constexpr static std::uint32_t TickPerSec = ClockSystem::kSysClkHz;
        
        inline static void Init() { 
          
        }
        
        inline static std::uint32_t GetTick() { 
          
        }
    };
    
    */
        
  } // inline namespace
}


