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
// Subclass of Dragon that assigns specific attributes to the Chinese Fireball.
//
// Instructor: Jocelyn Richardt
// Assignment: Dragon Project
// Author: Ace Martin
// Date: 2/19/24
//
// -----------------------------------------------------------------------

#pragma once
#include "Dragon.h"
class ChineseFireball :
    public Dragon
{
public: 
    /*
    * 
    * Initialized constructor using constructor of base class
    * 
    */
    ChineseFireball() : Dragon("Scarlet", "China", (rand() % 50) + 50) {};
    /*
    * 
    * Overriden train method
    * 
    */
    void train() override;

};

