#pragma once;
#include "Vertex.h"
using namespace std;

class Vertex4D :
	public Vertex
{
public:
	Vertex4D();
	~Vertex4D();
	Vertex4D(int PIN, int xCoord, int yCoord,
		int degrees, char color);
	Vertex4D(Vertex& vertex);

	bool isBurned(Vertex *inPlayV, Player *player);
	void deleteBurns(Vertex *inPlayV, Player *player, bool defensive);
	vector<Vertex*> findTriangles(Vertex*inPlayV, Player *player);

private:
	char color;

};