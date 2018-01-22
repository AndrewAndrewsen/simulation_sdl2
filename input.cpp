#include "input.h"




inputHandler::inputHandler(SDL_Surface& worldScreen, SDL_Renderer& renderer)
{
	rScreen = &worldScreen;
	rRenderer = &renderer;

	SDL_Surface* loadedSurface = SDL_LoadBMP("C:\\Users\\Anders\\source\\repos\\Godvgod\\Godvgod\\data\\textures\\cursor.bmp");
	
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));

	textureCursor = SDL_CreateTextureFromSurface(&renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;

	mousePos.x, mousePos.y = -1337;
	mousePos.w = 50;
	mousePos.h = 50;

	
	
}


void inputHandler::update() {

	SDL_GetMouseState(&mousePos.x, &mousePos.y);

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (e.button.button == SDL_BUTTON_LEFT) {

				for (std::list<interactiveObject*>::iterator ioI = interactiveObjects.begin(); ioI != interactiveObjects.end();) {

					if ((*ioI)->isClicked(mousePos)) {
						(*ioI)->selected();

					
					}

					++ioI;
				}

			}

		
		}




	}
}

void inputHandler::interactiveObjects_push(interactiveObject* object) {

	interactiveObjects.push_back(object);

}

void inputHandler::draw() {

	SDL_RenderCopy(rRenderer, textureCursor, NULL, &mousePos);
	//std::cout << "X: " << mousePos.x << " Y: " << mousePos.y << "W: " << mousePos.w << " H: " << mousePos.h << std::endl;

}



inputHandler::~inputHandler()
{
}
