/*
 * Point.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: snirhazan
 */

#include "Point.h"
#include <iostream>
using namespace std;

//Point class

/**
 * The constructor of class Point.
 * param int x - x coordinate, int y - y coordinate
 */
Point::Point(int x, int y) : xCoordinate(x), yCoordinate(y) {
	// TODO Auto-generated constructor stub

}

/**The destructor of Point.
 */

Point::~Point() {
	// TODO Auto-generated destructor stub
}

/**This function check if 2 Points are equal(operator overloading of operator ==).
 * @param Point other.
 * return true if the points are equal, false if not.
 */

bool Point::operator ==(Point& other) const {
	return (this->xCoordinate == other.xCoordinate && this->yCoordinate == other.yCoordinate);
}

/**This function return the x coordinate of the Point.
 * @return int Xcoordinate.
 */

int Point::getXCoordinate() const {
	return xCoordinate;
}

/**This function return the y coordinate of the Point.
 * @return int ycoordinate.
 */

int Point::getYCoordinate() const {
	return yCoordinate;
}

bool Point::isValid() const {
	if((xCoordinate < 0) || (yCoordinate < 0)) {
		return false;
	}
	return true;
}

/**This function print the Points(operator overloading of operator <<).
 * @param ostream out and Point p.
 *return ostream
 */

ostream &operator <<(ostream& out, const Point& p) {
	out<<"("<<p.xCoordinate + 1<<","<<p.yCoordinate + 1<<")";
	return out;
}
