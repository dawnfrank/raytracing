#include <iostream>
#include <cfloat>

#include "renderer.h"
#include "Window.h"
#include "sphere.h"
#include "mymath.h"

int main() {
	int x = 400;
	int y = 300;

	Renderer render;
	auto w = render.OpenWindow(x, y, TEXT("test"));

	double u,v;
	Vec3 pixel;
	HDC hdc;

	Vec3 lower_left_corner(-2.0, -1.5, -1.0);
	Vec3 horizontal(4.0, 0.0, 0.0);
	Vec3 vertical(0.0, 3.0, 0.0);
	Vec3 origin(0.0, 0.0, 0.0);

	while (render.Run()) {
		hdc = BeginPaint(w->GetHandler(), &w->GetPainter());
		for (int j = 0; j != y; ++j) {
			for (int i = 0; i != x; ++i) {
				u = double(i) / double(x);
				v = double(j) / double(y);
				SetPixel(hdc, i, j, RGB(int(u*255.99), int(v*255.99), int(0.2*255.99)));
			}
		}
		
		EndPaint(w->GetHandler(), &w->GetPainter());
	}
	return 0;
}