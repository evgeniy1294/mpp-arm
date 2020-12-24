#include "bsp.hpp"

std::array<std::uint8_t, 9> TestSequence = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


void bsp::Init()
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_CRCEN;
  
  board::Systick::Init();
  board::Leds::Init();
	
  return;
}




bool bsp::TestSequenceCheck()
{
  return true;	
}





bool bsp::TestSequencePartCheck()
{
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





