#pragma once

#include "tracer.h"

class MultipleObjects : public Tracer {
public:
	MultipleObjects(void) {}

	MultipleObjects(World* world):Tracer(world){}

	virtual RGBColor trace_ray(const Ray& ray) const;
};