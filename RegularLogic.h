/*
 * GameLogic.h
 *
 *  Created on: Nov 9, 2017
 *      Author: snirhazan
 */

#ifndef REGULARLOGIC_H_
#define REGULARLOGIC_H_
#include "Point.h"
#include "Board.h"
#include "GameLogic.h"
#include <iostream>
#include <vector>
class HumanPlayer;

class RegularLogic: public GameLogic {
public:
	RegularLogic();
	virtual ~RegularLogic();
	void SwitchPlayers(char play, Point p1 , Point p2, Board& b);
	void InsertInputAndSwitch(vector<Point> &v1,vector<Point> &v2,char type,Board& b);
	bool checkInput(Point &p ,vector<Point> &v);
	vector< vector<Point> > FindOptions(Board& b, char type);
	void PrintOptions(vector<Point> &v);

private:

	Point rowRight(Board& b,char type,int i,int j);
	Point rowLeft(Board& b,char type,int i,int j);
	Point colUp(Board& b,char type,int i,int j);
	Point colDown(Board& b,char type,int i,int j);
	Point UpRightDiagonal(Board& b,char type,int i,int j);
	Point DownRightDiagonal(Board& b,char type,int i,int j);
	Point UpleftDiagonal(Board& b,char type,int i,int j);
	Point DownleftDiagonal(Board& b,char type,int i,int j);
};

#endif /* REGULARLOGIC_H_ */
