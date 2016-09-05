#include <stdio.h>
#include "Vertex1D.h"
#include "Vertex3D.h"
#include <iostream>

Vertex1D::Vertex1D() : Vertex() {}

Vertex1D::Vertex1D(int PIN, int xCoord, int yCoord,
	int degrees, char color) : Vertex(PIN, xCoord, yCoord,
	degrees){
	this->color = color;

}

Vertex1D::~Vertex1D(){}

Vertex1D::Vertex1D(Vertex& vertex){
	/*PIN = 0;
	*occupier = NULL;
	for (int i = 0; i < 4; i++){
		triX[i] = NULL;
	}
	this->PIN = PIN;
	this->occupier = occupier;
	for (int i = 0; i < 4; i++){
		this->triX[i] = triX[i];
	}*/
	
}

//all functions here done 

bool Vertex1D::isBurned(Vertex *inPlayV, Player *player){
	bool result = false;
	if (inPlayV->kPrev->getOccupier() == NULL
		|| inPlayV->kPrev->getOccupier() == player)
		result = false;
	else 
		switch (dynamic_cast<Vertex1D*>(inPlayV)->color){
		case 'b':
			if (inPlayV->kPrev->getOccupier() ==
				inPlayV->bPrev->getOccupier() &&
				inPlayV->kNext->getOccupier() ==
				inPlayV->bPrev->getOccupier())
				result = true;
			break;
		case 'r':
			if (inPlayV->kPrev->getOccupier() ==
				inPlayV->rPrev->getOccupier() &&
				inPlayV->kNext->getOccupier() ==
				inPlayV->rPrev->getOccupier())
				result = true;
			break;
		case 'y':
			if (inPlayV->kPrev->getOccupier() ==
				inPlayV->yPrev->getOccupier() &&
				inPlayV->kNext->getOccupier() ==
				inPlayV->yPrev->getOccupier())
				result = true;
			break;
	}
	
	return result;
}

void Vertex1D::deleteBurns(Vertex *inPlayV,
	Player *player, bool defensive) {

	if (inPlayV->kPrev->getOccupier() == player 
		&& inPlayV->kNext->getOccupier() == player){
		switch (dynamic_cast<Vertex1D*>(inPlayV)->color){
		case 'b':
			scorePip(player, inPlayV->bPrev, defensive);
			break;

		case 'r':
			scorePip(player, inPlayV->rPrev, defensive);
			break;

		case 'y':
			scorePip(player, inPlayV->yPrev, defensive);
			break;

			//check if it created any triangles
			//Vertex::findTriangles(Vertex*,Player);
			//if so, Vertex::deleteTriangles(player); 
		}
	}
}

