#include "interactiveObject.h"



interactiveObject::interactiveObject()
{
}


interactiveObject::~interactiveObject()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}


bool interactiveObject::isClicked(SDL_Rect mPos) {
	//std::cout << " X: " << mPos.x << "  Y: " << mPos.y << std::endl;
	//std::cout << "pX: " << pos.x << " pY: " << pos.y  << " pX+w: " << pos.x+pos.w << " pX+h: " << pos.y+pos.h << std::endl;

	if (pos.x < mPos.x && 
	   (pos.x + pos.w) > mPos.x && 
		pos.y < mPos.y && 
	   (pos.h + pos.y) > mPos.y) {
		
		return true;
	}
	else { 
		return clicked;
	}

}

void interactiveObject::draw() {

	SDL_RenderCopy(rRenderer, texture, NULL, &pos);
}

void interactiveObject::update() {


}
 

void interactiveObject::selected(void) {
	
}

bool interactiveObject::getDeleteMe() {

	return deleteMe;
}

void interactiveObject::kill() {
	std::cout << "Kill() called" << std::endl;
	deleteMe = true;
}