#include <stdio.h>
#include "Vertex4D.h"
#include <iostream>

Vertex4D::Vertex4D() : Vertex() {}

Vertex4D::Vertex4D(int PIN, int xCoord, int yCoord,
	int degrees, char color) : Vertex(PIN, xCoord, yCoord,
	degrees){
	this->color = color;

}

Vertex4D::~Vertex4D(){}

Vertex4D::Vertex4D(Vertex& vertex){

}

bool Vertex4D::isBurned(Vertex *inPlayV, Player *player){
	bool result = false;
	switch (dynamic_cast<Vertex4D*>(inPlayV)->color){
	case 'p':
		if (inPlayV->yNext->getOccupier() != player
			&& inPlayV->yNext->getOccupier() != NULL){
			if (inPlayV->yNext->getOccupier() ==
				inPlayV->pPrev->getOccupier() &&
				inPlayV->yNext->getOccupier() ==
				inPlayV->yPrev->getOccupier()){
				result = true;
			}
			if (inPlayV->yNext->getOccupier() ==
				inPlayV->pNext->getOccupier() &&
				inPlayV->yNext->getOccupier() ==
				inPlayV->yPrev->getOccupier()){
				result = true;
			}
		}

		if (inPlayV->yPrev->getOccupier() != player
			&& inPlayV->yPrev->getOccupier() != NULL){
			if (inPlayV->yPrev->getOccupier() ==
				inPlayV->pPrev->getOccupier() &&
				inPlayV->yPrev->getOccupier() ==
				inPlayV->pNext->getOccupier()){
				result = true;
			}
			if (inPlayV->pPrev->getOccupier() ==
				inPlayV->pNext->getOccupier() &&
				inPlayV->pPrev->getOccupier() ==
				inPlayV->yPrev->getOccupier()){
				result = true;
			}
		}
		break;
	case 'o':
		if (inPlayV->bNext->getOccupier() != player
			&& inPlayV->bNext->getOccupier() != NULL){
			if (inPlayV->bNext->getOccupier() ==
				inPlayV->oPrev->getOccupier() &&
				inPlayV->bNext->getOccupier() ==
				inPlayV->bPrev->getOccupier()){
				result = true;
			}
			if (inPlayV->bNext->getOccupier() ==
				inPlayV->oNext->getOccupier() &&
				inPlayV->bNext->getOccupier() ==
				inPlayV->bPrev->getOccupier()){
				result = true;
			}
		}

		if (inPlayV->bPrev->getOccupier() != player
			&& inPlayV->bPrev->getOccupier() != NULL){
			if (inPlayV->bPrev->getOccupier() ==
				inPlayV->oPrev->getOccupier() &&
				inPlayV->bPrev->getOccupier() ==
				inPlayV->oNext->getOccupier()){
				result = true;
			}
			if (inPlayV->oPrev->getOccupier() ==
				inPlayV->oNext->getOccupier() &&
				inPlayV->oPrev->getOccupier() ==
				inPlayV->bPrev->getOccupier()){
				result = true;
			}
		}
		break;
	case 'g':
		if (inPlayV->rNext->getOccupier() != player
			&& inPlayV->rNext->getOccupier() != NULL){
			if (inPlayV->rNext->getOccupier() ==
				inPlayV->gPrev->getOccupier() &&
				inPlayV->rNext->getOccupier() ==
				inPlayV->rPrev->getOccupier()){
				result = true;
			}
			if (inPlayV->rNext->getOccupier() ==
				inPlayV->gNext->getOccupier() &&
				inPlayV->rNext->getOccupier() ==
				inPlayV->rPrev->getOccupier()){
				result = true;
			}
		}

		if (inPlayV->rPrev->getOccupier() != player
			&& inPlayV->rPrev->getOccupier() != NULL){
			if (inPlayV->rPrev->getOccupier() ==
				inPlayV->gPrev->getOccupier() &&
				inPlayV->rPrev->getOccupier() ==
				inPlayV->gNext->getOccupier()){
				result = true;
			}
			if (inPlayV->gPrev->getOccupier() ==
				inPlayV->gNext->getOccupier() &&
				inPlayV->gPrev->getOccupier() ==
				inPlayV->rPrev->getOccupier()){
				result = true;
			}
		}
		break;
	}
	return result;
}

