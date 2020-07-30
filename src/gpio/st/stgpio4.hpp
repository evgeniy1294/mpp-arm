/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/st/stgpio4.hpp
  @brief  Сompatibility series: STM32F4 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>


#if defined (STM32F401xc)||(STM32F401xe) 
  #include "spec/STM32F401_gpio_v1_0.hpp"
#elif defined (STM32F405xx)||(STM32F407xx)||(STM32F415xx)||(STM32F417xx)
  #include "spec/STM32F417_gpio_v1_0.hpp"
#elif defined (STM32F410cx)||(STM32F410rx)||(STM32F410tx)
  #include "spec/STM32F410_gpio_v1_0.hpp"
#elif defined (STM32F411xe)
  #include "spec/STM32F411_gpio_v1_0.hpp"
#elif defined (STM32F412cx)||(STM32F412rx)||(STM32F412vx)||(STM32F412zx)
  #include "spec/STM32F412_gpio_v1_0.hpp"
#elif defined (STM32F413xx)||(STM32F423xx)
  #include "spec/STM32F413_gpio_v1_0.hpp"
#elif defined (STM32F427xx)||(STM32F429xx)||(STM32F437xx)||(STM32F439xx)
  #include "spec/STM32F427_gpio_v1_0.hpp"
#elif defined (STM32F446xx)
  #include "spec/STM32F446_gpio_v1_0.hpp"
#elif defined (STM32F469xx)||(STM32F479xx)
  #include "spec/STM32F469_gpio_v1_0.hpp"
#else
  #error "You must define MCU"
#endif



namespace mpp::gpio
{
  inline namespace f4
  {      
    enum class Type       { Input = 0b00, Output = 0b01, Alternate = 0b10, Analog = 0b11 };
    enum class Pull       { Floating = 0b00, Up = 0b01, Down = 0b10};  
    enum class Speed      { Low = 0b00, Medium = 0b01, High = 0b10, VeryHigh = 0b11, None };
    enum class Driver     { PushPull = 0b0, OpenDrain = 0b1, None };
    enum class Trigger    { Falling, Rising, Both, None };      
    enum class ResetState { High, Low, None };
      
    
    template<typename Trait>
    constexpr bool IsValidTrait()
    {
      if constexpr (Trait::Type() == Type::Input)
      {
         static_assert((Trait::Driver() == Driver::None), "Use 'Driver::None' for input pin");
         static_assert((Trait::Speed() == Speed::None),   "Use 'Speed::None' for input pin");
         static_assert((Trait::Af() == 0), "Use 'Af == 0' for non alternate function pin");
         static_assert((Trait::ResetState() == ResetState::None), "Use 'ResetState::None' for non output pin");
         
		 return true;
      }
        
       
      if constexpr (Trait::Type() == Type::Output)
      {
		 static_assert((Trait::Driver() != Driver::None), "Don't use 'Driver::None' for output pin");
         static_assert((Trait::Trigger() == Trigger::None), "Use 'Trigger::None' for non input pin");
		 static_assert((Trait::Speed() != Speed::None), "Don't use 'Speed::None' for output pin");
		 static_assert((Trait::ResetState() != ResetState::None), "Don't use 'ResetState::None' for output pin");
		 static_assert((Trait::Af() == 0), "Use 'Af == 0' for non alternate function pin");
		 
		 return true;
      }
        
		
      if constexpr (Trait::Type() == Type::Analog)
	  {
         static_assert((Trait::Driver() == Driver::None), "Use 'Driver::None' for analog pin"); 
		 static_assert((Trait::Speed() == Speed::None), "Use 'Speed::None' for analog pin");
		 static_assert((Trait::Pull() == Pull::Floating)), "Use 'Pull::Floating' for analog pin");
		 static_assert((Trait::Trigger() == Trigger::None), "Use 'Trigger::None' for non input pin");
		 static_assert((Trait::ResetState() == ResetState::None), "Use 'ResetState::None' for non output pin");
		 static_assert((Trait::Inverted() == false), "Use 'Inverted == false' for analog pin");
		 static_assert((Trait::Af() == 0), "Use 'Af == 0' for non alternate function pin");
		  
		 return true;
	  }
		  
		  
      if constexpr (Trait::Type() == Type::Alternate)
	  {
		 static_assert((Trait::Driver() != Driver::None), "Don't use 'Driver::None' for AF pin");
		 static_assert((Trait::Speed() != Speed::None), "Don't use 'Speed::None' for AF pin"); 
		 static_assert((Trait::Trigger() == Trigger::None), "Use 'Trigger::None' for non input pin");
		 static_assert((Trait::ResetState() == ResetState::None), "Use 'ResetState::None' for non output pin");
		 static_assert((Trait::Inverted() == false), "Use 'Inverted == false' for AF pin");
		  
		 return true;
	  }
		  

      return false; 
    }  
      
      
      
      
      
