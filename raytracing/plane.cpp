#include "plane.h"

const double Plane::kEpsilon = 0.00001;

bool Plane::hit(const Ray& r, double& tmin, ShaderRec& rec) const {
	double t = (point - r.origin)*normal / (r.direction*normal);
	if (t>kEpsilon) {
		tmin = t;
		rec.normal = normal;
		rec.hit_point = r.origin + t*r.direction;
		return true;
	}
	return false;
}