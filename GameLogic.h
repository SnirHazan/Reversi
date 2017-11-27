/*
 * GameLogic.h
 *
 *  Created on: Nov 12, 2017
 *      Author: snirhazan
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

#include "Point.h"
#include <vector>
#include "Board.h"

class GameLogic {
public:
	GameLogic();
	virtual ~GameLogic();
	bool checkInput(Point &p ,vector<Point> &v1);
	void SwitchPlayers(char play, Point p1 , Point p2, Board& b);
	void InsertInputAndSwitch(vector<Point> &v1,vector<Point> &v2,char type,Board& b);
    void PrintOptions(vector<Point>& v);
	virtual vector< vector<Point> > FindOptions(Board& b, char type) = 0;


};

#endif /* GAMELOGIC_H_ */
