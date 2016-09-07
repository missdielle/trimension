#include <stdio.h>
#include "Vertex7D.h"
//#include "Vertex3D.h"
#include <iostream>

Vertex7D::Vertex7D() : Vertex() {}

Vertex7D::Vertex7D(int PIN, int xCoord, int yCoord,
	int degrees, char color) : Vertex(PIN, xCoord, yCoord,
degrees){
this->color = color;

}

Vertex7D::~Vertex7D() {}

Vertex7D::Vertex7D(Vertex& vertex) {

}

bool Vertex7D::isBurned(Vertex *inPlayV, Player *player) {
	bool result = false;

	switch (dynamic_cast<Vertex7D*>(inPlayV)->color) {
	case 'o':
		if (inPlayV->pPrev->getOccupier() != NULL){
			if (inPlayV->pPrev->getOccupier() != player) {
				if (inPlayV->pPrev->getOccupier()
					== inPlayV->rPrev->getOccupier()
					&& inPlayV->pPrev->getOccupier()
					== inPlayV->kNext->getOccupier()) {
					result = true;
				}
				if (inPlayV->pPrev->getOccupier()
					== inPlayV->rPrev->getOccupier()
					&& inPlayV->pPrev->getOccupier()
					== inPlayV->bNext->getOccupier()) {
					result = true;
				}
				if (inPlayV->pPrev->getOccupier()
					== inPlayV->bNext->getOccupier()
					&& inPlayV->pPrev->getOccupier()
					== inPlayV->gNext->getOccupier()) {
					result = true;
				}
			}
		}
		if (inPlayV->yPrev->getOccupier() != NULL){
			if (inPlayV->yPrev->getOccupier() != player) {
				if (inPlayV->yPrev->getOccupier()
					== inPlayV->gNext->getOccupier()
					&& inPlayV->yPrev->getOccupier()
					== inPlayV->bNext->getOccupier()) {
					result = true;
				}
				if (inPlayV->yPrev->getOccupier()
					== inPlayV->gNext->getOccupier()
					&& inPlayV->yPrev->getOccupier()
					== inPlayV->kPrev->getOccupier()) {
					result = true;
				}
			}
		}
		break;
	case 'p':
		if (inPlayV->bPrev->getOccupier() != NULL){
			if (inPlayV->bPrev->getOccupier() != player) {
				if (inPlayV->bPrev->getOccupier()
					== inPlayV->kNext->getOccupier()
					&& inPlayV->bPrev->getOccupier()
					== inPlayV->gPrev->getOccupier()) {
					result = true;
				}
				if (inPlayV->bPrev->getOccupier()
					== inPlayV->gPrev->getOccupier()
					&& inPlayV->bPrev->getOccupier()
					== inPlayV->yNext->getOccupier()) {
					result = true;
				}
			}
		}
		if (inPlayV->oNext->getOccupier() != NULL){
			if (inPlayV->oNext->getOccupier() != player) {
				if (inPlayV->oNext->getOccupier()
					== inPlayV->yNext->getOccupier()
					&& inPlayV->oNext->getOccupier()
					== inPlayV->rPrev->getOccupier()) {
					result = true;
				}
				if (inPlayV->oNext->getOccupier()
					== inPlayV->yNext->getOccupier()
					&& inPlayV->oNext->getOccupier()
					== inPlayV->gPrev->getOccupier()) {
					result = true;
				}
				if (inPlayV->oNext->getOccupier()
					== inPlayV->rPrev->getOccupier()
					&& inPlayV->oNext->getOccupier()
					== inPlayV->kPrev->getOccupier()) {
					result = true;
				}
			}
		}
		break;
	case 'g':
		if (inPlayV->pNext->getOccupier() != NULL){
			if (inPlayV->pNext->getOccupier() != player) {
				if (inPlayV->pNext->getOccupier()
					== inPlayV->bPrev->getOccupier()
					&& inPlayV->pNext->getOccupier()
					== inPlayV->kPrev->getOccupier()) {
					result = true;
				}
				if (inPlayV->pNext->getOccupier()
					== inPlayV->rNext->getOccupier()
					&& inPlayV->pNext->getOccupier()
					== inPlayV->oPrev->getOccupier()) {
					result = true;
				}
				if (inPlayV->pNext->getOccupier()
					== inPlayV->bPrev->getOccupier()
					&& inPlayV->pNext->getOccupier()
					== inPlayV->rNext->getOccupier()) {
					result = true;
				}
			}
		}
		if (inPlayV->oPrev->getOccupier() != NULL){
			if (inPlayV->oPrev->getOccupier() != player) {
				if (inPlayV->oPrev->getOccupier()
					== inPlayV->rNext->getOccupier()
					&& inPlayV->oPrev->getOccupier()
					== inPlayV->yPrev->getOccupier()) {
					result = true;
				}
				if (inPlayV->kNext->getOccupier()
					== inPlayV->yPrev->getOccupier()
					&& inPlayV->kNext->getOccupier()
					== inPlayV->oPrev->getOccupier()) {
					result = true;
				}
			}
		}
		break;
	}
	return result;
}

