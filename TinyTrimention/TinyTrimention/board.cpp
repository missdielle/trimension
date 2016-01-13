#include <stdio.h>
#include "board.h"

using namespace std;


Board::Board(){

	vertArray = new Vertex*[BOARDSIZE];;

	V1 = new Vertex1D(1, 100, 100, 1, 'y');
	V2 = new Vertex3D(2, 150, 200, 3, 'b');
	V3 = new Vertex6D(3, 200, 167, 6);
	V4 = new Vertex3D(4, 200, 100, 3, 'r');
	V5 = new Vertex7D(5, 200, 300, 7, 'o');
	V6 = new Vertex4D(6, 233, 200, 4, 'p');
	V7 = new Vertex7D(7, 300, 100, 7, 'g');
	V8 = new Vertex3D(8, 250, 400, 3, 'b');
	V9 = new Vertex6D(9, 300, 367, 6);
	V10 = new Vertex4D(10, 300, 300, 4, 'g');
	V11 = new Vertex6D(11, 300, 233, 6);
	V12 = new Vertex4D(12, 350, 200, 4, 'o');
	V13 = new Vertex6D(13, 400, 167, 6);
	V14 = new Vertex3D(14, 400, 100, 3, 'r');
	V15 = new Vertex7D(15, 300, 500, 7, 'o');
	V16 = new Vertex4D(16, 350, 400, 4, 'p');
	V17 = new Vertex12D(17, 400, 300, 12);
	V18 = new Vertex4D(18, 450, 200, 4, 'p');
	V19 = new Vertex7D(19, 500, 100, 7, 'g');
	V20 = new Vertex3D(20, 350, 600, 3, 'b');
	V21 = new Vertex6D(21, 450, 567, 6);
	V22 = new Vertex4D(22, 400, 500, 4, 'g');
	V23 = new Vertex6D(23, 400, 433, 6);
	V24 = new Vertex4D(24, 450, 400, 4, 'o');
	V25 = new Vertex6D(25, 500, 367, 6);
	V26 = new Vertex4D(26, 500, 300, 4, 'g');
	V27 = new Vertex6D(27, 500, 233, 6);
	V28 = new Vertex4D(28, 550, 200, 4, 'o');
	V29 = new Vertex6D(29, 600, 167, 6);
	V30 = new Vertex3D(30, 600, 100, 3, 'r');
	V31 = new Vertex1D(31, 400, 700, 1, 'r');
	V32 = new Vertex3D(32, 450, 600, 3, 'y');
	V33 = new Vertex7D(33, 500, 500, 7, 'p');
	V34 = new Vertex3D(34, 550, 400, 3, 'y');
	V35 = new Vertex7D(35, 600, 300, 7, 'p');
	V36 = new Vertex3D(36, 650, 200, 3, 'y');
	V37 = new Vertex1D(37, 700, 100, 1, 'b');

//commenting below...building Vertex directly so
//I can access them directly, then putting pointers 
//into an array for easy access (index+1 == PIN)
	//vertArray[0] = new Vertex1D(1, 100, 100, 1, 'y');
	//vertArray[1] = new Vertex3D(2, 150, 200, 3, 'b');
	//vertArray[2] = new Vertex6D(3, 200, 167, 6);
	//vertArray[3]= new Vertex3D(4, 200, 100, 3, 'r');
	//vertArray[4] = new Vertex7D(5, 200, 300, 7, 'o');
	//vertArray[5] = new Vertex4D(6, 233, 200, 4, 'p');
	//vertArray[6] = new Vertex7D(7, 300, 100, 7, 'g');
	//vertArray[7] = new Vertex3D(8, 250, 400, 3, 'b');
	//vertArray[8] = new Vertex6D(9, 300, 367, 6);
	//vertArray[9] = new Vertex4D(10, 300, 300, 4, 'g');
	//vertArray[10] = new Vertex6D(11, 300, 233, 6);
	//vertArray[11] = new Vertex4D(12, 350, 200, 4, 'o');
	//vertArray[12] = new Vertex6D(13, 400, 167, 6);
	//vertArray[13] = new Vertex3D(14, 400, 100, 3, 'r');
	//vertArray[14] = new Vertex7D(15, 300, 500, 7, 'o');
	//vertArray[15] = new Vertex4D(16, 350, 400, 4, 'p');
	//vertArray[16] = new Vertex12D(17, 400, 300, 12);
	//vertArray[17] = new Vertex4D(18, 450, 200, 4, 'p');
	//vertArray[18] = new Vertex7D(19, 500, 100, 7, 'g');
	//vertArray[19] = new Vertex3D(20, 350, 600, 3, 'b');
	//vertArray[20] = new Vertex6D(21, 450, 567, 6);
	//vertArray[21] = new Vertex4D(22, 400, 500, 4, 'g');
	//vertArray[22] = new Vertex6D(23, 400, 433, 6);
	//vertArray[23] = new Vertex4D(24, 450, 400, 4, 'o');
	//vertArray[24] = new Vertex6D(25, 500, 367, 6);
	//vertArray[25] = new Vertex4D(26, 500, 300, 4, 'g');
	//vertArray[26] = new Vertex6D(27, 500, 233, 6);
	//vertArray[27] = new Vertex4D(28, 550, 200, 4, 'o');
	//vertArray[28] = new Vertex6D(29, 600, 167, 6);
	//vertArray[29] = new Vertex3D(30, 600, 100, 3, 'r');
	//vertArray[30] = new Vertex1D(31, 400, 700, 1, 'r');
	//vertArray[31] = new Vertex3D(32, 450, 600, 3, 'y');
	//vertArray[32] = new Vertex7D(33, 500, 500, 7, 'p');
	//vertArray[33] = new Vertex3D(34, 550, 400, 3, 'y');
	//vertArray[34] = new Vertex7D(35, 600, 300, 7, 'p');
	//vertArray[35] = new Vertex3D(36, 650, 200, 3, 'y');
	//vertArray[36] = new Vertex1D(37, 700, 100, 1, 'b');

//let's put them into an array for easy access:
//	Vertex* vertArray[BOARDSIZE];//in board.h now
	vertArray[0] = V1;
	vertArray[1] = V2;
	vertArray[2] = V3;
	vertArray[3] = V4;
	vertArray[4] = V5;
	vertArray[5] = V6;
	vertArray[6] = V7;
	vertArray[7] = V8;
	vertArray[8] = V9;
	vertArray[9] = V10;
	vertArray[10] = V11;
	vertArray[11] = V12;
	vertArray[12] = V13;
	vertArray[13] = V14;
	vertArray[14] = V15;
	vertArray[15] = V16;
	vertArray[16] = V17;
	vertArray[17] = V18;
	vertArray[18] = V19;
	vertArray[19] = V20;
	vertArray[20] = V21;
	vertArray[21] = V22;
	vertArray[22] = V23;
	vertArray[23] = V24;
	vertArray[24] = V25;
	vertArray[25] = V26;
	vertArray[26] = V27;
	vertArray[27] = V28;
	vertArray[28] = V29;
	vertArray[29] = V30;
	vertArray[30] = V31;
	vertArray[31] = V32;
	vertArray[32] = V33;
	vertArray[33] = V34;
	vertArray[34] = V35;
	vertArray[35] = V36;
	vertArray[36] = V37;

	//now let's create the lines:
//red lines
	V4->rNext = V3;
	V3->rPrev = V4;
	V3->rNext = V5;
	V5->rPrev = V3;

	V7->rNext = V11;
	V11->rPrev = V7;
	V11->rNext = V10;
	V10->rPrev = V11;
	V10->rNext = V9;
	V9->rPrev = V10;
	V9->rNext = V15;
	V15->rPrev = V9;

	V14->rNext = V13;
	V13->rPrev = V14;
	V13->rNext = V17;
	V17->rPrev = V13;
	V17->rNext = V23;
	V23->rPrev = V17;
	V23->rNext = V22;
	V22->rPrev = V23;
	V22->rNext = V21;
	V21->rPrev = V22;
	V21->rNext = V31;
	V31->rPrev = V21;

	V19->rNext = V27;
	V27->rPrev = V19;
	V27->rNext = V26;
	V26->rPrev = V27;
	V26->rNext = V25;
	V25->rPrev = V26;
	V25->rNext = V33;
	V33->rPrev = V25;

	V30->rNext = V29;
	V29->rPrev = V30;
	V29->rNext = V35;
	V35->rPrev = V29;

//yellow lines
	V36->yNext = V29;
	V29->yPrev = V36;
	V29->yNext = V19;
	V19->yPrev = V29;

	V35->yNext = V27;
	V27->yPrev = V35;
	V27->yNext = V18;
	V18->yPrev = V27;
	V18->yNext = V13;
	V13->yPrev = V18;
	V13->yNext = V7;
	V7->yPrev = V13;

	V34->yNext = V25;
	V25->yPrev = V34;
	V25->yNext = V17;
	V17->yPrev = V25;
	V17->yNext = V11;
	V11->yPrev = V17;
	V11->yNext = V6;
	V6->yPrev = V11;	
	V6->yNext = V3;
	V3->yPrev = V6;
	V3->yNext = V1;
	V1->yPrev = V3;

	V33->yNext = V23;
	V23->yPrev = V33;
	V23->yNext = V16;
	V16->yPrev = V23;
	V16->yNext = V9;
	V9->yPrev = V16;
	V9->yNext = V5;
	V5->yPrev = V9;

	V32->yNext = V21;
	V21->yPrev = V32;
	V21->yNext = V15;
	V15->yPrev = V21;
		
//blue lines
	V20->bNext = V21;
	V21->bPrev = V20;
	V21->bNext = V33;
	V33->bPrev = V21;

	V15->bNext = V23;
	V23->bPrev = V15;
	V23->bNext = V24;
	V24->bPrev = V23;
	V24->bNext = V25;
	V25->bPrev = V24;
	V25->bNext = V35;
	V35->bPrev = V25;

	V8->bNext = V9;
	V9->bPrev = V8;
	V9->bNext = V17;
	V17->bPrev = V9;
	V17->bNext = V27;
	V27->bPrev = V17;
	V27->bNext = V28;
	V28->bPrev = V27;
	V28->bNext = V29;
	V29->bPrev = V28;
	V29->bNext = V37;
	V37->bPrev = V29;

	V5->bNext = V11;
	V11->bPrev = V5;
	V11->bNext = V12;
	V12->bPrev = V11;
	V12->bNext = V13;
	V13->bPrev = V12;
	V13->bNext = V19;
	V19->bPrev = V13;
		
	V2->bNext = V3;
	V3->bPrev = V2;
	V3->bNext = V7;
	V7->bPrev = V3;

//green lines
	V15->gNext = V22;
	V22->gPrev = V15;
	V22->gNext = V33;
	V33->gPrev = V22;

	V5->gNext = V10;
	V10->gPrev = V5;
	V10->gNext = V17;
	V17->gPrev = V10;
	V17->gNext = V26;
	V26->gPrev = V17;
	V26->gNext = V35;
	V35->gPrev = V26;

	V1->gNext = V4;
	V4->gPrev = V1;
	V4->gNext = V7;
	V7->gPrev = V4;
	V7->gNext = V14;
	V14->gPrev = V7;
	V14->gNext = V19;
	V19->gPrev = V14;
	V19->gNext = V30;
	V30->gPrev = V19;
	V30->gNext = V37;
	V37->gPrev = V30;

//orange lines
	V35->oNext = V28;
	V28->oPrev = V35;
	V28->oNext = V19;
	V19->oPrev = V28;

	V33->oNext = V24;
	V24->oPrev = V33;
	V24->oNext = V17;
	V17->oPrev = V24;
	V17->oNext = V12;
	V12->oPrev = V17;
	V12->oNext = V7;
	V7->oPrev = V12;

	V31->oNext = V20;
	V20->oPrev = V31;
	V20->oNext = V15;
	V15->oPrev = V20;
	V15->oNext = V8;
	V8->oPrev = V15;
	V8->oNext = V5;
	V5->oPrev = V8;
	V5->oNext = V2;
	V2->oPrev = V5;
	V2->oNext = V1;
	V1->oPrev = V2;

	V7->pNext = V6;
	V6->pPrev = V7;
	V6->pNext = V5;
	V5->pPrev = V6;

	V19->pNext = V18;
	V18->pPrev = V19;
	V18->pNext = V17;
	V17->pPrev = V18;
	V17->pNext = V16;
	V16->pPrev = V17;
	V16->pNext = V15;
	V15->pPrev = V16;

	V37->pNext = V36;
	V36->pPrev = V37;
	V36->pNext = V35;
	V35->pPrev = V36;
	V35->pNext = V34;
	V34->pPrev = V35;
	V34->pNext = V33;
	V33->pPrev = V34;
	V33->pNext = V32;
	V32->pPrev = V33;
	V32->pNext = V31;
	V31->pPrev = V32;

//black lines
	V1->kNext = V4;
	V4->kPrev = V1;
	V4->kNext = V7;
	V7->kPrev = V4;
	V7->kNext = V14;
	V14->kPrev = V7;
	V14->kNext = V19;
	V19->kPrev = V14;
	V19->kNext = V30;
	V30->kPrev = V19;
	V30->kNext = V37;
	V37->kPrev = V30;
	V37->kNext = V36;
	V36->kPrev = V37;
	V36->kNext = V35;
	V35->kPrev = V36;
	V35->kNext = V34;
	V34->kPrev = V35;
	V34->kNext = V33;
	V33->kPrev = V34;
	V33->kNext = V32;
	V32->kPrev = V33;
	V32->kNext = V31;
	V31->kPrev = V32;
	V31->kNext = V20;
	V20->kPrev = V31;
	V20->kNext = V15;
	V15->kPrev = V20;
	V15->kNext = V8;
	V8->kPrev = V15;
	V8->kNext = V5;
	V5->kPrev = V8;
	V5->kNext = V2;
	V2->kPrev = V5;
	V2->kNext = V1;
	V1->kPrev = V2;

}

//Board::Board(Vertex& vertex){
//}

Board::~Board(){
	delete V1;
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

}

Vertex* Board::getVertex(int vertNum){
	return vertArray[vertNum - 1];	//-1 since array index starts at 0
}
