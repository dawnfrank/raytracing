#pragma once

#include "rgbcolor.h"
#include "mymath.h"

class World;

class ShaderRec {
public:
	ShaderRec(World &w);
	ShaderRec(const ShaderRec &sr);

	Vec3 normal;
	Vec3 hit_point;
	bool hit_an_object;
	RGBColor color;
	World& w;
};