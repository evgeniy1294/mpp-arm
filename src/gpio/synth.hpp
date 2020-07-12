#pragma once

#include <cstdint>
#include <type_traits>
#include <iostream>


namespace mpp::gpio
{
  inline namespace synth
  {
    enum Configs { PIN_COUNT = 32 };
    
    enum class Port { A = 'A', B = 'B', C = 'C' };
    enum class Type { Input, Output, Analog };
    enum class Driver { PushPull, OpenDrain };
    enum class Pull { Up, Down, Floating };
  
    template < Pull pull, bool inverted >
    struct OutputInitializer final {
      constexpr inline static auto const Type() noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Driver() noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto const Pull() noexcept(true) { return pull; }
      constexpr inline static auto const Inverted() noexcept(true) {return inverted; }   
    };



    template < bool inverted >
    struct LedInitializer final {
      constexpr inline static auto const Type() noexcept(true) { return Type::Output; } 
      constexpr inline static auto const Driver() noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto const Pull() noexcept(true) { return Pull::Floating; }
      constexpr inline static auto const Inverted() noexcept(true) {return inverted; }   
    };
  
  
  
    template < Pull pull, bool inverted >
    struct InputInitializer final {
      constexpr inline static auto const Type() noexcept(true) { return Type::Input; } 
      constexpr inline static auto const Driver() noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto const Pull() noexcept(true) { return pull; }
      constexpr inline static auto const Inverted() noexcept(true) {return inverted; }   
    };


    template < Port __port, std::uint32_t __pin, typename InitializerList >
    class Gpio /*: public Interface */
    {
      static_assert(::std::is_same_v< InitializerList, ::std::decay_t<decltype(InitializerList())>>);
      static_assert((__pin < Configs::PIN_COUNT), "Pin index too big");
  
      public:
        static constexpr auto const port     = __port;
        static constexpr auto const pin      = __pin;
        static constexpr auto const type     = InitializerList::Type();
        static constexpr auto const driver   = InitializerList::Driver();
        static constexpr auto const pull     = InitializerList::Pull();
        static constexpr auto const inverted = InitializerList::Inverted();
  
        inline constexpr static auto Init() noexcept(true) {
           std::cout << "Synth gpio inited with parameters: " << std::endl;
	       std::cout << "Port: "     << static_cast<char>(port) << std::endl;
	       std::cout << "Pin: "      << pin << std::endl;
	       std::cout << "Type: "     << std::dec << static_cast<std::uint32_t>(type) << std::endl;
	       std::cout << "Driver: "   << std::dec << static_cast<std::uint32_t>(driver) << std::endl;
	       std::cout << "Pull: "     << std::dec << static_cast<std::uint32_t>(pull) << std::endl;
	       std::cout << "Inverted: " << std::dec << static_cast<std::uint32_t>(inverted) << std::endl;
        }
  
        // void Write(bool state) { this->state = (inverted) ? !state : state; }
        // bool Read() { return (inverted) ? !state : state; }
    };
  } // inline namespace  
} // namespace mpp::gpio



