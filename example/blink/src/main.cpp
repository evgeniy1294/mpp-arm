#include "bsp.hpp"

mpp::utils::Timer< bsp::Systick > tim;

int main() {
  tim.Start(100);

  while(1){
    if (tim.IsTimeOut())
    {
      tim.Reload();
      bsp::Leds::Toggle();
    } 
  } 
}
