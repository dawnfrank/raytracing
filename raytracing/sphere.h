#pragma once

#include "objectbase.h"

class Sphere{
public:
	Sphere() {}
	Sphere(Vec3 cen, double r) : center(cen), radius(r){};

	bool hit(const Ray& r, double &tmin, ShaderRec& rec) const;

	Vec3 center;
	double radius;
	static const double kEpsilon;
};