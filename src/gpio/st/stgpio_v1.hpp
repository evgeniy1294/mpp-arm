/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/st/stgpio_v1.hpp
  @brief  Compatible series: STM32F1 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>

/*
   STM32F100xB <--- STM32F100C4, STM32F100R4, STM32F100C6, STM32F100R6, STM32F100C8, STM32F100R8, STM32F100V8, STM32F100CB, STM32F100RB and STM32F100VB 
   STM32F100xE <--- STM32F100RC, STM32F100VC, STM32F100ZC, STM32F100RD, STM32F100VD, STM32F100ZD, STM32F100RE, STM32F100VE and STM32F100ZE 
   STM32F101x6 <--- STM32F101C4, STM32F101R4, STM32F101T4, STM32F101C6, STM32F101R6 and STM32F101T6 Devices 
   STM32F101xB <--- STM32F101C8, STM32F101R8, STM32F101T8, STM32F101V8, STM32F101CB, STM32F101RB, STM32F101TB and STM32F101VB 
   STM32F101xE <--- STM32F101RC, STM32F101VC, STM32F101ZC, STM32F101RD, STM32F101VD, STM32F101ZD, STM32F101RE, STM32F101VE and STM32F101ZE  
   STM32F101xG <--- STM32F101RF, STM32F101VF, STM32F101ZF, STM32F101RG, STM32F101VG and STM32F101ZG 
   STM32F102x6 <--- STM32F102C4, STM32F102R4, STM32F102C6 and STM32F102R6 
   STM32F102xB <--- STM32F102C8, STM32F102R8, STM32F102CB and STM32F102RB 
   STM32F103x6 <--- STM32F103C4, STM32F103R4, STM32F103T4, STM32F103C6, STM32F103R6 and STM32F103T6 
   STM32F103xB <--- STM32F103C8, STM32F103R8, STM32F103T8, STM32F103V8, STM32F103CB, STM32F103RB, STM32F103TB and STM32F103VB 
   STM32F103xE <--- STM32F103RC, STM32F103VC, STM32F103ZC, STM32F103RD, STM32F103VD, STM32F103ZD, STM32F103RE, STM32F103VE and STM32F103ZE 
   STM32F103xG <--- STM32F103RF, STM32F103VF, STM32F103ZF, STM32F103RG, STM32F103VG and STM32F103ZG 
   STM32F105xC <--- STM32F105R8, STM32F105V8, STM32F105RB, STM32F105VB, STM32F105RC and STM32F105VC
   STM32F107xC <--- STM32F107RB, STM32F107VB, STM32F107RC and STM32F107VC 
*/ 


#if defined (STM32F100xB)
  #include "spec/STM32F100xB_gpio.hpp"
#elif defined (STM32F100xE)
  #include "spec/STM32F100xE_gpio.hpp"
#elif defined (STM32F101x6)
  #include "spec/STM32F101x6_gpio.hpp"
#elif defined (STM32F101xB)
  #include "spec/STM32F101xB_gpio.hpp"
#elif defined (STM32F101xE)
  #include "spec/STM32F101xE_gpio.hpp"
#elif defined (STM32F101xG)
  #include "spec/STM32F101xG_gpio.hpp"
#elif defined (STM32F102x6)
  #include "spec/STM32F102x6_gpio.hpp"
#elif defined (STM32F102xB)
  #include "spec/STM32F102xB_gpio.hpp"
#elif defined (STM32F103x6)
  #include "spec/STM32F103x6_gpio.hpp"
#elif defined (STM32F103xB)
  #include "spec/STM32F103xB_gpio.hpp"
#elif defined (STM32F103xE)
  #include "spec/STM32F103xE_gpio.hpp"
#elif defined (STM32F103xG)
  #include "spec/STM32F103xG_gpio.hpp"
#elif defined (STM32F105xC)
  #include "spec/STM32F105xC_gpio.hpp"
#elif defined (STM32F107xC)
  #include "spec/STM32F107xC_gpio.hpp"
#else
  #error "You must define supported target"
#endif







