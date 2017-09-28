#pragma once

#include "Ray.h"

struct hit_record
{
	double t;
	Vec3 p;
	Vec3 normal;
};

class Hitable {
public:
	virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};