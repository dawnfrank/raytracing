#pragma once

#include <Vector>

#include "Window.h"
#include "fps.h"

class Window;
class World;

class Renderer
{
public:
	Renderer();
	~Renderer();

	Window* OpenWindow(uint32_t size_x, uint32_t size_y, std::wstring name);

	bool Run();
	void Paint();

private:
	void _BeginRenderer();
	void _EndRenderer();

	HDC _hdc;
	Window *_window = nullptr;

	FPS _fps;
};