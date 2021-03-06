/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /bsp/stm32f407g_disco/bsp.hpp
  @brief  Compatible board stm32f407-discovery 
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include "mpp/stm32f407xx.hpp"


int main();


namespace bsp
{
  // Systick and DWT
  struct FakeClk {
    constexpr static std::uint32_t kSysClkHz     = 16'000'000u;
    constexpr static std::uint32_t kSysTickClkHz = 16'000'000u; 
  };

  using Systick = mpp::core::Systick < FakeClk >;
    
  // Leds
  struct LedTrait final: mpp::gpio::LedTrait
  {
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::Off;
  };
    
  struct LedInvTrait final: mpp::gpio::LedTrait
  {
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::On;
  };

  using LedRed    = mpp::gpio::Gpio < mpp::gpio::PD14, LedTrait >;    
  using LedGreen  = mpp::gpio::Gpio < mpp::gpio::PD12, LedTrait >;  

  using Leds = mpp::gpio::IoGroup < LedRed, LedGreen >;
	
	
  // Specific function 
  void Init();
  bool TestSequenceCheck();
  void ErrorSignal();
  void OkSignal();
	
    
} // namespace bsp
