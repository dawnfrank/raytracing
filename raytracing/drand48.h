#pragma once

#define drand_m 0x100000000LL  
#define drand_c 0xB16  
#define drand_a 0x5DEECE66DLL  

static unsigned long long seed = 1;

double drand48(void);
