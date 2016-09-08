#include <stdio.h>
 #include "Vertex6D.h"

Vertex6D::Vertex6D() : Vertex() {}
Vertex6D::Vertex6D(int PIN, int xCoord, int yCoord,
	int degrees) : Vertex(PIN, xCoord, yCoord,
	degrees){
}
Vertex6D::~Vertex6D(){}
Vertex6D::Vertex6D(Vertex& vertex){}

bool Vertex6D::isBurned(Vertex *inPlayV, Player *player){
	bool result = false;
	if (inPlayV->rPrev->getOccupier()
		== inPlayV->bNext->getOccupier()
		&& inPlayV->rPrev->getOccupier()
		== inPlayV->yPrev->getOccupier()){
		if (inPlayV->rPrev->getOccupier() != player
			&& inPlayV->rPrev->getOccupier() != NULL)
			result = true;
	}

	if (inPlayV->yPrev->getOccupier()
		== inPlayV->rNext->getOccupier()
		&& inPlayV->yPrev->getOccupier()
		== inPlayV->bPrev->getOccupier()){
		if (inPlayV->yPrev->getOccupier() != player
			&& inPlayV->yPrev->getOccupier() != NULL)
			result = true;
	}

	if (inPlayV->bPrev->getOccupier()
		== inPlayV->yNext->getOccupier()
		&& inPlayV->bPrev->getOccupier()
		== inPlayV->rPrev->getOccupier()){
		if (inPlayV->bPrev->getOccupier() != player
			&& inPlayV->bPrev->getOccupier() != NULL)
			result = true;
	}

	if (inPlayV->bNext->getOccupier()
		== inPlayV->yPrev->getOccupier()
		&& inPlayV->bNext->getOccupier()
		== inPlayV->rNext->getOccupier()){
		if (inPlayV->bNext->getOccupier() != player
			&& inPlayV->bNext->getOccupier() != NULL)
			result = true;
	}

	if (inPlayV->rNext->getOccupier()
		== inPlayV->bPrev->getOccupier()
		&& inPlayV->rNext->getOccupier()
		== inPlayV->yNext->getOccupier()){
		if (inPlayV->rNext->getOccupier() != player
			&& inPlayV->rNext->getOccupier() != NULL)
			result = true;
	}

	if (inPlayV->yNext->getOccupier()
		== inPlayV->rPrev->getOccupier()
		&& inPlayV->yNext->getOccupier()
		== inPlayV->bNext->getOccupier()){
		if (inPlayV->yNext->getOccupier() != player
			&& inPlayV->yNext->getOccupier() != NULL)
			result = true;
	}

	return result;
}

