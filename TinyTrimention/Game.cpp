#include <stdio.h>
#include <iostream>

#include "Game.h"

using namespace std;

//const int BOARDSIZE = 37;//in Board.h
//int	MAXTURNS = 20;//in main

 
Game::Game(){
	threeBoardArray = new Board[3];	//make array of 3 boards
	//topBoard = threeBoardArray[0];//make index 0 the first/top level
	//Board topBoard;
	for (int i = 0; i < 3; i++){
		playerArray[i] = NULL;
	}
}

Game::~Game(){}

Player Game::playGame(int playerCount, bool defensive){

	Player *winner = NULL;	//function returns this
	int maxTurns = 20; 

	playerArray[0] = new Player(1, defensive);//parenthesis declares PIN
	playerArray[1] = new Player(2, defensive);//constructor initializes it
	playerArray[2] = new Player(3, defensive);	//and makes pipCount=30

	/*if (defensive == true){
		for (int i = 0; i < playerCount; i++){
			playerArray[i]->setPipCount(playerArray[i], 0);
		}
	}*/

	for (int turn = 0; turn < maxTurns; turn++){	//loop thru turns
		for (int i = 0; i < playerCount; i++){		//loop thru players
			bool validPlay = false;
			cout << "Player #" << i + 1 << "\n";
			while (validPlay == false){
				Vertex *currentV = getInput();		//call getInput method
				if (currentV == NULL) {	//player passed
					winner->removePip(playerArray[i]);//using winner for access to method
					validPlay = true;
				}
				else //if (currentV != NULL) 
				{
					if (checkIfTaken(currentV, playerArray[i]) == true) {
						cout << "sorry, that spot is unavailable, "
							<< "please try again\n";
					}
					else //if (checkIfTaken(currentV, playerArray[i]) == false)
					{
						cout << "available, let's play a pip:\n";
						placePip(currentV, playerArray[i], defensive);
						validPlay = true;
					}
				}
			}
				cout << "player#1: " << playerArray[0]->getPipCount(playerArray[0]) << endl;
				cout << "player#2: " << playerArray[1]->getPipCount(playerArray[1]) << endl;
				if (playerCount == 3)
					cout << "player#3: " << playerArray[2]->getPipCount(playerArray[2]) << endl;
		}
	}

	//check pipCount or capturedCount to determine winner
	if (defensive == true) {
		if (playerCount == 2) {
			if (playerArray[0]->getPipCount(playerArray[0]) >
				playerArray[1]->getPipCount(playerArray[1])) {
				winner = playerArray[0];
				cout << "The winner is: " << winner;
			}
			else if (playerArray[0]->getPipCount(playerArray[0]) <
				playerArray[1]->getPipCount(playerArray[1])) {
				winner = playerArray[1];
				cout << "The winner is: " << winner;
			}
			else if (playerArray[0]->getPipCount(playerArray[0]) ==
				playerArray[1]->getPipCount(playerArray[1])) {
				cout << "The game is a tie.";
			}
		}
		else if (playerCount == 3) {
			if ((playerArray[0]->getPipCount(playerArray[0]) >
				playerArray[1]->getPipCount(playerArray[1]) &&
				playerArray[0]->getPipCount(playerArray[0]) >
				playerArray[2]->getPipCount(playerArray[2]))){
					winner = playerArray[0];
					cout << "The winner is: " << winner;
			}
			else if ((playerArray[1]->getPipCount(playerArray[1]) >
				playerArray[0]->getPipCount(playerArray[0]) &&
				playerArray[1]->getPipCount(playerArray[1]) >
				playerArray[2]->getPipCount(playerArray[2]))) {
				winner = playerArray[1];
				cout << "The winner is: " << winner;
			}
			else if ((playerArray[2]->getPipCount(playerArray[2]) >
				playerArray[0]->getPipCount(playerArray[0]) &&
				playerArray[2]->getPipCount(playerArray[2]) >
				playerArray[1]->getPipCount(playerArray[1]))) {
				winner = playerArray[2];
				cout << "The winner is: " << winner;
			}
			else if (playerArray[0]->getPipCount(playerArray[0]) ==
				playerArray[1]->getPipCount(playerArray[1])) {
				cout << "Player 1 and Player 2 are tied for the win.";
			}
			else if (playerArray[1]->getPipCount(playerArray[1]) ==
				playerArray[2]->getPipCount(playerArray[2])) {
				cout << "Player 2 and Player 3 are tied for the win.";
			}
			else if (playerArray[0]->getPipCount(playerArray[0]) ==
				playerArray[2]->getPipCount(playerArray[2])) {
				cout << "Player 1 and Player 3 are tied for the win.";
			}
		}
	}
	else { //defensive == false, only possible for 3 players
		if (playerArray[0]->getCapturedPipCount(playerArray[0]) >
			playerArray[1]->getCapturedPipCount(playerArray[1]) &&
			playerArray[0]->getCapturedPipCount(playerArray[0]) >
			playerArray[2]->getCapturedPipCount(playerArray[2])) {
			winner = playerArray[0];
			cout << "The winner is: " << winner;
		}
		else if (playerArray[1]->getCapturedPipCount(playerArray[1]) >
			playerArray[0]->getCapturedPipCount(playerArray[0]) &&
			playerArray[1]->getCapturedPipCount(playerArray[1]) >
			playerArray[2]->getCapturedPipCount(playerArray[2])) {
			winner = playerArray[1];
			cout << "The winner is: " << winner;
		}
		else if (playerArray[2]->getCapturedPipCount(playerArray[2]) >
			playerArray[1]->getCapturedPipCount(playerArray[1]) &&
			playerArray[2]->getCapturedPipCount(playerArray[2]) >
			playerArray[0]->getCapturedPipCount(playerArray[0])) {
			winner = playerArray[2];
			cout << "The winner is: " << winner;
		}
		else if (playerArray[0]->getCapturedPipCount(playerArray[0]) ==
			playerArray[1]->getCapturedPipCount(playerArray[1])) {
			cout << "Player 1 and Player 2 are tied for the win.";
		}
		else if (playerArray[1]->getCapturedPipCount(playerArray[1]) ==
			playerArray[2]->getCapturedPipCount(playerArray[2])) {
			cout << "Player 2 and Player 3 are tied for the win.";
		}
		else if (playerArray[0]->getCapturedPipCount(playerArray[0]) ==
			playerArray[2]->getCapturedPipCount(playerArray[2])) {
			cout << "Player 1 and Player 3 are tied for the win.";
		}
	}

	
	return *winner;
}

