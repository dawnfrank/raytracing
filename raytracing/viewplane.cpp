#include "viewplane.h"

void ViewPlane::set_sampler(Sampler * sp)
{
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = nullptr;
	}
	sampler_ptr = sp;
}

int ViewPlane::get_samples_num()
{
	return sampler_ptr->num_samples;
}
