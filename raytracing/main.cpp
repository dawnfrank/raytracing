#include <iostream>

#include "renderer.h"

int main() {
	Renderer r;
	auto w = r.OpenWindow(800, 600, TEXT("test"));
	while (r.Run()) {
		r.Paint();
	}
	return 0;
}