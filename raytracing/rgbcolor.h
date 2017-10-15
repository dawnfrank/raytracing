#pragma once

#include <math.h>

#define EPSILON 1e-6f

struct RGBColor {

	inline RGBColor() : x(0), y(0), z(0) { }
	inline RGBColor(double x, double y, double z) : x(x), y(y), z(z) { }
	inline RGBColor(const double *v) : x(v[0]), y(v[1]), z(v[2]) { }
	inline RGBColor(const RGBColor &v) : x(v.x), y(v.y), z(v.z) { }

	inline int operator==(const RGBColor &v) { return (fabs(x - v.x) < EPSILON && fabs(y - v.y) < EPSILON && fabs(z - v.z) < EPSILON); }
	inline int operator!=(const RGBColor &v) { return !(*this == v); }

	inline const RGBColor operator*(double f) const { return RGBColor(x * f, y * f, z * f); }
	inline const RGBColor operator/(double f) const { return RGBColor(x / f, y / f, z / f); }
	inline const RGBColor operator+(const RGBColor &v) const { return RGBColor(x + v.x, y + v.y, z + v.z); }
	inline const RGBColor operator-() const { return RGBColor(-x, -y, -z); }
	inline const RGBColor operator-(const RGBColor &v) const { return RGBColor(x - v.x, y - v.y, z - v.z); }

	inline RGBColor &operator*=(double f) { return *this = *this * f; }
	inline RGBColor &operator/=(double f) { return *this = *this / f; }
	inline RGBColor &operator+=(const RGBColor &v) { return *this = *this + v; }
	inline RGBColor &operator-=(const RGBColor &v) { return *this = *this - v; }

	inline operator double*() { return (double*)&x; }
	inline operator const double*() const { return (double*)&x; }

	inline double &operator[](int i) { return ((double*)&x)[i]; }
	inline const double operator[](int i) const { return ((double*)&x)[i]; }


	inline void cross(const RGBColor &v1, const RGBColor &v2) {
		x = v1.y * v2.z - v1.z * v2.y;
		y = v1.z * v2.x - v1.x * v2.z;
		z = v1.x * v2.y - v1.y * v2.x;
	}

	union {
		struct {
			double x, y, z;
		};
		struct {
			double r, g, b;
		};
		double v[3];
	};
};

inline RGBColor operator*(double t, const RGBColor &v) { return v * t; }
inline RGBColor operator/(double t, const RGBColor &v) { return v / t; }
