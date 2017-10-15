#pragma once

#include "sphere.h"
#include "viewplane.h"
#include "tracer.h"

class World {
public:
	World() {}
	World(const World& w){}

	void build();

	RGBColor bg_color;
	Sphere sphere;
	ViewPlane vp;
	Tracer* tracer_ptr;
};