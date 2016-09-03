#include "Player.h"
#include <iostream>

Player::Player(){
	pipCount = 30; //defensive game as default
}

Player::Player(int number, bool defensive){
	this->number = number;
	if (defensive == true){
		pipCount = 30;
	} else
		pipCount = 0; 
}

Player::~Player(){

}

void Player::removePip(Player *player){
	cout << "player #" << player->number <<
		" pipCount was: " << player->pipCount << endl;
	player->pipCount--;
	cout << "player #" << player->number << 
		"pipCount is now: " << player->pipCount << endl;
}

void Player::addPip(Player *player){
	cout << "player #" << player->number <<
		"pipCount was: " << player->pipCount << endl;
	player->pipCount++;
	cout << "player #" << player->number << 
		"pipCount is now: " << player->pipCount << endl;
}

void Player::setPipCount(Player* player, int count){
	player->pipCount = count;
}

int Player::getPipCount(Player*player){
	return player->pipCount;
}

