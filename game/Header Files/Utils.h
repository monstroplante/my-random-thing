#pragma once

#include<SDL.h>

namespace utils {
	float hireTimeInSecounds() {
		float t = SDL_GetTicks();
		t *= 0.001f;

		return t;
	}
}
