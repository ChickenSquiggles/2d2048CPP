#include "Game.hpp"
#include "Manage.h"
#include <iostream>
#include <time.h>

SDL_Texture* tb;
SDL_Texture* t2;
SDL_Texture* t4;
SDL_Texture* t8;
SDL_Texture* t16;
SDL_Texture* t32;
SDL_Texture* t64;
SDL_Texture* t128;
SDL_Texture* t256;
SDL_Texture* t512;
SDL_Texture* t1024;
SDL_Texture* t2048;
SDL_Texture* te;

SDL_Event Game::event;

// Do not mind/use the first number in the list, because it does absolutely nothing :)
int values[17] = {0,
0, 0, 0, 0, 
0, 0, 0, 0, 
0, 0, 0, 0, 
0, 0, 0, 0
};

int xpos1[17] = {0,
0, 0, 0, 0,
0, 0, 0, 0,
0, 0, 0, 0,
0, 0, 0, 0
};

int ypos1[17] = { 0,
0, 0, 0, 0,
0, 0, 0, 0,
0, 0, 0, 0,
0, 0, 0, 0
};

const char* fileblank = "Assets/BlankTile.png";
const char* file2 = "Assets/2Tile.png";
const char* file4 = "Assets/4Tile.png";
const char* file8 = "Assets/8Tile.png";
const char* file16 = "Assets/16Tile.png";
const char* file32 = "Assets/32Tile.png";
const char* file64 = "Assets/64Tile.png";
const char* file128 = "Assets/128Tile.png";
const char* file256 = "Assets/256Tile.png";
const char* file512 = "Assets/512Tile.png";
const char* file1024 = "Assets/1024Tile.png";
const char* file2048 = "Assets/2048Tile.png";
const char* fileerror = "Assets/ErrorTile.png";

SDL_Rect srcR, destR;








Game::Game()
{}

Game::~Game()
{}

void spawn()
{
	bool spawned = false;
	bool broke = false;

	while (!spawned) {
		if (values[1] != 0 && values[2] != 0 && values[3] != 0 && values[4] != 0 && values[5] != 0 && values[6] != 0 && values[7] != 0 && values[8] != 0 && values[9] != 0 && values[10] != 0 && values[11] != 0 && values[12] != 0 && values[13] != 0 && values[14] != 0 && values[15] != 0 && values[16] != 0)
		{
			broke = true;
			break;
		}
		else {
			for (int i = rand() % 15 + 1; i < 17; i++) {
				if (values[i] == 0) {
					int temprand = rand() % 4 + 1;
					if (temprand == 0 || temprand == 1 || temprand == 2 || temprand == 3)
					{
						values[i] = 2;
					}
					else
					{
						values[i] = 4;
					}
					spawned = true;
					break;
				}
			}
		}
	}
	if (!broke) {

	}
}

SDL_Renderer* pointrender = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{


	srand(time(NULL));
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL2 Initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
		{
			std::cout << "Created Window" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
			std::cout << "Created Renderer" << std::endl;
			std::cout << "Started Screen Rendering" << std::endl;
		}
		isRunning = true;
		spawn();
	}
	else
	{
		isRunning = false;
	}

	SDL_Surface* TileBlank = IMG_Load(fileblank);
	SDL_Surface* Tile2 = IMG_Load(file2);
	SDL_Surface* Tile4 = IMG_Load(file4);
	SDL_Surface* Tile8 = IMG_Load(file8);
	SDL_Surface* Tile16 = IMG_Load(file16);
	SDL_Surface* Tile32 = IMG_Load(file32);
	SDL_Surface* Tile64 = IMG_Load(file64);
	SDL_Surface* Tile128 = IMG_Load(file128);
	SDL_Surface* Tile256 = IMG_Load(file256);
	SDL_Surface* Tile512 = IMG_Load(file512);
	SDL_Surface* Tile1024 = IMG_Load(file1024);
	SDL_Surface* Tile2048 = IMG_Load(file2048);
	SDL_Surface* TileE = IMG_Load(fileerror);
	tb = SDL_CreateTextureFromSurface(renderer, TileBlank);
	t2 = SDL_CreateTextureFromSurface(renderer, Tile2);
	t4 = SDL_CreateTextureFromSurface(renderer, Tile4);
	t8 = SDL_CreateTextureFromSurface(renderer, Tile8);
	t16 = SDL_CreateTextureFromSurface(renderer, Tile16);
	t32 = SDL_CreateTextureFromSurface(renderer, Tile32);
	t64 = SDL_CreateTextureFromSurface(renderer, Tile64);
	t128 = SDL_CreateTextureFromSurface(renderer, Tile128);
	t256 = SDL_CreateTextureFromSurface(renderer, Tile256);
	t512 = SDL_CreateTextureFromSurface(renderer, Tile512);
	t1024 = SDL_CreateTextureFromSurface(renderer, Tile1024);
	t2048 = SDL_CreateTextureFromSurface(renderer, Tile2048);
	te = SDL_CreateTextureFromSurface(renderer, TileE);
	SDL_FreeSurface(TileBlank);
	SDL_FreeSurface(Tile2);
	SDL_FreeSurface(Tile4);
	SDL_FreeSurface(Tile8);
	SDL_FreeSurface(Tile16);
	SDL_FreeSurface(Tile32);
	SDL_FreeSurface(Tile64);
	SDL_FreeSurface(Tile128);
	SDL_FreeSurface(Tile256);
	SDL_FreeSurface(Tile512);
	SDL_FreeSurface(Tile1024);
	SDL_FreeSurface(Tile2048);
	SDL_FreeSurface(TileE);
	pointrender = renderer;
}


