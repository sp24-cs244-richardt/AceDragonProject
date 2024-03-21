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
// An abstract base class to provide the basic attributes of all dragons.
//
// Instructor: Jocelyn Richardt
// Assignment: Dragon Project
// Author: Ace Martin
// Date: 3/21/24
//
// -----------------------------------------------------------------------

#pragma once
#include <string>
#include <iostream>
#include <random>
#include <time.h>
using namespace std;
class Dragon
{

protected: 
	string skinColor_;
	string nativeRange_;
	int firePower_;
	int health_;
	int charisma_;

public:
	Dragon(string s, string n, int f, int h, int c) : skinColor_(s), nativeRange_(n), firePower_(f), health_(h), charisma_(c) {};
	/*
	* 
	* Abstract train method 
	* 
	*/
	virtual void train() = 0;
	/*
	* 
	* Print method that prints the attributes of a dragon
	* 
	*/
	void print() {
		cout << "\nSkin Color: " << skinColor_ << "\nNative Range: " << nativeRange_ << "\nFire Power: " << firePower_ << "\nHealth: " << health_ << "\nCharisma: " << charisma_ << endl;
	}
	/*
	* 
	* Gets the fire power of a dragon
	* 
	*/
	int getFirePower() const {
        return firePower_;
    }
	/*
	* 
	* Gets the health of a dragon
	* 
	*/
    int getHealth() const {
        return health_;
    }
	/*
	* 
	* Gets the charisma of a dragon
	* 
	*/
    int getCharisma() const {
        return charisma_;
    }
	/*
	* 
	* Sets the charisma of a dragon
	* 
	*/
	void setCharisma(int newCharisma) {
		charisma_ = newCharisma;
	}
	/*
	* 
	* Sets the health of a dragon
	* 
	*/
    void setHealth(int newHealth) {
        health_ = newHealth;
    }
	/*
	* 
	* Increases the charisma of a dragon
	* 
	*/
    void increaseCharisma() {
        charisma_ += 5;
        if (charisma_ > 100)
            charisma_ = 100;
    }
	
};