void Vertex7D::deleteBurns(Vertex *inPlayV,
	Player *player, bool defensive) {
	switch (dynamic_cast<Vertex7D*>(inPlayV)->color) {
	case 'p':
		//k
		if (inPlayV->kPrev->getOccupier() == player) {
			if (inPlayV->kPrev->kPrev->getOccupier() == player
				|| inPlayV->oNext->getOccupier() == player) {
				scorePip(player, inPlayV->rPrev, defensive);
			}
		}
		//r
		if (inPlayV->rPrev->getOccupier() == player) {
			if (inPlayV->rPrev->yNext->getOccupier() == player
				|| inPlayV->yNext->getOccupier() == player) {
				scorePip(player, inPlayV->oNext, defensive);
			}
			if (inPlayV->rPrev->bNext->getOccupier() == player)
				scorePip(player, inPlayV->kPrev, defensive);
		}
		//o
		if (inPlayV->oNext->getOccupier() == player) {
			if (inPlayV->oNext->oNext->getOccupier() == player
				|| inPlayV->kPrev->getOccupier() == player) {
				scorePip(player, inPlayV->rPrev, defensive);
			}
			if (inPlayV->oNext->oNext->getOccupier() == player
				|| inPlayV->gPrev->getOccupier() == player) {
				scorePip(player, inPlayV->yNext, defensive);
			}

		}
		//y
		if (inPlayV->yNext->getOccupier() == player) {
			if (inPlayV->yNext->rPrev->getOccupier() == player
				|| inPlayV->rPrev->getOccupier() == player) {
				scorePip(player, inPlayV->oNext, defensive);
			}
			if (inPlayV->yNext->bPrev->getOccupier() == player
				|| inPlayV->bPrev->getOccupier() == player) {
				scorePip(player, inPlayV->gPrev, defensive);
			}
		}
		//g
		if (inPlayV->gPrev->getOccupier() == player) {
			if (inPlayV->gPrev->gPrev->getOccupier() == player
				|| inPlayV->oNext->getOccupier() == player) {
				scorePip(player, inPlayV->yNext, defensive);
			}
			if (inPlayV->gPrev->gPrev->getOccupier() == player
				|| inPlayV->kNext->getOccupier() == player) {
				scorePip(player, inPlayV->bPrev, defensive);
			}
		}
		//b
		if (inPlayV->bPrev->getOccupier() == player) {
			if (inPlayV->bPrev->yNext->getOccupier() == player
				|| inPlayV->yNext->getOccupier() == player) {
				scorePip(player, inPlayV->gPrev, defensive);
			}
			if (inPlayV->bPrev->rNext->getOccupier() == player) {
				scorePip(player, inPlayV->kNext, defensive);
			}
		}
		//k
		if (inPlayV->kNext->getOccupier() == player) {
			if (inPlayV->kNext->kNext->getOccupier() == player
				|| inPlayV->gPrev->getOccupier() == player) {
				scorePip(player, inPlayV->bPrev, defensive);
			}
		}
		break;
	case 'o':
		//k
		if (inPlayV->kPrev->getOccupier() == player) {
			if (inPlayV->kPrev->kPrev->getOccupier() == player
				|| inPlayV->gNext->getOccupier() == player) {
				scorePip(player, inPlayV->yPrev, defensive);
			}
		}
		//y
		if (inPlayV->yPrev->getOccupier() == player) {
			if (inPlayV->yPrev->bNext->getOccupier() == player
				|| inPlayV->bNext->getOccupier() == player) {
				scorePip(player, inPlayV->gNext, defensive);
			}
			if (inPlayV->yPrev->rNext->getOccupier() == player)
				scorePip(player, inPlayV->kPrev, defensive);
		}
		//g
		if (inPlayV->gNext->getOccupier() == player) {
			if (inPlayV->gNext->gNext->getOccupier() == player
				|| inPlayV->kPrev->getOccupier() == player) {
				scorePip(player, inPlayV->yPrev, defensive);
			}
			if (inPlayV->gNext->gNext->getOccupier() == player
				|| inPlayV->pPrev->getOccupier() == player) {
				scorePip(player, inPlayV->bNext, defensive);
			}

		}
		//b
		if (inPlayV->bNext->getOccupier() == player) {
			if (inPlayV->bNext->yPrev->getOccupier() == player
				|| inPlayV->yPrev->getOccupier() == player) {
				scorePip(player, inPlayV->oNext, defensive);
			}
			if (inPlayV->bNext->rPrev->getOccupier() == player
				|| inPlayV->rPrev->getOccupier() == player) {
				scorePip(player, inPlayV->pPrev, defensive);
			}
		}
		//p
		if (inPlayV->pPrev->getOccupier() == player) {
			if (inPlayV->pPrev->pPrev->getOccupier() == player
				|| inPlayV->gNext->getOccupier() == player) {
				scorePip(player, inPlayV->bNext, defensive);
			}
			if (inPlayV->pPrev->pPrev->getOccupier() == player
				|| inPlayV->kNext->getOccupier() == player) {
				scorePip(player, inPlayV->rPrev, defensive);
			}
		}
		//r
		if (inPlayV->rPrev->getOccupier() == player) {
			if (inPlayV->rPrev->bNext->getOccupier() == player
				|| inPlayV->bNext->getOccupier() == player) {
				scorePip(player, inPlayV->pPrev, defensive);
			}
			if (inPlayV->rPrev->yNext->getOccupier() == player) {
				scorePip(player, inPlayV->kNext, defensive);
			}
		}
		//k
		if (inPlayV->kNext->getOccupier() == player) {
			if (inPlayV->kNext->kNext->getOccupier() == player
				|| inPlayV->pPrev->getOccupier() == player) {
				scorePip(player, inPlayV->rPrev, defensive);
			}
		}
		break;
	case 'g':
		//k
		if (inPlayV->kPrev->getOccupier() == player) {
			if (inPlayV->kPrev->kPrev->getOccupier() == player
				|| inPlayV->pNext->getOccupier() == player) {
				scorePip(player, inPlayV->bPrev, defensive);
			}
		}
		//b
		if (inPlayV->bPrev->getOccupier() == player) {
			if (inPlayV->bPrev->rNext->getOccupier() == player
				|| inPlayV->rNext->getOccupier() == player) {
				scorePip(player, inPlayV->pNext, defensive);
			}
			if (inPlayV->bPrev->yNext->getOccupier() == player)
				scorePip(player, inPlayV->kPrev, defensive);
		}
		//p
		if (inPlayV->pNext->getOccupier() == player) {
			if (inPlayV->pNext->pNext->getOccupier() == player
				|| inPlayV->kPrev->getOccupier() == player) {
				scorePip(player, inPlayV->bPrev, defensive);
			}
			if (inPlayV->pNext->pNext->getOccupier() == player
				|| inPlayV->oPrev->getOccupier() == player) {
				scorePip(player, inPlayV->rNext, defensive);
			}

		}
		//r
		if (inPlayV->rNext->getOccupier() == player) {
			if (inPlayV->rNext->bPrev->getOccupier() == player
				|| inPlayV->bPrev->getOccupier() == player) {
				scorePip(player, inPlayV->pNext, defensive);
			}
			if (inPlayV->rNext->yPrev->getOccupier() == player
				|| inPlayV->yPrev->getOccupier() == player) {
				scorePip(player, inPlayV->oPrev, defensive);
			}
		}
		//o
		if (inPlayV->oPrev->getOccupier() == player) {
			if (inPlayV->oPrev->oPrev->getOccupier() == player
				|| inPlayV->pNext->getOccupier() == player) {
				scorePip(player, inPlayV->rNext, defensive);
			}
			if (inPlayV->oPrev->oPrev->getOccupier() == player
				|| inPlayV->kNext->getOccupier() == player) {
				scorePip(player, inPlayV->yPrev, defensive);
			}
		}
		//y
		if (inPlayV->yPrev->getOccupier() == player) {
			if (inPlayV->yPrev->rNext->getOccupier() == player
				|| inPlayV->rNext->getOccupier() == player) {
				scorePip(player, inPlayV->oPrev, defensive);
			}
			if (inPlayV->yPrev->bNext->getOccupier() == player) {
				scorePip(player, inPlayV->kNext, defensive);
			}
		}
		//k
		if (inPlayV->kNext->getOccupier() == player) {
			if (inPlayV->kNext->kNext->getOccupier() == player
				|| inPlayV->oPrev->getOccupier() == player) {
				scorePip(player, inPlayV->yPrev, defensive);
			}
		}
		break;
	}

}