void shiftup() 
{
	int a1 = values[1], a2 = values[2], a3 = values[3], a4 = values[4], b1 = values[5], b2 = values[6], b3 = values[7], b4 = values[8], c1 = values[9], c2 = values[10], c3 = values[11], c4 = values[12], d1 = values[13], d2 = values[14], d3 = values[15], d4 = values[16];
	bool moved = false;
	int tempcounter = 0;
	int newarray[4][4] = {};
	if (true)
	{

		newarray[0][0] = a1;
		newarray[0][1] = a2;
		newarray[0][2] = a3;
		newarray[0][3] = a4;
		newarray[1][0] = b1;
		newarray[1][1] = b2;
		newarray[1][2] = b3;
		newarray[1][3] = b4;
		newarray[2][0] = c1;
		newarray[2][1] = c2;
		newarray[2][2] = c3;
		newarray[2][3] = c4;
		newarray[3][0] = d1;
		newarray[3][1] = d2;
		newarray[3][2] = d3;
		newarray[3][3] = d4;
	}
	// Code*
	int i, j, li, ri;
	for (j = 0; j < 4; j++)
	{
		li = 0, ri = j;
		for (i = 1; i < 4; i++)
		{
			a1 = values[1], a2 = values[2], a3 = values[3], a4 = values[4], b1 = values[5], b2 = values[6], b3 = values[7], b4 = values[8], c1 = values[9], c2 = values[10], c3 = values[11], c4 = values[12], d1 = values[13], d2 = values[14], d3 = values[15], d4 = values[16];
			if (true)
			{

				newarray[0][0] = a1;
				newarray[0][1] = a2;
				newarray[0][2] = a3;
				newarray[0][3] = a4;
				newarray[1][0] = b1;
				newarray[1][1] = b2;
				newarray[1][2] = b3;
				newarray[1][3] = b4;
				newarray[2][0] = c1;
				newarray[2][1] = c2;
				newarray[2][2] = c3;
				newarray[2][3] = c4;
				newarray[3][0] = d1;
				newarray[3][1] = d2;
				newarray[3][2] = d3;
				newarray[3][3] = d4;
			}
			if (newarray[i][j] != 0)
			{
				if (newarray[i - 1][j] == 0 || newarray[i - 1][j] == newarray[i][j])
				{
					if (newarray[li][ri] == newarray[i][j])
					{
						newarray[li][ri] *= 2;
						newarray[i][j] = 0;
						moved = true;
					}
					else
					{
						if (newarray[li][ri] == 0)
						{
							newarray[li][ri] = newarray[i][j];
							newarray[i][j] = 0;
							moved = true;
						}
						else
						{
							newarray[++li][ri] = newarray[i][j];
							newarray[i][j] = 0;
							moved = true;
						}
					}
				}
				else li++;
			}
			values[1] = newarray[0][0];
			values[2] = newarray[0][1];
			values[3] = newarray[0][2];
			values[4] = newarray[0][3];
			values[5] = newarray[1][0];
			values[6] = newarray[1][1];
			values[7] = newarray[1][2];
			values[8] = newarray[1][3];
			values[9] = newarray[2][0];
			values[10] = newarray[2][1];
			values[11] = newarray[2][2];
			values[12] = newarray[2][3];
			values[13] = newarray[3][0];
			values[14] = newarray[3][1];
			values[15] = newarray[3][2];
			values[16] = newarray[3][3];
		}
	}
	// *Code
	if (moved)
	{
		spawn();
	}
}

