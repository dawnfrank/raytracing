#pragma once

#include <vector>

#include "mymath.h"
#include "define.h"

class Sampler {
public:
	Sampler(const int num_samples= DEFAULT_SAMPLES,const int num_sets= DEFAULT_SETS):
		num_samples(num_samples),
		num_sets(num_sets)
	{}

	virtual void generate_samples() = 0;
	Vec2 sample_unit_square();
	void map_samples_to_unit_disk(void);

	int num_samples;
	int num_sets;
	std::vector<Vec2> samples;
	std::vector<Vec2> disk_samples;
	unsigned long count=0;
	int jump=0;
};