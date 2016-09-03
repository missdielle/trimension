#pragma once;
#include "Vertex.h"
using namespace std;

class Vertex6D :
	public Vertex
{
public:
	Vertex6D();
	~Vertex6D();
	Vertex6D(int PIN, int xCoord, int yCoord,
		int degrees);
	Vertex6D(Vertex& vertex);

	/*Vertex * rNext;
	Vertex * rPrev;
	Vertex * yNext;
	Vertex * yPrev;
	Vertex * bNext;
	Vertex * bPrev;
	Vertex * kNext;
	Vertex * kPrev;*/

	bool isBurned(Vertex*inPlayv, Player *player);
	void deleteBurns(Vertex *inPlayV, Player *player, bool defensive);
	vector<Vertex*> findTriangles(Vertex*inPlayV, Player *player);

private:


};