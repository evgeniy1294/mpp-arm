/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /board/launchxl_cc1352p/board.hpp
  @brief  Compatible board stm32f407-discovery 
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>
#include "mpp/cc1352p.hpp"


int main();


namespace board {
  // Systick and DWT
  struct FakeClk {
    constexpr static std::uint32_t kSysClkHz     = 48'000'000u;
    constexpr static std::uint32_t kSysTickClkHz = 48'000'000u; 
  };

  using Systick = mpp::core::Systick < FakeClk >;
  using ClockCounter = mpp::core::ClockCounter < FakeClk >;
	
	
  // Leds
  struct LedTrait final: mpp::gpio::LedTrait {
    constexpr static mpp::gpio::CurrentMode kCurrentMode = mpp::gpio::CurrentMode::LC_MED;
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::Off;
  };
	
  using LedRed    = mpp::gpio::Gpio < mpp::gpio::DIO6, LedTrait >;       
  using LedGreen  = mpp::gpio::Gpio < mpp::gpio::DIO7, LedTrait >;
	
  using Leds = mpp::utils::IoSet < LedRed, LedGreen >;
	
	
  // Specific function 
  void Init();
	
} // namespace board

