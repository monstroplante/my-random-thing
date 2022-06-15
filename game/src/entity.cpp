#include<SDL.h>
#include<SDL_image.h>
#include"Entity.h"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
	:pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 128;
	currentFrame.h = 128;

}



SDL_Texture* Entity::getTex() {
	return tex;
}

SDL_Rect Entity::getCurrentFrame() {
	return currentFrame;
}
