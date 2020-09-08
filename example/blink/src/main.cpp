#include TARGET_HEADER_FILE

mpp::utils::Timer< board::Systick > tim;
mpp::utils::Timer< board::ClockCounter > dwt;

int main() {
  board::Systick::Init();
  board::ClockCounter::Init();

  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
  board::Leds::Init();	
  board::Leds::Set();

  tim.Start(100);
	
  while(1){
    if (tim.IsTimeOut())
	{
      tim.Reload();
      board::Leds::Toggle();
	} 
  }	
}
