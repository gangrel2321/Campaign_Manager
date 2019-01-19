#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	
	const int FPS = 60; 
	//max time between frames
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart; 
	int frameTime; 
	
	game = new Game();
	game->init("GameWindow", 800, 640, false);

	while (game->running())
	{

		frameStart = SDL_GetTicks(); //ms since SDL intialized


		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}

	game->clean();
	return 0;
}