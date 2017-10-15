#pragma once

#include "ray.h"
#include "rgbcolor.h"

class World;

class Tracer{
public:
	Tracer():world_ptr(nullptr){}
	Tracer(World *w) :world_ptr(w) {}

	virtual RGBColor trace_ray(const Ray& r)const {
		return RGBColor(0, 0, 0);
	};

	World* world_ptr;
};