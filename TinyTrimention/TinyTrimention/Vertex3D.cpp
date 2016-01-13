#include <stdio.h>
#include "Vertex3D.h"

Vertex3D::Vertex3D() : Vertex(){

}


Vertex3D::Vertex3D(int PIN, int xCoord, int yCoord,
	int degrees, char color) : Vertex(PIN, xCoord, yCoord,
	degrees){
	this->color = color;
}

Vertex3D::~Vertex3D(){

}

Vertex3D::Vertex3D(Vertex& vertex){

}

//all functions here done

bool Vertex3D::isBurned(Vertex *inPlayV, Player *player){
	bool result = false;
	//check if this spot is burned by OTHER player
	
	if (inPlayV->kNext->getOccupier() == NULL ||
		inPlayV->kNext->getOccupier() == player)
		result = false;
	else
		switch (dynamic_cast<Vertex3D*>(inPlayV)->color){
		case 'b':
			if (inPlayV->kPrev->getOccupier() ==
				inPlayV->bNext->getOccupier() &&
				inPlayV->kNext->getOccupier() ==
				inPlayV->bNext->getOccupier())
				result = true;
			break;
		case 'r':
			if (inPlayV->kPrev->getOccupier() ==
				inPlayV->rNext->getOccupier() &&
				inPlayV->kNext->getOccupier() ==
				inPlayV->rNext->getOccupier())
				result = true;
			break;
		case 'y':
			if (inPlayV->kPrev->getOccupier() ==
				inPlayV->yNext->getOccupier() &&
				inPlayV->kNext->getOccupier() ==
				inPlayV->yNext->getOccupier())
				result = true;
			break;
	}

	return result;	
}

void Vertex3D::deleteBurns(Vertex *inPlayV, Player *player, bool defensive) {

//checks along black line on either side
	if (inPlayV->kPrev->getOccupier() == player
		&& inPlayV->kNext->getOccupier() == player){
		switch (dynamic_cast<Vertex3D*>(inPlayV)->color){
		case 'b':
			if (inPlayV->bNext->getOccupier() != NULL 
				&& inPlayV->bNext->getOccupier() != player) {
				scorePip(player, inPlayV->bNext, defensive);
			}
			break;
		case 'r':
			if (inPlayV->rNext->getOccupier() != NULL
				&& inPlayV->rNext->getOccupier() != player) {
				scorePip(player, inPlayV->rNext, defensive);
			}
			break;
		case 'y':
			if (inPlayV->yNext->getOccupier() != NULL
				&& inPlayV->yNext->getOccupier() != player) {
				scorePip(player, inPlayV->yNext, defensive);
			}
			break;
		}
	}
//check if acute neighbors burn center
	if (inPlayV->kPrev->getOccupier() == player)
	{
		switch (dynamic_cast<Vertex3D*>(inPlayV)->color){
		case 'b':
			if (inPlayV->bNext->yPrev->getOccupier() == player) {
				if (inPlayV->bNext->getOccupier() != NULL
					&& inPlayV->bNext->getOccupier() != player) {
					scorePip(player, inPlayV->bNext, defensive);
				}
			}
			break;
		case 'r':
			if (inPlayV->rNext->bPrev->getOccupier() == player) {
				if (inPlayV->rNext->getOccupier() != NULL
					&& inPlayV->rNext->getOccupier() != player) {
					scorePip(player, inPlayV->rNext, defensive);
				}
			}
			break;
		case 'y':
			if (inPlayV->yNext->rPrev->getOccupier() == player) {
				if (inPlayV->yNext->getOccupier() != NULL
					&&inPlayV->yNext->getOccupier() != player) {
					scorePip(player, inPlayV->yNext, defensive);
				}
			}
			break;
		}
	}
	//other acute neighbor
	if (inPlayV->kNext->getOccupier() == player)
	{
		switch (dynamic_cast<Vertex3D*>(inPlayV)->color){
		case 'b':
			if (inPlayV->bNext->yPrev->getOccupier() == player) {
				if (inPlayV->bNext->getOccupier() != NULL
					&& inPlayV->bNext->getOccupier() != player) {
					scorePip(player, inPlayV->bNext, defensive);
				}
			}
			break;
		case 'r':
			if (inPlayV->rNext->bPrev->getOccupier() == player) {
				if (inPlayV->rNext->getOccupier() != NULL
					&& inPlayV->rNext->getOccupier() != player) {
					scorePip(player, inPlayV->rNext, defensive);
				}
			}
			break;
		case 'y':
			if (inPlayV->yNext->rPrev->getOccupier() == player) {
				if (inPlayV->yNext->getOccupier() != NULL
					&& inPlayV->yNext->getOccupier() != player) {
					scorePip(player, inPlayV->yNext, defensive);
				}
			}
			break;
		}
	}
//checks if shallow burns on each side burn acute neighbor
	
	switch (dynamic_cast<Vertex3D*>(inPlayV)->color) {
	case 'b':
		if (inPlayV->bNext->getOccupier() == player) {
			if (inPlayV->bNext->rPrev->getOccupier() == player) {
				if (inPlayV->kNext->getOccupier() != NULL
					&& inPlayV->kNext->getOccupier() != player) {
					scorePip(player, inPlayV->kNext, defensive);
				}
			}
			if (inPlayV->bNext->yPrev->getOccupier() == player) {
				if (inPlayV->kPrev->getOccupier() != NULL
					&& inPlayV->kPrev->getOccupier() != player) {
					scorePip(player, inPlayV->kPrev, defensive);
				}
			}
			
		}
		break;
	case 'r':
		if (inPlayV->rNext->getOccupier() == player) {
			if (inPlayV->rNext->yPrev->getOccupier() == player) {
				if (inPlayV->kNext->getOccupier() != NULL
					&& inPlayV->kNext->getOccupier() != player) {
					scorePip(player, inPlayV->kNext, defensive);
				}
			}
			if (inPlayV->rNext->bPrev->getOccupier() == player) {
				if (inPlayV->kPrev->getOccupier() != NULL
					&& inPlayV->kPrev->getOccupier() != player) {
					scorePip(player, inPlayV->kPrev, defensive);
				}
			}
			
		}
		break;
	case 'y':
		if (inPlayV->yNext->getOccupier() == player) {
			if (inPlayV->yNext->bPrev->getOccupier() == player) {
				if (inPlayV->kNext->getOccupier() != NULL
					&& inPlayV->kNext->getOccupier() != player) {
					scorePip(player, inPlayV->kNext, defensive);
				}
			}
			if (inPlayV->yNext->rPrev->getOccupier() == player) {
				if (inPlayV->kPrev->getOccupier() != NULL
					&& inPlayV->kPrev->getOccupier() != player) {
					scorePip(player, inPlayV->kPrev, defensive);
				}
			}
			
		}
		break;
	}

}
	//3D can't create triangles, so none to delete


vector<Vertex*> Vertex3D::findTriangles(Vertex*inPlayV, Player *player){
	vector<Vertex*> triV;
	//3D can't make triangles
	return triV;
}