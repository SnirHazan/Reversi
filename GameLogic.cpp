/*
 * GameLogic.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: snirhazan
 */

#include "GameLogic.h"
#include <algorithm>

//GameLogic class

/**
 * The constructor of the GameLogic.
 */

GameLogic::GameLogic() {
	// TODO Auto-generated constructor stub

}

/**
 * The destructor of the GameLogic.
 */

GameLogic::~GameLogic() {
	// TODO Auto-generated destructor stub
}

/**
 * This function ask the user to insert his move, check if valid,
 * and than switch the relevant Points in the Board .
 * @param vector<Point> v1,v2,char type and board b.
 */
void GameLogic::InsertInputAndSwitch(vector<Point>& v1, vector<Point>& v2,char type, Board& b) {
	cout<<"\n\n";
	int row,col = 0;
	cout<<"Please Enter Your move row,press Enter, and than col:"<<endl;
	for (;;) {
		cin>>row;
		cin>>col;
		if (cin.fail()) {
			cout << "Characters are not permitted!\n";

			cout<<"Your possible moves: ";
			this->PrintOptions(v1);
			cout<<endl;

			cout<<"Please Enter Your move row,press Enter, and than col:"<<endl;
			cin.clear();
			cin.ignore(10000,'\n');
		}
		else {
			break;
		}
	}
	Point p(row-1 ,col-1);
	while(this->checkInput(p,v1) != true) {
		cout<<"You can't do this move,try again."<<endl;

		cout<<"Your possible moves: ";
		this->PrintOptions(v1);
		cout<<endl;

		cout<<"Please Enter Your move row,press Enter, and than col:"<<endl;

		for (;;) {
			cin>>row;
			cin>>col;
			if (cin.fail()) {
				cout << "Characters are not permitted!\n";

				cout<<"Your possible moves: ";
				this->PrintOptions(v1);
				cout<<endl;

				cout<<"Please Enter Your move row,press Enter, and than col:"<<endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else {
				break;
			}
		}
		Point p(row-1 ,col-1);
		Point p1(row,col);
		if(this->checkInput(p,v1) == true){
			for(int i = 0 ; i < (int)v1.size() ; i++) {
				if(v1[i] == p) {
					Point temp(v2[i].getXCoordinate() + 1,v2[i].getYCoordinate()+1);
					SwitchPlayers(type,p1,temp,b);
				}
			}
			break;
		}
	}
	Point p1(row,col);
	for(int i = 0 ; i < (int)v1.size() ; i++) {
		if(v1[i] == p) {
			Point temp(v2[i].getXCoordinate() + 1,v2[i].getYCoordinate()+1);
			SwitchPlayers(type,p1,temp,b);
		}
	}
}

/**
 * This function check if  the input of the player is valid,
 *
 */

bool GameLogic::checkInput(Point &p ,vector<Point> &v1) {

	for(int i = 0; i < (int)v1.size(); i++){
		if(p == v1[i]){
			return true;
		}
	}
	return false;
}

/**
 * This function switch the relevant Points in the Board .
 * @param char play, Point p1,p2 and board b.
 */

void GameLogic::SwitchPlayers(char play, Point p1, Point p2, Board& b) {
	int rowS = p1.getXCoordinate();
	int colS = p1.getYCoordinate();

	int rowE = p2.getXCoordinate();
	int colE = p2.getYCoordinate();

	if(rowS == rowE) {
		if(colE < colS) {
			int temp = colS;
			colS = colE;
			colE = temp;
		}
		for(int j = colS ; j < colE + 1 ; j++){
			b.setInBoard(rowS, j , play);

		}

	} else if(colS == colE) {
		if(rowE < rowS) {
			int temp = rowS;
			rowS = rowE;
			rowE = temp;
		}
		for(int j = rowS ; j < rowE + 1 ; j++){
			b.setInBoard(j, colS , play);

		}
	} else if((rowS > rowE && colS > colE) ||(rowS < rowE && colS < colE)) {
		int newColS,newRowS = 0;
		newRowS = min(rowS,rowE);
		newColS = min(colS,colE);
		rowE = max(rowS,rowE);
		colE = max(colS,colE);

		while((newRowS < rowE + 1) && (newColS < colE + 1)) {
			b.setInBoard(newRowS, newColS , play);
			newRowS++;
			newColS++;
		}
	} else {
		int newColS,newRowS = 0;
		newRowS = max(rowS,rowE);
		newColS = min(colS,colE);
		rowE = min(rowS,rowE);
		colE = max(colS,colE);
		while((newRowS > rowE - 1) && (newColS < colE + 1)) {
			b.setInBoard(newRowS, newColS , play);
			newRowS--;
			newColS++;
		}
	}
}

/**
 * This function print the possible moves of the player.
 * @param vector v.
 */

void GameLogic::PrintOptions(vector<Point>& v) {

	vector<int> index;
	for(int i = 0 ; i < (int)v.size(); i++) {
		for(int l = i+1 ; l < (int)v.size(); l++){
			if(v[i] == v[l]){
				index.push_back(i);
			}
		}
	}
	for(int i = 0 ; i < (int)v.size(); i++) {
		if(find(index.begin(), index.end(), i) == index.end()){
			cout<<v[i]<<" ";
		}
	}
}





