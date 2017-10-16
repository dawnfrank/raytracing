#include "sampler.h"
#include "drand48.h"

Vec2 Sampler::sample_unit_square()
{
	if (count%num_samples == 0)jump = int(drand48()*num_sets)*num_samples;
	return samples[jump + count++ % (num_samples)*num_sets];
}
