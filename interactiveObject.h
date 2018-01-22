#pragma once
#include <SDL.h>
#include <string>
#include <iostream>

class interactiveObject
{
public:
	interactiveObject();
	~interactiveObject();
	bool isClicked(SDL_Rect);

	void draw();
	virtual void update();
	virtual void selected(void);

	bool getDeleteMe();
	void kill();

	
protected:
	SDL_Texture* texture;
	SDL_Surface* rScreen;
	SDL_Renderer* rRenderer;

	bool clicked = false;

	SDL_Rect pos;

	int speed = 5;

	std::string state;
	
	bool deleteMe = false;
};

