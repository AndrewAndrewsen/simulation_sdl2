#include "resourceEntity.h"



resourceEntity::resourceEntity(SDL_Surface& worldScreen, SDL_Renderer& renderer, std::string sMaterial)
{
	material = sMaterial;

	rRenderer = &renderer;
	rScreen = &worldScreen;
	SDL_Surface* loadedSurface = SDL_LoadBMP("C:\\Users\\Anders\\source\\repos\\Godvgod\\Godvgod\\data\\textures\\treeFull.bmp");
	currentTexture = SDL_CreateTextureFromSurface(&renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;


	pos.x = 100;
	pos.y = 100;
	pos.h = 50;
	pos.w = 50;

	amount = 1337;

}

void resourceEntity::draw() {

	SDL_RenderCopy(rRenderer, currentTexture, NULL, &pos);
}

void resourceEntity::update() {

		
}

void resourceEntity::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;
}

resourceEntity::~resourceEntity()
{



/*	SDL_Texture* textureHight;
	SDL_Texture* textureMed;
	SDL_Texture* textureLow;

	SDL_Texture* currentTexture;*/

}
