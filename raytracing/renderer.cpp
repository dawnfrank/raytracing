#include <iostream>

#include "Renderer.h"
#include "Window.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	delete _window;
}

Window * Renderer::OpenWindow(uint32_t size_x, uint32_t size_y, std::wstring name)
{
	_window = new Window(this, size_x, size_y, name);

	//	_BeginRenderer();
	return _window;
}

void Renderer::_BeginRenderer() {
	_hdc = BeginPaint(_window->GetHandler(), &_window->GetPainter());
}

void Renderer::_EndRenderer() {
	EndPaint(_window->GetHandler(), &_window->GetPainter());
}

void Renderer::Paint() {
	_BeginRenderer();
	HPEN hpen; // ����
	hpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	// DC ѡ�񻭱�
	SelectObject(_hdc, hpen);
	// (����)�ӳ�ʼ���ƶ��� 50,50
	MoveToEx(_hdc, 50, 50, NULL);
	// (����)�ӳ�ʼ�㻭�ߵ� 100,100
	LineTo(_hdc, 150, 100);
	_EndRenderer();
}

bool Renderer::Run()
{
	if (nullptr != _window) {
		_fps.Update();
		return _window->Update();
	}
	return true;
}
