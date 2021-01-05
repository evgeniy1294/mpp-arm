#include "bsp.hpp"


int main() {

  if (bsp::TestSequenceCheck())
    bsp::OkSignal();  
  else
    bsp::ErrorSignal();  

  while(1){

  } 
}
