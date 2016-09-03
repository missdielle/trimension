#include <stdio.h>
#include "Vertex12D.h"
//#include "Vertex3D.h"
#include <iostream>

Vertex12D::Vertex12D() : Vertex() {}


Vertex12D::Vertex12D(int PIN, int xCoord, int yCoord,
	int degrees) : Vertex(PIN, xCoord, yCoord,
	degrees){


}

Vertex12D::~Vertex12D(){}

Vertex12D::Vertex12D(Vertex& vertex){
	
}

bool Vertex12D::isBurned(Vertex *inPlayV, Player *player){
	bool result = false;
	
	if (inPlayV->gPrev->getOccupier() != NULL
		&& inPlayV->gPrev->getOccupier() != player){
		if (inPlayV->gPrev->getOccupier()
			== inPlayV->yNext->getOccupier()
			&& inPlayV->gPrev->getOccupier()
			== inPlayV->oNext->getOccupier()){
			result = true;
		}
		if (inPlayV->gPrev->getOccupier()
			== inPlayV->yNext->getOccupier()
			&& inPlayV->gPrev->getOccupier()
			== inPlayV->bPrev->getOccupier()){
			result = true;
		}
		if (inPlayV->gPrev->getOccupier()
			== inPlayV->bPrev->getOccupier()
			&& inPlayV->gPrev->getOccupier()
			== inPlayV->pNext->getOccupier()){
			result = true;
		}
	}

	if (inPlayV->rNext->getOccupier() != NULL
		&& inPlayV->rNext->getOccupier() != player){
		if (inPlayV->rNext->getOccupier()
			== inPlayV->pNext->getOccupier()
			&& inPlayV->rNext->getOccupier()
			== inPlayV->bPrev->getOccupier()){
			result = true;
		}
		if (inPlayV->rNext->getOccupier()
			== inPlayV->pNext->getOccupier()
			&& inPlayV->rNext->getOccupier()
			== inPlayV->oPrev->getOccupier()){
			result = true;
		}
		if (inPlayV->rNext->getOccupier()
			== inPlayV->oPrev->getOccupier()
			&& inPlayV->rNext->getOccupier()
			== inPlayV->yPrev->getOccupier()){
			result = true;
		}
	}

	if (inPlayV->rPrev->getOccupier() != NULL
		&& inPlayV->rPrev->getOccupier() != player){
		if (inPlayV->rPrev->getOccupier()
			== inPlayV->pPrev->getOccupier()
			&& inPlayV->rPrev->getOccupier()
			== inPlayV->bNext->getOccupier()){
			result = true;
		}
		if (inPlayV->rPrev->getOccupier()
			== inPlayV->pPrev->getOccupier()
			&& inPlayV->rPrev->getOccupier()
			== inPlayV->oNext->getOccupier()){
			result = true;
		}
		if (inPlayV->rPrev->getOccupier()
			== inPlayV->oNext->getOccupier()
			&& inPlayV->rPrev->getOccupier()
			== inPlayV->yNext->getOccupier()){
			result = true;
		}
	}

	return result;
}

void Vertex12D::deleteBurns(Vertex *inPlayV,
	Player *player, bool defensive) {
	//make occupiers NULL
	// ++/-- pipCounts of players
	if (inPlayV->gPrev->getOccupier() == player
		&& inPlayV->oNext->getOccupier() == player){
		if (inPlayV->yNext->getOccupier() != player
			&& inPlayV->yNext->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->yNext->getOccupier());
			}
			inPlayV->yNext->setOccupier(NULL);
		}
	}

	if (inPlayV->yNext->getOccupier() == player
		&& inPlayV->rPrev->getOccupier() == player){
		if (inPlayV->oNext->getOccupier() != player
			&& inPlayV->oNext->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->oNext->getOccupier());
			}
			inPlayV->oNext->setOccupier(NULL);
		}
	}

	if (inPlayV->oNext->getOccupier() == player
		&& inPlayV->pPrev->getOccupier() == player){
		if (inPlayV->rPrev->getOccupier() != player
			&& inPlayV->rPrev->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->rPrev->getOccupier());
			}
			inPlayV->rPrev->setOccupier(NULL);
		}
	}

	if (inPlayV->rPrev->getOccupier() == player
		&& inPlayV->bNext->getOccupier() == player){
		if (inPlayV->pPrev->getOccupier() != player
			&& inPlayV->pPrev->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->pPrev->getOccupier());
			}
			inPlayV->pPrev->setOccupier(NULL);
		}
	}

	if (inPlayV->pPrev->getOccupier() == player
		&& inPlayV->gNext->getOccupier() == player){
		if (inPlayV->bNext->getOccupier() != player
			&& inPlayV->bNext->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->bNext->getOccupier());
			}
			inPlayV->bNext->setOccupier(NULL);
		}
	}

	if (inPlayV->bNext->getOccupier() == player
		&& inPlayV->yPrev->getOccupier() == player){
		if (inPlayV->gNext->getOccupier() != player
			&& inPlayV->gNext->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->gNext->getOccupier());
			}
			inPlayV->gNext->setOccupier(NULL);
		}
	}

	if (inPlayV->gNext->getOccupier() == player
		&& inPlayV->oPrev->getOccupier() == player){
		if (inPlayV->yPrev->getOccupier() != player
			&& inPlayV->yPrev->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->yPrev->getOccupier());
			}
			inPlayV->yPrev->setOccupier(NULL);
		}
	}

	if (inPlayV->yPrev->getOccupier() == player
		&& inPlayV->rNext->getOccupier() == player){
		if (inPlayV->oPrev->getOccupier() != player
			&& inPlayV->oPrev->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->oPrev->getOccupier());
			}
			inPlayV->oPrev->setOccupier(NULL);
		}
	}

	if (inPlayV->oPrev->getOccupier() == player
		&& inPlayV->pNext->getOccupier() == player){
		if (inPlayV->rNext->getOccupier() != player
			&& inPlayV->rNext->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->rNext->getOccupier());
			}
			inPlayV->rNext->setOccupier(NULL);
		}
	}

	if (inPlayV->rNext->getOccupier() == player
		&& inPlayV->bPrev->getOccupier() == player){
		if (inPlayV->pNext->getOccupier() != player
			&& inPlayV->pNext->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->pNext->getOccupier());
			}
			inPlayV->pNext->setOccupier(NULL);
		}
	}

	if (inPlayV->pNext->getOccupier() == player
		&& inPlayV->gPrev->getOccupier() == player){
		if (inPlayV->bPrev->getOccupier() != player
			&& inPlayV->bPrev->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->bPrev->getOccupier());
			}
			inPlayV->bPrev->setOccupier(NULL);
		}
	}

	if (inPlayV->bPrev->getOccupier() == player
		&& inPlayV->yNext->getOccupier() == player){
		if (inPlayV->gPrev->getOccupier() != player
			&& inPlayV->gPrev->getOccupier() != NULL){
			if (defensive == false){
				player->addPip(player);
			}
			else{
				player->removePip(inPlayV->gPrev->getOccupier());
			}
			inPlayV->gPrev->setOccupier(NULL);
		}
	}

			//check if it created any triangles
			//Vertex::findTriangles(Vertex*,Player);
			//if so, Vertex::deleteTriangles(player); 
		
}

