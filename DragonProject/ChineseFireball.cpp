// -----------------------------------------------------------------------
//
// University of Wisconsin-Stout
// Mathematics, Statistics & Computer Science
// CS-244 Data Structures ** Spring 2024
//
// This software is student work for CSS-244 Data Structures and may not
// be copied except by the original author and instructor.
// Copyright 2024
//
// ChineseFireball.cpp
//
// Subclass of Dragon that assigns specific attributes to the Chinese Fireball.
//
// Instructor: Jocelyn Richardt
// Assignment: Dragon Project
// Author: Ace Martin
// Date: 3/21/24
//
// -----------------------------------------------------------------------

#include "ChineseFireball.h"

/*
*
* Train method for the Chinese Fireball
*
*/
void ChineseFireball::train() {
	firePower_ += (rand() % 15) + 10;
	if (firePower_ > 100) { firePower_ = 100; }
	health_ -= 20;
}
