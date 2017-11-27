/*
 * Board.cpp
 *
 *  Created on: Oct 28, 2017
 *      Author: snirhazan ,
 *      ID: 308045137
 */

#include "Board.h"
#include <string>
#include <iostream>
#define DEFAULT 8
using namespace std;

//Board class

/**
 * The constructor of class Board.
 * create defualt Board in size 8.
 */
Board::Board() : size(DEFAULT) {
	this->board = new char*[size];
	this->inatializeBoard();
	this->capacity = 4;

}

/**
 * The constructor of class Board.
 * @param int size - the size of the board.
 */
Board::Board(const int size) : size(size) {
	this->board = new char*[size];
	this->inatializeBoard();
	this->capacity = 4;
}
/**
 * The destructor of class Board.
 */
Board::~Board() {
	for(int i = 0 ; i < size ; i++) {
		delete[] board[i];
	}
	delete[] board;
}

/**
 * This function inatialize the Board by creating 2 dimension dynamic array .
 */

void Board::inatializeBoard() {
	for(int i = 0 ; i < size ; i++){
		this->board[i] = new char[size];

	}
	for(int i = 0 ; i < size ; i++) {
		for(int j = 0 ; j < size ; j++)
			this->board[i][j] = ' ';
	}
	this->setInBoard(size / 2  , size / 2  , 'O');
	this->setInBoard(size / 2 + 1  , size / 2 + 1 , 'O');
	this->setInBoard(size / 2 + 1 , size / 2 , 'X');
	this->setInBoard(size / 2 , size / 2 + 1 , 'X');

}


/**
 * This function print the board.
 */

void Board::printBoard() const {
	cout<<" |";
	for(int i = 0 ; i < size ; i++) {
		cout << " "<< i + 1 << " |";
	}
	cout << endl;
	cout << string(2 + 4 * size, '-') << endl;
	for(int i = 0 ; i < size ; i++) {
		cout << i + 1 << "|";
		for(int j = 0 ; j < size ; j++){
			cout <<" " << this->board[i][j] << " |";
		}
		cout << endl;
		cout << string(2 + 4 * size, '-') << endl;
	}

}
/**
 * This function set the player type in a chosen cell.
 * @param int row,int col and chat tpye.
 */
void Board::setInBoard(int row, int col, char player) {
	if(this->board[row-1][col-1] == ' ') {
		this->capacity = this->capacity + 1;
	}
	this->board[row-1][col-1] = player;
}
/**
 * This function check if the board is full.
 * @return true - if the board is full, false if not.
 */
bool Board::isFull() {
	if(this->capacity >= size*size) {
		return true;
	} else {
		return false;
	}
}

/**
 * This function check which of the players is the winner.
 * @return char - the type of the winner(X or O)
 */

char Board::checkWinner() {

	int xCounter = this->getScore('X');
	int OCounter = this->getScore('O');

	cout<<"X player score: "<<xCounter<<endl;
	cout<<"O player score: "<<OCounter<<endl;
	if(xCounter == OCounter) {
		return '=';
	} else if(xCounter > OCounter) {
		return 'X';
	} else {
		return 'O';
	}
}

/**
 * This function return the char in cell(i,j) that in the board
 * @param int i - row, int j - col.
 * @return char - the char in the cell.
 */

char Board::getCell(int i, int j) {

	return this->board[i][j];
}

int Board:: getScore(char type){

    int counter = 0;
    for(int i = 0; i < this->size ; i++) {
        for(int j = 0 ; j < this->size ; j++){
            if(this->board[i][j] == type){
                counter++;
            }
        }
    }
    return counter;
}

