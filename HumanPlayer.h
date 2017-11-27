/*
 * Human.h
 *
 *  Created on: Nov 9, 2017
 *      Author: snirhazan
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include "Board.h"
#include "Player.h"
#include "RegularLogic.h"



class HumanPlayer: public Player {
public:
	HumanPlayer();
	HumanPlayer(char type, GameLogic* GL);
	virtual ~HumanPlayer();
	virtual int PlayOneTurn(Board& b);
	char getType() const;

private:

};

#endif /* HUMANPLAYER_H_ */
