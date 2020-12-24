/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/core/bamblebee_n200.hpp
  @brief  Compatible with gd32f103 family and based on 
          RISC-V N200 core chip
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#define TIMER_MTIME_LO           (TIMER_MTIME)
#define TIMER_MTIME_HI           (TIMER_MTIME + 4)
#define TIMER_MTIMECMP_LO        (TIMER_MTIMECMP)
#define TIMER_MTIMECMP_HI        (TIMER_MTIMECMP + 4)
#define TIMER_MSTOP              (0xFF8)


namespace mpp::core {
    
  namespace __private { std::uint32_t GetTick(); void IncTick(); void ResetTick() } // namespace __private
    
  inline namespace n2000 {
    
    enum class CsrAccessMode { MRW, MRO, URW, URO };

    template < std::uint32_t tAddress, CsrAccessMode tAccessMode, typename tType >
    struct AbstractCsr 
    {
      using Type = tType;
      constexpr static std::uint32_t kAddress    = tAddress;
      constexpr static CsrAccessMode kAccessMode = tAccessMode;
    
      inline static void Write(Type value) {
         static_assert( kAccessMode != CsrAccessMode::MRO && kAccessMode != CsrAccessMode::URO, "This register is read only");
         write_csr(kAddress, value);
      }
      
      
      inline static Type Read() {
        return read_csr(kAddress);
      }
    };
    

    // _______RISC-V Standart CSR for machine mode________  
    
    /*! Machine Vendor ID Register */
    using MVENDORID     = AbstractCsr< 0xF11, CsrAccessMode::MRO, std::uint32_t >;
    
    /*! Machine Architecture ID Register */
    using MARCHID       = AbstractCsr< 0xF12, CsrAccessMode::MRO, std::uint32_t >;
    
    /*! Machine Implementation Register */ 
    using MIMPID        = AbstractCsr< 0xF13, CsrAccessMode::MRO, std::uint32_t >;
    
    /*! Hart ID Register */
    using MHARTID       = AbstractCsr< 0xF14, CsrAccessMode::MRO, std::uint32_t >;
    
    /*! Machine Status Register */ 
    using MSTATUS       = AbstractCsr< 0x300, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Machine ISA Register */ 
    using MISA          = AbstractCsr< 0x301, CsrAccessMode::MRO, std::uint32_t >;
    
    /*! Machine Interrupt Enable Register */
    using MIE           = AbstractCsr< 0x304, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Machine Trap-Vector Base-Address Register */
    using MTVEC         = AbstractCsr< 0x305, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! ECLIC Interrupt Vector Table Base Address */
    using MTVT          = AbstractCsr< 0x307, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Machine Scratch Register */
    using MSCRATCH      = AbstractCsr< 0x340, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Machine Exception Program Counter */
    using MEPC          = AbstractCsr< 0x341, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Machine Cause Register */
    using MCAUSE        = AbstractCsr< 0x342, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Machine Trap Value Register */
    using MTVAL         = AbstractCsr< 0x343, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Machine Interrupt Pending Register */
    using MIP           = AbstractCsr< 0x344, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! The next interrupt handler address and enable modifier */
    using MNXTI         = AbstractCsr< 0x345, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Current Interrupt Levels */
    using MINTSTATUS    = AbstractCsr< 0x346, CsrAccessMode::MRO, std::uint32_t >;
    
    /*! Scratch swap register for privileged mode */
    using MSCRATCHCSW   = AbstractCsr< 0x348, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Scratch swap register for interrupt levels */
    using MSCRATCHCSWL  = AbstractCsr< 0x349, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Lower 32 bits of Cycle counter */
    using MCYCLE        = AbstractCsr< 0xB00, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Upper 32 bits of Cycle counter */
    using MCYCLEH       = AbstractCsr< 0xB80, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Lower 32 bits of Instructions-retired counter */ 
    using MINSTRET      = AbstractCsr< 0xB02, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Upper 32 bits of Instructions-retired counter */ 
    using MINSTRETH     = AbstractCsr< 0xB82, CsrAccessMode::MRW, std::uint32_t >;
    
    
    // _______RISC-V Standart CSR for user mode________ 
      
    /*! MCYCLE read only copy */
    using CYCLE         = AbstractCsr< 0xC00, CsrAccessMode::URO, std::uint32_t >;
    
    /*! MTIME read only copy */ 
    using CYCLE         = AbstractCsr< 0xC01, CsrAccessMode::URO, std::uint32_t >;
    
    /*! MINSTRET read only copy */
    using INSTRET       = AbstractCsr< 0xC02, CsrAccessMode::URO, std::uint32_t >;
    
    /*! MCYCLEH read only copy */
    using CYCLEH        = AbstractCsr< 0xC80, CsrAccessMode::URO, std::uint32_t >;
    
    /*! MTIMEH read only copy */
    using TIMEH         = AbstractCsr< 0xC81, CsrAccessMode::URO, std::uint32_t >;
    
    /*! MINSTRETH read only copy */
    using INSTRETH      = AbstractCsr< 0xC82, CsrAccessMode::URO, std::uint32_t >;
    
    
    
    // _______Bumblebee Customized CSR________
    
    /*! Customized register for counters on & off */
    using MCOUNTINHIBIT = AbstractCsr< 0x320, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! NMI Entry Address */ 
    using MNVEC         = AbstractCsr< 0x7C3, CsrAccessMode::MRO, std::uint32_t >;
    
    /*! Customized Register Storing Type of Trap */
    using MSUBM         = AbstractCsr< 0x7C4, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Customized Register holding NMI Handler Entry Address */
    using MMISC_CTL     = AbstractCsr< 0x7D0, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Customized Register Holding the value of mstatus /* */
    using MSAVESTATUS   = AbstractCsr< 0x7D6, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Customized Register holding the value of mepc for the first-level preempted NMI or Exception */
    using MSAVEEPC1     = AbstractCsr< 0x7D7, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Customized Register holding the value of mcause for the first-level preempted NMI or Exception */
    using MSAVECAUSE1   = AbstractCsr< 0x7D8, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Customized Register holding the value of mepc for the second-level preempted NMI or Exception */
    using MSAVEEPC2     = AbstractCsr< 0x7D9, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Customized Register holding the value of mcause for the second-level preempted NMI or Exception */
    using MSAVECAUSE2   = AbstractCsr< 0x7DA, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Push msubm to stack */
    using PUSHMSUBM     = AbstractCsr< 0x7EB, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! ECLIC non-vectored interrupt handler address register */
    using MTVT2         = AbstractCsr< 0x7EC, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Jumping to next interrupt handler address and interrupt-enable register */
    using JALMNXTI      = AbstractCsr< 0x7ED, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Push mcause to stack */
    using PUSHMCAUSE    = AbstractCsr< 0x7EE, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Push mepc to stack */
    using PUSHMEPC      = AbstractCsr< 0x7EF, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! WFI Sleep Mode Register */
    using SLEEPVALUE    = AbstractCsr< 0x811, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Send Event Register */
    using TXEVT         = AbstractCsr< 0x812, CsrAccessMode::MRW, std::uint32_t >;
    
    /*! Wait for Event Control Register */
    using WFE           = AbstractCsr< 0x810, CsrAccessMode::MRW, std::uint32_t >;
    
    
    
    
    
    
    template< class ClockSystem >
    class MachineTimer {
      public:
        constexpr static std::uint32_t TickPerSec = 1000u;
        constexpr static std::uint32_t TimeCmp    = ClockSystem::kMachineTimerClkHz / 1000u;
      
        inline static std::uint32_t GetTick() { return __private::GetTick(); }
        
      
        inline static void Init() { 
          TIMER_REG(TIMER_MSTOP) = 1u;
          TIMER_REG(TIMER_MTIME_LO) = 0;
          TIMER_REG(TIMER_MTIME_HI) = 0;
          TIMER_REG(TIMER_MTIMECMP_LO) = TimeCmp;
          TIMER_REG(TIMER_MTIMECMP_HI) = 0;
          
          ResetTick();
          TIMER_REG(TIMER_MSTOP) = 0u;
        }
      
        
        static void InterruptHandler ()
        { 
          TIMER_REG(TIMER_MSTOP) = 1u;
          TIMER_REG(TIMER_MTIME_LO) = 0;
          TIMER_REG(TIMER_MTIME_HI) = 0;
          
          __private::IncTick();
          TIMER_REG(TIMER_MSTOP) = 0u;
        }         
    };
    
      
      
      
   /*
    template< class ClockSystem >
    class MachineTickCounter {
      public:
        constexpr static std::uint32_t TickPerSec = ClockSystem::kSysClkHz;
        
        inline static void Init() { 
          
        }
        
        inline static std::uint32_t GetTick() { 
          
        }
    };
    
    */
    
    
    
    enum class PriorityLevelGroup { L0P4 = 0, L1P3 = 1, L2P2 = 2, L3P1 = 3, L4P0 = 4 };
    
    struct EclicExampleTrait final {
      constexpr static PriorityLevelGroup kPriorityLevelGroup = PriorityLevelGroup::L3P1;
      constexpr static std::size_t kThresholdLevel  = 0;
    };
    
    
    
    
    template < class Trait >
    class Eclic final {
      static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
      
      private:
        constexpr static bool IsValidTrait() noexcept(true) {
          static_assert( Trait::kThresholdLevel <= 
              ((1 << static_cast< std::uint8_t >(Trait::kPriorityLevelGroup)) - 1), "Invalid threshold level");
          
          return true;
        }    
      
        template < class T, class... Ts >
        constexpr static bool IsValidInterrupt() { 
          return ( (static_cast<std::uint32_t>(T::kInterruptSource) != static_cast<std::uint32_t>(Ts::kInterruptSource)) && ... );
        }

        template < class T, class... Ts >
        constexpr static bool IsValidInterruptGroup()
        {
          if constexpr (sizeof...(Ts) == 0u)
            return true;
          else
            return IsValidInterrupt<T, Ts...>() && IsValidInterruptGroup<Ts...>();
        }
      
        static_assert(IsValidTrait(), "This trait contains error");
      
      public:
      
        constexpr static PriorityLevelGroup kPriorityLevelGroup = Trait::kPriorityLevelGroup;
        constexpr static std::size_t kThresholdLevel = Trait::kThresholdLevel;
       
        constexpr static std::uint8_t kCfgMask = static_cast<std::uint8_t>(kPriorityLevelGroup) << 1;
        constexpr static std::uint8_t kMthMask = kThresholdLevel;
      
      
        template < class... Interrupt >
        constexpr static void Init() {
          static_assert(IsValidInterruptGroup<Interrupt...>(), "All <kInterruptSource> fields must be unique");
          
          REG32(ECLIC_ADDR_BASE, ECLIC_CFG_OFFSET) = kCfgMask;
          REG32(ECLIC_ADDR_BASE, ECLIC_MTH_OFFSET) = kMthMask;
      
          ( Interrupt::Init(), ... ); 
        }
      
        constexpr static void EmitSoftwareInterrupt() {
          TIMER_REG(TIMER_MSIP) = 1u; 
        }
      
        template < class... Interrupt >
        constexpr static void EnableInterrupts() { ( Interrupt::Enable(), ... ); }
      
      
        template < class... InterruptList >
        constexpr static void DisableInterrupts() { ( Interrupt::Disable(), ... ); }
    };
  } // inline namespace
}


