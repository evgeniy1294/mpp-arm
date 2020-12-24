/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/gigadevice/gdgpio_v1.hpp
  @brief  Compatible series: GD32VF103xx 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>


#if !defined (GD32VF103xx)
  #error "You must define supported target"
#endif





namespace mpp::irq {
  inline namespace gd32v_irq_v1
  {      
    enum class Trigger:    uint8_t { Level = 0b000, Posedge = 0b010, Negedge = 0b110 };
    enum class HandleMode: uint8_t { NonVectored = 0b0, Vectored = 0b1 };
    
    
    
     struct ExampleTrait final {
        constexpr static HandleMode   kHandleMode = HandleMode::NonVectored;
        constexpr static Trigger      kTrigger    = Trigger::Level;
        constexpr static std::uint8_t kPriorityLevel = 0b1101;
     };
    
         
    
    template < IRQn_Type tInterruptSource, class Trait >
    class Interrupt final {
      public:
        static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
        static_assert( tInterruptSource < ECLIC_NUM_INTERRUPTS, "Wrong interrupt source ID");
        
        constexpr static IRQn_Type    kInterruptSource = tInterruptSource;
        constexpr static HandleMode   kHandleMode = Trait::kHandleMode;
        constexpr static Trigger      kTrigger = Trait::kTrigger;
        constexpr static std::uint8_t kPriorityLevel = Trait::kPriorityLevel;
            
        constexpr static std::uint8_t kIntAttrMask = static_cast< std::uint8_t >(kTrigger) |
                                                     static_cast< std::uint8_t >(kHandleMode);
        constexpr static std::uint8_t kIntCfgMask  = kPriorityLevel << (8 - ECLICINTCTLBITS);
                              
        inline static void Init() {
          constexpr std::uintptr_t intcfg  = ECLIC_ADDR_BASE + ECLIC_INT_IE_OFFSET + static_cast< std::uintptr_t >(kInterruptSource) * 4;
          constexpr std::uintptr_t intattr = ECLIC_ADDR_BASE + ECLIC_INT_IE_OFFSET + static_cast< std::uintptr_t >(kInterruptSource) * 4;
          
          *(volatile uint8_t*)intcfg  = kIntCfgMask;
          *(volatile uint8_t*)intattr = kIntAttrMask;
        }
        
        inline static void Enable() {
          constexpr std::uintptr_t intie = ECLIC_ADDR_BASE + ECLIC_INT_IE_OFFSET + static_cast< std::uintptr_t >(kInterruptSource) * 4;
          *(volatile uint8_t*)intie = 1; 
        }
          
        inline static void Disable() {
          constexpr std::uintptr_t intie = ECLIC_ADDR_BASE + ECLIC_INT_IE_OFFSET + static_cast< std::uintptr_t >(kInterruptSource) * 4;
          *(volatile uint8_t*)intie = 0; 
        }
    };
  
  }
}
