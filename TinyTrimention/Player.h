#pragma once;
#include <stdio.h>
 
using namespace std;


class Player {
public:
	Player(int number, bool defensive);
	Player();
	~Player();
	void removePip(Player*);
	void addPip(Player*);
	void addCapturePip(Player*);
	void setPipCount(Player*, int);
	int getPipCount(Player*);
	int getCapturedPipCount(Player*);
//write getNumber public funtion and move to private:
	int number; //player #

private:
//	int number; //player #
	int pipCount;
	int capturedCount;
		
};