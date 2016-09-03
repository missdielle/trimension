#include <stdio.h>
#include "board.h"

using namespace std;


Board::Board(){

	vertArray = new Vertex*[BOARDSIZE];

//making vertices and then putting them into an array causes 
//broken pointers down the road
	//V1 = new Vertex1D(1, 100, 100, 1, 'y');
	//V2 = new Vertex3D(2, 150, 200, 3, 'b');
	//V3 = new Vertex6D(3, 200, 167, 6);
	//V4 = new Vertex3D(4, 200, 100, 3, 'r');
	//V5 = new Vertex7D(5, 200, 300, 7, 'o');
	//V6 = new Vertex4D(6, 233, 200, 4, 'p');
	//V7 = new Vertex7D(7, 300, 100, 7, 'g');
	//V8 = new Vertex3D(8, 250, 400, 3, 'b');
	//V9 = new Vertex6D(9, 300, 367, 6);
	//V10 = new Vertex4D(10, 300, 300, 4, 'g');
	//V11 = new Vertex6D(11, 300, 233, 6);
	//V12 = new Vertex4D(12, 350, 200, 4, 'o');
	//V13 = new Vertex6D(13, 400, 167, 6);
	//V14 = new Vertex3D(14, 400, 100, 3, 'r');
	//V15 = new Vertex7D(15, 300, 500, 7, 'o');
	//V16 = new Vertex4D(16, 350, 400, 4, 'p');
	//V17 = new Vertex12D(17, 400, 300, 12);
	//V18 = new Vertex4D(18, 450, 200, 4, 'p');
	//V19 = new Vertex7D(19, 500, 100, 7, 'g');
	//V20 = new Vertex3D(20, 350, 600, 3, 'b');
	//V21 = new Vertex6D(21, 450, 567, 6);
	//V22 = new Vertex4D(22, 400, 500, 4, 'g');
	//V23 = new Vertex6D(23, 400, 433, 6);
	//V24 = new Vertex4D(24, 450, 400, 4, 'o');
	//V25 = new Vertex6D(25, 500, 367, 6);
	//V26 = new Vertex4D(26, 500, 300, 4, 'g');
	//V27 = new Vertex6D(27, 500, 233, 6);
	//V28 = new Vertex4D(28, 550, 200, 4, 'o');
	//V29 = new Vertex6D(29, 600, 167, 6);
	//V30 = new Vertex3D(30, 600, 100, 3, 'r');
	//V31 = new Vertex1D(31, 400, 700, 1, 'r');
	//V32 = new Vertex3D(32, 450, 600, 3, 'y');
	//V33 = new Vertex7D(33, 500, 500, 7, 'p');
	//V34 = new Vertex3D(34, 550, 400, 3, 'y');
	//V35 = new Vertex7D(35, 600, 300, 7, 'p');
	//V36 = new Vertex3D(36, 650, 200, 3, 'y');
	//V37 = new Vertex1D(37, 700, 100, 1, 'b');

//create an array of vertices  (index+1 == PIN)
	vertArray[0] = new Vertex1D(1, 100, 100, 1, 'y');
	vertArray[1] = new Vertex3D(2, 150, 200, 3, 'b');
	vertArray[2] = new Vertex6D(3, 200, 167, 6);
	vertArray[3]= new Vertex3D(4, 200, 100, 3, 'r');
	vertArray[4] = new Vertex7D(5, 200, 300, 7, 'o');
	vertArray[5] = new Vertex4D(6, 233, 200, 4, 'p');
	vertArray[6] = new Vertex7D(7, 300, 100, 7, 'g');
	vertArray[7] = new Vertex3D(8, 250, 400, 3, 'b');
	vertArray[8] = new Vertex6D(9, 300, 367, 6);
	vertArray[9] = new Vertex4D(10, 300, 300, 4, 'g');
	vertArray[10] = new Vertex6D(11, 300, 233, 6);
	vertArray[11] = new Vertex4D(12, 350, 200, 4, 'o');
	vertArray[12] = new Vertex6D(13, 400, 167, 6);
	vertArray[13] = new Vertex3D(14, 400, 100, 3, 'r');
	vertArray[14] = new Vertex7D(15, 300, 500, 7, 'o');
	vertArray[15] = new Vertex4D(16, 350, 400, 4, 'p');
	vertArray[16] = new Vertex12D(17, 400, 300, 12);
	vertArray[17] = new Vertex4D(18, 450, 200, 4, 'p');
	vertArray[18] = new Vertex7D(19, 500, 100, 7, 'g');
	vertArray[19] = new Vertex3D(20, 350, 600, 3, 'b');
	vertArray[20] = new Vertex6D(21, 450, 567, 6);
	vertArray[21] = new Vertex4D(22, 400, 500, 4, 'g');
	vertArray[22] = new Vertex6D(23, 400, 433, 6);
	vertArray[23] = new Vertex4D(24, 450, 400, 4, 'o');
	vertArray[24] = new Vertex6D(25, 500, 367, 6);
	vertArray[25] = new Vertex4D(26, 500, 300, 4, 'g');
	vertArray[26] = new Vertex6D(27, 500, 233, 6);
	vertArray[27] = new Vertex4D(28, 550, 200, 4, 'o');
	vertArray[28] = new Vertex6D(29, 600, 167, 6);
	vertArray[29] = new Vertex3D(30, 600, 100, 3, 'r');
	vertArray[30] = new Vertex1D(31, 400, 700, 1, 'r');
	vertArray[31] = new Vertex3D(32, 450, 600, 3, 'y');
	vertArray[32] = new Vertex7D(33, 500, 500, 7, 'p');
	vertArray[33] = new Vertex3D(34, 550, 400, 3, 'y');
	vertArray[34] = new Vertex7D(35, 600, 300, 7, 'p');
	vertArray[35] = new Vertex3D(36, 650, 200, 3, 'y');
	vertArray[36] = new Vertex1D(37, 700, 100, 1, 'b');

//let's put them into an array for easy access:
//	Vertex* vertArray[BOARDSIZE];//in board.h now
	//vertArray[0] = V1;
	//vertArray[1] = V2;
	//vertArray[2] = V3;
	//vertArray[3] = V4;
	//vertArray[4] = V5;
	//vertArray[5] = V6;
	//vertArray[6] = V7;
	//vertArray[7] = V8;
	//vertArray[8] = V9;
	//vertArray[9] = V10;
	//vertArray[10] = V11;
	//vertArray[11] = V12;
	//vertArray[12] = V13;
	//vertArray[13] = V14;
	//vertArray[14] = V15;
	//vertArray[15] = V16;
	//vertArray[16] = V17;
	//vertArray[17] = V18;
	//vertArray[18] = V19;
	//vertArray[19] = V20;
	//vertArray[20] = V21;
	//vertArray[21] = V22;
	//vertArray[22] = V23;
	//vertArray[23] = V24;
	//vertArray[24] = V25;
	//vertArray[25] = V26;
	//vertArray[26] = V27;
	//vertArray[27] = V28;
	//vertArray[28] = V29;
	//vertArray[29] = V30;
	//vertArray[30] = V31;
	//vertArray[31] = V32;
	//vertArray[32] = V33;
	//vertArray[33] = V34;
	//vertArray[34] = V35;
	//vertArray[35] = V36;
	//vertArray[36] = V37;

	//now let's create the lines:

//red lines
	vertArray[3]->rNext = vertArray[2];//4.3
	vertArray[2]->rPrev = vertArray[3];//3.4
	vertArray[2]->rNext = vertArray[4];//3.5
	vertArray[4]->rPrev = vertArray[2];//5.3

	vertArray[6]->rNext = vertArray[10];//7.11
	vertArray[10]->rPrev = vertArray[6];//11.7
	vertArray[10]->rNext = vertArray[9];//11.10
	vertArray[9]->rPrev = vertArray[10];//10.11
	vertArray[9]->rNext = vertArray[8];//10.9
	vertArray[8]->rPrev = vertArray[9];//9.10
	vertArray[8]->rNext = vertArray[14];//9.15
	vertArray[14]->rPrev = vertArray[8];//15.9

	vertArray[13]->rNext = vertArray[12];
	vertArray[12]->rPrev = vertArray[13];
	vertArray[12]->rNext = vertArray[16];
	vertArray[16]->rPrev = vertArray[12];
	vertArray[16]->rNext = vertArray[22];
	vertArray[22]->rPrev = vertArray[16];
	vertArray[22]->rNext = vertArray[21];
	vertArray[21]->rPrev = vertArray[22];
	vertArray[21]->rNext = vertArray[20];
	vertArray[20]->rPrev = vertArray[21];
	vertArray[20]->rNext = vertArray[30];
	vertArray[30]->rPrev = vertArray[20];

	vertArray[18]->rNext = vertArray[26];
	vertArray[26]->rPrev = vertArray[18];
	vertArray[26]->rNext = vertArray[25];
	vertArray[25]->rPrev = vertArray[26];
	vertArray[25]->rNext = vertArray[24];
	vertArray[24]->rPrev = vertArray[25];
	vertArray[24]->rNext = vertArray[32];
	vertArray[32]->rPrev = vertArray[24];

	vertArray[29]->rNext = vertArray[28];
	vertArray[28]->rPrev = vertArray[29];
	vertArray[28]->rNext = vertArray[34];
	vertArray[34]->rPrev = vertArray[28];

//yellow lines
	vertArray[35]->yNext = vertArray[28];
	vertArray[28]->yPrev = vertArray[35];
	vertArray[28]->yNext = vertArray[18];
	vertArray[18]->yPrev = vertArray[28];

	vertArray[34]->yNext = vertArray[26];
	vertArray[26]->yPrev = vertArray[34];
	vertArray[26]->yNext = vertArray[17];
	vertArray[17]->yPrev = vertArray[26];
	vertArray[17]->yNext = vertArray[12];
	vertArray[12]->yPrev = vertArray[17];
	vertArray[12]->yNext = vertArray[6];
	vertArray[6]->yPrev = vertArray[12];

	vertArray[33]->yNext = vertArray[24];
	vertArray[24]->yPrev = vertArray[33];
	vertArray[24]->yNext = vertArray[16];
	vertArray[16]->yPrev = vertArray[24];
	vertArray[16]->yNext = vertArray[10];
	vertArray[10]->yPrev = vertArray[16];
	vertArray[10]->yNext = vertArray[5];
	vertArray[5]->yPrev = vertArray[10];
	vertArray[5]->yNext = vertArray[2];
	vertArray[2]->yPrev = vertArray[5];
	vertArray[2]->yNext = vertArray[0];
	vertArray[0]->yPrev = vertArray[2];

	vertArray[32]->yNext = vertArray[22];
	vertArray[22]->yPrev = vertArray[32];
	vertArray[22]->yNext = vertArray[15];
	vertArray[15]->yPrev = vertArray[22];
	vertArray[15]->yNext = vertArray[8];
	vertArray[8]->yPrev = vertArray[15];
	vertArray[8]->yNext = vertArray[4];
	vertArray[4]->yPrev = vertArray[8];

	vertArray[31]->yNext = vertArray[20];
	vertArray[20]->yPrev = vertArray[31];
	vertArray[20]->yNext = vertArray[14];
	vertArray[14]->yPrev = vertArray[20];
		
//blue lines
	vertArray[19]->bNext = vertArray[20];
	vertArray[20]->bPrev = vertArray[19];
	vertArray[20]->bNext = vertArray[32];
	vertArray[32]->bPrev = vertArray[20];

	vertArray[14]->bNext = vertArray[22];
	vertArray[22]->bPrev = vertArray[14];
	vertArray[22]->bNext = vertArray[23];
	vertArray[23]->bPrev = vertArray[22];
	vertArray[23]->bNext = vertArray[24];
	vertArray[24]->bPrev = vertArray[23];
	vertArray[24]->bNext = vertArray[34];
	vertArray[34]->bPrev = vertArray[24];

	vertArray[7]->bNext = vertArray[8];
	vertArray[8]->bPrev = vertArray[7];
	vertArray[8]->bNext = vertArray[16];
	vertArray[16]->bPrev = vertArray[8];
	vertArray[16]->bNext = vertArray[26];
	vertArray[26]->bPrev = vertArray[16];
	vertArray[26]->bNext = vertArray[27];
	vertArray[27]->bPrev = vertArray[26];
	vertArray[27]->bNext = vertArray[28];
	vertArray[28]->bPrev = vertArray[27];
	vertArray[28]->bNext = vertArray[36];
	vertArray[36]->bPrev = vertArray[28];

	vertArray[4]->bNext = vertArray[10];
	vertArray[10]->bPrev = vertArray[4];
	vertArray[10]->bNext = vertArray[11];
	vertArray[11]->bPrev = vertArray[10];
	vertArray[11]->bNext = vertArray[12];
	vertArray[12]->bPrev = vertArray[11];
	vertArray[12]->bNext = vertArray[18];
	vertArray[18]->bPrev = vertArray[12];
		
	vertArray[1]->bNext = vertArray[2];
	vertArray[2]->bPrev = vertArray[1];
	vertArray[2]->bNext = vertArray[6];
	vertArray[6]->bPrev = vertArray[2];

//green lines
	vertArray[14]->gNext = vertArray[21];//15.22
	vertArray[21]->gPrev = vertArray[14];//22.15
	vertArray[21]->gNext = vertArray[32];//22.33
	vertArray[32]->gPrev = vertArray[21];//33.22

	vertArray[4]->gNext = vertArray[9];
	vertArray[9]->gPrev = vertArray[4];
	vertArray[9]->gNext = vertArray[16];
	vertArray[16]->gPrev = vertArray[9];
	vertArray[16]->gNext = vertArray[25];
	vertArray[25]->gPrev = vertArray[16];
	vertArray[25]->gNext = vertArray[34];
	vertArray[34]->gPrev = vertArray[25];

/* this will be green if/when a bigger board
	vertArray[0]->gNext = vertArray[3];
	vertArray[3]->gPrev = vertArray[0];
	vertArray[3]->gNext = vertArray[6];
	vertArray[6]->gPrev = vertArray[3];
	vertArray[6]->gNext = vertArray[13];
	vertArray[13]->gPrev = vertArray[6];
	vertArray[13]->gNext = vertArray[18];
	vertArray[18]->gPrev = vertArray[13];
	vertArray[18]->gNext = vertArray[29];
	vertArray[29]->gPrev = vertArray[18];
	vertArray[29]->gNext = vertArray[36];
	vertArray[36]->gPrev = vertArray[29];
*/

//orange lines
	vertArray[34]->oNext = vertArray[27];
	vertArray[27]->oPrev = vertArray[34];
	vertArray[27]->oNext = vertArray[18];
	vertArray[18]->oPrev = vertArray[27];

	vertArray[32]->oNext = vertArray[23];
	vertArray[23]->oPrev = vertArray[32];
	vertArray[23]->oNext = vertArray[16];
	vertArray[16]->oPrev = vertArray[23];
	vertArray[16]->oNext = vertArray[11];
	vertArray[11]->oPrev = vertArray[16];
	vertArray[11]->oNext = vertArray[6];
	vertArray[6]->oPrev = vertArray[11];

/* This will be used if/when bigger board
	vertArray[30]->oNext = vertArray[19];
	vertArray[19]->oPrev = vertArray[30];
	vertArray[19]->oNext = vertArray[14];
	vertArray[14]->oPrev = vertArray[19];
	vertArray[14]->oNext = vertArray[7];
	vertArray[7]->oPrev = vertArray[14];
	vertArray[7]->oNext = vertArray[4];
	vertArray[4]->oPrev = vertArray[7];
	vertArray[4]->oNext = vertArray[1];
	vertArray[1]->oPrev = vertArray[4];
	vertArray[1]->oNext = vertArray[0];
	vertArray[0]->oPrev = vertArray[1];
*/

//purple lines
	vertArray[6]->pNext = vertArray[5];
	vertArray[5]->pPrev = vertArray[6];
	vertArray[5]->pNext = vertArray[4];
	vertArray[4]->pPrev = vertArray[5];

	vertArray[18]->pNext = vertArray[17];
	vertArray[17]->pPrev = vertArray[18];
	vertArray[17]->pNext = vertArray[16];
	vertArray[16]->pPrev = vertArray[17];
	vertArray[16]->pNext = vertArray[15];
	vertArray[15]->pPrev = vertArray[16];
	vertArray[15]->pNext = vertArray[14];
	vertArray[14]->pPrev = vertArray[15];

/* these will be used if/when board is bigger
	vertArray[36]->pNext = vertArray[35];
	vertArray[35]->pPrev = vertArray[36];
	vertArray[35]->pNext = vertArray[34];
	vertArray[34]->pPrev = vertArray[35];
	vertArray[34]->pNext = vertArray[33];
	vertArray[33]->pPrev = vertArray[34];
	vertArray[33]->pNext = vertArray[32];
	vertArray[32]->pPrev = vertArray[33];
	vertArray[32]->pNext = vertArray[31];
	vertArray[31]->pPrev = vertArray[32];
	vertArray[31]->pNext = vertArray[30];
	vertArray[30]->pPrev = vertArray[31];
*/

//black lines
	vertArray[0]->kNext = vertArray[3];
	vertArray[3]->kPrev = vertArray[0];
	vertArray[3]->kNext = vertArray[6];
	vertArray[6]->kPrev = vertArray[3];
	vertArray[6]->kNext = vertArray[13];
	vertArray[13]->kPrev = vertArray[6];
	vertArray[13]->kNext = vertArray[18];
	vertArray[18]->kPrev = vertArray[13];
	vertArray[18]->kNext = vertArray[29];
	vertArray[29]->kPrev = vertArray[18];
	vertArray[29]->kNext = vertArray[36];
	vertArray[36]->kPrev = vertArray[29];
	vertArray[36]->kNext = vertArray[35];
	vertArray[35]->kPrev = vertArray[36];
	vertArray[35]->kNext = vertArray[34];
	vertArray[34]->kPrev = vertArray[35];
	vertArray[34]->kNext = vertArray[33];
	vertArray[33]->kPrev = vertArray[34];
	vertArray[33]->kNext = vertArray[32];
	vertArray[32]->kPrev = vertArray[33];
	vertArray[32]->kNext = vertArray[31];
	vertArray[31]->kPrev = vertArray[32];
	vertArray[31]->kNext = vertArray[30];
	vertArray[30]->kPrev = vertArray[31];
	vertArray[30]->kNext = vertArray[19];
	vertArray[19]->kPrev = vertArray[30];
	vertArray[19]->kNext = vertArray[14];
	vertArray[14]->kPrev = vertArray[19];
	vertArray[14]->kNext = vertArray[7];
	vertArray[7]->kPrev = vertArray[14];
	vertArray[7]->kNext = vertArray[4];
	vertArray[4]->kPrev = vertArray[7];
	vertArray[4]->kNext = vertArray[1];
	vertArray[1]->kPrev = vertArray[4];
	vertArray[1]->kNext = vertArray[0];
	vertArray[0]->kPrev = vertArray[1];

}

//Board::Board(Vertex& vertex){
//}

Board::~Board(){
/*	delete V1;
	delete V2;
	delete V3;
	delete V4;
	delete V5;
	delete V6;
	delete V7;
	delete V8;
	delete V9;
	delete V10;
	delete V11;
	delete V12;
	delete V13;
	delete V14;
	delete V15;
	delete V16;
	delete V17;
	delete V18;
	delete V19;
	delete V20;
	delete V21;
	delete V22;
	delete V23;
	delete V24;
	delete V25;
	delete V26;
	delete V27;
	delete V28;
	delete V29;
	delete V30;
	delete V31;
	delete V32;
	delete V33;
	delete V34;
	delete V35;
	delete V36;
	delete V37;
	*/

	for (int i = 0; i < BOARDSIZE; i++) {
		delete vertArray[i];
	}
}

Vertex* Board::getVertex(int vertNum){
	return vertArray[vertNum - 1];	//-1 since array index starts at 0
}
