/*
 * Game.h
 *
 *  Created on: Nov 7, 2017
 *      Author: snirhazan
 */

#ifndef GAME_H_
#define GAME_H_
#include "Board.h"
#include <vector>
#include "HumanPlayer.h"

class Game {
public:
	Game(Player* p1 , Player* p2 ,int size);
	virtual ~Game();
	void run();
	void endGame();
	void startOrExit();

private:
	Player* p1;
	Player* p2;
	vector<Player*> players;
	Board* gameBoard;
	int size;


};

#endif /* GAME_H_ */
