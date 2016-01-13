#pragma once;
#include "Player.h"
#include <vector>
using namespace std;



class Vertex {
protected:
	int PIN;		//# assigned to vertex
	Player *occupier;	//player whose pip is on vertex
	int xCoord;		//for graphics
	int yCoord;		//for graphics
	int degrees;	//determines createLine function
	int triX[3];	//count of how many triangles surround vertex
		//triX is array of triangle occupiers
		//ie [0] is player1's triangles
//	vector<Vertex*> triV;
		//created inside findTriangles method
		//used when looping thru and marking triX ++ or --
		//used in addTriangles and deleteTriangles
		//resets on each call to findTriangles

public:

//	Vertex* getV();			//??used

	Vertex * rNext;
	Vertex * rPrev;
	Vertex * yNext;
	Vertex * yPrev;
	Vertex * bNext;
	Vertex * bPrev;
	Vertex * kNext;
	Vertex * kPrev;
	Vertex * gNext;
	Vertex * gPrev;
	Vertex * oNext;
	Vertex * oPrev;
	Vertex * pNext;
	Vertex * pPrev;

	Vertex();
	Vertex(int PIN, int xCoord, int yCoord,
		int degrees);
	~Vertex();

	int getPIN();			//use in graphics? input uses vertArray
	Player* getOccupier();	//used everywhere
	int getDegrees();		//used in 4D deleteBurns
	void setOccupier(Player*);

	virtual bool isBurned(Vertex*, Player*) = 0;
		//checks if burned by OTHER player
		//overriding in subclasses
	
	virtual void deleteBurns(Vertex*, Player*, bool);
		//deletes pips that new play burns
		//overriding in subclasses

	virtual vector<Vertex*> findTriangles(Vertex*, Player*) = 0;
		//returns all verts inside triangle created
		//each vert added for each triangle it's in
		//overriding in subclasses

	bool isInsideTriX(Vertex*inPlayV, Player* player);
		//checks triX arrays for others' triangles
	void scoreTriPips(vector<Vertex*>, Player*, bool);
		//removes opponents' pips
	void addTriangles(vector<Vertex*>, Player*);
		//adds to triX arrays
	void deleteTriangles(vector<Vertex*>, Player*);
		//deletes from triX arrays
		//game.cpp changes occupier in placePip
	void scorePip(Player*player, Vertex *ptr, bool defensive);
		//checks if spot is NULL, add/deletes per strategy
};
