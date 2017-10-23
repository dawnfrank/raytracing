#include "camera_pinhole.h"
#include "world.h"

Camera_Pinhole::Camera_Pinhole(Vec3 eye, Vec3 at, Vec3 up)
	:Camera(eye, at, up)
{
	zoom = 1.0;
	d = at[2] - eye[2];
}

Vec3 Camera_Pinhole::ray_direction(const Vec2 p) const {
	Vec3 dir = p.x*u + p.y*v - d*w;
	dir.normalize();
	return dir;
}

void Camera_Pinhole::render_scene(World & world)
{
	int w = world.vp.hres;
	int h = world.vp.vres;
	RGBColor pixel_color;
	Ray ray;
	Vec2 sp, pp;
	int sample_num = world.vp.get_samples_num();

	world.vp.pixel_size /= zoom;
	ray.origin = eye;

	for (int i = 0; i != w; ++i) {
		for (int j = 0; j != h; ++j) {
			pixel_color = RGBColor(0, 0, 0);
			for (int s = 0; s != sample_num; ++s) {
				sp = world.vp.sampler_ptr->sample_unit_square();
				pp.x = world.vp.pixel_size*(i - 0.5*(world.vp.hres - 1) + sp.x);
				pp.y = world.vp.pixel_size*(j - 0.5*(world.vp.vres - 1) + sp.y);
				ray.direction = Vec3(pp.x, pp.y, d);
				pixel_color += world.tracer_ptr->trace_ray(ray);
			}
			pixel_color /= sample_num;
			world.bit_map[i + j*w] = pixel_color;
		}
	}
}