vector<Vertex*> Vertex1D::findTriangles(Vertex*inPlayV, Player *player) {
	
	vector<Vertex*> triV;	//holds verticies from all triangles formed
	Vertex *tmpV = NULL;	//traverses pointers

//first level triangle
	if (inPlayV->kPrev->kPrev->getOccupier() == player
		&& inPlayV->kNext->kNext->getOccupier() == player) {
		switch (dynamic_cast<Vertex1D*>(inPlayV)->color) {
		case 'y':
			triV.push_back(inPlayV->kNext);
			triV.push_back(inPlayV->kPrev);
			triV.push_back(inPlayV->yPrev);
			triV.push_back(inPlayV->yPrev->yPrev);
			break;
		case 'b':
			triV.push_back(inPlayV->kNext);
			triV.push_back(inPlayV->kPrev);
			triV.push_back(inPlayV->bPrev);
			triV.push_back(inPlayV->bPrev->bPrev);
			break;
		case 'r':
			triV.push_back(inPlayV->kNext);
			triV.push_back(inPlayV->kPrev);
			triV.push_back(inPlayV->rPrev);
			triV.push_back(inPlayV->rPrev->rPrev);
			break;
		}
	}
//second level triangle
	if (inPlayV->kPrev->kPrev->kPrev->kPrev->getOccupier() == player
		&& inPlayV->kNext->kNext->kNext->kNext->getOccupier() == player) {

//legs
		tmpV = inPlayV->kPrev;
		while (tmpV != inPlayV->kPrev->kPrev->kPrev->kPrev) {
			triV.push_back(tmpV);
			tmpV = tmpV->kPrev;
		}
		tmpV = inPlayV->kNext;
		while (tmpV != inPlayV->kNext->kNext->kNext->kNext) {
			triV.push_back(tmpV);
			tmpV = tmpV->kNext;
		}
//make switch for colors of vertical lines
		switch (dynamic_cast<Vertex1D*>(inPlayV)->color) {
		case 'b':
	//middle line
			tmpV = inPlayV->bPrev;
			while (tmpV != inPlayV->bPrev->bPrev->bPrev->bPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->bPrev;
			}
	//side lines
			tmpV = inPlayV->kPrev->kPrev->bPrev;
			while (tmpV != inPlayV->kPrev->kPrev->bPrev->bPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->bPrev;
			}
			tmpV = inPlayV->kNext->kNext->bPrev;
			while (tmpV != inPlayV->kNext->kNext->bPrev->bPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->bPrev;
			}
	//misc
			triV.push_back(inPlayV->kPrev->kPrev->pNext);
			triV.push_back(inPlayV->kNext->kNext->gPrev);
			break;

		case 'r':
	//middle line
			tmpV = inPlayV->rPrev;
			while (tmpV != inPlayV->rPrev->rPrev->rPrev->rPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->rPrev;
			}
	//side lines
			tmpV = inPlayV->kPrev->kPrev->rPrev;
			while (tmpV != inPlayV->kPrev->kPrev->rPrev->rPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->rPrev;
			}
			tmpV = inPlayV->kNext->kNext->rPrev;
			while (tmpV != inPlayV->kNext->kNext->rPrev->rPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->rPrev;
			}
	//misc
			triV.push_back(inPlayV->kPrev->kPrev->oNext);
			triV.push_back(inPlayV->kNext->kNext->pPrev);
			break;

		case 'y':
	//middle line
			tmpV = inPlayV->yPrev;
			while (tmpV != inPlayV->yPrev->yPrev->yPrev->yPrev->yPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->yPrev;
			}
	//side lines
			tmpV = inPlayV->kPrev->kPrev->yPrev;
			while (tmpV != inPlayV->kPrev->kPrev->yPrev->yPrev->yPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->yPrev;
			}
			tmpV = inPlayV->kNext->kNext->yPrev;
			while (tmpV != inPlayV->kNext->kNext->yPrev->yPrev->yPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->yPrev;
			}
	//misc
			triV.push_back(inPlayV->kPrev->kPrev->gNext);
			triV.push_back(inPlayV->kNext->kNext->oPrev);

			break;
		}
	}

//third level triangle
	if (inPlayV->kPrev->kPrev->kPrev->kPrev->kPrev->kPrev->getOccupier() == player
		&& inPlayV->kNext->kNext->kNext->kNext->kNext->kNext->getOccupier() == player) {
//legs
		tmpV = inPlayV->kPrev;
		while (tmpV != inPlayV->kPrev->kPrev->kPrev->kPrev->kPrev->kPrev) {
			triV.push_back(tmpV);
			tmpV = tmpV->kPrev;
		}
		tmpV = inPlayV->kNext;
		while (tmpV != inPlayV->kNext->kNext->kNext->kNext->kNext->kNext) {
			triV.push_back(tmpV);
			tmpV = tmpV->kNext;
		}
		switch (dynamic_cast<Vertex1D*>(inPlayV)->color) {
		case 'b':
	//middle line
			tmpV = inPlayV->bPrev;
			while (tmpV != inPlayV->bPrev->bPrev->bPrev->bPrev->bPrev->bPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->bPrev;
			}
	//side lines
			tmpV = inPlayV->kPrev->kPrev->bPrev;
			while (tmpV != inPlayV->kPrev->kPrev->bPrev->bPrev->bPrev->bPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->bPrev;
			}
			tmpV = inPlayV->kNext->kNext->bPrev;
			while (tmpV != inPlayV->kNext->kNext->bPrev->bPrev->bPrev->bPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->bPrev;
			}
	//outer side lines
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->bPrev);
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->bPrev->bPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->bPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->bPrev->bPrev);
			break;
	//misc
			triV.push_back(inPlayV->kPrev->kPrev->pNext);
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->pNext);
			triV.push_back(inPlayV->bPrev->bPrev->bPrev->bPrev->gPrev);
			triV.push_back(inPlayV->kNext->kNext->gPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->gPrev);
			triV.push_back(inPlayV->bPrev->bPrev->bPrev->bPrev->pNext);
			break;
		case 'r':
	//middle line
			tmpV = inPlayV->rPrev;
			while (tmpV != inPlayV->rPrev->rPrev->rPrev->rPrev->rPrev->rPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->rPrev;
			}
	//side lines
			tmpV = inPlayV->kPrev->kPrev->rPrev;
			while (tmpV != inPlayV->kPrev->kPrev->rPrev->rPrev->rPrev->rPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->rPrev;
			}
			tmpV = inPlayV->kNext->kNext->rPrev;
			while (tmpV != inPlayV->kNext->kNext->rPrev->rPrev->rPrev->rPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->rPrev;
			}
	//outer side lines
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->rPrev);
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->rPrev->rPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->rPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->rPrev->rPrev);

	//misc
			triV.push_back(inPlayV->kPrev->kPrev->oNext);
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->oNext);
			triV.push_back(inPlayV->rPrev->rPrev->rPrev->rPrev->pPrev);
			triV.push_back(inPlayV->kNext->kNext->pPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->pPrev);
			triV.push_back(inPlayV->rPrev->rPrev->rPrev->rPrev->oNext);
			break;
		case 'y':
	//middle line
			tmpV = inPlayV->yPrev;
			while (tmpV != inPlayV->yPrev->yPrev->yPrev->yPrev->yPrev->yPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->yPrev;
			}
	//side lines
			tmpV = inPlayV->kPrev->kPrev->yPrev;
			while (tmpV != inPlayV->kPrev->kPrev->yPrev->yPrev->yPrev->yPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->yPrev;
			}
			tmpV = inPlayV->kNext->kNext->yPrev;
			while (tmpV != inPlayV->kNext->kNext->yPrev->yPrev->yPrev->yPrev) {
				triV.push_back(tmpV);
				tmpV = tmpV->yPrev;
			}
	//outer side lines
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->yPrev);
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->yPrev->yPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->yPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->yPrev->yPrev);

	//misc
			triV.push_back(inPlayV->kPrev->kPrev->gNext);
			triV.push_back(inPlayV->kPrev->kPrev->kPrev->kPrev->gNext);
			triV.push_back(inPlayV->rPrev->rPrev->rPrev->rPrev->oPrev);
			triV.push_back(inPlayV->kNext->kNext->oPrev);
			triV.push_back(inPlayV->kNext->kNext->kNext->kNext->oPrev);
			triV.push_back(inPlayV->rPrev->rPrev->rPrev->rPrev->gNext);

			break;
		}
	}

	return triV;
}























