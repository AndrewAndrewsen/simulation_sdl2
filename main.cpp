#include <iostream>
#include <SDL.h>

#include "core.h"


using namespace std;


SDL_Event e;


int lastTicks = 0;



int main(int arc, char * argv[]) {
	core core;
	core.loadContent();
	

	while (!core.isGameOver()) {
	
		if(SDL_GetTicks() > lastTicks + (1000/144)) {

			core.draw();
			core.update();

			lastTicks = SDL_GetTicks();
		}
		

	}


	return 0;
}