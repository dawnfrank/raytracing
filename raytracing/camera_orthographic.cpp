#include "camera_orthographic.h"
#include "world.h"

Vec3 Camera_Orthographic::ray_direction(const Vec2 p) const
{
	return Vec3(0, 0, -1);
}

void Camera_Orthographic::render_scene(World & world)
{
	int w = world.vp.hres;
	int h = world.vp.vres;
	RGBColor pixel_color;
	Ray ray;
	Vec2 sp, pp;
	int sample_num = world.vp.get_samples_num();

	ray.origin = eye;

	for (int i = 0; i != w; ++i) {
		for (int j = 0; j != h; ++j) {
			pixel_color = RGBColor(0, 0, 0);
			for (int s = 0; s != sample_num; ++s) {
				sp = world.vp.sampler_ptr->sample_unit_square();
				pp.x = world.vp.pixel_size*(i - 0.5*world.vp.hres + sp.x);
				pp.y = world.vp.pixel_size*(j - 0.5*world.vp.vres + sp.y);
				ray.direction = Vec3(pp.x, pp.y, d);
				pixel_color += world.tracer_ptr->trace_ray(ray);
			}
			pixel_color /= sample_num;
			world.bit_map[i + j*w] = pixel_color;
		}
	}
}
