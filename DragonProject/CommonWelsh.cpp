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
// CommonWelsh.cpp
//
// Subclass of Dragon that assigns specific attributes to the Common Welsh.
//
// Instructor: Jocelyn Richardt
// Assignment: Dragon Project
// Author: Ace Martin
// Date: 2/19/24
//
// -----------------------------------------------------------------------

#include "CommonWelsh.h"

int CommonWelsh::trustFactor_ = 5;

/*
*
* Train method for the Common Welsh
*
*/
void CommonWelsh::train() {
	firePower_ += trustFactor_;
	if (firePower_ > 100) { firePower_ = 100; }
	trustFactor_ += 5;
	if (trustFactor_ > 50) { trustFactor_ = 5; }
}

