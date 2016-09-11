#pragma once;
#include "Player.h"
#include "board.h"

using namespace std;

//int MAXTURNS = 20;

class Game {
//	int playerCount;
	int maxTurns;
	bool defensiveGame;

protected:
	
	//Board *topBoard;
	Board *threeBoardArray;
	Player *player1;
	Player *player2;
	Player *player3;
	Player* playerArray[3];


public:
	Game();
	~Game();
	
	Player playGame(int playerCount, bool defensive);
		//returns winner
	
	Vertex* getInput();
	bool checkIfTaken(Vertex*, Player*);
	void placePip(Vertex*, Player*, bool);
	
};