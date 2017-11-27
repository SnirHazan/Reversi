/*
 * Player.h
 *
 *  Created on: Nov 12, 2017
 *      Author: snirhazan
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "RegularLogic.h"

class Player {
public:
	Player(char type1, GameLogic* gameL);
	virtual ~Player();
	char getType() const;
	virtual int PlayOneTurn(Board& b) = 0;

protected:
	char type2;
	GameLogic* gameLogic;
};

#endif /* PLAYER_H_ */
