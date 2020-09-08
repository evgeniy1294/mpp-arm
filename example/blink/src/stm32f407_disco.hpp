/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/stm32f407_disco.hpp
  @brief  Compatible board stm32f407-discovery 
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>
#include "mpp/stm32f407xx.hpp"

std::uint32_t GetTick();
namespace board
{
  // Systick and DWT
  struct FakeClk {
    constexpr static std::uint32_t kSysClkHz     = 16'000'000u;
    constexpr static std::uint32_t kSysTickClkHz = 16'000'000u; 
  };

  using Systick = mpp::core::Systick < FakeClk >;
  using ClockCounter = mpp::core::ClockCounter < FakeClk >;
    
  // Leds
  struct LedTrait final: mpp::gpio::LedTrait
  {
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::Off;
  };
    
  struct LedInvTrait final: mpp::gpio::LedTrait
  {
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::On;
  };

  using LedBlue   = mpp::gpio::Gpio < mpp::gpio::PD15, LedTrait >;
  using LedRed    = mpp::gpio::Gpio < mpp::gpio::PD14, LedInvTrait >;    
  using LedOrange = mpp::gpio::Gpio < mpp::gpio::PD13, LedInvTrait >;   
  using LedGreen  = mpp::gpio::Gpio < mpp::gpio::PD12, LedTrait >;  

  using Leds = mpp::gpio::IoGroup < LedBlue, LedRed, LedOrange, LedGreen >;
    
} // namespace board
