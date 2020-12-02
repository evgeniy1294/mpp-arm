/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/st/stgpiof4.hpp
  @brief  Compatible series: STM32F4, STM32G0 
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
#elif defined (STM32G071xx)
  #include "spec/STM32G07x_gpio_v1_0.hpp"
#else
  #error "You must define supported MCU"
#endif



namespace mpp::gpio
{
  inline namespace f4
  {      
    enum class Type         { Input = 0b00, Output = 0b01, Alternate = 0b10, Analog = 0b11 };
    enum class Pull         { Floating = 0b00, Up = 0b01, Down = 0b10, None };  
    enum class Speed        { Low = 0b00, Medium = 0b01, High = 0b10, VeryHigh = 0b11, None };
    enum class Driver       { PushPull = 0b0, OpenDrain = 0b1, None };
    enum class DefaultState { High, Low, None };
    enum class Inversion    { Off = 0x0ul, On = 0x1ul, None };
      
      
    /*! 
      Inherit your OutputTrait from this struct. 
      Child must contain fields: kSpeed, kDriver, kPull, kInversion, kDefaultState.
    */
    struct OutputTrait {
      constexpr static Type kType        = Type::Output; 
      constexpr static std::uint32_t kAf = 0u;
      
      /* 
	    Your trait must contain this field:
          constexpr static Speed kSpeed = Speed::Low, Medium, High, VeryHigh;
          constexpr static Driver kDriver = Driver::PushPull, OpenDrain; 
          constexpr static Pull kPull = Pull::Floating, Up, Down;
          constexpr static Inversion kInversion = Inversion::Off, On;
          constexpr static DefaultState kDefaultState = DefaultState::High, Low;
      */ 
    };
      
      
    /*! 
      Inherit your LedTrait from this struct. 
      Child must contain fields: kInversion.
    */
    struct LedTrait: OutputTrait {
      constexpr static Driver kDriver = Driver::PushPull;
      constexpr static Pull kPull = Pull::Floating;
      constexpr static Speed kSpeed = Speed::Low;
      constexpr static DefaultState kDefaultState = DefaultState::Low;    
        
      /*
	    Your trait must contain this field:
          constexpr static Inversion kInversion = Inversion::Off, On;
      */
    };
      
    
    /*! 
      Inherit your InputTrait from this struct. 
      Child must contain fields: kPull, kInversion.
    */ 
    struct InputTrait {
      constexpr static Type kType = Type::Input; 
      constexpr static Driver kDriver = Driver::None;
      constexpr static DefaultState kDefaultState = DefaultState::None;   
      constexpr static std::uint32_t kAf = 0ul;
      constexpr static Speed kSpeed = Speed::None;
        
      /*
	    Your trait must contain this field:
          constexpr static Pull kPull = Pull::Floating, Up, Down;
          constexpr static Inversion kInversion = Inversion::Off, On;
      */ 
    };

      
      
      
      

    template < class IO, class Trait > class Gpio final {
      static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
      static_assert(::std::is_same_v< IO,    ::std::decay_t< decltype(IO()) > >);

      private:
        constexpr static bool IsValidTrait() noexcept(true) {
          if constexpr (Trait::kType == Type::Input) {
            static_assert((Trait::kDriver == Driver::None), "Use 'Driver::None' for input pin");
            static_assert((Trait::kSpeed == Speed::None),   "Use 'Speed::None' for input pin");
			static_assert((Trait::kPull != Pull::None),   "Don't use 'Pull::None' for input pin");  
            static_assert((Trait::kAf == 0), "Use 'Af == 0' for non alternate function pin");
            static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
            static_assert((Trait::kInversion != Inversion::None), "Don't use 'Inversion::None' for output pin");
         
           return true;
         }
        
       
         if constexpr (Trait::kType == Type::Output) {
           static_assert((Trait::kDriver != Driver::None), "Don't use 'Driver::None' for output pin");
           static_assert((Trait::kSpeed != Speed::None), "Don't use 'Speed::None' for output pin");
		   static_assert((Trait::kPull != Pull::None),   "Don't use 'Pull::None' for output pin");
           static_assert((Trait::kDefaultState != DefaultState::None), "Don't use 'DefaultState::None' for output pin");
           static_assert((Trait::kAf == 0), "Use 'Af == 0' for non alternate function pin");
           static_assert((Trait::kInversion != Inversion::None), "Don't use 'Inversion::None' for output pin");
         
           return true;
         }
        
        
         if constexpr (Trait::kType == Type::Analog) {
           static_assert((Trait::kDriver == Driver::None), "Use 'Driver::None' for analog pin"); 
           static_assert((Trait::kSpeed == Speed::None), "Use 'Speed::None' for analog pin");
           static_assert((Trait::kPull == Pull::None), "Use 'Pull::None' for analog pin");
           static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
           static_assert((Trait::kInversion == Inversion::None), "Use 'Inversion::None' for analog pin");
           static_assert((Trait::kAf == 0), "Use 'Af == 0' for non alternate function pin");
          
           return true;
         }
          
          
         if constexpr (Trait::kType == Type::Alternate) {
           static_assert((Trait::kDriver != Driver::None), "Don't use 'Driver::None' for AF pin");
           static_assert((Trait::kSpeed != Speed::None), "Don't use 'Speed::None' for AF pin"); 
           static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
           static_assert((Trait::kInversion == Inversion::None), "Use 'Inversion::None' for AF pin");
		   static_assert((Trait::kPull != Pull::None),   "Don't use 'Pull::None' for AF pin");
           static_assert(((Trait::kAf != 0)&&(Trait::kAf < 16)), "Use 'Af != 0' for AF pin");
          
           return true;
         }
          

         return false; 
       }
        
       static_assert(IsValidTrait(), "This trait contains error");
       static_assert(IsValidIo< IO >(), "You try use incorrect pin id");
      
        
      public:
        static constexpr Port kPort                 = IO::kPort;
        static constexpr std::uint32_t kPin         = IO::kPin;
        static constexpr Type kType                 = Trait::kType;
        static constexpr Driver kDriver             = Trait::kDriver;
        static constexpr Pull kPull                 = Trait::kPull;
        static constexpr Speed kSpeed               = Trait::kSpeed;
        static constexpr std::uint32_t kAf          = Trait::kAf;
        static constexpr Inversion kInversion       = Trait::kInversion;
        static constexpr DefaultState kStateDefault = Trait::kDefaultState;
        
        static constexpr std::uint32_t kModerMask        = static_cast<std::uint32_t>(kType) << (kPin << 1ul);
        static constexpr std::uint32_t kModerClearMask   = ~(0b11 << (kPin << 1ul));
        static constexpr std::uint32_t kPupdrMask        = (kPull != Pull::None) ? static_cast<std::uint32_t>(kPull) << (kPin << 1ul) : 0u;
        static constexpr std::uint32_t kPupdrClearMask   = ~(0b11 << (kPin << 1ul));
        static constexpr std::uint32_t kOspeedrMask      = (kSpeed  != Speed::None ) ? static_cast<std::uint32_t>(kSpeed)  << (kPin << 1ul) : 0ul;
        static constexpr std::uint32_t kOspeedrClearMask = ~(0b11 << (kPin << 1ul));
        static constexpr std::uint32_t kOtyperMask       = (kDriver != Driver::None) ? static_cast<std::uint32_t>(kDriver) <<  kPin : 0ul;
        static constexpr std::uint32_t kOtyperClearMask  = ~(0b1ul << kPin); 
        static constexpr std::uint32_t kAfr0Mask         = (kPin < 8u)  ? static_cast<std::uint32_t>(kAf) << (kPin << 2u) : 0u;
        static constexpr std::uint32_t kAfr0ClearMask    = ~((kPin < 8u)  ? 0b1111u << (kPin << 2ul) : 0u);
        static constexpr std::uint32_t kAfr1Mask         = (kPin >= 8u) ? static_cast<std::uint32_t>(kAf) << ((kPin-8u) << 2u) : 0u;
        static constexpr std::uint32_t kAfr1ClearMask    = ~((kPin >= 8u) ? 0b1111 << ((kPin-8u) << 2ul) : 0u);
        static constexpr std::uint32_t kBsrrInitMask     = (kType != Type::Output) ? 0b1ul << (kPin+16u) :
                                                             (kInversion == Inversion::On) ? 
                                                               (kStateDefault == DefaultState::High) ? 0b1u << (kPin+16u) : 0b1u << kPin :
                                                               (kStateDefault == DefaultState::High) ? 0b1u << kPin : 0b1u << (kPin+16u);
        static constexpr std::uint32_t kBsrrSetMask      = (kType != Type::Output) ? 0u : (kInversion == Inversion::On) ? 0b1ul << (kPin+16u) : 0b1ul << kPin;
        static constexpr std::uint32_t kBsrrResetMask    = (kType != Type::Output) ? 0u : (kInversion == Inversion::On) ? 0b1ul << kPin : 0b1ul << (kPin+16u);
        static constexpr std::uint32_t kOdrMask          = (kType != Type::Output) ? 0u : 1ul << kPin;
        static constexpr std::uint32_t kIdrMask          = (kType != Type::Input)  ? 0u : 1ul << kPin;
        
        inline static void Init() noexcept(true) {
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          // Set mode   
          regs->MODER &= kModerClearMask;
          if constexpr (kModerMask != 0ul) regs->MODER |= kModerMask;
            
          // Set out type  
          regs->OTYPER &= kOtyperClearMask;
          if constexpr (kOtyperMask != 0ul) regs->OTYPER |= kOtyperMask;
            
          // Set out speed
          regs->OSPEEDR &= kOspeedrClearMask;     
          if constexpr (kOspeedrMask != 0ul) regs->OSPEEDR |= kOspeedrMask;
            
          // Set pull 
          regs->PUPDR &= kPupdrClearMask;  
          if constexpr (kPupdrMask != 0ul) regs->PUPDR |= kPupdrMask;
            
          // Set AF
          if constexpr (kAfr0ClearMask != 0xFFFFFFFF)
            regs->AFR[0] &= kAfr0ClearMask;

          if constexpr (kAfr1ClearMask != 0xFFFFFFFF)
            regs->AFR[1] &= kAfr1ClearMask;
            
          if constexpr (kAfr0Mask != 0ul) regs->AFR[0] |= kAfr0Mask;
          if constexpr (kAfr1Mask != 0ul) regs->AFR[1] |= kAfr1Mask;
            
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

          regs->BSRR = kBsrrInitMask;
              
          return;
        }

        
        inline static void Set() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->BSRR = kBsrrSetMask;
        }
        
        
        inline static void Reset() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->BSRR = kBsrrResetMask; 
        }
        
        
        inline static void Toggle() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->ODR ^= kOdrMask;            
        }
        
        
        inline static bool Read() noexcept(true) {
          static_assert((kType == Type::Input), "This gpio not input, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          bool ret = static_cast<bool>(regs->IDR & kIdrMask);   
          return (kInversion == Inversion::On) ? !ret : ret; 
        }
    };
      
      
  
    template< class... IO > class IoGroup final
    {
      private:
        template < class T, class... Ts >
        constexpr static Port ExtractPort() { return T::kPort; }
            
        template < class T, class... Ts >
        constexpr static bool IsValidIo() { return ( ((static_cast<std::uint32_t>(T::kPort) == static_cast<std::uint32_t>(Ts::kPort)) && (T::kPin != Ts::kPin)) && ... ); }

        template < class T, class... Ts >
        constexpr static bool IsValidGroup() // !!! Result Incorrect
        {
          if constexpr (sizeof...(Ts) == 0u)
            return true;
          else
            return IsValidIo<Ts...>() && IsValidGroup<Ts...>();
        }
      
        static_assert(IsValidGroup<IO...>(), "All <kPort> fields must be equal, all <kPin> fields must be unique");
   
      public:
        static constexpr Port kPort = ExtractPort< IO... >();
        constexpr static std::uint32_t kModerMask        = ( ... | IO::kModerMask );
        constexpr static std::uint32_t kModerClearMask   = ( ... & IO::kModerClearMask );
        constexpr static std::uint32_t kPupdrMask        = ( ... | IO::kPupdrMask );
        constexpr static std::uint32_t kPupdrClearMask   = ( ... & IO::kPupdrClearMask );
        constexpr static std::uint32_t kOtyperMask       = ( ... | IO::kOtyperMask );
        constexpr static std::uint32_t kOtyperClearMask  = ( ... & IO::kOtyperClearMask );
        constexpr static std::uint32_t kOspeedrMask      = ( ... | IO::kOspeedrMask );
        constexpr static std::uint32_t kOspeedrClearMask = ( ... & IO::kOspeedrClearMask );
        constexpr static std::uint32_t kAfr0Mask         = ( ... | IO::kAfr0Mask );
        constexpr static std::uint32_t kAfr0ClearMask    = ( ... & IO::kAfr0ClearMask );
        constexpr static std::uint32_t kAfr1Mask         = ( ... | IO::kAfr1Mask );
        constexpr static std::uint32_t kAfr1ClearMask    = ( ... & IO::kAfr1ClearMask );
        constexpr static std::uint32_t kBsrrInitMask     = ( ... | IO::kBsrrInitMask );
        constexpr static std::uint32_t kBsrrSetMask      = ( ... | IO::kBsrrSetMask );
        constexpr static std::uint32_t kBsrrResetMask    = ( ... | IO::kBsrrResetMask );
        constexpr static std::uint32_t kOdrMask          = ( ... | IO::kOdrMask );
        constexpr static std::uint32_t kIdrMask          = ( ... | IO::kIdrMask );
        constexpr static std::uint32_t kInputInvMask     = ( ... | (((IO::kInversion == Inversion::On)&&(IO::kType == Type::Input))  ? 1u << IO::kPin : 0u) );
        constexpr static std::uint32_t kOutputInvMask    = ( ... | (((IO::kInversion == Inversion::On)&&(IO::kType == Type::Output)) ? 1u << IO::kPin : 0u) );
    
        inline static void Init() noexcept(true) {
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };

          regs->MODER &= kModerClearMask;
          if constexpr (kModerMask != 0u) regs->MODER |= kModerMask;

          regs->PUPDR &= kPupdrClearMask;
          if constexpr (kPupdrMask != 0u) regs->PUPDR |= kPupdrMask;

          regs->OTYPER &= kOtyperClearMask;
          if constexpr (kOtyperMask != 0u) regs->OTYPER |= kOtyperMask;

          regs->OSPEEDR &= kOspeedrClearMask;
          if constexpr (kOspeedrMask != 0u) regs->OSPEEDR |= kOspeedrMask;

          if constexpr (kAfr0ClearMask != 0xFFFFFFFF)
            regs->AFR[0] &= kAfr0ClearMask;

          if constexpr (kAfr1ClearMask != 0xFFFFFFFF)
            regs->AFR[1] &= kAfr1ClearMask;
            
          if constexpr (kAfr0Mask != 0ul) regs->AFR[0] |= kAfr0Mask;
          if constexpr (kAfr1Mask != 0ul) regs->AFR[1] |= kAfr1Mask;

          regs->BSRR = kBsrrInitMask;
        }
        
        inline static void Set() noexcept(true) {
          static_assert((kBsrrSetMask != 0u), "IoGroup haven't output pin");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };

          regs->BSRR = kBsrrSetMask;
        }
        
        inline static void Reset() noexcept(true) {
          static_assert((kBsrrSetMask != 0u), "IoGroup haven't output pin");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->BSRR = kBsrrResetMask; 
        }
        
        inline static void Toggle() noexcept(true) {
          static_assert((kBsrrSetMask != 0u), "IoGroup haven't output pin");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->ODR ^= kOdrMask;            
        }
        
        inline static std::uint32_t Read() noexcept(true) {
          static_assert((kIdrMask != 0u), "IoGroup haven't input pin");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          std::uint32_t ret = regs->IDR & kIdrMask;
          if constexpr (kInputInvMask != 0u) ret ^= kInputInvMask;
           
          return ret;
        }
    };
      
    
        /* Saved for EXTI module                                       
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
  } // namespace f4
} // namespace mpp::gpio



