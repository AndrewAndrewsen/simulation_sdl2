#pragma once
#include <SDL.h>
#include <list>
#include <SDL_timer.h>

#include "peasant.h"
#include "resourceEntity.h"
#include "input.h"
#include "interactiveObject.h"



class core
{
public:
	core();
	~core();

	
	void loadContent();
	void update();
	void draw();

	bool isGameOver();

private:
	SDL_Window *window;
	SDL_Surface *surface; 
	SDL_Renderer *renderer;
	
	

	int screen_width = 2440;
	int screen_height = 1080;

	bool gameOver = false;

	std::list<peasant*> peasants;
	std::list<resourceEntity*> resourceEntities;

	

	
	inputHandler *input;

	SDL_Event e;
};