void shiftdown()
{
	int a1 = values[1], a2 = values[2], a3 = values[3], a4 = values[4], b1 = values[5], b2 = values[6], b3 = values[7], b4 = values[8], c1 = values[9], c2 = values[10], c3 = values[11], c4 = values[12], d1 = values[13], d2 = values[14], d3 = values[15], d4 = values[16];
	bool moved = false;
	int tempcounter = 0;
	int newarray[4][4] = {};
	if (true)
	{

		newarray[0][0] = a1;
		newarray[0][1] = a2;
		newarray[0][2] = a3;
		newarray[0][3] = a4;
		newarray[1][0] = b1;
		newarray[1][1] = b2;
		newarray[1][2] = b3;
		newarray[1][3] = b4;
		newarray[2][0] = c1;
		newarray[2][1] = c2;
		newarray[2][2] = c3;
		newarray[2][3] = c4;
		newarray[3][0] = d1;
		newarray[3][1] = d2;
		newarray[3][2] = d3;
		newarray[3][3] = d4;
	}


	int i, j, li, ri;
	for (j = 0; j < 4; j++)
	{
		li = 3, ri = j;
		for (i = 2; i >= 0; i--)
		{
			a1 = values[1], a2 = values[2], a3 = values[3], a4 = values[4], b1 = values[5], b2 = values[6], b3 = values[7], b4 = values[8], c1 = values[9], c2 = values[10], c3 = values[11], c4 = values[12], d1 = values[13], d2 = values[14], d3 = values[15], d4 = values[16];
			if (true)
			{

				newarray[0][0] = a1;
				newarray[0][1] = a2;
				newarray[0][2] = a3;
				newarray[0][3] = a4;
				newarray[1][0] = b1;
				newarray[1][1] = b2;
				newarray[1][2] = b3;
				newarray[1][3] = b4;
				newarray[2][0] = c1;
				newarray[2][1] = c2;
				newarray[2][2] = c3;
				newarray[2][3] = c4;
				newarray[3][0] = d1;
				newarray[3][1] = d2;
				newarray[3][2] = d3;
				newarray[3][3] = d4;
			}
			if (newarray[i][j] != 0)
			{
				if (newarray[i + 1][j] == 0 || newarray[i + 1][j] == newarray[i][j])
				{
					if (newarray[li][ri] == newarray[i][j])
					{
						newarray[li][ri] *= 2;
						newarray[i][j] = 0;
						moved = true;
					}
					else
					{
						if (newarray[li][ri] == 0)
						{
							newarray[li][ri] = newarray[i][j];
							newarray[i][j] = 0;
							moved = true;
						}
						else
						{
							newarray[--li][ri] = newarray[i][j];
							newarray[i][j] = 0;
							moved = true;
						}
					}
				}
				else li--;
			}
			values[1] = newarray[0][0];
			values[2] = newarray[0][1];
			values[3] = newarray[0][2];
			values[4] = newarray[0][3];
			values[5] = newarray[1][0];
			values[6] = newarray[1][1];
			values[7] = newarray[1][2];
			values[8] = newarray[1][3];
			values[9] = newarray[2][0];
			values[10] = newarray[2][1];
			values[11] = newarray[2][2];
			values[12] = newarray[2][3];
			values[13] = newarray[3][0];
			values[14] = newarray[3][1];
			values[15] = newarray[3][2];
			values[16] = newarray[3][3];
		}
	}

	if (moved)
	{
		spawn();
	}
}

