#pragma once

#include <cstdint>
#include <type_traits>
#include <iostream>


namespace mpp::gpio
{
  inline namespace synth
  {
    
    enum class Port       { A = 0u, B = 1u, C = 2u, D = 3u };
    enum class Type       { Input, Output, Analog };
    enum class Driver     { None, PushPull, OpenDrain };
    enum class Pull       { Floating, Up, Down };
    enum class ResetState { None, High, Low };
	  
	  
    enum Configs { PIN_COUNT = 32 };
	constexpr bool IsValidPinId(Port port, std::uint32_t pin)
    {
      return pin < PIN_COUNT;
    };
	  
	  
	  
	  
    template < Pull pull, bool inverted >
    struct OutputTrait final {
      constexpr inline static auto const Type()     noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Driver()   noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto const Pull()     noexcept(true) { return pull; }
      constexpr inline static auto const Inverted() noexcept(true) {return inverted; }   
    };

	  
	  


    template < bool inverted >
    struct LedTrait final {
      constexpr inline static auto const Type() noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Driver() noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto const Pull() noexcept(true) { return Pull::Floating; }
      constexpr inline static auto const Inverted() noexcept(true) {return inverted; }   
    };
  
	  
	  
  
  
    template < Pull pull, bool inverted >
    struct InputTrait final {
      constexpr inline static auto const Type() noexcept(true) { return Type::Input; } 
      constexpr inline static auto const Driver() noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto const Pull() noexcept(true) { return pull; }
      constexpr inline static auto const Inverted() noexcept(true) {return inverted; }   
    };


	  
	  
	  
	  
    template < Port __port, std::uint32_t __pin, typename Trait >
    class Gpio /*: public Interface */
    {
      static_assert(::std::is_same_v< Traits, ::std::decay_t< decltype(Traits()) > >);
      static_assert(IsValidPinId(port, pin), "You try use invalid pin id");
  
      static_assert(((type == Type::Input )&&(driver      == Driver::None)),     "Use 'Driver::None' for input pin");
      static_assert(((type == Type::Analog)&&(driver      == Driver::None)),     "Use 'Driver::None' for analog pin");	
	  static_assert(((type == Type::Analog)&&(pull        == Pull::Floating)),   "Use 'Pull::Floating' for analog pin");
      static_assert(((type != Type::Output)&&(reset_state == ResetState::None)), "Use 'ResetState::None' for non output pin");
      static_assert(((type == Type::Output)&&(reset_state != ResetState::None)), "Don't use 'ResetState::None' for output pin");
      static_assert(((type == Type::Analog)&&(inverted    == false)),            "Use 'inverted == false' for analog pin");
		
      public:
        static constexpr const Port          port     = __port;
        static constexpr const std::uint32_t pin      = __pin;
        static constexpr const Type          type     = Trait::Type();
        static constexpr const Driver        driver   = Trait::Driver();
        static constexpr const Pull          pull     = Trait::Pull();
        static constexpr const bool          inverted = Trait::Inverted();
  
		
        inline constexpr static auto Init() noexcept(true) {
           std::cout << "Synth gpio inited with parameters: " << std::endl;
	       std::cout << "Port: "     << static_cast<char>(port) << std::endl;
	       std::cout << "Pin: "      << pin << std::endl;
	       std::cout << "Type: "     << std::dec << static_cast<std::uint32_t>(type)     << std::endl;
	       std::cout << "Driver: "   << std::dec << static_cast<std::uint32_t>(driver)   << std::endl;
	       std::cout << "Pull: "     << std::dec << static_cast<std::uint32_t>(pull)     << std::endl;
	       std::cout << "Inverted: " << std::dec << static_cast<std::uint32_t>(inverted) << std::endl;
        }
  
        // void Write(bool state) { this->state = (inverted) ? !state : state; }
        // bool Read() { return (inverted) ? !state : state; }
    };
  } // inline namespace  
} // namespace mpp::gpio



