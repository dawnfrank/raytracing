#include <iostream>
#include <cfloat>

#include "renderer.h"
#include "Window.h"
#include "world.h"

int main() {
	int w = 400;
	int h = 300;

	Renderer render;
	HDC hdc;
	auto window = render.OpenWindow(w, h, TEXT("test"));

	World world;
	world.build();

	RGBColor pixel_color; 
	Ray ray;
	double zw = -100;
	Vec2 sp, pp;
	int sample_num = world.vp.get_samples_num();

	ray.origin =Vec3(0, 0, 150);

	while (render.Run()) {
		hdc = BeginPaint(window->GetHandler(), &window->GetPainter());
		for (int i = 0; i != w; ++i) {
			for (int j = 0; j != h; ++j) {
				pixel_color = RGBColor(0, 0, 0);
				for (int s = 0; s != sample_num; ++s) {
					sp = world.vp.sampler_ptr->sample_unit_square();
					pp.x = world.vp.pixel_size*(i - 0.5*(world.vp.hres - 1) + sp.x);
					pp.y = world.vp.pixel_size*(j - 0.5*(world.vp.vres - 1) + sp.y);
					ray.direction = Vec3(pp.x, pp.y, zw);
					pixel_color += world.tracer_ptr->trace_ray(ray);
				}
				pixel_color /= sample_num;
				SetPixel(hdc, i, j, RGB(int(pixel_color.r*255.99), int(pixel_color.g*255.99), int(pixel_color.b*255.99)));
			}
		}
		EndPaint(window->GetHandler(), &window->GetPainter());
	}
	return 0;
}