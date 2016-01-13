#pragma once;
#include "Vertex.h"
using namespace std;

class Vertex3D :
	public Vertex
{
public:
	Vertex3D();
	~Vertex3D();
	Vertex3D(int PIN, int xCoord, int yCoord,
		int degrees, char color);
	Vertex3D(Vertex& vertex);

	/*Vertex * kNext;
	Vertex * kPrev;
	Vertex * bNext;
	Vertex * rNext;
	Vertex * yNext;*/

	bool isBurned(Vertex*, Player*);
	void deleteBurns(Vertex *inPlayV, Player *player, bool defensive);
	vector<Vertex*> findTriangles(Vertex*inPlayV, Player *player);

private:
	char color;

};