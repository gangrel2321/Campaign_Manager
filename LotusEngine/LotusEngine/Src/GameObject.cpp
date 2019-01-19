#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);
	xPos = x;
	yPos = y;
}

void GameObject::Update()
{
	xPos++;
	yPos++;

	srcRect.w = 32;
	srcRect.h = 32;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.x = xPos;
	destRect.y = yPos; 
	destRect.w = srcRect.w * 2; //scale by 2
	destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}