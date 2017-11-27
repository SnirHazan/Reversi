/*
 * InPutTest.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: snirhazan
 */

#include "InPutTest.h"
using namespace std;
#include <iostream>

//Class InPutTest

/**
 * The constructor of the InPutTest.
 */
InPutTest::InPutTest() {
	// TODO Auto-generated constructor stub

}
/**
 * The destructor of the InPutTest.
 */
InPutTest::~InPutTest() {
	// TODO Auto-generated destructor stub
}

/**
 * This function ask from the user to insert the size of the Board.
 */

int InPutTest::getNumberFromUser() {
	cout<<"Insert size of game board:";
	int size = 0;
	for (;;) {
		cin>>size;
		if (cin.fail()) {
			cout << "Characters are not permitted.\n";
			cout<<"Please insert size of game board:"<<endl;
			cin.clear();
			cin.ignore(10000,'\n');
		} else if (size < 3) {
			cout << "The value you have entered is not valid, please enter a number bigger than 2:\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			break;
		}
	}
	return size;
}
