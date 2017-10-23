#pragma once

#include <vector>

#include "sphere.h"
#include "viewplane.h"
#include "tracer.h"
#include "objectbase.h"
#include "camera.h"

class World {
public:
	World() {}
	World(const World& w){}

	void build();
	inline void add_object(ObjectBase* object_ptr);
	ShaderRec hit_objects(const Ray& ray);


	RGBColor bg_color;
	Sphere sphere;
	ViewPlane vp;
	Tracer* tracer_ptr;
	Camera* camera_ptr;
	std::vector<ObjectBase*> objects;
	std::vector<RGBColor> bit_map;
};