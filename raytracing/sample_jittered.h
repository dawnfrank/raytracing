#pragma once

#include "sampler.h"

class Sample_Jittered :public Sampler {
public:
	Sample_Jittered(const int num_samples = 4, const int num_sets = 10);

	void generate_samples();
};