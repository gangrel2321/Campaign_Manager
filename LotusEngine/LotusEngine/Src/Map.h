#pragma once
#include "Game.h"

class Map 
{
public:
	Map();
	~Map();

	void LoadMap(int mapArr[20][25]);
	void DrawMap();

private:
	std::unordered_map<int, SDL_Texture*> textureMap;
	SDL_Rect src, dest;

	int map[20][25]; //tiles in map

};