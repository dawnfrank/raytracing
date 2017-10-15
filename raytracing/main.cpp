#include <iostream>
#include <cfloat>

#include "renderer.h"
#include "Window.h"
#include "world.h"
#include "drand48.h"

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
	double zw = 100;
	double x, y;
	int n = 4;

	ray.direction = Vec3(0, 0, -1);
	
	while (render.Run()) {
		hdc = BeginPaint(window->GetHandler(), &window->GetPainter());
		for (int j = 0; j != h; ++j) {
			for (int i = 0; i != w; ++i) {
				pixel_color = RGBColor(0, 0, 0);
				//jittered sampling
				for (int p = 0; p != n; ++p) {
					for (int q = 0; q != n; ++q) {
						x = world.vp.pixel_size*(i - 0.5*world.vp.hres + (drand48()+p) / n);
						y = world.vp.pixel_size*(j - 0.5*world.vp.vres + (drand48()+p) / n);
						ray.origin = Vec3(x, y, zw);
						pixel_color += world.tracer_ptr->trace_ray(ray);
					}
				}
				
				pixel_color /= n*n;
				SetPixel(hdc, i, j, RGB(int(pixel_color.r*255.99), int(pixel_color.g*255.99), int(pixel_color.b*255.99)));
			}
		}
		EndPaint(window->GetHandler(), &window->GetPainter());
	}
	return 0;
}