vector<Vertex*> Vertex7D::findTriangles(Vertex*inPlayV, Player *player) {
	vector<Vertex*> triV;	//holds verticies inside triangle created
	Vertex *tmpV = NULL;	//used in traversing tree
	switch (dynamic_cast<Vertex7D*>(inPlayV)->color) {
	case 'o':
		//1st level secondary colors 
		if (inPlayV->kPrev->kPrev->getOccupier() == player
			&& inPlayV->gNext->gNext->getOccupier() == player) {
			triV.push_back(inPlayV->kPrev);
			triV.push_back(inPlayV->yPrev);
			triV.push_back(inPlayV->yPrev->yPrev);
			triV.push_back(inPlayV->gNext);
		}
		if (inPlayV->kNext->kNext->getOccupier() == player
			&& inPlayV->pPrev->pPrev->getOccupier() == player) {
			triV.push_back(inPlayV->kNext);
			triV.push_back(inPlayV->rPrev);
			triV.push_back(inPlayV->rPrev->rPrev);
			triV.push_back(inPlayV->pPrev);
		}
		//upside down 1st level secondary
		if (inPlayV->gNext->gNext->getOccupier() == player
			&& inPlayV->pPrev->pPrev->getOccupier() == player) {
			triV.push_back(inPlayV->gNext);
			triV.push_back(inPlayV->bNext);
			triV.push_back(inPlayV->bNext->bNext);
			triV.push_back(inPlayV->pPrev);
		}
		//2nd level secondary
		if (inPlayV->pPrev->pPrev->pPrev != NULL) {
			if (inPlayV->pPrev->pPrev->pPrev->pPrev->getOccupier() == player
				&& inPlayV->kNext->kNext->kNext->kNext->getOccupier() == player) {
				//edge leg
				tmpV = inPlayV->kNext;
				while (tmpV->getDegrees() != 1) {
					triV.push_back(tmpV);
					tmpV = tmpV->kNext;
				}
				//color leg
				tmpV = inPlayV->pPrev;
				while (tmpV->pPrev != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->pPrev;
				}
				//primary lines
				tmpV = inPlayV->rPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->rPrev;
				}
				tmpV = inPlayV->kNext->kNext->rPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->rPrev;
				}
				tmpV = inPlayV->pPrev->pPrev->rPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->rPrev;
				}
				//misc.
				triV.push_back(inPlayV->kNext->kNext->pPrev);
				triV.push_back(inPlayV->pPrev->pPrev->oNext);
			}
		}
		//2nd level secondary - other side
		if (inPlayV->gNext->gNext->gNext != NULL) {
			if (inPlayV->gNext->gNext->gNext->gNext->getOccupier() == player
				&& inPlayV->kPrev->kPrev->kPrev->kPrev->getOccupier() == player) {
				//edge leg
				tmpV = inPlayV->kPrev;
				while (tmpV->getDegrees() != 1) {
					triV.push_back(tmpV);
					tmpV = tmpV->kPrev;
				}
				//color leg
				tmpV = inPlayV->gNext;
				while (tmpV->gNext != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->gNext;
				}
				//primary lines
				tmpV = inPlayV->yPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->yPrev;
				}
				tmpV = inPlayV->kPrev->kPrev->yPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->yPrev;
				}
				tmpV = inPlayV->gNext->gNext->yPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->yPrev;
				}
				//misc.
				triV.push_back(inPlayV->kPrev->kPrev->gNext);
				triV.push_back(inPlayV->gNext->gNext->oPrev);
			}
		}
		//1st level primary
		if (inPlayV->yPrev->yPrev->yPrev != NULL
			&& inPlayV->bNext->bNext->bNext != NULL) {
			if (inPlayV->yPrev->yPrev->yPrev->getOccupier() == player
				&& inPlayV->bNext->bNext->bNext->getOccupier() == player) {
				triV.push_back(inPlayV->yPrev);
				triV.push_back(inPlayV->yPrev->yPrev);
				triV.push_back(inPlayV->gNext);
				triV.push_back(inPlayV->gNext->gNext);
				triV.push_back(inPlayV->bNext);
				triV.push_back(inPlayV->bNext->bNext);
			}
		}
		if (inPlayV->bNext->bNext->bNext != NULL
			&& inPlayV->rPrev->rPrev->rPrev != NULL) {
			if (inPlayV->bNext->bNext->bNext->getOccupier() == player
				&& inPlayV->rPrev->rPrev->rPrev->getOccupier() == player) {
				triV.push_back(inPlayV->bNext);
				triV.push_back(inPlayV->bNext->bNext);
				triV.push_back(inPlayV->pPrev);
				triV.push_back(inPlayV->pPrev->pPrev);
				triV.push_back(inPlayV->rPrev);
				triV.push_back(inPlayV->rPrev->rPrev);
			}
		}
		//2nd level primary
		if (inPlayV->bNext->bNext->bNext != NULL
			&& inPlayV->yPrev->yPrev->yPrev != NULL) {
			if (inPlayV->bNext->bNext->bNext->bNext->getOccupier() == player
				&& inPlayV->yPrev->yPrev->yPrev->yPrev->getOccupier() == player) {
				triV.push_back(inPlayV->bNext);
				triV.push_back(inPlayV->bNext->bNext);
				triV.push_back(inPlayV->bNext->bNext->bNext);
				triV.push_back(inPlayV->yPrev);
				triV.push_back(inPlayV->yPrev->yPrev);
				triV.push_back(inPlayV->yPrev->yPrev->yPrev);
				triV.push_back(inPlayV->gNext);
				triV.push_back(inPlayV->gNext->gNext);
				triV.push_back(inPlayV->gNext->gNext->oPrev);
				triV.push_back(inPlayV->gNext->gNext->yPrev);
				triV.push_back(inPlayV->gNext->gNext->gNext);
				triV.push_back(inPlayV->gNext->gNext->bNext);
				triV.push_back(inPlayV->gNext->gNext->pPrev);
			}
		}
		if (inPlayV->bNext->bNext->bNext != NULL
			&& inPlayV->rPrev->rPrev->rPrev != NULL) {
			if (inPlayV->bNext->bNext->bNext->bNext->getOccupier() == player
				&& inPlayV->rPrev->rPrev->rPrev->rPrev->getOccupier() == player) {
				triV.push_back(inPlayV->bNext);
				triV.push_back(inPlayV->bNext->bNext);
				triV.push_back(inPlayV->bNext->bNext->bNext);
				triV.push_back(inPlayV->rPrev);
				triV.push_back(inPlayV->rPrev->rPrev);
				triV.push_back(inPlayV->rPrev->rPrev->rPrev);
				triV.push_back(inPlayV->pPrev);
				triV.push_back(inPlayV->pPrev->pPrev);
				triV.push_back(inPlayV->pPrev->pPrev->pPrev);
				triV.push_back(inPlayV->pPrev->pPrev->bNext);
				triV.push_back(inPlayV->pPrev->pPrev->oNext);
				triV.push_back(inPlayV->pPrev->pPrev->rPrev);
				triV.push_back(inPlayV->pPrev->pPrev->gNext);
			}
		}
		break;
	case 'p':
		//1st level secondary 
		if (inPlayV->kPrev->kPrev->getOccupier() == player
			&& inPlayV->oNext->oNext->getOccupier() == player) {
			triV.push_back(inPlayV->kPrev);
			triV.push_back(inPlayV->rPrev);
			triV.push_back(inPlayV->rPrev->rPrev);
			triV.push_back(inPlayV->oNext);
		}
		if (inPlayV->kNext->kNext->getOccupier() == player
			&& inPlayV->gPrev->gPrev->getOccupier() == player) {
			triV.push_back(inPlayV->kNext);
			triV.push_back(inPlayV->bPrev);
			triV.push_back(inPlayV->bPrev->bPrev);
			triV.push_back(inPlayV->gPrev);
		}
		//upside down 1st level secondary
		if (inPlayV->oNext->oNext->getOccupier() == player
			&& inPlayV->gPrev->gPrev->getOccupier() == player) {
			triV.push_back(inPlayV->oNext);
			triV.push_back(inPlayV->yNext);
			triV.push_back(inPlayV->yNext->yNext);
			triV.push_back(inPlayV->gPrev);
		}

		//2nd level secondary
		if (inPlayV->oNext->oNext->oNext != NULL && inPlayV->kPrev->kPrev->kPrev != NULL) {
			if (inPlayV->oNext->oNext->oNext->oNext->getOccupier() == player
				&& inPlayV->kPrev->kPrev->kPrev->kPrev->getOccupier() == player) {
				//edge leg
				tmpV = inPlayV->kPrev;
				while (tmpV->getDegrees() != 1) {
					triV.push_back(tmpV);
					tmpV = tmpV->kPrev;
				}
				//color leg
				tmpV = inPlayV->oNext;
				while (tmpV->oNext != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->oNext;
				}
				//primary lines
				tmpV = inPlayV->rPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->rPrev;
				}
				tmpV = inPlayV->kPrev->kPrev->rPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->rPrev;
				}
				tmpV = inPlayV->oNext->oNext->rPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->rPrev;
				}
				//misc.
				triV.push_back(inPlayV->kPrev->kPrev->oNext);
				triV.push_back(inPlayV->oNext->oNext->pPrev);
			}
		}
		//2nd level secondary - other side
		if (inPlayV->gPrev->gPrev->gPrev != NULL && inPlayV->kNext->kNext->kNext != NULL) {
			if (inPlayV->gPrev->gPrev->gPrev->gPrev->getOccupier() == player
				&& inPlayV->kNext->kNext->kNext->kNext->getOccupier() == player) {
				//edge leg
				tmpV = inPlayV->kNext;
				while (tmpV->getDegrees() != 1) {
					triV.push_back(tmpV);
					tmpV = tmpV->kNext;
				}
				//color leg
				tmpV = inPlayV->gPrev;
				while (tmpV->gPrev != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->gPrev;
				}
				//primary lines
				tmpV = inPlayV->bPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->bPrev;
				}
				tmpV = inPlayV->kNext->kNext->bPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->bPrev;
				}
				tmpV = inPlayV->gPrev->gPrev->bPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->bPrev;
				}
				//misc.
				triV.push_back(inPlayV->kNext->kNext->gPrev);
				triV.push_back(inPlayV->gPrev->gPrev->pNext);
			}
		}
		//1st level primary
		if (inPlayV->bPrev->bPrev->bPrev != NULL
			&& inPlayV->yNext->yNext->yNext != NULL){
			if (inPlayV->bPrev->bPrev->bPrev->getOccupier() == player
				&& inPlayV->yNext->yNext->yNext->getOccupier() == player) {
				triV.push_back(inPlayV->gPrev);
				triV.push_back(inPlayV->gPrev->gPrev);
				triV.push_back(inPlayV->yNext);
				triV.push_back(inPlayV->yNext->yNext);
				triV.push_back(inPlayV->bPrev);
				triV.push_back(inPlayV->bPrev->bPrev);
			}
		}
		if (inPlayV->rPrev->rPrev->rPrev != NULL
			&& inPlayV->yNext->yNext->yNext != NULL) {
			if (inPlayV->rPrev->rPrev->rPrev->getOccupier() == player
				&& inPlayV->yNext->yNext->yNext->getOccupier() == player) {
				triV.push_back(inPlayV->rPrev);
				triV.push_back(inPlayV->rPrev->rPrev);
				triV.push_back(inPlayV->oNext);
				triV.push_back(inPlayV->oNext->oNext);
				triV.push_back(inPlayV->yNext);
				triV.push_back(inPlayV->yNext->yNext);
			}
		}

		//2nd level primary
		if (inPlayV->bPrev->bPrev->bPrev != NULL && inPlayV->yNext->yNext->yNext != NULL) {
			if (inPlayV->bPrev->bPrev->bPrev->bPrev->getOccupier() == player
				&& inPlayV->yNext->yNext->yNext->yNext->getOccupier() == player) {
				triV.push_back(inPlayV->bPrev);
				triV.push_back(inPlayV->bPrev->bPrev);
				triV.push_back(inPlayV->bPrev->bPrev->bPrev);
				triV.push_back(inPlayV->yNext);
				triV.push_back(inPlayV->yNext->yNext);
				triV.push_back(inPlayV->yNext->yNext->yNext);
				triV.push_back(inPlayV->gPrev);
				triV.push_back(inPlayV->gPrev->gPrev);
				triV.push_back(inPlayV->gPrev->gPrev->gPrev);
				triV.push_back(inPlayV->gPrev->gPrev->pNext);
				triV.push_back(inPlayV->gPrev->gPrev->bPrev);
				triV.push_back(inPlayV->gPrev->gPrev->yNext);
				triV.push_back(inPlayV->gPrev->gPrev->oNext);
			}
		}
		if (inPlayV->rPrev->rPrev->rPrev != NULL && inPlayV->yNext->yNext->yNext != NULL) {
			if (inPlayV->rPrev->rPrev->rPrev->rPrev->getOccupier() == player
				&& inPlayV->yNext->yNext->yNext->yNext->getOccupier() == player) {
				triV.push_back(inPlayV->rPrev);
				triV.push_back(inPlayV->rPrev->rPrev);
				triV.push_back(inPlayV->rPrev->rPrev->rPrev);
				triV.push_back(inPlayV->yNext);
				triV.push_back(inPlayV->yNext->yNext);
				triV.push_back(inPlayV->yNext->yNext->yNext);
				triV.push_back(inPlayV->oNext);
				triV.push_back(inPlayV->oNext->oNext);
				triV.push_back(inPlayV->oNext->oNext->pNext);
				triV.push_back(inPlayV->oNext->oNext->rNext);
				triV.push_back(inPlayV->oNext->oNext->oNext);
				triV.push_back(inPlayV->oNext->oNext->yPrev);
				triV.push_back(inPlayV->oNext->oNext->gNext);
			}
		}
		break;
	case 'g':
		//1st level secondary 
		if (inPlayV->kPrev->kPrev->getOccupier() == player
			&& inPlayV->pNext->pNext->getOccupier() == player) {
			triV.push_back(inPlayV->kPrev);
			triV.push_back(inPlayV->bPrev);
			triV.push_back(inPlayV->bPrev->bPrev);
			triV.push_back(inPlayV->pNext);
		}
		if (inPlayV->kNext->kNext->getOccupier() == player
			&& inPlayV->oPrev->oPrev->getOccupier() == player) {
			triV.push_back(inPlayV->kNext);
			triV.push_back(inPlayV->yPrev);
			triV.push_back(inPlayV->yPrev->yPrev);
			triV.push_back(inPlayV->oPrev);
		}
		//upside down 1st level secondary
		if (inPlayV->pNext->pNext->getOccupier() == player
			&& inPlayV->oPrev->oPrev->getOccupier() == player) {
			triV.push_back(inPlayV->pNext);
			triV.push_back(inPlayV->rNext);
			triV.push_back(inPlayV->rNext->rNext);
			triV.push_back(inPlayV->oPrev);
		}
		//2nd level secondary
		if (inPlayV->oPrev->oPrev->oPrev != NULL && inPlayV->kNext->kNext->kNext != NULL) {
			if (inPlayV->oPrev->oPrev->oPrev->oPrev->getOccupier() == player
				&& inPlayV->kNext->kNext->kNext->kNext->getOccupier() == player) {
				//edge leg
				tmpV = inPlayV->kNext;
				while (tmpV->getDegrees() != 1) {
					triV.push_back(tmpV);
					tmpV = tmpV->kNext;
				}
				//color leg
				tmpV = inPlayV->oPrev;
				while (tmpV->oPrev != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->oPrev;
				}
				//primary lines
				tmpV = inPlayV->yPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->yPrev;
				}
				tmpV = inPlayV->kNext->kNext->yPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->yPrev;
				}
				tmpV = inPlayV->oPrev->oPrev->yPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->yPrev;
				}
				//misc.
				triV.push_back(inPlayV->kNext->kNext->oPrev);
				triV.push_back(inPlayV->oPrev->oPrev->gNext);
			}
		}
		//2nd level secondary - other side
		if (inPlayV->pNext->pNext->pNext != NULL && inPlayV->kPrev->kPrev->kPrev != NULL) {
			if (inPlayV->pNext->pNext->pNext->pNext->getOccupier() == player
				&& inPlayV->kPrev->kPrev->kPrev->kPrev->getOccupier() == player) {
				//edge leg
				tmpV = inPlayV->kPrev;
				while (tmpV->getDegrees() != 1) {
					triV.push_back(tmpV);
					tmpV = tmpV->kPrev;
				}
				//color leg
				tmpV = inPlayV->pNext;
				while (tmpV->pNext != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->pNext;
				}
				//primary lines
				tmpV = inPlayV->bPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->bPrev;
				}
				tmpV = inPlayV->kPrev->kPrev->bPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->bPrev;
				}
				tmpV = inPlayV->pNext->pNext->bPrev;
				while (tmpV != NULL) {
					triV.push_back(tmpV);
					tmpV = tmpV->bPrev;
				}
				//misc.
				triV.push_back(inPlayV->kPrev->kPrev->pNext);
				triV.push_back(inPlayV->pNext->pNext->gPrev);
			}
		}
		//1st level primary
		if (inPlayV->bPrev->bPrev->bPrev != NULL
			&& inPlayV->rNext->rNext->rNext != NULL) {
			if (inPlayV->bPrev->bPrev->bPrev->getOccupier() == player
				&& inPlayV->rNext->rNext->rNext->getOccupier() == player) {
				triV.push_back(inPlayV->bPrev);
				triV.push_back(inPlayV->bPrev->bPrev);
				triV.push_back(inPlayV->pNext);
				triV.push_back(inPlayV->pNext->pNext);
				triV.push_back(inPlayV->rNext);
				triV.push_back(inPlayV->rNext->rNext);
			}
		}
		if (inPlayV->rNext->rNext->rNext != NULL
			&& inPlayV->yPrev->yPrev->yPrev != NULL) {
			if (inPlayV->rNext->rNext->rNext->getOccupier() == player
				&& inPlayV->yPrev->yPrev->yPrev->getOccupier() == player) {
				triV.push_back(inPlayV->rNext);
				triV.push_back(inPlayV->rNext->rNext);
				triV.push_back(inPlayV->oPrev);
				triV.push_back(inPlayV->oPrev->oPrev);
				triV.push_back(inPlayV->yPrev);
				triV.push_back(inPlayV->yPrev->yPrev);
			}
		}
	//2nd level primary
		if (inPlayV->bPrev->bPrev->bPrev != NULL
			&& inPlayV->rNext->rNext->rNext != NULL) {
			if (inPlayV->bPrev->bPrev->bPrev->bPrev->getOccupier() == player
				&& inPlayV->rNext->rNext->rNext->rNext->getOccupier() == player) {
				triV.push_back(inPlayV->bPrev);
				triV.push_back(inPlayV->bPrev->bPrev);
				triV.push_back(inPlayV->bPrev->bPrev->bPrev);
				triV.push_back(inPlayV->rNext);
				triV.push_back(inPlayV->rNext->rNext);
				triV.push_back(inPlayV->rNext->rNext->rNext);
				triV.push_back(inPlayV->pNext);
				triV.push_back(inPlayV->pNext->pNext);
				triV.push_back(inPlayV->pNext->pNext->gPrev);
				triV.push_back(inPlayV->pNext->pNext->bPrev);
				triV.push_back(inPlayV->pNext->pNext->pNext);
				triV.push_back(inPlayV->pNext->pNext->rNext);
				triV.push_back(inPlayV->pNext->pNext->oPrev);
			}
		}
		if (inPlayV->rNext->rNext->rNext != NULL
			&& inPlayV->yPrev->yPrev->yPrev != NULL){
			if (inPlayV->rNext->rNext->rNext->rNext->getOccupier() == player
				&& inPlayV->yPrev->yPrev->yPrev->yPrev->getOccupier() == player) {
				triV.push_back(inPlayV->rNext);
				triV.push_back(inPlayV->rNext->rNext);
				triV.push_back(inPlayV->rNext->rNext->rNext);
				triV.push_back(inPlayV->yPrev);
				triV.push_back(inPlayV->yPrev->yPrev);
				triV.push_back(inPlayV->yPrev->yPrev->yPrev);
				triV.push_back(inPlayV->oPrev);
				triV.push_back(inPlayV->oPrev->oPrev);
				triV.push_back(inPlayV->oPrev->oPrev->pNext);
				triV.push_back(inPlayV->oPrev->oPrev->rNext);
				triV.push_back(inPlayV->oPrev->oPrev->oPrev);
				triV.push_back(inPlayV->oPrev->oPrev->yPrev);
				triV.push_back(inPlayV->oPrev->oPrev->gNext);
			}
		}
		break;
	}
	return triV;
}