#pragma once

#include "camera.h"

class Camera_Orthographic :public Camera {
public:
	Camera_Orthographic(Vec3 eye, Vec3 at, Vec3 up = Vec3(0, 1, 0)) :Camera(eye, at, up) {}
	Vec3 ray_direction(const Vec2 p) const;
	void render_scene(World &world);

	double d;
};