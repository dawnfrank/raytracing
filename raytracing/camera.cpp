#include "camera.h"

void Camera::compute_uvw()
{
	w = eye - at;
	w.normalize();
	u = cross(w, up);
	u.normalize();
	v = cross(w, u);
}
