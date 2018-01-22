#pragma once
#include <SDL.h>
#include <string>
#include "input.h"
#include "interactiveObject.h"



class peasant : public interactiveObject
{
public:
	peasant(SDL_Surface&, SDL_Renderer&);
	~peasant();

	//void draw();
	void update();
//	selected;
	virtual void selected(void);

	void state_idle();
	

private:
/*	SDL_Texture* texture;
	SDL_Surface* rScreen;
	SDL_Renderer* rRenderer;

	inputHandler* input;

	SDL_Rect pos;
	
	int speed = 5;

	std::string state; */
		

};

