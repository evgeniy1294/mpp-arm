#include "board.hpp"


int main() {

  if ((!board::TestSequenceCheck()) || (!board::TestSequencePartCheck()))
  {
	board::ErrorSignal();  
  }
  else
  {
	board::OkSignal();  
  }


  while(1){

  } 
}
