#include "bsp.hpp"

std::array<std::uint32_t, 9> TestSequence = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


void bsp::Init()
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_CRCEN;
  
  Systick::Init();
  Leds::Init();
  Leds::Reset();
    
  return;
}






bool bsp::TestSequenceCheck()
{
  using namespace mpp::crc;
  volatile std::uint32_t crc = 0;

  HardwareLogic::Reset(CRC);
  HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.size());
  crc = HardwareLogic::Finalize(CRC); 
	
  if (crc != 0x1556f485)
    return false;
  
  return true;  
}







void bsp::ErrorSignal() {
  LedGreen::Reset();
  LedRed::Set();    
}





void bsp::OkSignal() {
  LedRed::Reset();
  LedGreen::Set();  
}





