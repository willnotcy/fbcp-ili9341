#pragma once

#ifndef KERNEL_MODULE
#include <inttypes.h>
#include <unistd.h>  

// Initialized in spi.cpp along with the rest of the BCM2835 peripheral:
// Read as two separate 32-bit registers (not a single unaligned 64-bit 
// pointer) since AArch64 requires natural alignment for accesses to 
// device-mapped memory; a 4-byte-aligned 64-bit read causes SIGBUS on  
// 64-bit ARM even though it was silently tolerated on 32-bit ARM.
extern volatile uint32_t *systemTimerRegisterLo;
extern volatile uint32_t *systemTimerRegisterHi;

inline uint64_t tick()  
{  
  uint32_t hi, lo;
  do  
  {
 hi = *systemTimerRegisterHi; 
 lo = *systemTimerRegisterLo; 
  } while (*systemTimerRegisterHi != hi); 
  return ((uint64_t)hi << 32) | lo; 
}  

#endif


#ifdef NO_THROTTLING 
#define usleep(x) ((void)0)
#endif