namespace mpp::gpio
{
  inline namespace stgpio_v1
  {      
    
    enum class Type         { Output = 0b0111u, Alternate = 0b1111u, Analog = 0b0000, Input = 0b1100 };
    enum class Driver       { PushPull = 0b1000u, OpenDrain = 0b1100u , None = 0b0000u };
    enum class Pull         { Floating = 0b0100u, Up = 0b1000u, Down = 0b1001u, None = 0b0000u };  
    enum class Speed        { None  = 0b0000u, Low = 0b0010u, Medium = 0b0001u, High = 0b0011u };
    enum class DefaultState { High, Low, None };
    enum class Inversion    { Off, On, None };
    
    
	  
	template< Port port, std::uint32_t pin>
	struct IO
	{
	  constexpr static Port kPort = port;
      constexpr static std::uint32_t kPin = pin;
	};
	  
	  
    /*! 
      Inherit your OutputTrait from this struct. 
      Child must contain fields: kSpeed, kDriver, kInversion, kDefaultState.
    */
    struct OutputTrait {
      constexpr static Type kType = Type::Output; 
      constexpr static Pull kPull = Pull::None;
      
      /* 
        Your trait must contain this field:
          constexpr static Speed kSpeed = Speed::Low, Medium, High;
          constexpr static Driver kDriver = Driver::PushPull, OpenDrain; 
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
      constexpr static Speed kSpeed = Speed::None;
        
      /*
        Your trait must contain this field:
          constexpr static Pull kPull = Pull::Floating, Up, Down;
          constexpr static Inversion kInversion = Inversion::Off, On;
      */ 
    };

    
    
    /*! 
      Output trait for alternate function IO
    */
    template< Driver driver, Speed speed >
    struct AlternateOutputTrait final {
      constexpr static Type kType = Type::Alternate; 
      constexpr static Pull kPull = Pull::None;
      constexpr static DefaultState kDefaultState = DefaultState::None; 
      constexpr static Inversion kInversion = Inversion::None;
      constexpr static Speed kSpeed   = speed;
      constexpr static Driver kDriver = driver; 
    };
    
    
  
    
    /*! 
      Input IO trait for alternate function IO
    */
    template< Pull pull >
    struct AlternateInputTrait final : InputTrait {
      constexpr static Pull kPull = pull;
      constexpr static Inversion kInversion = Inversion::Off;
    };
    

    
    
    using TimOutputChannel        = AlternateOutputTrait< Driver::PushPull, Speed::High >;     
    using TimInputChannel         = AlternateInputTrait < Pull::Floating >;
    using TimBreakInput           = AlternateInputTrait < Pull::Floating >;   
    using TimExternalTriggerInput = AlternateInputTrait < Pull::Floating >;
      
    
    using UsartTx          = AlternateOutputTrait< Driver::PushPull, Speed::High >;     
    using UsartRts         = AlternateOutputTrait< Driver::PushPull, Speed::Low >;     
    using UsartCk          = AlternateOutputTrait< Driver::PushPull, Speed::High >;     
    using UsartRxFloating  = AlternateInputTrait < Pull::Floating >;  
    using UsartRxPullUp    = AlternateInputTrait < Pull::Up >;
    using UsartCtsFloating = AlternateInputTrait < Pull::Floating >;  
    using UsartCtsPullUp   = AlternateInputTrait < Pull::Up >;
        
    
    using SpiMasterSck          = AlternateOutputTrait< Driver::PushPull,  Speed::High >;
    using SpiMasterMosi         = AlternateOutputTrait< Driver::PushPull,  Speed::High >;
    using SpiMasterNss          = AlternateOutputTrait< Driver::PushPull,  Speed::High >;
    using SpiSlaveMisoPtP       = AlternateOutputTrait< Driver::PushPull,  Speed::High >;
    using SpiSlaveMisoMS        = AlternateOutputTrait< Driver::OpenDrain, Speed::High >;
    using SpiSlaveSck           = AlternateInputTrait < Pull::Floating >;  
    using SpiSlaveMosiFloating  = AlternateInputTrait < Pull::Floating >;  
    using SpiSlaveMosiPullUp    = AlternateInputTrait < Pull::Up >;
    using SpiMasterMisoFloating = AlternateInputTrait < Pull::Floating >; 
    using SpiMasterMisoPullUp   = AlternateInputTrait < Pull::Up >;
    using SpiSlaveNssFloating   = AlternateInputTrait < Pull::Floating >; 
    using SpiSlaveNssPullUp     = AlternateInputTrait < Pull::Up >; 
    using SpiSlaveNssPullDown   = AlternateInputTrait < Pull::Down >; 
    
  
    using I2SMasterWs           = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using I2SMasterCk           = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using I2STransmitterSd      = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using I2SMasterMck          = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using I2SSlaveWs            = AlternateInputTrait < Pull::Floating >; 
    using I2SSlaveCk            = AlternateInputTrait < Pull::Floating >;     
    using I2SReceiverSdFloating = AlternateInputTrait < Pull::Floating >;
    using I2SReceiverSdPullUp   = AlternateInputTrait < Pull::Up >;
    using I2SReceiverSdPullDown = AlternateInputTrait < Pull::Down >;


    using I2CScl = AlternateOutputTrait< Driver::OpenDrain, Speed::Medium >;
    using I2CSda = AlternateOutputTrait< Driver::OpenDrain, Speed::Medium >;
    
    
    using CanTx         = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using CanRxFloating = AlternateInputTrait < Pull::Floating >;
    using CanRxPullUp   = AlternateInputTrait < Pull::Up >;
         
     
    using OtgFsSof        = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using OtgFsVbus       = AlternateInputTrait < Pull::Floating >;
    using OtgFsIdFloating = AlternateInputTrait < Pull::Floating >;     
    using OtgFsIdPullUp   = AlternateInputTrait < Pull::Up >; 
    

    using SdioCk   = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using SdioCmd  = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using SdioData = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    
    
    using FsmcAddr          = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcData          = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcCk            = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNoe           = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNwe           = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNe            = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNce           = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNl            = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNbl           = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNiord         = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNiowr         = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNreg          = AlternateOutputTrait< Driver::PushPull, Speed::High >;
    using FsmcNios16        = AlternateInputTrait < Pull::Floating >;
    using FsmcIntr          = AlternateInputTrait < Pull::Floating >;
    using FsmcInt           = AlternateInputTrait < Pull::Floating >;
    using FsmcNwaitFloating = AlternateInputTrait < Pull::Floating >;
    using FsmcNwaitPullUp   = AlternateInputTrait < Pull::Up >;
    using FsmcCdFloating    = AlternateInputTrait < Pull::Floating >;
    using FsmcCdPullUp      = AlternateInputTrait < Pull::Up >;
    
    
    
    
      
    template < class IO, class Trait > class Gpio final {
      static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
      static_assert(::std::is_same_v< IO,    ::std::decay_t< decltype(IO()) > >);
      
      
      private:
        constexpr static bool IsValidTrait() noexcept(true) {
          if constexpr (Trait::kType == Type::Input) {
            static_assert((Trait::kDriver == Driver::None), "Use 'Driver::None' for input pin");
            static_assert((Trait::kSpeed == Speed::None),   "Use 'Speed::None' for input pin");
            static_assert((Trait::kPull != Pull::None),   "Don't use 'Pull::None' for input pin");
            static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
            static_assert((Trait::kInversion != Inversion::None), "Don't use 'Inversion::None' input pin");
            
           return true;
         }
        
       
         if constexpr (Trait::kType == Type::Output) {
           static_assert((Trait::kDriver != Driver::None), "Don't use 'Driver::None' for output pin");
           static_assert((Trait::kPull == Pull::None),   "Use 'Pull::None' for output pin");
           static_assert((Trait::kSpeed != Speed::None), "Don't use 'Speed::None' for output pin");
           static_assert((Trait::kDefaultState != DefaultState::None), "Don't use 'DefaultState::None' for output pin");
           static_assert((Trait::kInversion != Inversion::None), "Don't use 'Inversion::None' for output pin");
         
           return true;
         }
        
        
         if constexpr (Trait::kType == Type::Analog) {
           static_assert((Trait::kDriver == Driver::None), "Use 'Driver::None' for analog pin"); 
           static_assert((Trait::kSpeed == Speed::None), "Use 'Speed::None' for analog pin");
           static_assert((Trait::kPull == Pull::None), "Use 'Pull::None' for analog pin");
           static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
           static_assert((Trait::kInversion == Inversion::None), "Use 'Inversion::None' for analog pin");
          
           return true;
         }
          
          
         if constexpr (Trait::kType == Type::Alternate) {
           static_assert((Trait::kDriver != Driver::None), "Don't use 'Driver::None' for AF pin");
           static_assert((Trait::kSpeed != Speed::None), "Don't use 'Speed::None' for AF pin"); 
           static_assert((Trait::kPull == Pull::None),   "Use 'Pull::None' for AF pin");
           static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
           static_assert((Trait::kInversion == Inversion::None), "Use 'Inversion::None' for AF pin");
          
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
        static constexpr Inversion kInversion       = Trait::kInversion;
        static constexpr DefaultState kStateDefault = Trait::kDefaultState;
      
        static constexpr  std::uint32_t CR = (((kType == Type::Input) ? 
                               static_cast<std::uint32_t>(kPull) : static_cast<std::uint32_t>(kDriver)) |
                               static_cast<std::uint32_t>(kSpeed)) & static_cast<std::uint32_t>(kType);
          
        static constexpr std::uint32_t kCrlMask       = (kPin < 8u) ? CR << (kPin << 2u) : 0u;
        static constexpr std::uint32_t kCrlClearMask  = ~((kPin < 8u) ? ~(0b1111 << (kPin << 2ul)) : 0u);
        static constexpr std::uint32_t kCrhMask       = (kPin > 7u) ? CR << ((kPin-8) << 2u) : 0u;
        static constexpr std::uint32_t kCrhClearMask  = ~((kPin > 7u) ? ~(0b1111 << ((kPin-8) << 2ul)) : 0u);
        static constexpr std::uint32_t kOdrMask       = (kType != Type::Output) ? 0u : 1ul << kPin;
        static constexpr std::uint32_t kIdrMask       = (kType != Type::Input)  ? 0u : 1ul << kPin;
        static constexpr std::uint32_t kBsrrSetMask   = (kType != Type::Output) ? 0u : (kInversion == Inversion::On) ? 0b1ul << (kPin+16u) : 0b1ul << kPin;
        static constexpr std::uint32_t kBsrrResetMask = (kType != Type::Output) ? 0u : (kInversion == Inversion::On) ? 0b1ul << kPin : 0b1ul << (kPin+16u);
        static constexpr std::uint32_t kBsrrInitMask  = (kType != Type::Output) ? 
                                                          (kType == Type::Input && kPull == Pull::Up) ?
                                                             0b1ul << kPin :
                                                             0b1ul << (kPin+16u) :
                                                          (kInversion == Inversion::On) ? 
                                                            (kStateDefault == DefaultState::High) ? 0b1u << (kPin+16u) : 0b1u << kPin :
                                                            (kStateDefault == DefaultState::High) ? 0b1u << kPin : 0b1u << (kPin+16u);
      
        inline static void Init() noexcept(true) {
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
          
          if constexpr (kPin < 8) 
          {
            regs->CRL &= kCrlClearMask;
            if constexpr (kCrlMask != 0) regs->CRL |= kCrlMask;
          }
          else
          {
            regs->CRH &= kCrhClearMask;
            if constexpr (kCrhMask != 0) regs->CRH |= kCrhMask;
          }
          
          regs->BSRR = kBsrrInitMask;
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
        constexpr static bool IsValidGroup()
        {
          if constexpr (sizeof...(Ts) == 0u)
            return true;
          else
            return IsValidIo<T, Ts...>() && IsValidGroup<Ts...>();
        }
      
        static_assert(IsValidGroup<IO...>(), "All <kPort> fields must be equal, all <kPin> fields must be unique");
      
      public:
        static constexpr Port kPort = ExtractPort< IO... >();
        constexpr static std::uint32_t kCrlMask       = ( ... | IO::kCrlMask );
        constexpr static std::uint32_t kCrlClearMask  = ( ... & IO::kCrlClearMask );
        constexpr static std::uint32_t kCrhMask       = ( ... | IO::kCrhMask );
        constexpr static std::uint32_t kCrhClearMask  = ( ... & IO::kCrhClearMask );
        constexpr static std::uint32_t kOdrMask       = ( ... | IO::kOdrMask );
        constexpr static std::uint32_t kIdrMask       = ( ... | IO::kIdrMask );
        constexpr static std::uint32_t kBsrrInitMask  = ( ... | IO::kBsrrInitMask );
        constexpr static std::uint32_t kBsrrSetMask   = ( ... | IO::kBsrrSetMask );
        constexpr static std::uint32_t kBsrrResetMask = ( ... | IO::kBsrrResetMask );
        constexpr static std::uint32_t kInputInvMask  = ( ... | (((IO::kInversion == Inversion::On)&&(IO::kType == Type::Input))  ? 1u << IO::kPin : 0u) );
        constexpr static std::uint32_t kOutputInvMask = ( ... | (((IO::kInversion == Inversion::On)&&(IO::kType == Type::Output)) ? 1u << IO::kPin : 0u) );
         
      
        inline static void Init() noexcept(true) {
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
          
          if constexpr (kCrlClearMask != 0xffff'ffff) 
            regs->CRL &= kCrlClearMask;
          
          if constexpr (kCrhClearMask != 0xffff'ffff) 
            regs->CRH &= kCrhClearMask;
          
          if constexpr (kCrlMask != 0)
            regs->CRL |= kCrlMask;
          
          if constexpr (kCrhMask != 0)
            regs->CRH |= kCrhMask;
             
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
    
  } // inline namespace
} // mpp::gpio
