#pragma once

#include "tracer.h"
#include "shaderec.h"

class World;

class SingleSphere :public Tracer {
public:
	SingleSphere() :Tracer() {}
	SingleSphere (World *w):Tracer(w){}

	virtual RGBColor trace_ray(const Ray& r)const;
};

