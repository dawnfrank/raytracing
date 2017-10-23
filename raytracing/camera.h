#pragma once

#include "mymath.h"

class World;

class Camera {
public:
	Camera(Vec3 eye, Vec3 at, Vec3 up = Vec3(0, 1, 0)) :eye(eye), at(at), up(up) {}
	virtual void render_scene(World &w) = 0;
	void compute_uvw();

	Vec3 eye, at, up;
	Vec3 u, v, w;
	double exposure_time;
};