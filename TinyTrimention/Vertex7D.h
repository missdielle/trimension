#pragma once;
#include "Vertex.h"
using namespace std;

class Vertex7D :
	public Vertex
{
public:
	Vertex7D();
	~Vertex7D();
	Vertex7D(int PIN, int xCoord, int yCoord,
		int degrees, char color);
	Vertex7D(Vertex& vertex);

	bool isBurned(Vertex *inPlayV, Player *player);
	void deleteBurns(Vertex *inPlayV, Player *player, bool defensive);
	vector<Vertex*> findTriangles(Vertex*inPlayV, Player *player);

private:
	char color;

};