void shiftright()
{
	int a1 = values[1], a2 = values[2], a3 = values[3], a4 = values[4], b1 = values[5], b2 = values[6], b3 = values[7], b4 = values[8], c1 = values[9], c2 = values[10], c3 = values[11], c4 = values[12], d1 = values[13], d2 = values[14], d3 = values[15], d4 = values[16];
	bool moved = false;
	int tempcounter = 0;
	int newarray[4][4] = {};
	if (true)
	{

		newarray[0][0] = a1;
		newarray[0][1] = a2;
		newarray[0][2] = a3;
		newarray[0][3] = a4;
		newarray[1][0] = b1;
		newarray[1][1] = b2;
		newarray[1][2] = b3;
		newarray[1][3] = b4;
		newarray[2][0] = c1;
		newarray[2][1] = c2;
		newarray[2][2] = c3;
		newarray[2][3] = c4;
		newarray[3][0] = d1;
		newarray[3][1] = d2;
		newarray[3][2] = d3;
		newarray[3][3] = d4;
	}
	// Code*
	int i, j, li, ri;
	for (i = 0; i < 4; i++)
	{
		li = i, ri = 3;
		for (j = 2; j >= 0; j--)
		{
			a1 = values[1], a2 = values[2], a3 = values[3], a4 = values[4], b1 = values[5], b2 = values[6], b3 = values[7], b4 = values[8], c1 = values[9], c2 = values[10], c3 = values[11], c4 = values[12], d1 = values[13], d2 = values[14], d3 = values[15], d4 = values[16];
			if (true)
			{

				newarray[0][0] = a1;
				newarray[0][1] = a2;
				newarray[0][2] = a3;
				newarray[0][3] = a4;
				newarray[1][0] = b1;
				newarray[1][1] = b2;
				newarray[1][2] = b3;
				newarray[1][3] = b4;
				newarray[2][0] = c1;
				newarray[2][1] = c2;
				newarray[2][2] = c3;
				newarray[2][3] = c4;
				newarray[3][0] = d1;
				newarray[3][1] = d2;
				newarray[3][2] = d3;
				newarray[3][3] = d4;
			}
			if (newarray[i][j] != 0)
			{
				if (newarray[i][j + 1] == 0 || newarray[i][j + 1] == newarray[i][j])
				{
					if (newarray[li][ri] == newarray[i][j])
					{
						newarray[li][ri] *= 2;
						newarray[i][j] = 0;
						moved = true;
					}
					else
					{
						if (newarray[li][ri] == 0)
						{
							newarray[li][ri] = newarray[i][j];
							newarray[i][j] = 0;
							moved = true;
						}
						else
						{
							newarray[li][--ri] = newarray[i][j];
							newarray[i][j] = 0;
							moved = true;
						}
					}
				}
				else ri--;
				values[1] = newarray[0][0];
				values[2] = newarray[0][1];
				values[3] = newarray[0][2];
				values[4] = newarray[0][3];
				values[5] = newarray[1][0];
				values[6] = newarray[1][1];
				values[7] = newarray[1][2];
				values[8] = newarray[1][3];
				values[9] = newarray[2][0];
				values[10] = newarray[2][1];
				values[11] = newarray[2][2];
				values[12] = newarray[2][3];
				values[13] = newarray[3][0];
				values[14] = newarray[3][1];
				values[15] = newarray[3][2];
				values[16] = newarray[3][3];
			}
		}
	}
	// *Code
	if (moved)
	{
		spawn();
	}
}

