#include "board.hpp"

std::array<std::uint8_t, 9> TestSequence = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


void board::Init()
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_CRCEN;
  
  board::Systick::Init();
  board::Leds::Init();
	
  return;
}




bool board::TestSequenceCheck()
{
  return true;	
}





bool board::TestSequencePartCheck()
{
  return true;	
}







void board::ErrorSignal() {
  LedGreen::Reset();
  LedRed::Set();	
}





void board::OkSignal() {
  LedRed::Reset();
  LedGreen::Set();	
}





