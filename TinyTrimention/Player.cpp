#include "Player.h"
#include "Game.h"
#include <iostream>

int PIPCOUNT = 10;

Player::Player(){
	pipCount = PIPCOUNT; //defensive game as default
	capturedCount = 0;
}

Player::Player(int number, bool defensive){
	this->number = number;
		pipCount = PIPCOUNT;
		capturedCount = 0;
}

Player::~Player(){

}

void Player::removePip(Player *player){
	cout << "player #" << player->number <<
		" pipCount was: " << player->pipCount << endl;
	player->pipCount--;
	cout << "player #" << player->number << 
		" pipCount is now: " << player->pipCount << endl;
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

void Player::addCapturePip(Player *player) {
	cout << "player #" << player->number <<
		"capturedPipCount was: " << player->getCapturedPipCount(player) << endl;
	player->capturedCount++;
	cout << "player #" << player->number <<
		"capturedPipCount is now: " << player->getCapturedPipCount(player) << endl;
}

int Player::getCapturedPipCount(Player*player) {
	return player->capturedCount;
}