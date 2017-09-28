#pragma once

#include "mymath.h"
class Ray {
public:
	Ray();
	Ray(const Vec3& ori, const Vec3& dir) :origin(ori), direction(dir) { direction.normalize(); }

	Vec3 point_at_parameter(double t) const { return origin + direction*t; }

	Vec3 origin;
	Vec3 direction;
};