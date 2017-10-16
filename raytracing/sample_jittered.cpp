
#include "sample_jittered.h"
#include "drand48.h"

Sample_Jittered::Sample_Jittered(const int num_samples, const int num_sets)
	:Sampler(num_samples, num_sets)
{
	generate_samples();
}

void Sample_Jittered::generate_samples()
{
	for (int p = 0; p != num_sets; ++p)
		for (int i = 0; i != num_samples; ++i)
			for (int j = 0; j != num_samples; ++j) {
				Vec2 sp((i + drand48()) / num_samples, (j + drand48()) / num_samples);
				samples.push_back(sp);
			}
}
