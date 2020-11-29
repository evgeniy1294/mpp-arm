#include "board.hpp"


mpp::utils::Timer< board::Systick > tim;


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