    template < Pull pull, Driver driver, ResetState reset_state, bool inverted >
    struct OutputTrait final {
      constexpr inline static auto const Type()       noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Trigger()    noexcept(true) { return Type::none; } 
      constexpr inline static auto const Driver()     noexcept(true) { return driver; }
      constexpr inline static auto const Pull()       noexcept(true) { return pull; }
      constexpr inline static auto const Speed()      noexcept(true) { return Speed::Medium; }
      constexpr inline static auto const Af()         noexcept(true) { return 0; }
      constexpr inline static auto const Inverted()   noexcept(true) { return inverted; }
      constexpr inline static auto const ResetState() noexcept(true) { return reset_satate; }
    };
      
      
    
    template < bool inverted >
    struct LedTrait final {
      constexpr inline static auto const Type()       noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Trigger()    noexcept(true) { return Trigger::None; } 
      constexpr inline static auto const Driver()     noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto const Pull()       noexcept(true) { return Pull::Floating; }
      constexpr inline static auto const Speed()      noexcept(true) { return Speed::Low; }
      constexpr inline static auto const Af()         noexcept(true) { return 0; }
      constexpr inline static auto const Inverted()   noexcept(true) { return inverted; }
      constexpr inline static auto const ResetState() noexcept(true) { return ResetState::Low; }   
    };
      
    
      
    template < Pull pull, Trigger trigger, bool inverted >
    struct InputTrait final {
      constexpr inline static auto const Type()       noexcept(true) { return Type::Input; } 
      constexpr inline static auto const Trigger()    noexcept(true) { return trigger; } 
      constexpr inline static auto const Driver()     noexcept(true) { return Driver::None; }
      constexpr inline static auto const Pull()       noexcept(true) { return pull; }
      constexpr inline static auto const Speed()      noexcept(true) { return Speed::Low; }
      constexpr inline static auto const Af()         noexcept(true) { return 0; }
      constexpr inline static auto const Inverted()   noexcept(true) { return inverted; }   
      constexpr inline static auto const ResetState() noexcept(true) { return ResetState::None; }   
    };

      
	  
      
      

