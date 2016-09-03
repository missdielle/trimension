
#pragma once;
#include "Vertex.h"
using namespace std;

class Vertex1D : 
	public Vertex 
{
public:
	Vertex1D();
	~Vertex1D();
	Vertex1D(int PIN, int xCoord, int yCoord,
		int degrees, char color);
	Vertex1D(Vertex& vertex);

	//Vertex * kNext;
	//Vertex * kPrev;
	//Vertex * bPrev;
	//Vertex * rPrev;
	//Vertex * yPrev;

	bool isBurned(Vertex *inPlayV, Player *player);
	void deleteBurns(Vertex *inPlayV, Player *player, bool defensive);
	vector<Vertex*> findTriangles(Vertex*inPlayV, Player *player);

private:
	char color;

};