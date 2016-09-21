#include <iostream>
#include "board.h"
#include "Vertex.h"
#include "Game.h"
#include <SDL.h>


using namespace std;
//int MAXTURNS = 20;

//some SDL globals:
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]){

	int playerCount = 0;
	char strategy = NULL;
	bool defensive = true;
	Game game;

	cout << "Shall we play a game?\n\n";

	while ((playerCount != 2 && playerCount != 3) || !cin){
		cout << "Are there 2 or 3 players?";
		cin >> playerCount;
		cin.clear();
		cin.ignore();
	}

	if (playerCount == 3) {
		//repeats question if other letters or a number is entered
		while (strategy != 'd' && strategy != 'o') {
			cout << "Do you want to play a (d)efensive or"
				<< " (o)ffensive game?";
			cin >> strategy;
			cin.clear();
			cin.ignore();

			//change these ifs to a switch to save computation speed?
			if (strategy == 'd')
				bool defensive = true;
			if (strategy == 'o') {
				bool defensive = false;
			}
		}
	}

	//SDL window (following code is from lazyfoo.net tutorial)
	SDL_Window* window = NULL;
	//surface on window
	SDL_Surface * screenSurface = NULL; 
	//initialize window inside error check
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	game.playGame(playerCount, defensive);


	system("Pause");
	return 0;
}




