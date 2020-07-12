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

#if   defined (STM32F401xc)||(STM32F401xe) 
  #include "spec/gpio401.hpp"

#elif defined (STM32F405xx)||(STM32F407xx)||(STM32F415xx)||(STM32F417xx)
  #include "spec/gpio407.hpp"

#elif defined (STM32F410cx)||(STM32F410rx)||(STM32F410tx)
  #include "spec/gpio410.hpp"

#elif defined (STM32F411xx)
  #include "spec/gpio411.hpp"

#elif defined (STM32F412cx)||(STM32F412rx)||(STM32F412vx)||(STM32F412zx) || (STM32F413xx) || (STM32F423xx)
  #include "spec/gpio412.hpp"

#elif defined (STM32F427xx)||(STM32F429xx)||(STM32F437xx)||(STM32F439xx)
  #include "spec/gpio427.hpp"





#elif defined (STM32F446xx)
  #include "spec/gpio446.hpp"

#elif defined (STM32F469xx)
  #include "spec/gpio469.hpp"

#elif defined (STM32F479xx)
  #include "spec/gpio479.hpp"

#else
  #error "You must define supported target device"
#endif




namespace mpp::gpio
{
  inline namespace f4
  {
	enum Configs { PIN_COUNT = 16 };
	  
	enum class Type   { Input = 0b00, Output = 0b01, Alternate = 0b10, Analog = 0b11 };
	enum class Driver { None = 0b0, PushPull = 0b0, OpenDrain = 0b1 };
    enum class Pull   { Floating = 0b00, Up = 0b01, Down = 0b10};  
	enum class Speed  { None = 0b00, Low = 0b00, Medium = 0b01, High = 0b10, VeryHigh = 0b11 };
	enum class Trigger{ None, Falling, Rising, Both };		
    
	  
	
	template < Pull pull, Driver driver, bool inverted >
    struct OutputInitializer final {
      constexpr inline static auto const Type()     noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Trigger()  noexcept(true) { return Type::none; } 
      constexpr inline static auto const Driver()   noexcept(true) { return driver; }
      constexpr inline static auto const Pull()     noexcept(true) { return pull; }
	  constexpr inline static auto const Speed()    noexcept(true) { return Speed::None; }
      constexpr inline static auto const Af()       noexcept(true) { return Af::None; }
      constexpr inline static auto const Inverted() noexcept(true) { return inverted; }   
    };
	  
	  
	
	template < bool inverted >
    struct LedInitializer final {
      constexpr inline static auto const Type()     noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Trigger()  noexcept(true) { return Trigger::None; } 
      constexpr inline static auto const Driver()   noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto const Pull()     noexcept(true) { return Pull::Floating; }
      constexpr inline static auto const Speed()    noexcept(true) { return Speed::Low; }
	  constexpr inline static auto const Af()       noexcept(true) { return Af::None; }
      constexpr inline static auto const Inverted() noexcept(true) { return inverted; }   
    };
	  
	
	  
	template < Pull pull, Trigger trigger, bool inverted >
    struct InputInitializer final {
      constexpr inline static auto const Type()     noexcept(true) { return Type::Input; } 
      constexpr inline static auto const Trigger()  noexcept(true) { return trigger; } 
      constexpr inline static auto const Driver()   noexcept(true) { return Driver::None; }
      constexpr inline static auto const Pull()     noexcept(true) { return pull; }
      constexpr inline static auto const Speed()    noexcept(true) { return Speed::Low; }
	  constexpr inline static auto const Af()       noexcept(true) { return Af::None; }
      constexpr inline static auto const Inverted() noexcept(true) { return inverted; }   
    };

	  
	  
	  

	template < Port port__, std::uint32_t pin__, typename InitializerList >
    class Gpio 
    {
      static_assert(::std::is_same_v< InitializerList, ::std::decay_t< decltype(InitializerList()) > >);
      static_assert((pin__ < Configs::PIN_COUNT), "There are only 16 pins on port");
      
      static_assert(((type == Type::Input    )&&(driver  != Driver::None)),  "Use 'Driver::None' for input pin");
      static_assert(((type == Type::Analog   )&&(driver  != Driver::None)),  "Use 'Driver::None' for analog pin");
      static_assert(((type == Type::Input    )&&(speed   != Speed::None)),   "Use 'Speed::None' for input pin");
      static_assert(((type == Type::Analog   )&&(speed   != Speed::None)),   "Use 'Speed::None' for analog pin");
      static_assert(((type != Type::Input    )&&(trigger != Trigger::None)), "Use 'Trigger::None' for non input pin");
      static_assert(((type != Type::Alternate)&&(af      != Af::None)),      "Use 'Af::None' for non alternate function pin");		
		
		
      public:
        static constexpr auto const port     = port__;
        static constexpr auto const pin      = pin__;
        static constexpr auto const type     = InitializerList::Type();
        static constexpr auto const trigger  = InitializerList::Trigger();
        static constexpr auto const driver   = InitializerList::Driver();
        static constexpr auto const pull     = InitializerList::Pull();
        static constexpr auto const speed    = InitializerList::Speed();
        static constexpr auto const af       = InitializerList::Af();
        static constexpr auto const inverted = InitializerList::Inverted();
        
        
		inline constexpr static auto Init() noexcept(true) {
		  static GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
			
		  static constexpr std::uint32_t moder   = static_cast<std::uint32_t>(type)   << (pin << 1ul);
          static constexpr std::uint32_t ospeed  = static_cast<std::uint32_t>(speed)  << (pin << 1ul);
          static constexpr std::uint32_t pupdr   = static_cast<std::uint32_t>(pull)   << (pin << 1ul);	
          static constexpr std::uint32_t otyper  = static_cast<std::uint32_t>(driver) <<  pin;		
          static constexpr std::uint32_t afr_idx = (pin < 8u) ? 0 : 1;
          static constexpr std::uint32_t afr     = (pin < 8u) ? static_cast<std::uint32_t>(af) << (pin << 2ul) :
		                                                        static_cast<std::uint32_t>(af) << ((pin-8u) << 2ul);
          static constexpr std::uint32_t afr_clr = (pin < 8u) ? 0b1111 << (pin << 2ul) :
			                                                    0b1111 << ((pin-8u) << 2ul);
			
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
			
          return;
        }

		
        inline static auto Set() noexcept(true) {
		  static_assert((type == Type::Output), "This gpio not output, check 'type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
			
          constexpr static std::uint32_t mask = (inverted) ? 0x10000ul << pin : 1ul << pin;
			
          regs->BSRR = mask;
		}
		
		
		inline static auto Reset() noexcept(true) {
		  static_assert((type == Type::Output), "This gpio not output, check 'type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
			
          constexpr static std::uint32_t mask = (inverted) ? 1ul << pin: 0x10000ul << pin;
			
          regs->BSRR = mask; 
		}
		
		
		inline static auto Toggle() noexcept(true) {
		  static_assert((type == Type::Output), "This gpio not output, check 'type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
			
          constexpr static std::uint32_t mask = 1ul << static_cast<std::uint32_t>(pin);
			
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



