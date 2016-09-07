#include <iostream>
#include <stdio.h>
#include "Vertex.h"
#include "Game.h"
using namespace std;

Vertex::Vertex(){
	PIN = 0;
	setOccupier(NULL);
	for (int i = 0; i < 4; i++){
		triX[i] = NULL;
	}
}

Vertex::Vertex(int PIN, int xCoord, int yCoord,
	int degrees){
	this->PIN = PIN;
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->degrees = degrees;
	Player *occupier = NULL;
	for (int i = 0; i < 3; i++){
		triX[i] = 0;
	}
}

//Vertex * Vertex::getV(){		//not using this, but it's here if I need it
//	return this;
//}

Vertex::~Vertex(){
	delete rNext;
	rNext = NULL;
	delete rPrev;
	rPrev = NULL;
	delete yNext;
	yNext = NULL;
	delete yPrev;
	yPrev = NULL;
	delete bNext;
	bNext = NULL;
	delete bPrev;
	bPrev = NULL;
	delete kNext;
	kNext = NULL;
	delete kPrev;
	kPrev = NULL;
	delete gNext;
	gNext = NULL;
	delete gPrev;
	gPrev = NULL;
	delete oNext;
	oNext = NULL;
	delete oPrev;
	oPrev = NULL;
	delete pNext;
	pNext = NULL;
	delete pPrev;
	pPrev = NULL;

	//vertex's are made and deleted in board.cpp
}

int Vertex::getPIN(){
	return PIN;
}

Player* Vertex::getOccupier(){
//	return this->occupier;
	return occupier;
}

int Vertex::getDegrees(){
	return degrees;
}

void Vertex::setOccupier(Player* player){
	occupier = player;
	//this->occupier = player;
}

//overriding in subclasses:
bool Vertex::isBurned(Vertex *playV, Player *curr){
	return false;
}

//overriding in subclasses:
void Vertex::deleteBurns(Vertex *playV, Player *curr, bool defensive){
	return;
}

//overriding in subclasses:
vector<Vertex*> Vertex::findTriangles(Vertex*inPlayV, Player *player){
	vector<Vertex*> triV;
	return triV;
}

//triX is an int array inside each vert that increments at player's index
//triX is not dependant on degree, so put it here
bool Vertex::isInsideTriX(Vertex*inPlayV, Player *player){
	bool inside = false;
	for (int i = 1; i < 4; i++){	//loop through players
		if (player->number != i && inPlayV->triX[i-1] > 0){	
			//eliminate cur player's triangles && check array counts	
				inside = true;		
		}
	}
	return inside;
}
//folowing three methods are NOT overridden:

//adds 1 to each vert's triX at player #'s index
void Vertex::addTriangles(vector<Vertex*> myVector, Player*player){
	for (vector<Vertex*>::iterator it = myVector.begin(); it != myVector.end(); it++) {
		Vertex* tmp = *it;
		tmp->triX[(player->number) - 1]++;	//increments the vertex's vector at player's index
			cout << "triX array of vertex " << tmp->PIN 
				<< " incremented at index of player# " << player->number << endl;
	}
	return;
}

//delete 1 from ea Vert's triX at player #'s index
void Vertex::deleteTriangles(vector<Vertex*> myVector, Player*player){

	for (vector<Vertex*>::iterator it = myVector.begin(); it != myVector.end(); it++) {
		Vertex* tmp = *it;
		tmp->triX[(player->number) - 1]--;
		cout << "triX array of vertex " << tmp->PIN 
			<< " deccremented at index of player# " << player->number << endl;
	}
	return;
}

//scoreTriPips scores all the pips and changes their occupiers to NULL
void Vertex::scoreTriPips(vector<Vertex*> myVector, Player*player, bool defensive) {
	//scorePip method checks validity/adjusts scores/removes pip
	for (vector<Vertex*>::iterator it = myVector.begin(); it != myVector.end(); it++) {
		scorePip(player, *it, defensive);
	}
	return;
}

//this one is called inside subclasses & other functions
//no action if vertex is null or same as player
//adds or delete's count from score
//marks vertex occupier as null
void Vertex::scorePip(Player*player, Vertex *ptr, bool defensive) {
	if (ptr->getOccupier() != NULL && ptr->getOccupier() != player) {
		cout << "deleting vertex: " << ptr->getPIN() << endl;
			if (defensive == true) {
				player->removePip(ptr->getOccupier());
			}
			else
				player->addPip(player);
			
			Player*tmpP = ptr->getOccupier();//holds occupier to delete any triangles
			ptr->setOccupier(NULL);//here to prevent double scoring of burns and tri's

		//if deleted pip had triangles, we need to find and delete them
			vector<Vertex*> tmpVector;	//holds all verticies found inside new triangle
			tmpVector = ptr->findTriangles(ptr, tmpP);
			ptr->deleteTriangles(tmpVector, tmpP);

 

		return;
	}
}