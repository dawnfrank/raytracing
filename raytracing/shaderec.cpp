#include "shaderec.h"

ShaderRec::ShaderRec(World &w) :
	hit_an_object(false),
	normal(),
	hit_point(),
	color(),
	w(w)
{}

ShaderRec::ShaderRec(const ShaderRec &sr) :
	hit_an_object(sr.hit_an_object),
	normal(sr.normal),
	hit_point(sr.hit_point),
	color(sr.color),
	w(sr.w) 
{}