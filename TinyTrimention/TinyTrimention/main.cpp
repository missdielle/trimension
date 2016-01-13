#include <iostream>
#include "board.h"
#include "Vertex.h"
#include "Game.h"

using namespace std;



int main(){
	Game game;
	int playerCount = 0;
	char strategy = NULL;
	bool defensive = true;


	cout << "Shall we play a game?\n\n";

// commenting out until I need them

	while (playerCount != 2 && playerCount != 3 || !cin){
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

	game.playGame(playerCount, defensive);


	



	system("Pause");
	return 0;
}




