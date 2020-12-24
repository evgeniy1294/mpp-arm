#include "bsp.hpp"


int main() {

  if ((!bsp::TestSequenceCheck()) || (!bsp::TestSequencePartCheck()))
  {
    bsp::ErrorSignal();  
  }
  else
  {
    bsp::OkSignal();  
  }


  while(1){

  } 
}