void Vertex4D::deleteBurns(Vertex *inPlayV,
	Player *player, bool defensive) {
	
	switch (dynamic_cast<Vertex4D*>(inPlayV)->color) {
	case 'p':
//8 possible burns per case
	//1-2, long flat line, burn the shallow neighbor
		if (inPlayV->pPrev->getOccupier() == player				
			&& inPlayV->pNext->getOccupier() == player) {	
				scorePip(player, inPlayV->yNext, defensive);
		//now burn the 2nd shallow neighbor:
				scorePip(player, inPlayV->yPrev, defensive);
		}
	//3-4. short flat line, burn the acute neighbor
		if (inPlayV->yNext->getOccupier() == player
			&& inPlayV->yPrev->getOccupier() == player) {
				scorePip(player, inPlayV->pNext, defensive);
		//now burn the other acute neighbor:
			if (inPlayV->pPrev != NULL && inPlayV->pPrev->getOccupier() != player) {	//bottom
				scorePip(player, inPlayV->pPrev, defensive);
			}
		}
	//5-6. short trees burning opposite acute neighbors
		if (inPlayV->yNext->getOccupier() == player) {
			if (inPlayV->yNext->bPrev->getOccupier() == player) {
					scorePip(player, inPlayV->pNext, defensive);
			}
			if (inPlayV->yNext->rPrev->getOccupier() == player) {
				//if pPrev == NULL, burns pPrev
					scorePip(player, inPlayV->pPrev, defensive);
			}
		}
	//7-8, short trees on other side for both acute neighbors
		if (inPlayV->yPrev->getOccupier() == player) {
			if (inPlayV->yPrev->bNext->getOccupier() == player) {
					scorePip(player, inPlayV->pPrev, defensive);
			}
			if (inPlayV->yPrev->rNext->getOccupier() == player) {
				//if pNext == NULL, burn pNext
					scorePip(player, inPlayV->pNext, defensive);
			}
		}

	//legs surrounding shallow neighbors - burn shallow neighbors
	//degree of acute neighbor determines path to outside leg
	//7D uses black where 12D uses colors

//shallow burns with pNext vertex
		if (inPlayV->pNext->getOccupier() == player) {
			if (inPlayV->pNext->gNext->getOccupier() == player) {
				//check Null and Player, then delete yPrev
					scorePip(player, inPlayV->yPrev, defensive);
			}
			switch (inPlayV->pNext->getDegrees()) {
			case 7:
				if (inPlayV->pNext->kNext->getOccupier() == player) {
						scorePip(player, inPlayV->yNext, defensive);
				}
				break;
			case 12:
				if (inPlayV->pNext->oNext->getOccupier() == player) {
						scorePip(player, inPlayV->yNext, defensive);
				}
				break;
			}
		}
//shallow burns with pPrev vertex
		if (inPlayV->pPrev->getOccupier() == player) {
			if (inPlayV->pPrev->oPrev->getOccupier() == player) {
					scorePip(player, inPlayV->yPrev, defensive);
			}

			switch (inPlayV->pPrev->getDegrees()) {
			case 7:
				if (inPlayV->pPrev->kPrev->getOccupier() == player) {
						scorePip(player, inPlayV->yNext, defensive);
				}
				break;
			case 12:
				if (inPlayV->pPrev->gPrev->getOccupier() == player) {
						scorePip(player, inPlayV->yNext, defensive);
				}
				break;
			}
		
		}


		break;

	case 'o':
		//8 possible burns per case
		//1-2, long flat line, burn the shallow neighbors
		if (inPlayV->oPrev->getOccupier() == player
			&& inPlayV->oNext->getOccupier() == player) {
			scorePip(player, inPlayV->bPrev, defensive);
			scorePip(player, inPlayV->bNext, defensive);
		}
		//3-4. short flat line, burn the acute neighbors
		if (inPlayV->bNext->getOccupier() == player
			&& inPlayV->bPrev->getOccupier() == player) {
			scorePip(player, inPlayV->oNext, defensive);
			scorePip(player, inPlayV->oPrev, defensive);
		}
		//5-6. short trees burning opposite acute neighbors
		if (inPlayV->bNext->getOccupier() == player) {
			if (inPlayV->bNext->rPrev->getOccupier() == player) {
				scorePip(player, inPlayV->oNext, defensive);
			}
			if (inPlayV->bNext->yPrev->getOccupier() == player) {
				scorePip(player, inPlayV->oPrev, defensive);
			}
		}
		//7-8, short trees on other side for both acute neighbors
		if (inPlayV->bPrev->getOccupier() == player) {
			if (inPlayV->bPrev->rNext->getOccupier() == player) {
				scorePip(player, inPlayV->oPrev, defensive);
			}
			if (inPlayV->bPrev->yNext->getOccupier() == player) {
				scorePip(player, inPlayV->oNext, defensive);
			}
		}

		//legs surrounding shallow neighbors - burn shallow neighbors
		//degree of acute neighbor determines path to outside leg
		//7D uses black where 12D uses colors

		//shallow burns with oNext vertex
		if (inPlayV->oNext->getOccupier() == player) {
			if (inPlayV->oNext->pNext->getOccupier() == player) {
				//check Null and Player, then delete bPrev
				scorePip(player, inPlayV->bPrev, defensive);
			}
			switch (inPlayV->oNext->getDegrees()) {
			case 7:
				if (inPlayV->oNext->kNext->getOccupier() == player) {
					//check Null and Player, then delete bNext
					scorePip(player, inPlayV->bNext, defensive);
				}
				break;
			case 12:
				if (inPlayV->oNext->gNext->getOccupier() == player) {
					//check Null and Player, then  delete bNext
					scorePip(player, inPlayV->bNext, defensive);
				}
				break;
			}
		}
		//shallow burns with oPrev vertex
		if (inPlayV->oPrev->getOccupier() == player) {
			if (inPlayV->oPrev->gPrev->getOccupier() == player) {
				//check null & plaer and delete bPrev
				scorePip(player, inPlayV->bPrev, defensive);
			}

			switch (inPlayV->oPrev->getDegrees()) {
			case 7:
				if (inPlayV->oPrev->kPrev->getOccupier() == player) {
					//check null&player and delete bNext
					scorePip(player, inPlayV->bNext, defensive);
				}
				break;
			case 12:
				if (inPlayV->oPrev->pPrev->getOccupier() == player) {
					//check null & player and delete bNext
					scorePip(player, inPlayV->bNext, defensive);
				}
				break;
			}
		}
		break;
	case 'g':
	//12 possible burns per case
		//1-2, long flat line, burn the shallow neighbor
		if (inPlayV->gPrev->getOccupier() == player
			&& inPlayV->gNext->getOccupier() == player) {
			scorePip(player, inPlayV->rNext, defensive);
			//burn the other shallow neighbor:
			scorePip(player, inPlayV->rPrev, defensive);
		}
		//3-4. short flat line, burn the acute neighbor
		if (inPlayV->rNext->getOccupier() == player
			&& inPlayV->rPrev->getOccupier() == player) {
			scorePip(player, inPlayV->gNext, defensive);
			scorePip(player, inPlayV->gPrev, defensive);
		}
		//5-6. short trees burning opposite acute neighbors
		if (inPlayV->rNext->getOccupier() == player) {
			if (inPlayV->rNext->yPrev->getOccupier() == player) {
				//if gNext == NULL, burns gNext
				scorePip(player, inPlayV->gNext, defensive);
			}
			if (inPlayV->rNext->bPrev->getOccupier() == player) {
				//if gPrev == NULL, burns gPrev
				scorePip(player, inPlayV->gPrev, defensive);
			}
		}
		//7-8, short trees on other side for both acute neighbors
		if (inPlayV->rPrev->getOccupier() == player) {
			if (inPlayV->rPrev->yNext->getOccupier() == player) {
				//if gPrev != player , delete - nest folowing if
				scorePip(player, inPlayV->gPrev, defensive);
			}
			if (inPlayV->rPrev->bNext->getOccupier() == player) {
				//if gNext != player , delete - nest following if
				scorePip(player, inPlayV->gNext, defensive);
			}
		}

		//legs surrounding shallow neighbors - burn shallow neighbors
		//degree of acute neighbor determines path to outside leg
		//7D uses black where 12D uses colors

		//9-12, shallow burns with gNext vertex
		if (inPlayV->gNext->getOccupier() == player) {
			if (inPlayV->gNext->oNext->getOccupier() == player) {
				//check Null and Player, then delete rPrev
				scorePip(player, inPlayV->rPrev, defensive);
			}
			switch (inPlayV->gNext->getDegrees()) {
			case 7:
				if (inPlayV->gNext->kNext->getOccupier() == player) {
					//check Null and Player, then delete rNext
					scorePip(player, inPlayV->rNext, defensive);
				}
				break;
			case 12:
				if (inPlayV->gNext->pNext->getOccupier() == player) {
					//check Null and Player, then  delete rNext
					scorePip(player, inPlayV->rNext, defensive);
				}
				break;
			}
		}
		//shallow burns with gPrev vertex
		if (inPlayV->gPrev->getOccupier() == player) {
			if (inPlayV->gPrev->pPrev->getOccupier() == player) {
				//check null & plaer and delete rPrev
				scorePip(player, inPlayV->rPrev, defensive);
			}

			switch (inPlayV->gPrev->getDegrees()) {
			case 7:
				if (inPlayV->gPrev->kPrev->getOccupier() == player) {
					//check null&player and delete rNext
					scorePip(player, inPlayV->rNext, defensive);
				}
				break;
			case 12:
				if (inPlayV->gPrev->oPrev->getOccupier() == player) {
					//check null & player and delete rNext
					scorePip(player, inPlayV->rNext, defensive);
				}
				break;
			}
		}
		break;
	}
}
vector<Vertex*> Vertex4D::findTriangles(Vertex*inPlayV, Player *player){
	vector<Vertex*> triV;
	//4D can't make triangles
	return triV;
}