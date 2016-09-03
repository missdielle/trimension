#pragma once;
#include "Vertex.h"
using namespace std;

class Vertex12D :
	public Vertex
{
public:
	Vertex12D();
	~Vertex12D();
	Vertex12D(int PIN, int xCoord, int yCoord,
		int degrees);
	Vertex12D(Vertex& vertex);

	bool isBurned(Vertex *inPlayV, Player *player);
	void deleteBurns(Vertex *inPlayV, Player *player, bool defensive);
	vector<Vertex*> findTriangles(Vertex*inPlayV, Player *player);

private:


};