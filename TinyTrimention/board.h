#pragma once;
#include "Vertex.h"
#include "Vertex1D.h"
#include "Vertex3D.h"
#include "Vertex4D.h"
#include "Vertex6D.h"
#include "Vertex7D.h"
#include "Vertex12D.h"

using namespace std;

const int BOARDSIZE = 37;

class Board {
private:

//following declares an array of Vertex pointers
	Vertex **vertArray;
/*	Vertex1D *V1;
	Vertex3D *V2;
	Vertex6D *V3;
	Vertex3D *V4;
	Vertex7D *V5;
	Vertex4D *V6;
	Vertex7D *V7;
	Vertex3D *V8;
	Vertex6D *V9;
	Vertex4D *V10;
	Vertex6D *V11;
	Vertex4D *V12;
	Vertex6D *V13;
	Vertex3D *V14;
	Vertex7D *V15;
	Vertex4D *V16;
	Vertex12D *V17;
	Vertex4D *V18;
	Vertex7D *V19;
	Vertex3D *V20;
	Vertex6D *V21;
	Vertex4D *V22;
	Vertex6D *V23;
	Vertex4D *V24;
	Vertex6D *V25;
	Vertex4D *V26;
	Vertex6D *V27;
	Vertex4D *V28;
	Vertex6D *V29;
	Vertex3D *V30;
	Vertex1D *V31;
	Vertex3D *V32;
	Vertex7D *V33;
	Vertex3D *V34;
	Vertex7D *V35;
	Vertex3D *V36;
	Vertex1D *V37;
*/
	
public:
	Vertex* getVertex(int);
	Board();
//	Board(Vertex& vertex);
	~Board();
	
};