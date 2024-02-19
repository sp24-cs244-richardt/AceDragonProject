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
// main.cpp
//
// Main assigns, calls, and executes the code.
//
// Instructor: Jocelyn Richardt
// Assignment: Dragon Project
// Author: Ace Martin
// Date: 2/19/24
//
// -----------------------------------------------------------------------

#include "HungarianHorntail.h"
#include "CommonWelsh.h"
#include "ChineseFireball.h"
#include "Dragon.h"
#include "string"

using namespace std;


int main() {
    // Set seed for random number generator to time once so it will stop being generated by time
    srand((unsigned int)time(NULL));

    // Create a constant number for dragon array
    const int NUM_DRAGONS = 9;

    // Create an array to hold pointers to dragons
    Dragon* dragonPointers[NUM_DRAGONS];

    // Loop through array to assign three of each dragon to the dragon pointers
    for (int i = 0; i < NUM_DRAGONS; i++) {
        if (i < 3) dragonPointers[i] = new ChineseFireball();
        else if (i < 6) dragonPointers[i] = new CommonWelsh();
        else dragonPointers[i] = new HungarianHorntail();
    }

    // Loop through array to print the information for each dragon before and after it is trained
    for (int i = 0; i < NUM_DRAGONS; i++) {
        cout << "** Dragon " << (i + 1) << " **" << endl;
        dragonPointers[i]->print();
        dragonPointers[i]->train();
        cout << "\n** Dragon " << (i + 1) << " after training **" << endl;
        dragonPointers[i]->print();
        cout << "-------------------------" << endl;

    }

}