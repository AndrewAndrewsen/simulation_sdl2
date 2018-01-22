#include "core.h"



core::core()
{
	SDL_Init(SDL_INIT_VIDEO);
	

	window = SDL_CreateWindow("God v. god!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

	
	//interactiveObjects = new std::list<class T*>();

	input = new inputHandler(*surface, *renderer);
}


void core::loadContent() {
	peasant* pes = new peasant(*surface, *renderer);
	peasants.push_back(pes);

	resourceEntity* tree = new resourceEntity(*surface, *renderer, "tree");
	resourceEntities.push_back(tree);

	resourceEntity* tree2 = new resourceEntity(*surface, *renderer, "tree");
	tree2->setPosition(150, 150);
	resourceEntities.push_back(tree2);
	
	input->interactiveObjects_push(pes);
	input->interactiveObjects_push(tree);
	input->interactiveObjects_push(tree2);



}

void core::update() {




	std::list<peasant*>::iterator pI;
	for (pI = peasants.begin(); pI != peasants.end();)
	{
		(*pI)->update();

		if ((*pI)->getDeleteMe()) {
			(pI) = peasants.erase(pI);// peasants.erase(pI);
		
		}
		else {
			++pI;
		}
	}


	
	if (!resourceEntities.empty()) {
		 
		for (std::list<resourceEntity*>::iterator rI = resourceEntities.begin(); rI != resourceEntities.end();)
		{
			(*rI)->update();

			if ((*rI)->getDeleteMe())
				rI = resourceEntities.erase(rI);
			else
				++rI;

				
		

		}
	}


	




	input->update();
}

void core::draw() {

	SDL_RenderClear(renderer);
	
	std::list<peasant*>::iterator pI;
	for (pI = peasants.begin(); pI != peasants.end(); ++pI)
	{
		(*pI)->draw();
	}

	std::list<resourceEntity*>::iterator rI;
	for (rI = resourceEntities.begin(); rI != resourceEntities.end(); ++rI)
	{
		(*rI)->draw();

	}


	input->draw();

	SDL_RenderPresent(renderer);
	//SDL_UpdateWindowSurface(window);
}

bool core::isGameOver() {
	return gameOver;
}


core::~core()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}
