/*
 * Game.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: snirhazan
 */

#include "Game.h"
#include "Board.h"
#include "RegularLogic.h"
// class Game

/**
 * The constructor of the Game.
 * @param player* p1,p2 and size of Board.
 */

Game::Game(Player* p1,Player* p2,int size): p1(p1), p2(p2),size(size){

	this->gameBoard = new Board(size);
	this->players.push_back(p1);
	this->players.push_back(p2);
}

/**
 * The destructor of the Game.
 */
Game::~Game() {
	delete gameBoard;
	delete p1;
	delete p2;
}

/**
 * The function run the Game.
 */
void Game::run() {

	cout<<"Current Board:"<<endl;
	cout<<endl;
	this->gameBoard->printBoard();
	int counter = 0;
	while(this->gameBoard->isFull() == false && counter < 2) {
		for(int i = 0 ; i< (int)players.size() ; i++) {
			int Play1 = players[i]->PlayOneTurn(*this->gameBoard);
			if(Play1 == 1){
				counter++;
				if(counter == 2){
					cout<<"No possible moves to both of the players."<<endl;
					break;
				}
			} else{
				counter = 0;
			}
			if(this->gameBoard->isFull() == true) {
				cout<<"The board is full,no possible moves!"<<endl;
				cout<<"Current Board:"<<endl;
				cout<<endl;
				this->gameBoard->printBoard();
				break;
			}
		}
	}
	endGame();
	startOrExit();
}

/**
 * The function check who is the winner and print it.
 */
void Game::endGame() {

	cout<<"Game Over!"<<endl;
	char win = this->gameBoard->checkWinner();
	if(win == '='){
		cout<<"There is no winner!"<<endl;
	} else {
		cout<<"** The winner is : "<<win<<" **"<<endl;
	}
}

/**
 * The function check if the player wnt to play again
 * or he want to quit.
 */

void Game::startOrExit() {
	cout<<endl;
	char symbol;
	cout<<"Play Again - please press n and than Enter"<<endl;;
	cout<<"Quit - please press q and than Enter"<<endl;;
	cin>>symbol;
	if(symbol != 'n') {
		cout<<"Thank you for playing Reversi!"<<endl;;
	}
	if(symbol == 'n') {
		delete gameBoard;
		this->gameBoard = new Board(size);
		run();
	}
}
