#include "bsp.hpp"


void bsp::Init()
{
  RCC->IOPENR   |= RCC_IOPENR_GPIOAEN;
  RCC->IOPSMENR |= RCC_IOPSMENR_GPIOASMEN;
  
  bsp::Systick::Init();
  bsp::Leds::Init();
	
  return;
}

