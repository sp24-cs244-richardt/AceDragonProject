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
// Date: 2/19/24
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

public:
	Dragon(string s, string n, int f) : skinColor_(s), nativeRange_(n), firePower_(f) {};
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
		cout << "\nSkin Color: " << skinColor_ << "\nNative Range: " << nativeRange_ << "\nFire Power: " << firePower_ << endl;
	}
	
};

