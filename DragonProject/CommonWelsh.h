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
// Dragon.h
//
// Subclass of Dragon that assigns specific attributes to the Common Welsh.
//
// Instructor: Jocelyn Richardt
// Assignment: Dragon Project
// Author: Ace Martin
// Date: 2/19/24
//
// -----------------------------------------------------------------------

#pragma once
#include "Dragon.h"
class CommonWelsh :
    public Dragon
{
private: 
    int trustFactor_ = 5;

public:
    /*
    *
    * Initialized constructor using constructor of base class
    *
    */
    CommonWelsh() : Dragon("Green", "Wales", (rand() % 50) + 10) {};
    /*
    * 
    * Overriden train method
    * 
    */
    void train() override;

};

