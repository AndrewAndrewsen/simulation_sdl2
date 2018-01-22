#include "ui.h"



ui::ui()
{
	SDL_Surface* tempSurface;

	tempSurface = SDL_LoadBMP("C:\\Users\\Anders\\source\\repos\\Godvgod\\Godvgod\\data\\textures\\uibg.bmp");

	tempSurface = NULL;
	SDL_FreeSurface(tempSurface);
}


ui::~ui()
{
}
