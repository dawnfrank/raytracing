#include <iostream>

#include "renderer.h"
#include "Window.h"
#include "ray.h"

double hit_sphere(const Vec3& center, double radius, const Ray &r) {
	Vec3 oc = r.origin - center;
	double a = r.direction * r.direction;
	double b = oc * r.direction * 2.0;
	double c = oc * oc - radius * radius;
	double discirminant = b*b - 4 * a*c;
	if(discirminant < 0) return -1.0;
	else return (-b - sqrt(discirminant)) / (a*2.0);
}

Vec3 color(const Ray &r) {
	double t = hit_sphere(Vec3(0, 0, -1), 0.5, r);
	if (t > 0.0) {
		Vec3 N = r.point_at_parameter(t) - Vec3(0, 0, -1);
		return Vec3(N.x + 1, N.y+1, N.z + 1)*0.5;
	}
	t = 0.5*(r.direction.y + 1.0);
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

	while (render.Run()) {
		hdc = BeginPaint(w->GetHandler(), &w->GetPainter());
		for (int j = 0; j != y; ++j) {
			for (int i = 0; i != x; ++i) {
				u = double(i) / double(x);
				v = double(j) / double(y);
				Ray r(origin, lower_left_corner+horizontal*u+vertical*v);
				pixel = color(r);
				SetPixel(hdc, i, j, RGB(int(pixel[0]*255.99), int(pixel[1]*255.99), int(pixel[2]*255.99)));
			}
		}
		
		EndPaint(w->GetHandler(), &w->GetPainter());
	}
	return 0;
}