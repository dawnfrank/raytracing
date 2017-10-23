#pragma once

#include "camera.h"

class Camera_Pinhole :public Camera {
public:
	Camera_Pinhole(Vec3 eye, Vec3 at, Vec3 up = Vec3(0, 1, 0));
	Vec3 ray_direction(const Vec2 p) const;
	void render_scene(World& w);

	double d;
	double zoom;
};