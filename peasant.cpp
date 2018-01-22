#include "peasant.h"



peasant::peasant(SDL_Surface& worldScreen, SDL_Renderer& renderer)
{
	rRenderer = &renderer;
	rScreen = &worldScreen;
	SDL_Surface* loadedSurface = SDL_LoadBMP("C:\\Users\\Anders\\source\\repos\\Godvgod\\Godvgod\\data\\textures\\peasant.bmp");
	texture = SDL_CreateTextureFromSurface(&renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;

	state = "idle";
	
	pos.x = 0;
	pos.y = 0;
	pos.h = 10;
	pos.w = 10;
}


void peasant::selected(void) {
	pos.h = 100;
	pos.w = 100;
	
}

void peasant::update() {

	if (state == "idle") {
		peasant::state_idle();
	}

	
	
}


peasant::~peasant()
{
	/*SDL_DestroyTexture(texture);
	texture = NULL;*/
}


void peasant::state_idle() {
	


}