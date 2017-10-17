#include "sample_random.h"
#include "drand48.h"

Sample_Random::Sample_Random(const int num_samples, const int num_sets):
	Sampler(num_samples,num_sets)
{
	generate_samples();
}

void Sample_Random::generate_samples()
{
	int totalNum = num_samples*num_sets;
	for (int i = 0; i != totalNum; ++i){
		Vec2 sp(drand48(), drand48());
		samples.push_back(sp);
	}
}