bool Game::checkIfTaken(Vertex*currV, Player *player){
	bool taken = false;
	if (currV->getOccupier() != NULL){
		taken = true;
		cout << "vertex is occupied\n";
	}
	else if (currV->isBurned(currV, player) == true){
		taken = true;
		cout << "vertex is burned\n";
	}
	else if (currV->isInsideTriX(currV, player) == true){
		taken = true;
		cout << "vertex is inside one or more triangles\n";
	}
	return taken;
}

Vertex* Game::getInput(){
	int input = 0;
	cout << "Which vertex would you like to place a pip on? (or enter 99 to pass) ";
	cin >> input;
	cin.clear();
	cin.ignore();

	while (!input) {
		cout << "I'm sorry, I didn't understand that.\n";
		cout << "Which vertex would you like to place a pip on? (or enter 99 to pass)";
		cin >> input;
	}
	if (input == 99) {
		return NULL;
	}
	//return threeBoardArray->getVertex(input);//uses [0] by default
	return threeBoardArray[0].getVertex(input);
}

void Game::placePip(Vertex *currV, Player *player, bool defensiveGame){
	cout << "setting occupier to current player\n";
	currV->setOccupier(player);

	//delete pips new play burns:
	currV->deleteBurns(currV, player, defensiveGame);
			
	vector<Vertex*> tmpVector;	//holds all verticies inside new triangle
	tmpVector = currV->findTriangles(currV, player);
	
	//this adds every vertex to an array
	//addTriangles also marks captured verticies as NULL
	currV->addTriangles(tmpVector, player);
	
	//iterates through all verts in triangle, runs scorePip method
	//on each verts, which scores only if not null or player
	currV->scoreTriPips(tmpVector, player, defensiveGame);
	
	return;
}