void Vertex6D::deleteBurns(Vertex *inPlayV, Player *player, bool defensive) {

//analyze method--possible improvement if switch cases for degrees are rearranged
	//so the || parts work...or maybe not

//outside legs depend on degree of vertex
//12 degree doesn't need "||" since inside burns are lower down
//ifs lower down are inside burns that don't depend on degree

//outside legs burning shallow neighbors*********************need conditon for up or down pointing 6D
	if (inPlayV->rNext->getOccupier() == player) {
		switch (inPlayV->rNext->getDegrees()) {
		case 1:
			//no outside burns on 1 degree corners
			break;
		case 7:
			//if color == org or purp, only have to do half
			if (inPlayV->rNext->pPrev == NULL) {	//only works on side with orange
				if (inPlayV->rNext->yNext->getOccupier() == player) {
					if (inPlayV->bPrev->getOccupier() != NULL &&
						inPlayV->bPrev->getOccupier() != player) {
						scorePip(player, inPlayV->bPrev, defensive);
					}
				}
			}
			if (inPlayV->rNext->oNext == NULL) {	//only works on side with purple
				if (inPlayV->rNext->bNext->getOccupier() == player) {
					if (inPlayV->yPrev->getOccupier() != NULL &&
						inPlayV->yPrev->getOccupier() != player) {
						scorePip(player, inPlayV->yPrev, defensive);
					}
				}
			}
			break;
		case 12:
			if (inPlayV->rNext->yNext->getOccupier() == player
//				|| inPlayV->yNext->getOccupier() == player
				) {
				scorePip(player, inPlayV->bPrev, defensive);
			}
			if (inPlayV->rNext->bNext->getOccupier() == player
//				|| inPlayV->bNext->getOccupier() == player
				) {
				scorePip(player, inPlayV->yPrev, defensive);
			}
			break;
		}
	}
	if (inPlayV->yNext->getOccupier() == player) {
		switch (inPlayV->yNext->getDegrees()) {
		case 1:
			//no burns on corner
			break;
		case 7:
			//if color == org or green, only have to do half
			if (inPlayV->yNext->gNext == NULL) {	//only works on side with org
				if (inPlayV->yNext->rNext->getOccupier() == player) {
					if (inPlayV->bPrev->getOccupier() != NULL &&
						inPlayV->bPrev->getOccupier() != player) {
						scorePip(player, inPlayV->bPrev, defensive);
					}
				}
			}
			if (inPlayV->yNext->oPrev == NULL) {	//only works on side with grn
				if (inPlayV->yNext->bNext->getOccupier() == player) {
					if (inPlayV->rPrev->getOccupier() != NULL &&
						inPlayV->rPrev->getOccupier() != player) {
						scorePip(player, inPlayV->rPrev, defensive);
					}
				}
			}
			break;
		case 12:
			if (inPlayV->yNext->bNext->getOccupier() == player
//				|| inPlayV->bNext->getOccupier() == player
				) {
				scorePip(player, inPlayV->rPrev, defensive);
			}
			if (inPlayV->yNext->rNext->getOccupier() == player
//				|| inPlayV->rNext->getOccupier() == player
				) {
				scorePip(player, inPlayV->bPrev, defensive);
			}
			break;
		}
	}
	if (inPlayV->bNext->getOccupier() == player) {
		switch (inPlayV->bNext->getDegrees()) {
		case 1:
			//no burns
			break;
		case 7:
			//if color == pur or green, only have to do half
			if (inPlayV->bNext->pNext == NULL) {	//only works on side with grn
				if (inPlayV->bNext->yNext->getOccupier() == player) {
						scorePip(player, inPlayV->rPrev, defensive);
				}
			}
			if (inPlayV->bNext->gPrev == NULL) {	//only works on side with pur
				if (inPlayV->bNext->rNext->getOccupier() == player) {
						scorePip(player, inPlayV->yPrev, defensive);
				}
			}
			break;
		case 12:
			if (inPlayV->bNext->yNext->getOccupier() == player
//				|| inPlayV->yNext->getOccupier() == player
				) {
				scorePip(player, inPlayV->rPrev, defensive);
			}
			if (inPlayV->bNext->rNext->getOccupier() == player
//				|| inPlayV->rNext->getOccupier() == player
				) {
				scorePip(player, inPlayV->yPrev, defensive);
			}
			break;
		}
	}

	//This does below but only one direction
//outside legs burning acute neighbors
//again, don't need "||" since inside burns are lower down
//	if (inPlayV->rPrev->getOccupier() == player) {
//		if (inPlayV->rPrev->getDegrees() == 4) {
//			if (inPlayV->rPrev->rPrev->getOccupier() == player
////				|| inPlayV->bPrev->getOccupier() == player
//				) {
//				scorePip(player, inPlayV->yNext, defensive);
//			}
//			if (inPlayV->rPrev->rPrev->getOccupier() == player
////				|| inPlayV->yPrev->getOccupier() == player
//				) {
//				scorePip(player, inPlayV->bNext, defensive);
//			}
//		}
//	}
//	if (inPlayV->yPrev->getOccupier() == player) {
//		if (inPlayV->yPrev->getDegrees() == 4) {
//			if (inPlayV->yPrev->yPrev->getOccupier() == player
////				|| inPlayV->bPrev->getOccupier() == player
//				) {
//				scorePip(player, inPlayV->rNext, defensive);
//			}
//			if (inPlayV->yPrev->yPrev->getOccupier() == player
////				|| inPlayV->rPrev->getOccupier() == player
//				) {
//				scorePip(player, inPlayV->bNext, defensive);
//			}
//		}
//	}
//	if (inPlayV->bPrev->getOccupier() == player) {
//		if (inPlayV->bPrev->getDegrees() == 4) {
//			if (inPlayV->bPrev->bPrev->getOccupier() == player
////				|| inPlayV->yPrev->getOccupier() == player
//				) {
//				scorePip(player, inPlayV->rNext, defensive);
//			}
//			if (inPlayV->bPrev->bPrev->getOccupier() == player
////				|| inPlayV->rPrev->getOccupier() == player
//				) {
//				scorePip(player, inPlayV->yNext, defensive);
//			}
//		}
//	}

//three in a row on a primary line burns both sides
	//outside condition for pointing towards prev(down) or next(up)
//triangles pointing down
	if (inPlayV->yNext->getDegrees() == 4 || 
		inPlayV->yNext->getDegrees() == 3) {	//pointing down
		if (inPlayV->yNext->yNext != NULL && 
			inPlayV->yNext->getOccupier() == player &&
			inPlayV->yNext->yNext->getOccupier() == player) {
			scorePip(player, inPlayV->bPrev, defensive);
			scorePip(player, inPlayV->rPrev, defensive);
		}
		if (inPlayV->bNext->bNext != NULL && 
			inPlayV->bNext->getOccupier() == player && 
			inPlayV->bNext->bNext->getOccupier() == player) {
			scorePip(player, inPlayV->rPrev, defensive);
			scorePip(player, inPlayV->yPrev, defensive);
		}
		if (inPlayV->rNext->rNext != NULL &&
			inPlayV->rNext->getOccupier() == player &&
			inPlayV->rNext->rNext->getOccupier() == player) {
			scorePip(player, inPlayV->bPrev, defensive);
			scorePip(player, inPlayV->yPrev, defensive);
		}
	}

//triangles pointing up
	if (inPlayV->yPrev->getDegrees() == 4
		|| inPlayV->yPrev->getDegrees() == 3) {
		if (inPlayV->yPrev->yPrev != NULL && 
			inPlayV->yPrev->getOccupier() == player &&
			inPlayV->yPrev->yPrev->getOccupier() == player) {
			scorePip(player, inPlayV->bNext, defensive);
			scorePip(player, inPlayV->rNext, defensive);
		}
		if (inPlayV->bPrev->bPrev != NULL && 
			inPlayV->bPrev->getOccupier() == player &&
			inPlayV->bPrev->bPrev->getOccupier() == player) {
			scorePip(player, inPlayV->rNext, defensive);
			scorePip(player, inPlayV->yNext, defensive);
		}
		if (inPlayV->rPrev->rPrev != NULL && 
			inPlayV->rPrev->getOccupier() == player &&
			inPlayV->rPrev->rPrev->getOccupier() == player) {
			scorePip(player, inPlayV->bNext, defensive);
			scorePip(player, inPlayV->yNext, defensive);
		}
	}

//inside burns of acute neighbors
	if (inPlayV->yPrev->getOccupier() == player &&
		inPlayV->rPrev->getOccupier() == player) {
		scorePip(player, inPlayV->bNext, defensive);
	}
	if (inPlayV->rPrev->getOccupier() == player &&
		inPlayV->bPrev->getOccupier() == player) {
		scorePip(player, inPlayV->yNext, defensive);
	}
	if (inPlayV->bPrev->getOccupier() == player &&
		inPlayV->yPrev->getOccupier() == player) {
		scorePip(player, inPlayV->rNext, defensive);
	}

//inside burns of shallow neighbors
	if (inPlayV->rNext->getOccupier() == player &&
		inPlayV->bNext->getOccupier() == player) {
		scorePip(player, inPlayV->yPrev, defensive);
	}
	if (inPlayV->bNext->getOccupier() == player &&
		inPlayV->yNext->getOccupier() == player) {
		scorePip(player, inPlayV->rPrev, defensive);
	}
	if (inPlayV->yNext->getOccupier() == player &&
		inPlayV->rNext->getOccupier() == player) {
		scorePip(player, inPlayV->bPrev, defensive);
	}

//when inPlay is a side leg of a burn
	//if prime prev == 4 or 3  is upright triangle
	//if prime next == 4 or 3  is downward triangle

	if (inPlayV->rPrev->getDegrees() == 3 || 
		inPlayV->rPrev->getDegrees() == 4) {
		if (inPlayV->rPrev->rPrev != NULL && 
			inPlayV->rPrev->rPrev->getOccupier() == player) {
			if (inPlayV->yNext->getOccupier() == player
				|| inPlayV->bNext->getOccupier() == player) {
				scorePip(player, inPlayV->rPrev, defensive);
			}
		}
	}
	if (inPlayV->bPrev->getDegrees() == 3 || 
		inPlayV->bPrev->getDegrees() == 4) {
		if (inPlayV->bPrev->bPrev != NULL && 
			inPlayV->bPrev->bPrev->getOccupier() == player) {
			if (inPlayV->yNext->getOccupier() == player
				|| inPlayV->rNext->getOccupier() == player) {
				scorePip(player, inPlayV->bPrev, defensive);
			}
		}
	}
	if (inPlayV->yPrev->getDegrees() == 3 || 
		inPlayV->yPrev->getDegrees() == 4) {
		if (inPlayV->yPrev->yPrev != NULL && 
			inPlayV->yPrev->yPrev->getOccupier() == player) {
			if (inPlayV->rNext->getOccupier() == player
				|| inPlayV->bNext->getOccupier() == player) {
				scorePip(player, inPlayV->yPrev, defensive);
			}
		}
	}
	
	if (inPlayV->rNext->getDegrees() == 3 || 
		inPlayV->rNext->getDegrees() == 4) {
		if (inPlayV->rNext->rNext != NULL && 
			inPlayV->rNext->rNext->getOccupier() == player) {
			if (inPlayV->yPrev->getOccupier() == player
				|| inPlayV->bPrev->getOccupier() == player) {
				scorePip(player, inPlayV->rNext, defensive);
			}
		}
	}
	if (inPlayV->bNext->getDegrees() == 3 || 
		inPlayV->bNext->getDegrees() == 4) {
		if (inPlayV->bNext->bNext != NULL && 
			inPlayV->bNext->bNext->getOccupier() == player) {
			if (inPlayV->yPrev->getOccupier() == player
				|| inPlayV->rPrev->getOccupier() == player) {
				scorePip(player, inPlayV->bNext, defensive);
			}
		}
	}
	if (inPlayV->yNext->getDegrees() == 3 || 
		inPlayV->yNext->getDegrees() == 4) {
		if (inPlayV->yNext->yNext != NULL && 
			inPlayV->yNext->yNext->getOccupier() == player) {
			if (inPlayV->rPrev->getOccupier() == player
				|| inPlayV->bPrev->getOccupier() == player) {
				scorePip(player, inPlayV->yNext, defensive);
			}
		}
	}





/*
	if (inPlayV->rNext->getOccupier()== player 
		&& inPlayV->yNext->getOccupier() == player 
		&& inPlayV->bPrev->getOccupier() != player)
		{
			inPlayV->bPrev->setOccupier(NULL);
			//d game means -- the owners of the pips
			//o game means ++ the current player
			if (defensive == true){
				inPlayV->bPrev->getOccupier()->removePip(player);
			}
			else
				player->addPip(player);
	}

	if (inPlayV->bPrev->getOccupier()
		== player &&
		inPlayV->yPrev->getOccupier()
		== player &&
		inPlayV->rNext->getOccupier()
		!= player) {
		inPlayV->rNext->setOccupier(NULL);
		if (defensive == true){
			inPlayV->rNext->
				getOccupier()->removePip(player);
		}
		else
			player->addPip(player);
	}
	if (inPlayV->rNext->getOccupier()
		== player &&
		inPlayV->bNext->getOccupier()
		== player &&
		inPlayV->yPrev->getOccupier()
		!= player){
		inPlayV->yPrev->setOccupier(NULL);
		if (defensive == true){
			inPlayV->yPrev->
				getOccupier()->removePip(player);
		}
		else
			player->addPip(player);
	}

	if (inPlayV->yPrev->getOccupier()
		== player &&
		inPlayV->rPrev->getOccupier()
		== player &&
		inPlayV->bNext->getOccupier()
		!= player){
		inPlayV->bNext->setOccupier(NULL);
		if (defensive == true){
			inPlayV->bNext->
				getOccupier()->removePip(player);
		}
		else
			player->addPip(player);
	}

	if (inPlayV->bNext->getOccupier()
		== player &&
		inPlayV->yNext->getOccupier()
		== player &&
		inPlayV->rPrev->getOccupier()
		!= player){
		inPlayV->rPrev->setOccupier(NULL);
		if (defensive == true){
			inPlayV->rPrev->
				getOccupier()->removePip(player);
		}
		else
			player->addPip(player);
	}

	if (inPlayV->rPrev->getOccupier()
		== player &&
		inPlayV->bPrev->getOccupier()
		== player &&
		inPlayV->yNext->getOccupier()
		!= player){
		inPlayV->yNext->setOccupier(NULL);
		if (defensive == true){
			inPlayV->yNext->
				getOccupier()->removePip(player);
		}
		else
			player->addPip(player);
	}
	*/
	//check if it created any triangles
	//Vertex::findTriangles(Vertex*,Player);
	//if so, Vertex::deleteTriangles(player); 
}

