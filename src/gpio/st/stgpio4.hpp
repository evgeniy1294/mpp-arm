/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/st/stgpio4.hpp
  @brief  Compatible series: STM32F4 
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
  #error "You must define supported MCU"
#endif



namespace mpp::gpio
{
  inline namespace f4
  {      
    enum class Type         { Input = 0b00, Output = 0b01, Alternate = 0b10, Analog = 0b11 };
    enum class Pull         { Floating = 0b00, Up = 0b01, Down = 0b10};  
    enum class Speed        { Low = 0b00, Medium = 0b01, High = 0b10, VeryHigh = 0b11, None };
    enum class Driver       { PushPull = 0b0, OpenDrain = 0b1, None };
    // enum class Trigger      { Falling, Rising, Both, None };      
    enum class DefaultState { High, Low, None };
    enum class Inversion    { Off = 0x0ul, On = 0x1ul, None };
      
    
    template< class Trait >
    constexpr bool IsValidTrait()
    {
      if constexpr (Trait::Type() == Type::Input)
      {
         static_assert((Trait::Driver() == Driver::None), "Use 'Driver::None' for input pin");
         static_assert((Trait::Speed() == Speed::None),   "Use 'Speed::None' for input pin");
         static_assert((Trait::Af() == 0), "Use 'Af == 0' for non alternate function pin");
         static_assert((Trait::DefaultState() == DefaultState::None), "Use 'DefaultState::None' for non output pin");
         
         return true;
      }
        
       
      if constexpr (Trait::Type() == Type::Output)
      {
         static_assert((Trait::Driver() != Driver::None), "Don't use 'Driver::None' for output pin");
         // static_assert((Trait::Trigger() == Trigger::None), "Use 'Trigger::None' for non input pin");
         static_assert((Trait::Speed() != Speed::None), "Don't use 'Speed::None' for output pin");
         static_assert((Trait::DefaultState() != DefaultState::None), "Don't use 'DefaultState::None' for output pin");
         static_assert((Trait::Af() == 0), "Use 'Af == 0' for non alternate function pin");
         
         return true;
      }
        
        
      if constexpr (Trait::Type() == Type::Analog)
      {
         static_assert((Trait::Driver() == Driver::None), "Use 'Driver::None' for analog pin"); 
         static_assert((Trait::Speed() == Speed::None), "Use 'Speed::None' for analog pin");
         static_assert((Trait::Pull() == Pull::Floating), "Use 'Pull::Floating' for analog pin");
         // static_assert((Trait::Trigger() == Trigger::None), "Use 'Trigger::None' for non input pin");
         static_assert((Trait::DefaultState() == DefaultState::None), "Use 'DefaultState::None' for non output pin");
         static_assert((Trait::Inversion() == Inversion::None), "Use 'Inversion::None' for analog pin");
         static_assert((Trait::Af() == 0), "Use 'Af == 0' for non alternate function pin");
          
         return true;
      }
          
          
      if constexpr (Trait::Type() == Type::Alternate)
      {
         static_assert((Trait::Driver() != Driver::None), "Don't use 'Driver::None' for AF pin");
         static_assert((Trait::Speed() != Speed::None), "Don't use 'Speed::None' for AF pin"); 
         // static_assert((Trait::Trigger() == Trigger::None), "Use 'Trigger::None' for non input pin");
         static_assert((Trait::DefaultState() == DefaultState::None), "Use 'DefaultState::None' for non output pin");
         static_assert((Trait::Inversion() == Inversion::None), "Use 'Inversion::None' for AF pin");
          
         return true;
      }
          

      return false; 
    }  
      
      
      
      
      
    template < Pull pull, Driver driver, DefaultState reset_state, Inversion inv >
    struct OutputTrait final {
      constexpr inline static auto Type()         noexcept(true) { return Type::Output; } 
      // constexpr inline static auto Trigger()      noexcept(true) { return Type::none; } 
      constexpr inline static auto Driver()       noexcept(true) { return driver; }
      constexpr inline static auto Pull()         noexcept(true) { return pull; }
      constexpr inline static auto Speed()        noexcept(true) { return Speed::Medium; }
      constexpr inline static auto Af()           noexcept(true) { return 0; }
      constexpr inline static auto Inversion()    noexcept(true) { return inv; }
      constexpr inline static auto DefaultState() noexcept(true) { return reset_satate; }
    };
      
      
    
    template < Inversion inv >
    struct LedTrait final {
      constexpr inline static auto Type()         noexcept(true) { return Type::Output; } 
      // constexpr inline static auto Trigger()      noexcept(true) { return Trigger::None; } 
      constexpr inline static auto Driver()       noexcept(true) { return Driver::PushPull; }
      constexpr inline static auto Pull()         noexcept(true) { return Pull::Floating; }
      constexpr inline static auto Speed()        noexcept(true) { return Speed::Low; }
      constexpr inline static auto Af()           noexcept(true) { return 0; }
      constexpr inline static auto Inversion()    noexcept(true) { return inv; }
      constexpr inline static auto DefaultState() noexcept(true) { return DefaultState::Low; }   
    };
      
    
      
    template < Pull pull, Trigger trigger, Inversion inv >
    struct InputTrait final {
      constexpr inline static auto Type()         noexcept(true) { return Type::Input; } 
      // constexpr inline static auto Trigger()      noexcept(true) { return trigger; } 
      constexpr inline static auto Driver()       noexcept(true) { return Driver::None; }
      constexpr inline static auto Pull()         noexcept(true) { return pull; }
      constexpr inline static auto Speed()        noexcept(true) { return Speed::Low; }
      constexpr inline static auto Af()           noexcept(true) { return 0; }
      constexpr inline static auto Inversion()    noexcept(true) { return inv; }   
      constexpr inline static auto DefaultState() noexcept(true) { return DefaultState::None; }   
    };

      
      
      
      

    template < class IO, class Trait >
    class Gpio final {
      static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
      static_assert(::std::is_same_v< IO,    ::std::decay_t< decltype(IO()) > >);
      static_assert(IsValidTrait< Trait >(), "This trait is invalid");
      static_assert(IsValidIo< IO >(), "You try use invalid pin id");
      
        
      public:
        static constexpr Port kPort                 = IO::Port();
        static constexpr std::uint32_t kPin         = IO::Pin();
        static constexpr Type kType                 = Trait::Type();
        // static constexpr Trigger kTrigger           = Trait::Trigger();
        static constexpr Driver kDriver             = Trait::Driver();
        static constexpr Pull kPull                 = Trait::Pull();
        static constexpr Speed kSpeed               = Trait::Speed();
        static constexpr std::uint32_t kAf          = Trait::Af();
        static constexpr Inversion kInversion       = Trait::Inversion();
        static constexpr DefaultState kStateDefault = Trait::DefaultState();
        
        
        inline constexpr static auto Init() noexcept(true) {
          static GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(port) };
            
          constexpr std::uint32_t moder   = static_cast<std::uint32_t>(kType) << (kPin << 1ul);
          constexpr std::uint32_t pupdr   = static_cast<std::uint32_t>(kPull) << (kPin << 1ul);  
          constexpr std::uint32_t ospeed  = (kSpeed  != Speed::None ) ? static_cast<std::uint32_t>(kSpeed)  << (kPin << 1ul) : 0ul;
          constexpr std::uint32_t otyper  = (kDriver != Driver::None) ? static_cast<std::uint32_t>(kDriver) <<  kPin : 0ul;      
          constexpr std::uint32_t afr_idx = (kPin < 8u) ? 0u : 1u;
          constexpr std::uint32_t afr     = (kPin < 8u) ? static_cast<std::uint32_t>(kAf) << (kPin << 2ul) :
                                                          static_cast<std::uint32_t>(kAf) << ((kPin-8u) << 2ul);
          constexpr std::uint32_t afr_clr = (kPin < 8u) ? 0b1111u << (kPin << 2ul) :
                                                          0b1111u << ((kPin-8ul) << 2ul);
          constexpr std::uint32_t bsrr    = (kType != Type::Output) ? 0b1ul << (kPin+16u) :
                                                (kInversion == Inversion::On) ? 
                                                    (kStateDefault == DefaultState::High) ? 0b1u << (kPin+16u) : 0b1u << kKin :
                                                    (kStateDefault == DefaultState::High) ? 0b1u << kPin : 0b1u << (kPin+16u);
            
          // Set mode   
          regs->MODER &= ~(0b11 << (kPin << 1ul));
          if constexpr (moder != 0ul) regs->MODER |= moder;
            
          // Set out type  
          regs->OTYPER &= ~(0b1ul << kPin); 
          if constexpr (otyper != 0ul) regs->OTYPER |= otyper;
            
          // Set out speed
          regs->OSPEEDR &= ~(0b11 << (kPin << 1ul));     
          if constexpr (ospeed != 0ul) regs->OSPEEDR |= ospeed;
            
          // Set pull 
          regs->PUPDR &= ~(0b11 << (kPin << 1ul));  
          if constexpr (pupdr != 0ul) regs->PUPDR |= pupdr;
            
          // Set AF
          regs->AFR[afr_idx] &= ~afr_clr;
          if constexpr (afr != 0ul) regs->AFR[afr_idx] |= afr;
            
          // Set trigger
          /*
          if constexpr (kTrigger != Trigger::None)
          {
            static constexpr std::uint32_t port_idx = ((static_cast<uint32_t>(regs) - GPIOA_BASE) >> 10u);
            static constexpr std::uint32_t grp_idx  = kPin >> 2;
            static constexpr std::uint32_t offset   = (kPin - (grp_idx << 2)) << 2;
              
            // Connect EXTI to pin
            SYSCFG->EXTICR[grp_idx] |= port_idx << offset;
            
            // Enable EXTI
            EXTI->IMR |= (1 << kPin);
              
            // Set trigger
            if constexpr ((kTrigger == Trigger::Falling) || (kTrigger == Trigger::Both))
              EXTI->FTSR |= 1 << kPin;
              
            if constexpr ((kTrigger == Trigger::Rising ) || (kTrigger == Trigger::Both))
              EXTI->RTSR |= 1 << kPin;
          }
          */

          regs->BSRR = bsrr;
              
          return;
        }

        
        inline static auto Set() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          constexpr std::uint32_t mask = (kInversion == Inversion::On) ? 0b1ul << (kPin+16u) : 1ul << kPin;
            
          regs->BSRR = mask;
        }
        
        
        inline static auto Reset() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          constexpr std::uint32_t mask = (kInversion == Inversion::On) ? 1ul << kPin: 0b1ul << (kPin+16u);
                
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
          regs->BSRR = mask; 
        }
        
        
        inline static auto Toggle() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          constexpr std::uint32_t mask = 1ul << static_cast<std::uint32_t>(kPin);
            
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
          regs->ODR ^= mask;            
        }
        
        
        inline static auto Read() noexcept(true) {
          static_assert((kType == Type::Input), "This gpio not input, check 'Type' field");

          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
          bool ret = static_cast<bool>(regs->IDR & (1ul << static_cast<std::uint32_t>(kPin)));   
          return (kInversion == Inversion::On) ? !ret : ret; 
        }
    };
	  
	  
	template< class... IO > class IoGroup final
    {
      public:
        inline constexpr static auto Init() 
        { 
          constexpr std::uint32_t port= (... && static_cast<std::uint32>(IO::kPort));
          
          
          constexpr std::uint32_t MODER = (... | (static_cast<std::uint32_t>(IO::kType) << (IO::kPin << 1u)));
          constexpr std::uint32_t MODER_CLR = ~(... | (0b11 << (IO::kPin << 1u)));
          constexpr std::uint32_t OTYPER = (... | ((IO::kDriver != Driver::None) ? static_cast<std::uint32_t>(IO::kDriver) <<  IO::kPin : 0u));
          constexpr std::uint32_t OTYPER_CLR = ~(... | static_cast<std::uint32_t>((0b1ul << IO::kPin)));
          constexpr std::uint32_t OSPEEDR = (... | ((IO::kSpeed != Speed::None ) ? static_cast<std::uint32_t>(IO::kSpeed)  << (IO::kPin << 1u) : 0u));
          constexpr std::uint32_t OSPEEDR_CLR = ~(... | (0b11u << (IO::kPin << 1u)));
          constexpr std::uint32_t AFR0 = (... | ((IO::kPin < 8u) ? static_cast<std::uint32_t>(IO::kAf) << (IO::kPin << 2u) : 0u));
          constexpr std::uint32_t AFR1 = (... | ((IO::kPin >= 8u) ? static_cast<std::uint32_t>(IO::kAf) << ((IO::kPin-8u) << 2u) : 0u));
          constexpr std::uint32_t AFR0_CLR = ~(... | ((IO::kPin < 8u) ? 0b1111 << (IO::kPin << 2ul) : 0u));
          constexpr std::uint32_t AFR1_CLR = ~(... | ((IO::kPin >= 8u) ? 0b1111 << ((IO::kPin-8u) << 2ul) : 0u));
          
          constexpr std::uint32_t BSRR = (... | ((IO::kType != Type::Output) ? 0b1ul << (IO::kPin+16u) :
                                                (IO::kInvertion == Invertion::On) ? 
                                                    (IO::kStateDefault == DefaultState::High) ? 
                                                        0b1ul << (IO::kPin+16u) : 0b1ul << IO::kPin :
                                                    (IO::kStateDefault == DefaultState::High) ? 0b1ul << IO::kPin : 0b1ul << (IO::kPin+16u) ));
       
          /*                                        
          constexpr std::uint32_t IMR = (... | ((IO::kTrigger != Trigger::None) ? (1u << IO::kPin) : 0u));
          constexpr std::uint32_t FTSR = (... | (((IO::kTrigger == Trigger::Falling) || (IO::kTrigger == Trigger::Both)) ? (1u << IO::kPin) : 0u));
          constexpr std::uint32_t FTSR_CLR = ~(... | ((IO::kTrigger != Trigger::None) ? (1u << IO::kPin) : 0u));
          constexpr std::uint32_t RTSR = (... | (((IO::kTrigger == Trigger::Rising ) || (IO::kTrigger == Trigger::Both)) ? (1u << IO::kPin) : 0u));
          constexpr std::uint32_t RTSR_CLR = ~(... | ((IO::kTrigger != Trigger::None) ? (1u << IO::kPin) : 0u));
          constexpr std::uint32_t EXTICR1 = (... | (((IO::kTrigger != Trigger::None) && ((IO::kPin >> 2) == 0u)) ? 
                                                   ((static_cast<std::uint32_t>(IO::kPort) - GPIOA_BASE) >> 10u) << ((IO::kPin - (IO::kPin & 0xCu)) << 2u) : 0u));
      
          constexpr std::uint32_t EXTICR2 = (... | (((IO::kTrigger != Trigger::None) && ((IO::kPin >> 2) == 1u)) ? 
                                               ((static_cast<std::uint32_t>(IO::kPort) - GPIOA_BASE) >> 10u) << ((IO::kPin - (IO::kPin & 0xCu)) << 2u) : 0u));
      
          constexpr std::uint32_t EXTICR3 = (... | (((IO::kTrigger != Trigger::None) && ((IO::kPin >> 2) == 2u)) ? 
                                               ((static_cast<std::uint32_t>(IO::kPort) - GPIOA_BASE) >> 10u) << ((IO::kPin - (IO::kPin & 0xCu)) << 2u) : 0u));
                                               
          constexpr std::uint32_t EXTICR4 = (... | (((IO::kTrigger != Trigger::None) && ((IO::kPin >> 2) == 3u)) ? 
                                               ((static_cast<std::uint32_t>(IO::kPort) - GPIOA_BASE) >> 10u) << ((IO::kPin - (IO::kPin & 0xCu)) << 2u) : 0u)); 
      
          constexpr std::uint32_t EXTICR1_CLR = ~(... | (((IO::kTrigger != Trigger::None) && ((IO::kPin >> 2) == 0u)) ? 0b1111u << ((IO::kPin - (IO::kPin & 0xCu)) << 2u) : 0u));
          constexpr std::uint32_t EXTICR2_CLR = ~(... | (((IO::kTrigger != Trigger::None) && ((IO::kPin >> 2) == 1u)) ? 0b1111u << ((IO::kPin - (IO::kPin & 0xCu)) << 2u) : 0u));
          constexpr std::uint32_t EXTICR3_CLR = ~(... | (((IO::kTrigger != Trigger::None) && ((IO::kPin >> 2) == 2u)) ? 0b1111u << ((IO::kPin - (IO::kPin & 0xCu)) << 2u) : 0u));
          constexpr std::uint32_t EXTICR4_CLR = ~(... | (((IO::kTrigger != Trigger::None) && ((IO::kPin >> 2) == 3u)) ? 0b1111u << ((IO::kPin - (IO::kPin & 0xCu)) << 2u) : 0u));
          */
      
      std::cout << "BSRR = 0x" << std::hex << BSRR << std::endl;
      std::cout << "MODER  = 0x" << std::hex << MODER << std::endl;
      std::cout << "MODER Clear Mask = 0x" << std::hex << MODER_CLR << std::endl;
      std::cout << "OTYPER = 0x" << std::hex << OTYPER << std::endl;
      std::cout << "OTYPER Clear Mask = 0x" << std::hex << OTYPER_CLR << std::endl;
      std::cout << "OSPEEDR = 0x" << std::hex << OSPEEDR << std::endl;
      std::cout << "OSPEEDRCLR = 0x" << std::hex << OSPEEDR_CLR << std::endl;
      std::cout << "AFR0 = 0x" << std::hex << AFR0 << std::endl;
      std::cout << "AFR1 = 0x" << std::hex << AFR1 << std::endl;
      std::cout << "AFR0_CLR = 0x" << std::hex << AFR0_CLR << std::endl;
      std::cout << "AFR1_CLR = 0x" << std::hex << AFR1_CLR << std::endl;
      
      /*
      std::cout << "IMR = 0x" << std::hex << IMR << std::endl;
      std::cout << "FTSR = 0x" << std::hex << FTSR << std::endl;
      std::cout << "FTSR_CLR = 0x" << std::hex << FTSR_CLR << std::endl;
      std::cout << "RTSR = 0x" << std::hex << RTSR << std::endl;
      std::cout << "RTSR_CLR = 0x" << std::hex << RTSR_CLR << std::endl;
      std::cout << "EXTICR1 = 0x" << std::hex << EXTICR1 << std::endl;
      std::cout << "EXTICR2 = 0x" << std::hex << EXTICR2 << std::endl;
      std::cout << "EXTICR3 = 0x" << std::hex << EXTICR3 << std::endl;
      std::cout << "EXTICR4 = 0x" << std::hex << EXTICR4 << std::endl;
      std::cout << "EXTICR1_CLR = 0x" << std::hex << EXTICR1_CLR << std::endl;
      std::cout << "EXTICR2_CLR = 0x" << std::hex << EXTICR2_CLR << std::endl;
      std::cout << "EXTICR3_CLR = 0x" << std::hex << EXTICR3_CLR << std::endl;
      std::cout << "EXTICR4_CLR = 0x" << std::hex << EXTICR4_CLR << std::endl;
      */
    }
      
  } // namespace f4
} // namespace mpp::gpio



