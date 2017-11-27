/*
 * Human.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: snirhazan
 */

#include "HumanPlayer.h"
#include <iostream>

#include "RegularLogic.h"

//HumanPlayer class.

/**The constructor of HumanPlayer, use the constructor of player.
 * @param GameLogic and Type of the player.
 */

HumanPlayer::HumanPlayer(char type, GameLogic* GL): Player(type,GL){

}

/**The destructor of HumanPlayer.
 */

HumanPlayer::~HumanPlayer() {

}

/**Play One Turn function of the player
 * @param Board b - the board of the game.
 * @return int , 0 - if the player succeed to do his turn
 *              1 - if don't.
 */

int HumanPlayer::PlayOneTurn(Board& b) {
	vector<vector<Point> > v = this->gameLogic->FindOptions(b,type2);
	vector<Point>v1 = v[0];
	vector<Point>v2 = v[1];
	//--------------------------------------------------------------
	if(v1.empty() == true){
		cout<<type2<<": It's Your Move."<<endl;
		cout<<"No possible moves,play passes back to the other player"<<endl;
		cout<<"**Press any key to continue and than press Enter**"<<endl;
		cin.ignore();
		cin.ignore();
		return 1;
	}
	cout<<type2<<": It's Your Move."<<endl;
	cout<<"Your possible moves: ";

	this->gameLogic->PrintOptions(v1);
	this->gameLogic->InsertInputAndSwitch(v1,v2,type2, b);

	cout<<"Current Board:"<<endl;
	cout<<endl;
	b.printBoard();

	return 0;
}
