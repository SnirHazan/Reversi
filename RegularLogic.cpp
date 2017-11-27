/*
 * GameLogic.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: snirhazan
 */

#include "Point.h"
#include "Board.h"
#include <vector>
#include <set>
#include <algorithm>
#include "HumanPlayer.h"

/**
 * The constructor of the RegularLogic.
 */

RegularLogic::RegularLogic() {

}

/**
 * The destructor of the RegularLogic.
 */

RegularLogic::~RegularLogic() {

}

/**This function return the optional moves of the player.
 * @return vector<vector<Point>> v.
 */
vector< vector<Point> > RegularLogic::FindOptions(Board& b, char type) {
	vector<Point>v1;
	vector<Point>v2;

	for(int i = 0; i < b.getSize();i++) {
		for(int j = 0; j < b.getSize(); j++) {
			if(b.getCell(i,j) == ' ') {
				Point pEnd1 = rowRight(b,type,i,j);
				if(pEnd1.isValid() == true) {
					Point p(i,j);
					v1.push_back(p);
					v2.push_back(pEnd1);
				}
				Point pEnd2 = rowLeft(b,type,i,j);
				if(pEnd2.isValid() == true) {
					Point p(i,j);
					v1.push_back(p);
					v2.push_back(pEnd2);
				}
				Point pEnd3 = colUp(b,type,i,j);
				if(pEnd3.isValid() == true) {
					Point p(i,j);
					v1.push_back(p);
					v2.push_back(pEnd3);
				}
				Point pEnd4 = colDown(b,type,i,j);
				if(pEnd4.isValid() == true) {
					Point p(i,j);
					v1.push_back(p);
					v2.push_back(pEnd4);
				}
				Point pEnd5 = DownRightDiagonal(b,type,i,j);
				if(pEnd5.isValid() == true) {
					Point p(i,j);
					v1.push_back(p);
					v2.push_back(pEnd5);
				}
				Point pEnd6 = UpleftDiagonal(b,type,i,j);
				if(pEnd6.isValid() == true) {
					Point p(i,j);
					v1.push_back(p);
					v2.push_back(pEnd6);
				}
				Point pEnd7 = DownleftDiagonal(b,type,i,j);
				if(pEnd7.isValid() == true) {
					Point p(i,j);
					v1.push_back(p);
					v2.push_back(pEnd7);
				}
				Point pEnd8 = UpRightDiagonal(b,type,i,j);
				if(pEnd8.isValid() == true) {
					Point p(i,j);
					v1.push_back(p);
					v2.push_back(pEnd8);
				}
			}
		}
	}
	vector<vector<Point> > v;
	v.push_back(v1);
	v.push_back(v2);
	return v;
}
/**
 * This function check the if the empty Point is valid for
 *  insertion to the next move of the player.
 *  check from the point to it's right.
 */

Point RegularLogic::rowRight(Board& b,char type, int i, int j) {
	char Find;
	int counter = 0;
	if(type == 'X') {
		Find = 'O';
	} else {
		Find = 'X';
	}
	if(j == b.getSize() - 1) {
		return Point(-1,-1);
	}
	int temp = j + 1;
	for(; (b.getCell(i,temp) == Find) && (temp < b.getSize() - 1) ;temp++){
		counter++;
	}
	if(counter > 0 && b.getCell(i,temp) == type) {
		return Point(i,temp);
	}
	return Point(-1,-1);

}
/**
 * This function check the if the empty Point is valid for
 *  insertion to the next move of the player.
 *  check from the point to it's left.
 */
Point RegularLogic::rowLeft(Board& b, char type, int i, int j) {
	char Find;
	int counter = 0;
	if(type == 'X') {
		Find = 'O';
	} else {
		Find = 'X';
	}
	if(j == 0) {
		return Point(-1,-1);
	}
	int temp = j - 1;
	for(; (b.getCell(i,temp) == Find) && (temp > 0) ;temp--){
		counter++;
	}
	if(counter > 0 && b.getCell(i,temp) == type) {
		return Point(i,temp);
	}
	return Point(-1,-1);
}

/**
 * This function check the if the empty Point is valid for
 *  insertion to the next move of the player.
 *  check from the point -> up.
 */

