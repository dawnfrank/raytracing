#include "world.h"
#include "singlesphere.h"
#include "multiobject.h"
#include "define.h"
#include "plane.h"
#include "sample_multijittered.h"
#include "camera_pinhole.h"

/*
void World::build() {
	vp.hres = 400;
	vp.vres = 300;
	vp.pixel_size = 1;
	vp.gamma = 1.0;
	vp.inv_gamma = 1.0;

	bg_color = RGBColor(0, 0, 0);
	tracer_ptr = new MultipleObjects(this);

	Sphere *sphere_ptr = new Sphere(Vec3(0, 30, 0),85);
	sphere_ptr->color = RGBColor(1, 0, 0);
	add_object(sphere_ptr);

	sphere_ptr = new Sphere(Vec3(0, -25, 0),60);
	sphere_ptr->color = RGBColor(0, 1, 0);
	add_object(sphere_ptr);

	Plane *plane_ptr = new Plane(Vec3(0, 0, 0),Vec3(0,0,1));
	plane_ptr->color = RGBColor(0.8, 0.8, 0.8);
	add_object(plane_ptr);
}
*/

void World::build() {
	int num_samples = 16;
	bit_map.resize(400 * 300);
	vp.hres = 400;
	vp.vres = 300;
	vp.pixel_size = 1;
	vp.gamma = 1.0;
	vp.inv_gamma = 1.0;
	vp.set_sampler(new Sample_MultiJittered(num_samples));

	bg_color = RGBColor(0, 0, 0);
	tracer_ptr = new SingleSphere(this);
	camera_ptr = new Camera_Pinhole(Vec3(0,0,100),Vec3(0,0,0));

	sphere.center = Vec3(0, 0, 0);
	sphere.radius = 85;
}


inline void World::add_object(ObjectBase * object_ptr)
{
	objects.push_back(object_ptr);
}

ShaderRec World::hit_objects(const Ray &ray) {
	ShaderRec sr(*this);

	double t;
	double tmin = kHugeValue;
	int num_objects = objects.size();

	for (int i = 0; i < num_objects; ++i) {
		if (objects[i]->hit(ray, t, sr) && (t < tmin)) {
			sr.hit_an_object = true;
			sr.color = objects[i]->get_color();
			tmin = t;
		}
	}
	return sr;
}