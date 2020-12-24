#include "board.hpp"


void board::Init()
{
  Eclic::Init<MachineTimerInterrupt>();

  // Настраиваем машинный таймер. Таймер будет переполнятся раз в 1 мс.     
  board::Systick::Init();

  //Разрешить прерывание таймера - прерывание номер 7
  MachineTimerInterrupt::Enable();

  // Разрешаем глобальное машинное прерывание 
  auto tmp = MSTATUS::Read();
  MSTATUS::Write(tmp | (1 << 3));
  
  RCU->APB2EN |= RCU_APB2EN_PAEN | RCU_APB2EN_PCEN;
  
  board::Leds::Init();
    
  return;
}