Point RegularLogic::colUp(Board& b, char type, int i, int j) {
	char Find;
	int counter = 0;
	if(type == 'X') {
		Find = 'O';
	} else {
		Find = 'X';
	}
	if(i == 0) {
		return Point(-1,-1);
	}
	int temp = i - 1;
	for(; (b.getCell(temp,j) == Find) && (temp > 0) ;temp--){
		counter++;
	}
	if(counter > 0 && b.getCell(temp,j) == type) {
		return Point(temp,j);
	}
	return Point(-1,-1);
}

/**
 * This function check the if the empty Point is valid for
 *  insertion to the next move of the player.
 *  check from the point -> down.
 */

Point RegularLogic::colDown(Board& b, char type, int i, int j) {
	char Find;
	int counter = 0;
	if(type == 'X') {
		Find = 'O';
	} else {
		Find = 'X';
	}
	if(i == b.getSize() - 1) {
		return Point(-1,-1);
	}
	int temp = i + 1;
	for(; (b.getCell(temp,j) == Find) && (temp < b.getSize() - 1) ;temp++){
		counter++;
	}
	if(counter > 0 && b.getCell(temp,j) == type) {
		return Point(temp,j);
	}
	return Point(-1,-1);
}

/**
 * This function check the if the empty Point is valid for
 *  insertion to the next move of the player.
 *  check the diagonal from the point -> downright .
 */

Point RegularLogic::DownRightDiagonal(Board& b, char type, int i, int j) {
	char Find;
	int counter = 0;
	if(type == 'X') {
		Find = 'O';
	} else {
		Find = 'X';
	}
	if((i == b.getSize() - 1) || (j == b.getSize() - 1)) {
		return Point(-1,-1);
	}
	int tempi = i + 1;
	int tempj = j + 1;
	for(; (b.getCell(tempi,tempj) == Find) && (tempi < b.getSize() - 1)&& (tempj < b.getSize() - 1) ;tempi++,tempj++){
		counter++;
	}
	if(counter > 0 && b.getCell(tempi,tempj) == type) {
		return Point(tempi,tempj);
	}
	return Point(-1,-1);
}

/**
 * This function check the if the empty Point is valid for
 *  insertion to the next move of the player.
 *  check the diagonal from the point -> upLeft .
 */

Point RegularLogic::UpleftDiagonal(Board& b, char type, int i, int j) {
	char Find;
	int counter = 0;
	if(type == 'X') {
		Find = 'O';
	} else {
		Find = 'X';
	}
	if((i < 2) || (j < 2)) {
		return Point(-1,-1);
	}
	int tempi = i - 1;
	int tempj = j - 1;
	for(; (b.getCell(tempi,tempj) == Find) && (tempi > 0) && (tempj >  0) ;tempi--,tempj--){
		counter++;
	}
	if(counter > 0 && b.getCell(tempi,tempj) == type) {
		return Point(tempi,tempj);
	}
	return Point(-1,-1);
}

/**
 * This function check the if the empty Point is valid for
 *  insertion to the next move of the player.
 *  check the diagonal from the point -> upright .
 */

Point RegularLogic::UpRightDiagonal(Board& b, char type, int i, int j) {
	char Find;
	int counter = 0;
	if(type == 'X') {
		Find = 'O';
	} else {
		Find = 'X';
	}
	if((i < 2) || (j == b.getSize() - 1)) {
		return Point(-1,-1);
	}
	int tempi = i - 1;
	int tempj = j + 1;
	for(; (b.getCell(tempi,tempj) == Find) && (tempi > 0) && (tempj <  b.getSize() - 1) ;tempi--,tempj++){
		counter++;
	}
	if(counter > 0 && b.getCell(tempi,tempj) == type) {
		return Point(tempi,tempj);
	}
	return Point(-1,-1);
}
/**
 * This function check the if the empty Point is valid for
 *  insertion to the next move of the player.
 *  check the diagonal from the point -> downLeft .
 */
Point RegularLogic::DownleftDiagonal(Board& b, char type, int i, int j) {
	char Find;
	int counter = 0;
	if(type == 'X') {
		Find = 'O';

	} else {
		Find = 'X';
	}
	if((i == b.getSize() - 1) || (j < 2)) {
		return Point(-1,-1);
	}
	int tempi = i + 1;
	int tempj = j - 1;
	for(; (b.getCell(tempi,tempj) == Find) && (tempi < b.getSize() - 1) && (tempj >  0) ;tempi++,tempj--){
		counter++;
	}
	if(counter > 0 && b.getCell(tempi,tempj) == type) {
		return Point(tempi,tempj);
	}
	return Point(-1,-1);
}
