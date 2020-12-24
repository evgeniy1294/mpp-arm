/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/gigadevice/gdgpio_v1.hpp
  @brief  Compatible series: GD32VF103xx 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>


#if defined (GD32VF103xx)
  #include "spec/gd32vf103xx_gpio.hpp"
#else
  #error "You must define supported target"
#endif







namespace mpp::gpio
{
  inline namespace gd32v_gpio_v1
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
          
        static constexpr std::uint32_t kCtl0Mask       = (kPin < 8u) ? CR << (kPin << 2u) : 0u;
        static constexpr std::uint32_t kCtl0ClearMask  = ~((kPin < 8u) ? ~(0b1111 << (kPin << 2ul)) : 0u);
        static constexpr std::uint32_t kCtl1Mask       = (kPin > 7u) ? CR << ((kPin-8) << 2u) : 0u;
        static constexpr std::uint32_t kCtl1ClearMask  = ~((kPin > 7u) ? ~(0b1111 << ((kPin-8) << 2ul)) : 0u);
        static constexpr std::uint32_t kOctlMask       = (kType != Type::Output) ? 0u : 1ul << kPin;
        static constexpr std::uint32_t kIstatMask      = (kType != Type::Input)  ? 0u : 1ul << kPin;
        static constexpr std::uint32_t kBopSetMask     = (kType != Type::Output) ? 0u : (kInversion == Inversion::On) ? 0b1ul << (kPin+16u) : 0b1ul << kPin;
        static constexpr std::uint32_t kBopResetMask   = (kType != Type::Output) ? 0u : (kInversion == Inversion::On) ? 0b1ul << kPin : 0b1ul << (kPin+16u);
        static constexpr std::uint32_t kBopInitMask    = (kType != Type::Output) ? 
                                                           (kType == Type::Input && kPull == Pull::Up) ?
                                                             0b1ul << kPin :
                                                             0b1ul << (kPin+16u) :
                                                           (kInversion == Inversion::On) ? 
                                                             (kStateDefault == DefaultState::High) ? 0b1u << (kPin+16u) : 0b1u << kPin :
                                                             (kStateDefault == DefaultState::High) ? 0b1u << kPin : 0b1u << (kPin+16u);
      
        inline static void Init() noexcept(true) {          
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
            
          if constexpr (kPin < 8) 
          {
              
            GPIO_CTL0(regs) &= kCtl0ClearMask;
            if constexpr (kCtl0Mask != 0) GPIO_CTL0(regs) |= kCtl0Mask;
          }
          else
          {
            GPIO_CTL1(regs) &= kCtl1ClearMask;
            if constexpr (kCtl1Mask != 0) GPIO_CTL1(regs) |= kCtl1Mask;
          }
          
          GPIO_BOP(regs) = kBopInitMask;
        }
      
      
        inline static void Set() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field"); 
            
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
          GPIO_BOP(regs) = kBopSetMask;
        }
      
      
      
        inline static void Reset() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
            
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
          GPIO_BOP(regs) = kBopResetMask; 
        }
        
        
        inline static void Toggle() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");   
          
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
          GPIO_OCTL(regs) ^= kOctlMask;            
        }
      
      
      
        inline static bool Read() noexcept(true) {
          static_assert((kType == Type::Input), "This gpio not input, check 'Type' field");   
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
          
          bool ret = static_cast<bool>(GPIO_ISTAT(regs) & kIstatMask);   
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
        constexpr static std::uint32_t kCtl0Mask       = ( ... | IO::kCtl0Mask );
        constexpr static std::uint32_t kCtl0ClearMask  = ( ... & IO::kCtl0ClearMask );
        constexpr static std::uint32_t kCtl1Mask       = ( ... | IO::kCtl1Mask );
        constexpr static std::uint32_t kCtl1ClearMask  = ( ... & IO::kCtl1ClearMask );
        constexpr static std::uint32_t kOctlMask       = ( ... | IO::kOctlMask );
        constexpr static std::uint32_t kIstatMask      = ( ... | IO::kIstatMask );
        constexpr static std::uint32_t kBopInitMask    = ( ... | IO::kBopInitMask );
        constexpr static std::uint32_t kBopSetMask     = ( ... | IO::kBopSetMask );
        constexpr static std::uint32_t kBopResetMask   = ( ... | IO::kBopResetMask );
        constexpr static std::uint32_t kInputInvMask   = ( ... | (((IO::kInversion == Inversion::On)&&(IO::kType == Type::Input))  ? 1u << IO::kPin : 0u) );
        constexpr static std::uint32_t kOutputInvMask  = ( ... | (((IO::kInversion == Inversion::On)&&(IO::kType == Type::Output)) ? 1u << IO::kPin : 0u) );
         
      
        inline static void Init() noexcept(true) {
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
          
          if constexpr (kCtl0ClearMask != 0xffff'ffff) 
            GPIO_CTL0(regs) &= kCtl0ClearMask;
          
          if constexpr (kCtl1ClearMask != 0xffff'ffff) 
            GPIO_CTL1(regs) &= kCtl1ClearMask;
          
          if constexpr (kCtl0Mask != 0)
            GPIO_CTL0(regs) |= kCtl0Mask;
          
          if constexpr (kCtl1Mask != 0)
            GPIO_CTL1(regs) |= kCtl1Mask;
             
          GPIO_BOP(regs) = kBopInitMask;
        }
      
      
        inline static void Set() noexcept(true) {
          static_assert((kBopSetMask != 0u), "IoGroup haven't output pin");
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
          
          GPIO_BOP(regs) = kBopSetMask;
        }
        
      
        inline static void Reset() noexcept(true) {
          static_assert((kBopResetMask != 0u), "IoGroup haven't output pin");
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
          
          GPIO_BOP(regs) = kBopResetMask; 
        }
        
      
        inline static void Toggle() noexcept(true) {
          static_assert((kOctlMask != 0u), "IoGroup haven't output pin");        
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
          
          GPIO_OCTL(regs) ^= kOctlMask;            
        }
        
      
        inline static std::uint32_t Read() noexcept(true) {
          static_assert((kIstatMask != 0u), "IoGroup haven't input pin");
          constexpr std::uint32_t regs{static_cast<std::uint32_t>(kPort)};
            
          std::uint32_t ret = GPIO_ISTAT(regs) & kIstatMask;
          if constexpr (kInputInvMask != 0u) ret ^= kInputInvMask;
           
          return ret;
        }
      
    };
    
  } // inline namespace
} // mpp::gpio
