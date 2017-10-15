#pragma once

#include "objectbase.h"

struct Plane :public ObjectBase {
	Plane() {}
	Plane(Vec3 p, Vec3 norm) : point(p), normal(norm) {};

	virtual bool hit(const Ray& r, double& tmin, ShaderRec& rec) const;

private:
	Vec3 point;
	Vec3 normal;
	static const double kEpsilon;
};