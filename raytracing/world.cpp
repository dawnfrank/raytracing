#include "world.h"

void World::build() {
	vp.hres = 300;
	vp.vres = 400;
	vp.pixel_size = 1.0;
	vp.gamma = 1.0;

	bg_color = RGBColor(0, 0, 0);
	//	tracer_ptr = new SingleSphere(this);

	sphere.center = Vec3(0, 0, 0);
	sphere.radius = 85.0;
}