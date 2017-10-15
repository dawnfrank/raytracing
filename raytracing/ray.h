#pragma once

#include "mymath.h"

struct Ray {
	Ray() {};
	Ray(const Vec3& ori, const Vec3& dir) :origin(ori), direction(dir) { direction.normalize(); }
	Ray(const Ray& r) { origin = r.origin; direction = r.direction; }
	
	Ray& operator=(const Ray&r) { origin = r.origin; direction = r.direction; return *this; };

	Vec3 point_at_parameter(double t) const { return origin + direction*t; }

	Vec3 origin;
	Vec3 direction;
};