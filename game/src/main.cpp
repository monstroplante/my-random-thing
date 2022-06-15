#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>
#include <Windows.h>

#include"RenderWindow.h"
#include"Entity.h"
#include"Utils.h"


int main(int argc, char* args[]) {
	ShowWindow(::GetConsoleWindow(), SW_HIDE);
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "SDL_INIT HAS FAITL. Error : " << SDL_GetError() << std::endl;
	}

	if (!(IMG_Init(0x00000002))) {
		std::cout << "IMG_INIT HAS FAITL. Error : " << SDL_GetError() << std::endl;
	}

	RenderWindow window("GAME", 1000, 1000);


	std::cout << window.getRefreshRate() << std::endl;

	SDL_Texture* planet = window.loadTexture("./planet.png");


	int x_w = 500 - 64;
	int y_w = 500 - 64;
	std::vector<Entity> entities = {
		Entity(Vector2f(250 - 64 ,250 - 64),planet),

	};

	Entity entity = Entity(Vector2f(x_w, y_w), planet);



	bool gameRunning = true;

	SDL_Event event;

	const float timeStep = 0.006f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSecounds();

	float r = 0;

	float multiplierx;
	float multipliery;

	while (gameRunning) {

		int startTicks = SDL_GetTicks();

		float newTime = utils::hireTimeInSecounds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					gameRunning = false;
				}

			}
			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep;

		window.clear();


		window.render(entity, r);

		if (GetKeyState('R') & 0x8000 || x_w < 0 || y_w < 0 || x_w >1000 - 128 || y_w > 1000 - 128) {
			x_w = 500 - 64;
			y_w = 500 - 64;
			r = 0;
			entity = Entity(Vector2f(500 - 64, 500 - 64), planet);
		}

		if (GetKeyState('W') & 0x8000)
		{
			multiplierx = 0;
			multipliery = 0;


			if (r >= 0 && r <= 90) {

				multiplierx = r / 90;
				multipliery = 1 - multiplierx;
				x_w = x_w + multiplierx * 6;
				y_w = y_w - multipliery * 6;


			}
			if (r < 0 && r >= -90)
			{
				multiplierx = r / -90;
				multipliery = 1 - multiplierx;
				x_w = x_w - multiplierx * 6;
				y_w = y_w - multipliery * 6;
			}


			if (r > 90) {

				multiplierx = (r - 90) / 90;
				multipliery = 1 - multiplierx;
				x_w = x_w + multipliery * 6;
				y_w = y_w + multiplierx * 6;


			}

			if (r < -90) {
				multiplierx = (r + 90) / -90;
				multipliery = 1 - multiplierx;
				x_w = x_w - multipliery * 6;
				y_w = y_w + multiplierx * 6;
			}

			int x_wr = (int)x_w;
			int y_wr = (int)y_w;

			std::cout << "x : " << x_wr << std::endl;
			std::cout << "y : " << y_wr << std::endl;


			std::cout << "rotation : " << r << std::endl;
			std::cout << "multiplierx : " << multiplierx * 6 << std::endl;
			std::cout << "multipiery : " << multipliery * 5 << std::endl;
			std::cout << "multipiery +y : " << multipliery * 5 + multiplierx * 5 << std::endl;
			std::cout << "----------------\n" << std::endl;





			entity = Entity(Vector2f(x_wr, y_wr), planet);

		};
		if (GetKeyState('S') & 0x8000)
		{
			multiplierx = 0;
			multipliery = 0;


			if (r >= 0 && r <= 90) {

				multiplierx = r / 90;
				multipliery = 1 - multiplierx;
				x_w = x_w - multiplierx * 6;
				y_w = y_w + multipliery * 6;


			}
			if (r < 0 && r >= -90)
			{
				multiplierx = r / -90;
				multipliery = 1 - multiplierx;
				x_w = x_w + multiplierx * 6;
				y_w = y_w + multipliery * 6;
			}


			if (r > 90) {

				multiplierx = (r - 90) / 90;
				multipliery = 1 - multiplierx;
				x_w = x_w - multipliery * 6;
				y_w = y_w - multiplierx * 6;


			}

			if (r < -90) {
				multiplierx = (r + 90) / -90;
				multipliery = 1 - multiplierx;
				x_w = x_w + multipliery * 6;
				y_w = y_w - multiplierx * 6;
			}

			int x_wr = (int)x_w;
			int y_wr = (int)y_w;

			std::cout << "x : " << x_wr << std::endl;
			std::cout << "y : " << y_wr << std::endl;


			std::cout << "rotation : " << r << std::endl;
			std::cout << "multiplierx : " << multiplierx * 6 << std::endl;
			std::cout << "multipiery : " << multipliery * 5 << std::endl;
			std::cout << "multipiery +y : " << multipliery * 5 + multiplierx * 5 << std::endl;
			std::cout << "----------------\n" << std::endl;





			entity = Entity(Vector2f(x_wr, y_wr), planet);

		};

		if (GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
		{



			entity = Entity(Vector2f(x_w, y_w), planet);
		};

		// std::cout << r << std::endl;

		if (GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
		{
			r = r - 2;
		};

		if (GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/) {
			r = r + 2;
		}

		if (r < -180) {
			r = 180;
		}
		if (r > 180) {
			r = -180;
		}






		int frameTicks = SDL_GetTicks() - startTicks;

		window.display();

		if (frameTicks < 1000 / window.getRefreshRate()) {
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);

		}

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
