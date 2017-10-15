
#include "multiobject.h"
#include "world.h"
#include "shaderec.h"


RGBColor MultipleObjects::trace_ray(const Ray& ray) const {
	ShaderRec sr(world_ptr->hit_objects(ray)); // sr is copy constructed

	if (sr.hit_an_object)
		return (sr.color);
	else
		return (world_ptr->bg_color);
}
