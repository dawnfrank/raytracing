#include "sample_regular.h"
#include "drand48.h"

Sample_Reguler::Sample_Reguler(const int num_samples, const int num_sets)
	:Sampler(num_samples, num_sets)
{
	generate_samples();
}

void Sample_Reguler::generate_samples()
{
	int n = (int)sqrt(num_samples);
	for (int k = 0; k != num_sets; ++k)
		for (int i = 0; i != n; ++i)
			for (int j = 0; j != n; ++j) {
				Vec2 sp(double(i + 1) / double(num_samples + 1), double(j + 1) / double(num_samples + 1));
				samples.push_back(sp);
			}
}