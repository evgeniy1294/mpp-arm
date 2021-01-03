/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/core/riscv.hpp
  @brief  Compatible with riscv core
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>


namespace mpp::core {
  


  enum class Accessibility { MRW, MRO, URW, URO };
  
  // TODO: Change std::uint32_t to xlen_t
  // TODO: Change __builtin_constant_p to std::is_constant_evaluated() (C++20)
  template< std::uintptr_t tAddress, Accessibility tAccessibility >
  class AbstractCsr
  {
    public:
  
      static constexpr std::uintptr_t kAddress = tAddress;
      static constexpr Accessibility kAccessibility = tAccessibility;
    
      static_assert ( kAddress < 4096, "Wrong CSR address" );
    
      inline static void Write [[gnu::always_inline]] (std::uint32_t value) {
        static_assert(kAccessibility == Accessibility::MRW || kAccessibility == Accessibility::URW, "This CSR read only");
        
        if ( __builtin_constant_p(value) && value < 32u ) {
          asm volatile ("csrrwi  x0, %[csr], %[uimm]" 
                        : /* No output parameters */
                        : [csr] "i"(kAddress), [uimm] "i"(value) // <- Input parameters
                        : /* No clobbers */ );  
        }
        else {
          asm volatile ("csrw  %[csr], %[aval]" 
                        : /* No output parameters */
                        : [csr] "i"(kAddress), [aval] "r"(value) // <- Input parameters
                        : /* No clobbers */ );  
        }
      }
    
      inline static std::uint32_t Read [[gnu::always_inline]] () {
        std::uint32_t ret;
        asm volatile ("csrr %[dest], %[csr]" 
                      : [dest] "=r"(ret)      // <- Output parameters
                      : [csr]  "i"(kAddress)  // <- Input parameters
                      : /* No clobbers */ );
    
        return ret;
      }
    
      inline static void Set [[gnu::always_inline]] (std::uint32_t mask) {
        static_assert(kAccessibility == Accessibility::MRW || kAccessibility == Accessibility::URW, "This CSR read only");
        
        if ( __builtin_constant_p(mask) && mask < 32u) {
          asm volatile ("csrsi  %[csr], %[uimm]" 
                        : /* No output parameters */
                        : [csr] "i"(kAddress), [uimm] "i"(mask) // <- Input parameters
                        : /* No clobbers */ );  
        }
        else {
          asm volatile ("csrs  %[csr], %[aval]" 
                        : /* No output parameters */
                        : [csr] "i"(kAddress), [aval] "r"(mask) // <- Input parameters
                        : /* No clobbers */ );  
        }
      }
    
      inline static void Clear [[gnu::always_inline]] (std::uint32_t mask) {
        static_assert(kAccessibility == Accessibility::MRW || kAccessibility == Accessibility::URW, "This CSR read only");
        
        if ( __builtin_constant_p(mask) && mask < 32u) {
          asm volatile ("csrci  %[csr], %[uimm]" 
                        : /* No output parameters */
                        : [csr] "i"(kAddress), [uimm] "i"(mask) // <- Input parameters
                        : /* No clobbers */ );  
        }
        else {
          asm volatile ("csrc  %[csr], %[aval]" 
                        : /* No output parameters */
                        : [csr] "i"(kAddress), [aval] "r"(mask) // <- Input parameters
                        : /* No clobbers */ );  
        }
      }
  }; 
  
  
} // namespace mpp::core