    template < class IO, class Trait >
    class Gpio 
    {
      static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
      static_assert(::std::is_same_v< IO,    ::std::decay_t< decltype(IO()) > >);
      static_assert(IsValidTrait< Trait >(), "This trait is invalid");
      static_assert(IsValidIo< IO >(), "You try use invalid pin id");
      
        
      public:
        static constexpr const Port port              = IO::Port();
        static constexpr const std::uint32_t pin      = IO::Pin();
        static constexpr const Type type              = Trait::Type();
        static constexpr const Trigger trigger        = Trait::Trigger();
        static constexpr const Driver driver          = Trait::Driver();
        static constexpr const Pull pull              = Trait::Pull();
        static constexpr const Speed speed            = Trait::Speed();
        static constexpr const std::uint32_t af       = Trait::Af();
        static constexpr const bool inverted          = Trait::Inverted();
        static constexpr const ResetState reset_state = Trait::ResetState();
        
        
        inline constexpr static auto Init() noexcept(true) {
          static GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
            
          static constexpr std::uint32_t moder   = static_cast<std::uint32_t>(type) << (pin << 1ul);
          static constexpr std::uint32_t pupdr   = static_cast<std::uint32_t>(pull) << (pin << 1ul);  
          static constexpr std::uint32_t ospeed  = (speed  != Speed::None ) ? static_cast<std::uint32_t>(speed)  << (pin << 1ul) : 0ul;
          static constexpr std::uint32_t otyper  = (driver != Driver::None) ? static_cast<std::uint32_t>(driver) <<  pin : 0ul;      
          static constexpr std::uint32_t afr_idx = (pin < 8u) ? 0 : 1;
          static constexpr std::uint32_t afr     = (pin < 8u) ? static_cast<std::uint32_t>(af) << (pin << 2ul) :
                                                                static_cast<std::uint32_t>(af) << ((pin-8u) << 2ul);
          static constexpr std::uint32_t afr_clr = (pin < 8u) ? 0b1111 << (pin << 2ul) :
                                                                0b1111 << ((pin-8u) << 2ul);
          static constexpr std::uint32_t level   = (inverted) ? (reset_state == ResetState::High) ? 0b0ul : 0b1ul :
                                                                (reset_state == ResetState::High) ? 0b1ul : 0b0ul;
          static constexpr std::uint32_t bsrr    = (level == 1u) ? 0b1ul << pin : 0b1ul << (pin+16u);
            
            
          // Set mode   
          regs->MODER &= ~(0b11 << (pin << 1ul));
          if constexpr (moder != 0ul) regs->MODER |= moder;
            
          // Set out type  
          regs->OTYPER &= ~(0b1ul << pin); 
          if constexpr (otyper != 0ul) regs->OTYPER |= otyper;
            
          // Set out speed
          regs->OSPEEDR &= ~(0b11 << (pin << 1ul));     
          if constexpr (ospeed != 0ul) regs->OSPEEDR |= ospeed;
            
          // Set pull 
          regs->PUPDR &= ~(0b11 << (pin << 1ul));  
          if constexpr (pupdr != 0ul) regs->PUPDR |= pupdr;
            
          // Set AF
          regs->AFR[afr_idx] &= ~afr_clr;
          if constexpr (afr != 0ul) regs->AFR[afr_idx] |= afr;
            
          // Set trigger
          if constexpr (trigger != Trigger::None)
          {
            static constexpr std::uint32_t port_idx = ((static_cast<uint32_t>(regs) - GPIOA_BASE) >> 10u);
            static constexpr std::uint32_t grp_idx  = pin >> 2;
            static constexpr std::uint32_t offset   = (pin - (grp_idx << 2)) << 2;
              
            // Connect EXTI to pin
            SYSCFG->EXTICR[grp_idx] |= port_idx << offset;
            
            // Enable EXTI
            EXTI->IMR |= (1 << pin);
              
            // Set trigger
            if constexpr ((trigger == Trigger::Falling) || (trigger == Trigger::Both))
              EXTI->FTSR |= 1 << pin;
              
            if constexpr ((trigger == Trigger::Rising ) || (trigger == Trigger::Both))
              EXTI->RTSR |= 1 << pin;
          }
             
          if constexpr (reset_state != ResetState::None)
            regs->BSRR = bsrr;
              
          return;
        }

        
        inline static auto Set() noexcept(true) {
          static_assert((type == Type::Output), "This gpio not output, check 'type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
            
          constexpr static std::uint32_t mask = (inverted) ? 0b1ul << (pin+16u) : 1ul << pin;
            
          regs->BSRR = mask;
        }
        
        
        inline static auto Reset() noexcept(true) {
          static_assert((type == Type::Output), "This gpio not output, check 'type' field");
          constexpr static std::uint32_t mask = (inverted) ? 1ul << pin: 0b1ul << (pin+16u);
                
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
          regs->BSRR = mask; 
        }
        
        
        inline static auto Toggle() noexcept(true) {
          static_assert((type == Type::Output), "This gpio not output, check 'type' field");
          constexpr static std::uint32_t mask = 1ul << static_cast<std::uint32_t>(pin);
            
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
          regs->ODR ^= mask;            
        }
        
        
        inline static auto Read() noexcept(true) {
          static_assert((type == Type::Input), "This gpio not input, check 'type' field");

          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
          bool ret = static_cast<bool>(regs->IDR & (1ul << static_cast<std::uint32_t>(pin)));   
          return (inverted) ? !ret : ret; 
        }
    };
      
  } // namespace f4
} // namespace mpp::gpio



