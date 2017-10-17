#pragma once

#include "sampler.h"

class Sample_NRooks :public Sampler {
public:
	Sample_NRooks(const int num_samples = DEFAULT_SAMPLES, const int num_sets = DEFAULT_SETS);

	void generate_samples();
};
