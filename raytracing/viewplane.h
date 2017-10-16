#pragma once

#include "sampler.h"

class ViewPlane {
public:
	void set_sampler(Sampler*sp);
	int get_samples_num();

	int hres;
	int vres;
	double pixel_size;
	double gamma;
	double inv_gamma;

	Sampler *sampler_ptr;
};