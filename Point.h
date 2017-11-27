/*
 * Point.h
 *
 *  Created on: Nov 6, 2017
 *      Author: snirhazan
 */

#ifndef POINT_H_
#define POINT_H_
#include <iostream>
using namespace std;


class Point {
public:
	Point(int x, int y);
	virtual ~Point();
	int getXCoordinate() const;
	int getYCoordinate() const;
	bool operator==(Point& other) const;
	bool isValid() const;

	friend ostream &operator <<(ostream& out, const Point& p);

private:
	int xCoordinate;
	int yCoordinate;
};

#endif /* POINT_H_ */
