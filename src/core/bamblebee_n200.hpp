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
    class MachineTimer {
      public:
        constexpr static std::uint32_t TickPerSec = 1000u;
        constexpr static std::uint32_t TimeCmp    = ClockSystem::kMachineTimerClkHz / 1000u;
      
        inline static std::uint32_t GetTick() { return __private::GetTick(); }
        
      
        inline static void Init() { 
          TIMER_REG(TIMER_MSTOP) = 1u;
          TIMER_REG(TIMER_MTIME_LO) = 0;
          TIMER_REG(TIMER_MTIME_HI) = 0;
          TIMER_REG(TIMER_MTIMECMP_LO) = TimeCmp;
          TIMER_REG(TIMER_MTIMECMP_HI) = 0;
          
          ResetTick();
          TIMER_REG(TIMER_MSTOP) = 0u;
          clear_csr(CSR_MCOUNTINHIBIT, 0 /* CSR_MCOUNTINHIBIT_CY */);
        }
      
        
        static void InterruptHandler ()
        { 
          TIMER_REG(TIMER_MSTOP) = 1u;
          TIMER_REG(TIMER_MTIME_LO) = 0;
          TIMER_REG(TIMER_MTIME_HI) = 0;
          
          __private::IncTick();
          TIMER_REG(TIMER_MSTOP) = 0u;
        }         
    };
    
      
      
      
   /*
    template< class ClockSystem >
    class MachineTickCounter {
      public:
        constexpr static std::uint32_t TickPerSec = ClockSystem::kSysClkHz;
        
        inline static void Init() { 
          
        }
        
        inline static std::uint32_t GetTick() { 
          
        }
    };
    
    */
    
    
    
    enum class PriorityLevelGroup { L0P4 = 0, L1P3 = 1, L2P2 = 2, L3P1 = 3, L4P0 = 4 };
    
    struct EclicExampleTrait final {
      constexpr static PriorityLevelGroup kPriorityLevelGroup = PriorityLevelGroup::L3P1;
      constexpr static std::size_t kThresholdLevel  = 0;
    };
    
    
    
    
    template < class Trait >
    class Eclic final {
      static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
      
      private:
        constexpr static bool IsValidTrait() noexcept(true) {
          static_assert( Trait::kThresholdLevel <= 
              ((1 << static_cast< std::uint8_t >(Trait::kPriorityLevelGroup)) - 1), "Invalid threshold level");
          
          return true;
        }    
      
        template < class T, class... Ts >
        constexpr static bool IsValidInterrupt() { 
          return ( (static_cast<std::uint32_t>(T::kInterruptSource) != static_cast<std::uint32_t>(Ts::kInterruptSource)) && ... );
        }

        template < class T, class... Ts >
        constexpr static bool IsValidInterruptGroup()
        {
          if constexpr (sizeof...(Ts) == 0u)
            return true;
          else
            return IsValidInterrupt<T, Ts...>() && IsValidInterruptGroup<Ts...>();
        }
      
        static_assert(IsValidTrait(), "This trait contains error");
      
      public:
      
        constexpr static PriorityLevelGroup kPriorityLevelGroup = Trait::kPriorityLevelGroup;
        constexpr static std::size_t kThresholdLevel = Trait::kThresholdLevel;
       
        constexpr static std::uint8_t kCfgMask = static_cast<std::uint8_t>(kPriorityLevelGroup) << 1;
        constexpr static std::uint8_t kMthMask = kThresholdLevel;
      
      
        template < class... Interrupt >
        constexpr static void Init() {
          static_assert(IsValidInterruptGroup<Interrupt...>(), "All <kInterruptSource> fields must be unique");
          
          REG32(ECLIC_ADDR_BASE, ECLIC_CFG_OFFSET) = kCfgMask;
          REG32(ECLIC_ADDR_BASE, ECLIC_MTH_OFFSET) = kMthMask;
      
          ( Interrupt::Init(), ... ); 
        }
      
        constexpr static void EmitSoftwareInterrupt() {
          TIMER_REG(TIMER_MSIP) = 1u; 
        }
      
        template < class... Interrupt >
        constexpr static void EnableInterrupts() { ( Interrupt::Enable(), ... ); }
      
      
        template < class... InterruptList >
        constexpr static void DisableInterrupts() { ( Interrupt::Disable(), ... ); }
    };
  } // inline namespace
}


