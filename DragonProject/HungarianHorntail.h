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
// HungarianHorntail.h
//
// Subclass of Dragon that assigns specific attributes to the Hungarian Horntail.
//
// Instructor: Jocelyn Richardt
// Assignment: Dragon Project
// Author: Ace Martin
// Date: 3/21/24
//
// -----------------------------------------------------------------------

#pragma once
#include "Dragon.h"
class HungarianHorntail :
    public Dragon
{
public:
    /*
    *
    * Initialized constructor using constructor of base class
    *
    */
    HungarianHorntail() : Dragon("Black", "Hungary", (rand() % 75) + 10, (rand() % 31) + 60, (rand() % 21) + 75) {};
    /*
    * 
    * Overriden train method
    * 
    */
    void train() override;
};

