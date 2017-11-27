/*
 * Player.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: snirhazan
 */

#include "Player.h"
//Class Player

/**
 * The construcor of Player.
 * @param char type1,GameLogic* gameL.
 */

Player::Player(char type1, GameLogic* gameL) : type2(type1), gameLogic(gameL) {

}

/**
 * The destrucor of Player.
 */

Player::~Player() {

}

/**
 * This function return the type of the Player.
 */

char Player::getType() const {
	return type2;
}

