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
	while (render.Run()) {
		world.camera_ptr->render_scene(world);

		hdc = BeginPaint(window->GetHandler(), &window->GetPainter());
		for (int i = 0; i != w; ++i) {
			for (int j = 0; j != h; ++j) {
				pixel_color = world.bit_map[i + j*w];
				SetPixel(hdc, i, j, RGB(int(pixel_color.r*255.99), int(pixel_color.g*255.99), int(pixel_color.b*255.99)));
			}
		}
		EndPaint(window->GetHandler(), &window->GetPainter());
	}
	return 0;
}