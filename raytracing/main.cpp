#include <iostream>
#include <cfloat>

#include "renderer.h"
#include "Window.h"
#include "sphere.h"
#include "hitable_list.h"

Vec3 color(const Ray &r,Hitable *world) {
	hit_record rec;
	if (world->hit(r,0.0, DBL_MAX,rec)) {
		return 0.5*Vec3(rec.normal.x + 1, rec.normal.y+1, rec.normal.z+ 1);
	}
	double t = 0.5*(r.direction.y + 1.0);
	return Vec3(1.0, 1.0, 1.0)*(1.0 - t) + Vec3(0.5, 0.7, 1.0)*t;
}

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

	Hitable *list[2];
	list[0] = new Sphere(Vec3(0, 0, -1), 0.5);
	list[1] = new Sphere(Vec3(0, -100.5, -1), 100);
	Hitable *world = new Hitable_list(list, 2);

	while (render.Run()) {
		hdc = BeginPaint(w->GetHandler(), &w->GetPainter());
		for (int j = 0; j != y; ++j) {
			for (int i = 0; i != x; ++i) {
				u = double(i) / double(x);
				v = double(j) / double(y);
				Ray r(origin, lower_left_corner+horizontal*u+vertical*v);
				pixel = color(r,world);
				SetPixel(hdc, i, j, RGB(int(pixel[0]*255.99), int(pixel[1]*255.99), int(pixel[2]*255.99)));
			}
		}
		
		EndPaint(w->GetHandler(), &w->GetPainter());
	}
	return 0;
}