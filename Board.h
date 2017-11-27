/*
 * Board.h
 *
 *  Created on: Oct 28, 2017
 *      Author: snirhazan
 *      ID: 308045137
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <string>
#include <iostream>
using namespace std;

class Board {
public:
	Board();
	Board(const int size);
	~Board();
	void setInBoard(int row, int col, char c);
	void printBoard() const;
	bool isFull();
	char checkWinner();
	char getCell(int i, int j);

	int getSize() const {
		return size;
	}
	int getScore(char type);

private:
	char** board;
	int size;
	int capacity;
	void inatializeBoard();

};

#endif /* BOARD_H_ */
