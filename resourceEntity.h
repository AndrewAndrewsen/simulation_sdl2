#pragma once
#include <SDL.h>
#include <string>

#include "interactiveObject.h"

class resourceEntity : public interactiveObject
{
public:
	resourceEntity(SDL_Surface& , SDL_Renderer&, std::string );
	~resourceEntity();

	void draw();
	void update();

	void setPosition(int, int);

private:
	int amount;
	std::string material;

	//SDL_Rect pos;

	SDL_Texture* textureHight;
	SDL_Texture* textureMed;
	SDL_Texture* textureLow;

	SDL_Texture* currentTexture;

	SDL_Surface* rScreen;
	SDL_Renderer* rRenderer;



};

