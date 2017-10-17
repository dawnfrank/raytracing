#pragma once

#include "sampler.h"

class Sample_Random :public Sampler {
public:
	Sample_Random(const int num_samples = DEFAULT_SAMPLES, const int num_sets = DEFAULT_SETS);

	void generate_samples();
};