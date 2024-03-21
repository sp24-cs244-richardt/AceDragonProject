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
// HungarianHorntail.cpp
//
// Subclass of Dragon that assigns specific attributes to the Hungarian Horntail.
//
// Instructor: Jocelyn Richardt
// Assignment: Dragon Project
// Author: Ace Martin
// Date: 3/21/24
//
// -----------------------------------------------------------------------

#include "HungarianHorntail.h"

/*
* 
* Train method for the Hungarian Hortail
* 
*/
void HungarianHorntail::train() {
	if (firePower_ < 20) {
		firePower_ += 5;
	}
	else {
		firePower_ += (rand() % 25) + 15;
		if (firePower_ > 100) { firePower_ = 100; }
	}
	health_ -= 20;
}


