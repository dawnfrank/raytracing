#pragma once

#include "mymath.h"
#include "ray.h"
#include "shaderec.h"

struct ObjectBase {
	virtual bool hit(const Ray& r, double& tmin, ShaderRec& rec) const=0;
	virtual RGBColor get_color() {
		return color;
	}
	RGBColor color;
};