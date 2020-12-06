#include "board.hpp"


void board::Init()
{
  RCU->APB2EN |= RCU_APB2EN_PAEN | RCU_APB2EN_PCEN;
  
  board::Systick::Init();
  board::Leds::Init();
	
  return;
}

