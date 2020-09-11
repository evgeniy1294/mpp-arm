#include "board.hpp"


mpp::utils::Timer< board::Systick > tim;
mpp::utils::Timer< board::ClockCounter > dwt;


int main() {
  tim.Start(100);

  while(1){
    if (tim.IsTimeOut())
    {
      tim.Reload();
      board::Leds::Toggle();
    } 
  } 
}
