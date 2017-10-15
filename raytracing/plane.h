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

const double Plane::kEpsilon = 0.00001;

bool Plane::hit(const Ray& r, double& tmin, ShaderRec& rec) const {
	double t = (point - r.origin)*normal / (r.direction*normal);
	if(t>kEpsilon){
		tmin = t;
		rec.normal = normal;
		rec.hit_point = r.origin + t*r.direction;
		return true;
	}
	return false;
}