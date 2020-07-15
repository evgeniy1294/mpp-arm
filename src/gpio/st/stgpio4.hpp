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







namespace mpp::gpio
{
  inline namespace f4
  {
	enum Configs { PIN_COUNT = 16 };
	  
	enum class Type       { Input = 0b00, Output = 0b01, Alternate = 0b10, Analog = 0b11 };
	enum class Driver     { None = 0b0, PushPull = 0b0, OpenDrain = 0b1 };
    enum class Pull       { Floating = 0b00, Up = 0b01, Down = 0b10};  
	enum class Speed      { None = 0b00, Low = 0b00, Medium = 0b01, High = 0b10, VeryHigh = 0b11 };
	enum class Trigger    { None, Falling, Rising, Both };		
    enum class ResetState { None, High, Low };
	  
	
	template < Pull pull, Driver driver, ResetState reset_state, bool inverted >
    struct OutputInitializer final {
      constexpr inline static auto const Type()       noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Trigger()    noexcept(true) { return Type::none; } 
      constexpr inline static auto const Driver()     noexcept(true) { return driver; }
      constexpr inline static auto const Pull()       noexcept(true) { return pull; }
	  constexpr inline static auto const Speed()      noexcept(true) { return Speed::None; }
      constexpr inline static auto const Af()         noexcept(true) { return 0; }
      constexpr inline static auto const Inverted()   noexcept(true) { return inverted; }
      constexpr inline static auto const ResetState() noexcept(true) { return reset_satate; }
    };
	  
	  
	
	template < bool inverted >
    struct LedInitializer final {
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
    struct InputInitializer final {
      constexpr inline static auto const Type()       noexcept(true) { return Type::Input; } 
      constexpr inline static auto const Trigger()    noexcept(true) { return trigger; } 
      constexpr inline static auto const Driver()     noexcept(true) { return Driver::None; }
      constexpr inline static auto const Pull()       noexcept(true) { return pull; }
      constexpr inline static auto const Speed()      noexcept(true) { return Speed::Low; }
	  constexpr inline static auto const Af()         noexcept(true) { return 0; }
      constexpr inline static auto const Inverted()   noexcept(true) { return inverted; }   
      constexpr inline static auto const ResetState() noexcept(true) { return ResetState::None; }   
    };

	  
	  
	  

	template < Port port__, std::uint32_t pin__, typename InitializerList >
    class Gpio 
    {
      static_assert(::std::is_same_v< InitializerList, ::std::decay_t< decltype(InitializerList()) > >);
      static_assert((pin__ < Configs::PIN_COUNT), "There are only 16 pins on port");
      
      static_assert(((type == Type::Input    )&&(driver      == Driver::None)),     "Use 'Driver::None' for input pin");
      static_assert(((type == Type::Analog   )&&(driver      == Driver::None)),     "Use 'Driver::None' for analog pin");
      static_assert(((type == Type::Input    )&&(speed       == Speed::None)),      "Use 'Speed::None' for input pin");
      static_assert(((type == Type::Analog   )&&(speed       == Speed::None)),      "Use 'Speed::None' for analog pin");
      static_assert(((type != Type::Input    )&&(trigger     == Trigger::None)),    "Use 'Trigger::None' for non input pin");
      static_assert(((type != Type::Alternate)&&(af          == 0)),                "Use 'Af == 0' for non alternate function pin");		
      static_assert(((type != Type::Output   )&&(reset_state == ResetState::None)), "Use 'ResetState::None' for non output pin");
      static_assert(((type == Type::Output   )&&(reset_state != ResetState::None)), "Don't use 'ResetState::None' for output pin");
		
      public:
        static constexpr const Port port              = port__;
        static constexpr const auto pin               = pin__;
        static constexpr const Type type              = InitializerList::Type();
        static constexpr const Trigger trigger        = InitializerList::Trigger();
        static constexpr const Driver driver          = InitializerList::Driver();
        static constexpr const Pull pull              = InitializerList::Pull();
        static constexpr const Speed speed            = InitializerList::Speed();
        static constexpr const Af af                  = InitializerList::Af();
        static constexpr const bool inverted          = InitializerList::Inverted();
		static constexpr const ResetState reset_state = InitializerList::ResetState();
        
        
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
			
          constexpr static std::uint32_t mask = (inverted) ? 0x10000ul << pin : 1ul << pin;
			
          regs->BSRR = mask;
		}
		
		
		inline static auto Reset() noexcept(true) {
		  static_assert((type == Type::Output), "This gpio not output, check 'type' field");
          constexpr static std::uint32_t mask = (inverted) ? 1ul << pin: 0x10000ul << pin;
				
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



