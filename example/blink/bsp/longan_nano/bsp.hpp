/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /bsp/longan_nano/bsp.hpp
  @brief  Compatible board: longan nano
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>
#include "mpp/gd32vf103.hpp"


int main();


namespace bsp
{
  // Systick and DWT
  struct FakeClk {
    constexpr static std::uint32_t kSysClkHz     = 8'000'000u;
    constexpr static std::uint32_t kSysTickClkHz = 8'000'000u; 
  };

  using Systick = mpp::core::MachineTimer < FakeClk >;
  
  
  // Interrupt controller and source
  struct MachineTimerIntTrait final {
    constexpr static HandleMode   kHandleMode = HandleMode::NonVectored;
    constexpr static Trigger      kTrigger    = Trigger::Level;
    constexpr static std::uint8_t kPriorityLevel = 0b0010;
  };
  
  
  struct EclicTrait final {
    constexpr static PriorityLevelGroup kPriorityLevelGroup = mpp::core::PriorityLevelGroup::L3P1;
    constexpr static std::size_t kThresholdLevel  = 0;
  };
  
  
  using Eclic = mpp::core::Eclic< EclicTrait >;
  using MachineTimerInterrupt = mpp::irq::Interrupt < CLIC_INT_TMR, MachineTimerIntTrait >;
  
    
  // Leds
  struct LedTrait final: mpp::gpio::LedTrait
  {
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::Off;
  };
    

  using LedRed   = mpp::gpio::Gpio < mpp::gpio::IO< mpp::gpio::Port::C, 13 >,  LedTrait >;  
  using LedGreen = mpp::gpio::Gpio < mpp::gpio::IO< mpp::gpio::Port::A, 1  >,  LedTrait >;  
  using LedBlue  = mpp::gpio::Gpio < mpp::gpio::IO< mpp::gpio::Port::A, 2  >,  LedTrait >;  
  
  
  using Leds = mpp::gpio::IoSet < LedRed, LedGreen, LedBlue >;
  
  
  // Specific function 
  void Init();
    
} // namespace board