vector<Vertex*> Vertex6D::findTriangles(Vertex*inPlayV, Player *player){
	vector<Vertex*> triV;
//corners don't make any triangles, so return triV empty
	if (inPlayV->yNext->getDegrees() == 1
		|| inPlayV->bNext->getDegrees() == 1
		|| inPlayV->rNext->getDegrees() == 1) {
		return triV;
	}
//around a 12D - 12 cases
	else if (inPlayV->yNext->getDegrees() == 12) {
		if (inPlayV->yNext->yNext->getOccupier() == player &&
			inPlayV->bPrev->bPrev->bPrev->getOccupier() == player) {
			triV.push_back(inPlayV->yNext->gPrev);
			triV.push_back(inPlayV->yNext->bPrev);
			triV.push_back(inPlayV->yNext->pNext);
			triV.push_back(inPlayV->yNext->rNext);
			triV.push_back(inPlayV->yNext->oPrev);
			triV.push_back(inPlayV->yNext);
		}
		if (inPlayV->yNext->yNext->getOccupier() == player &&
			inPlayV->rPrev->rPrev->rPrev->getOccupier() == player) {
			triV.push_back(inPlayV->yNext->oNext);
			triV.push_back(inPlayV->yNext->rPrev);
			triV.push_back(inPlayV->yNext->pPrev);
			triV.push_back(inPlayV->yNext->bNext);
			triV.push_back(inPlayV->yNext->gNext);
			triV.push_back(inPlayV->yNext);
		}

	}
	else if (inPlayV->rNext->getDegrees() == 12) {
		if (inPlayV->rNext->rNext->getOccupier() == player &&
			inPlayV->yPrev->yPrev->yPrev->getOccupier() == player) {
			triV.push_back(inPlayV->rNext->pPrev);
			triV.push_back(inPlayV->rNext->bNext);
			triV.push_back(inPlayV->rNext->gNext);
			triV.push_back(inPlayV->rNext->yPrev);
			triV.push_back(inPlayV->rNext->oPrev);
			triV.push_back(inPlayV->rNext);
		}
		if (inPlayV->rNext->rNext->getOccupier() == player &&
			inPlayV->bPrev->bPrev->bPrev->getOccupier() == player) {
			triV.push_back(inPlayV->rNext->oNext);
			triV.push_back(inPlayV->rNext->yNext);
			triV.push_back(inPlayV->rNext->gPrev);
			triV.push_back(inPlayV->rNext->bPrev);
			triV.push_back(inPlayV->rNext->pNext);
			triV.push_back(inPlayV->rNext);
		}
	}
	
	else if (inPlayV->bNext->getDegrees() == 12) {
		if (inPlayV->bNext->bNext->getOccupier() == player &&
			inPlayV->yPrev->yPrev->yPrev->getOccupier() == player) {
			triV.push_back(inPlayV->bNext->pNext);
			triV.push_back(inPlayV->bNext->rNext);
			triV.push_back(inPlayV->bNext->oPrev);
			triV.push_back(inPlayV->bNext->yPrev);
			triV.push_back(inPlayV->bNext->gNext);
			triV.push_back(inPlayV->bNext);
		}
		if (inPlayV->bNext->bNext->getOccupier() == player &&
			inPlayV->rPrev->rPrev->rPrev->getOccupier() == player) {
			triV.push_back(inPlayV->bNext->gPrev);
			triV.push_back(inPlayV->bNext->yNext);
			triV.push_back(inPlayV->bNext->oNext);
			triV.push_back(inPlayV->bNext->rPrev);
			triV.push_back(inPlayV->bNext->pPrev);
			triV.push_back(inPlayV->bNext);
		}
	}
	
	else if (inPlayV->yPrev->getDegrees() == 12) {
		if (inPlayV->yPrev->yPrev->getOccupier() == player &&
			inPlayV->bNext->bNext->bNext->getOccupier() == player) {
			triV.push_back(inPlayV->yPrev->oNext);
			triV.push_back(inPlayV->yPrev->rPrev);
			triV.push_back(inPlayV->yPrev->pPrev);
			triV.push_back(inPlayV->yPrev->bNext);
			triV.push_back(inPlayV->yPrev->gNext);
			triV.push_back(inPlayV->yPrev);
		}
		if (inPlayV->yPrev->yPrev->getOccupier() == player &&
			inPlayV->rNext->rNext->rNext->getOccupier() == player){
			triV.push_back(inPlayV->yPrev->gPrev);
			triV.push_back(inPlayV->yPrev->bPrev);
			triV.push_back(inPlayV->yPrev->pNext);
			triV.push_back(inPlayV->yPrev->rNext);
			triV.push_back(inPlayV->yPrev->oPrev);
			triV.push_back(inPlayV->yPrev);
		}
	}
	else if (inPlayV->rPrev->getDegrees() == 12) {
		if (inPlayV->rPrev->rPrev->getOccupier() == player &&
			inPlayV->yNext->yNext->yNext->getOccupier() == player) {
			triV.push_back(inPlayV->rPrev->oNext);
			triV.push_back(inPlayV->rPrev->yNext);
			triV.push_back(inPlayV->rPrev->gPrev);
			triV.push_back(inPlayV->rPrev->bPrev);
			triV.push_back(inPlayV->rPrev->pNext);
			triV.push_back(inPlayV->rPrev);
		}
		if (inPlayV->rPrev->rPrev->getOccupier() == player &&
			inPlayV->bNext->bNext->bNext->getOccupier() == player) {
			triV.push_back(inPlayV->rPrev->pPrev);
			triV.push_back(inPlayV->rPrev->bNext);
			triV.push_back(inPlayV->rPrev->gNext);
			triV.push_back(inPlayV->rPrev->yPrev);
			triV.push_back(inPlayV->rPrev->oPrev);
			triV.push_back(inPlayV->rPrev);
		}
	}
	else if (inPlayV->bPrev->getDegrees() == 12) {
		if (inPlayV->bPrev->bPrev->getOccupier() == player &&
			inPlayV->yNext->yNext->yNext->getOccupier() == player) {
			triV.push_back(inPlayV->bPrev->pPrev);
			triV.push_back(inPlayV->bPrev->rPrev);
			triV.push_back(inPlayV->bPrev->oNext);
			triV.push_back(inPlayV->bPrev->yNext);
			triV.push_back(inPlayV->bPrev->gPrev);
			triV.push_back(inPlayV->bPrev);
		}
		if (inPlayV->bPrev->bPrev->getOccupier() == player &&
			inPlayV->rNext->rNext->rNext->getOccupier() == player) {
			triV.push_back(inPlayV->bPrev->gNext);
			triV.push_back(inPlayV->bPrev->yPrev);
			triV.push_back(inPlayV->bPrev->oPrev);
			triV.push_back(inPlayV->bPrev->rNext);
			triV.push_back(inPlayV->bPrev->pNext);
			triV.push_back(inPlayV->bPrev);
		}
	}
	return triV;
}