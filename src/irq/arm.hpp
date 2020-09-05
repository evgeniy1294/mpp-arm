/**
***********************************************************
  @author Evgenii Fedoseev
  @file   /src/irq/nvic.hpp
  @brief  NVIC base interrupt toolset  
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint> 
#include "cmsis_gcc.h"

namespace mpp::irq
{
  typedef void (*Vector)();
    
  inline namespace arm 
  {
    class Cover
    {
      public:
        void Protect()
        {
          __disable_irq(); 
          Sync(); 
        }
        
        void Unprotect()
        { 
          Unsync();
          __enable_irq();
        }

        void Sync()   { __asm__ volatile("": : :"memory"); }
        void Unsync() { __asm__ volatile("": : :"memory"); }
    };
    
          
  } // inline namespace
} // namespace mpp::irq