void shiftleft()
{
	int a1 = values[1], a2 = values[2], a3 = values[3], a4 = values[4], b1 = values[5], b2 = values[6], b3 = values[7], b4 = values[8], c1 = values[9], c2 = values[10], c3 = values[11], c4 = values[12], d1 = values[13], d2 = values[14], d3 = values[15], d4 = values[16];
	bool moved = false;
	int tempcounter = 0;
	int newarray[4][4] = {};
	if (true)
	{

		newarray[0][0] = a1;
		newarray[0][1] = a2;
		newarray[0][2] = a3;
		newarray[0][3] = a4;
		newarray[1][0] = b1;
		newarray[1][1] = b2;
		newarray[1][2] = b3;
		newarray[1][3] = b4;
		newarray[2][0] = c1;
		newarray[2][1] = c2;
		newarray[2][2] = c3;
		newarray[2][3] = c4;
		newarray[3][0] = d1;
		newarray[3][1] = d2;
		newarray[3][2] = d3;
		newarray[3][3] = d4;
	}
	// Code*
	int i, j, li, ri;
	for (i = 0; i < 4; i++)
	{
		li = i, ri = 0;
		for (j = 1; j < 4; j++)
		{
			a1 = values[1], a2 = values[2], a3 = values[3], a4 = values[4], b1 = values[5], b2 = values[6], b3 = values[7], b4 = values[8], c1 = values[9], c2 = values[10], c3 = values[11], c4 = values[12], d1 = values[13], d2 = values[14], d3 = values[15], d4 = values[16];
			if (true)
			{

				newarray[0][0] = a1;
				newarray[0][1] = a2;
				newarray[0][2] = a3;
				newarray[0][3] = a4;
				newarray[1][0] = b1;
				newarray[1][1] = b2;
				newarray[1][2] = b3;
				newarray[1][3] = b4;
				newarray[2][0] = c1;
				newarray[2][1] = c2;
				newarray[2][2] = c3;
				newarray[2][3] = c4;
				newarray[3][0] = d1;
				newarray[3][1] = d2;
				newarray[3][2] = d3;
				newarray[3][3] = d4;
			}
			if (newarray[i][j] != 0)
			{
				if (newarray[i][j - 1] == 0 || newarray[i][j - 1] == newarray[i][j])
				{
					if (newarray[li][ri] == newarray[i][j])
					{
						newarray[li][ri] *= 2;
						newarray[i][j] = 0;
						moved = true;
					}
					else
					{
						if (newarray[li][ri] == 0)
						{
							newarray[li][ri] = newarray[i][j];
							newarray[i][j] = 0;
							moved = true;
						}
						else
						{
							newarray[li][++ri] = newarray[i][j];
							newarray[i][j] = 0;
							moved = true;
						}
					}
				}
				else ri++;
			}
			values[1] = newarray[0][0];
			values[2] = newarray[0][1];
			values[3] = newarray[0][2];
			values[4] = newarray[0][3];
			values[5] = newarray[1][0];
			values[6] = newarray[1][1];
			values[7] = newarray[1][2];
			values[8] = newarray[1][3];
			values[9] = newarray[2][0];
			values[10] = newarray[2][1];
			values[11] = newarray[2][2];
			values[12] = newarray[2][3];
			values[13] = newarray[3][0];
			values[14] = newarray[3][1];
			values[15] = newarray[3][2];
			values[16] = newarray[3][3];
		}
	}
	// *Code
	if (moved)
	{
		spawn();
	}
}




void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (Game::event.key.keysym.sym) 
		{
		case SDLK_UP:
			shiftup();
			break;
		case SDLK_w:
			shiftup();
			break;
		case SDLK_DOWN:
			shiftdown();
			break;
		case SDLK_s:
			shiftdown();
			break;
		case SDLK_LEFT:
			shiftleft();
			break;
		case SDLK_a:
			shiftleft();
			break;
		case SDLK_RIGHT:
			shiftright();
			break;
		case SDLK_d:
			shiftright();
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:

		break;

	default:
		break;
	}
}





void Game::update()
{
	destR.h = 120;
	destR.w = 120;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
	for (int i = 1; i < 17; i++)
	{
		bool didsomething = false;

		int temp = values[i];
		switch (temp)
		{
		case 0:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, tb, NULL, &destR);
			break;
		case 2:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t2, NULL, &destR);
			break;
		case 4:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t4, NULL, &destR);
			break;
		case 8:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t8, NULL, &destR);
			break;
		case 16:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t16, NULL, &destR);
			break;
		case 32:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t32, NULL, &destR);
			break;
		case 64:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}			
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t64, NULL, &destR);
			break;
		case 128:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t128, NULL, &destR);
			break;
		case 256:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t256, NULL, &destR);
			break;
		case 512:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t512, NULL, &destR);
			break;
		case 1024:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t512, NULL, &destR);
			break;
		case 2048:
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			xpos1[i] = destR.x;
			ypos1[i] = destR.y;
			didsomething = true;
			SDL_RenderCopy(renderer, t2048, NULL, &destR);
			break;
		default:
			break;
		}
		if (!didsomething)
		{
			if (i == 1 || i == 2 || i == 3 || i == 4) {
				destR.y = 8;
			}
			if (i == 5 || i == 6 || i == 7 || i == 8) {
				destR.y = 136;
			}
			if (i == 9 | i == 10 | i == 11 || i == 12) {
				destR.y = 264;
			}
			if (i == 13 || i == 14 | i == 15 || i == 16) {
				destR.y = 392;
			}
			if (i == 4 || i == 8 || i == 12 || i == 16) {
				destR.x = 392;
			}
			else if (i == 3 || i == 7 || i == 11 || i == 15) {
				destR.x = 264;
			}
			else if (i == 2 || i == 6 || i == 10 || i == 14) {
				destR.x = 136;
			}
			else if (i == 1 || i == 5 || i == 9 || i == 13) {
				destR.x = 8;
			}
			SDL_RenderCopy(renderer, te, NULL, &destR);
		}
	}

	

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
