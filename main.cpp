/*
 * main.cpp
 *
 *  Created on: Oct 28, 2017
 *      Author: snirhazan
 *      ID: 308045137
 */

#include <string>
#include <iostream>
#include "Game.h"
#include "HumanPlayer.h"
#include "Point.h"
#include "RegularLogic.h"
#include "InPutTest.h"

using namespace std;

/**
 * The main class.
 * initialize the relevant players and the game.
 */
int main() {
	cout<<"Reversi!"<<endl;

	//Check input of size of board from the user.
	int size = InPutTest::getNumberFromUser();

	//Initialized player,logic and the game.

	GameLogic* gameL = new RegularLogic;
	Player* pX = new HumanPlayer('X',gameL);
	Player* pO = new HumanPlayer('O',gameL);

	Game reversi(pX,pO,size);

	//Run the game.
	reversi.run();

	//Free the memory.
	delete gameL;

}








