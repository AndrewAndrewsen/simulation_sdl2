#pragma once
#include <SDL.h>
#include <iostream>
#include <list>

#include "interactiveObject.h"


class inputHandler
{
public:
	inputHandler(SDL_Surface&, SDL_Renderer&);
	~inputHandler();

	void update();
	void draw();


	void interactiveObjects_push(interactiveObject*);
private:
	SDL_Texture* textureCursor;
	SDL_Surface* rScreen;
	SDL_Renderer* rRenderer;

	SDL_Rect mousePos;

	bool clicked = false;

	SDL_Event e;
	std::list<interactiveObject*> interactiveObjects;

};

