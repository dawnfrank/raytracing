#include "drand48.h"

double drand48(void)
{
	seed = (drand_a * seed + drand_c) & 0xFFFFFFFFFFFFLL;
	unsigned long long x = seed >> 16;
	return  ((double)x / (double)drand_m);

}
