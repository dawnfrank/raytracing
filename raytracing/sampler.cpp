#include "sampler.h"
#include "drand48.h"

Vec2 Sampler::sample_unit_square()
{
	if (count%num_samples == 0)jump = int(drand48()*num_sets)*num_samples;
	return samples[jump + count++ % num_samples];
}

void Sampler::map_samples_to_unit_disk(void)
{
	int size = samples.size();
	double r, phi;		// polar coordinates
	Vec2 sp; 		// sample point on unit disk

	disk_samples.reserve(size);

	for (int j = 0; j < size; j++) {
		// map sample point to [-1, 1] X [-1,1]

		sp.x = 2.0 * samples[j].x - 1.0;
		sp.y = 2.0 * samples[j].y - 1.0;

		if (sp.x > -sp.y) {			// sectors 1 and 2
			if (sp.x > sp.y) {		// sector 1
				r = sp.x;
				phi = sp.y / sp.x;
			}
			else {					// sector 2
				r = sp.y;
				phi = 2 - sp.x / sp.y;
			}
		}
		else {						// sectors 3 and 4
			if (sp.x < sp.y) {		// sector 3
				r = -sp.x;
				phi = 4 + sp.y / sp.x;
			}
			else {					// sector 4
				r = -sp.y;
				if (sp.y != 0.0)	// avoid division by zero at origin
					phi = 6 - sp.x / sp.y;
				else
					phi = 0.0;
			}
		}

		phi *= PI / 4.0;

		disk_samples[j].x = r * cos(phi);
		disk_samples[j].y = r * sin(phi);
	}

	samples.erase(samples.begin(), samples.end());
}
