#ifndef GPIO_H_
#define GPIO_H_

#include "system_stm32f4xx.h"

// template class for I/O driver
template <typename addr_type,
          typename reg_type,
          const addr_type addr,
          const reg_type val>
class reg_access
{
  public:
    static void reg_set() { *reinterpret_cast<volatile addr_type*>(addr) = val;}
    static void reg_and() { *reinterpret_cast<volatile addr_type*>(addr) &= val;}
    static void reg_or()  { *reinterpret_cast<volatile addr_type*>(addr) |= val;}
    static void reg_not() { *reinterpret_cast<volatile addr_type*>(addr) &= (~val);}
    static void reg_get() { return *reinterpret_cast<volatile addr_type*>(addr);}

    static void bit_set() { *reinterpret_cast<volatile addr_type*>(addr) |= static_cast<reg_type>(1UL << val);}
    static void bit_clr() { *reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(~static_cast<reg_type>(1UL << val));}
    static void bit_not() { *reinterpret_cast<volatile addr_type*>(addr) ^= static_cast<reg_type>(1UL << val);}
    static void bit_get() { return (static_cast<volatile reg_type>(reg_get() & static_cast<reg_type>(1UL << val) >> val);}
};
        

#endif