vector<Vertex*> Vertex12D::findTriangles(Vertex*inPlayV, Player *player){
	vector<Vertex*> triV;
	if (inPlayV->gNext->gNext->getOccupier() != NULL
		&& inPlayV->gNext->gNext->getOccupier() == player) {
		if (inPlayV->gNext->gNext->getOccupier()
			== inPlayV->pPrev->pPrev->getOccupier()) {
			triV.push_back(inPlayV->gNext);
			triV.push_back(inPlayV->bNext);
			triV.push_back(inPlayV->bNext->bNext);
			triV.push_back(inPlayV->pPrev);
		}
	}
	if (inPlayV->pPrev->pPrev->getOccupier() != NULL
		&& inPlayV->pPrev->pPrev->getOccupier() == player) {
		if (inPlayV->pPrev->pPrev->getOccupier()
			== inPlayV->oNext->oNext->getOccupier()) {
			triV.push_back(inPlayV->pPrev);
			triV.push_back(inPlayV->rPrev);
			triV.push_back(inPlayV->rPrev->rPrev);
			triV.push_back(inPlayV->oNext);
		}
	}
	if (inPlayV->oNext->oNext->getOccupier() != NULL
		&& inPlayV->oNext->oNext->getOccupier() == player) {
		if (inPlayV->oNext->oNext->getOccupier()
			== inPlayV->gPrev->gPrev->getOccupier()) {
			triV.push_back(inPlayV->oNext);
			triV.push_back(inPlayV->yNext);
			triV.push_back(inPlayV->yNext->yNext);
			triV.push_back(inPlayV->gPrev);
		}
	}
	if (inPlayV->gPrev->gPrev->getOccupier() != NULL
		&& inPlayV->gPrev->gPrev->getOccupier() == player) {
		if (inPlayV->gPrev->gPrev->getOccupier()
			== inPlayV->pNext->pNext->getOccupier()) {
			triV.push_back(inPlayV->gPrev);
			triV.push_back(inPlayV->bPrev);
			triV.push_back(inPlayV->bPrev->bPrev);
			triV.push_back(inPlayV->pNext);
		}
	}
	if (inPlayV->pNext->pNext->getOccupier() != NULL
		&& inPlayV->pNext->pNext->getOccupier() == player) {
		if (inPlayV->pNext->pNext->getOccupier()
			== inPlayV->oPrev->oPrev->getOccupier()) {
			triV.push_back(inPlayV->pNext);
			triV.push_back(inPlayV->rNext);
			triV.push_back(inPlayV->rNext->rNext);
			triV.push_back(inPlayV->oPrev);
		}
	}
	if (inPlayV->oPrev->oPrev->getOccupier() != NULL
		&& inPlayV->oPrev->oPrev->getOccupier() == player) {
		if (inPlayV->oPrev->oPrev->getOccupier()
			== inPlayV->gNext->gNext->getOccupier()) {
			triV.push_back(inPlayV->oPrev);
			triV.push_back(inPlayV->yPrev);
			triV.push_back(inPlayV->yPrev->yPrev);
			triV.push_back(inPlayV->gNext);
		}
	}
	return triV;
}