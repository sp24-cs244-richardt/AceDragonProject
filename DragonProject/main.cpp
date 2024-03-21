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
// Date: 3/21/24
//
// -----------------------------------------------------------------------

#include "HungarianHorntail.h"
#include "CommonWelsh.h"
#include "ChineseFireball.h"
#include "Dragon.h"
#include "string"
#include <list>

using namespace std;

void battle(list<Dragon*>& playerDragons, bool& playerTurn, Dragon* &wildDragon) {
    cout << "\nSelect a champion to go battle:\n";
    int i = 1;
    for (auto dragon : playerDragons) {
        cout << i << ". ";
        dragon->print();
        cout << endl;
        i++;
    }
    int choice;
    cin >> choice;
    choice--; // Adjust for zero-based indexing
    if (choice < 0 || choice >= playerDragons.size()) {
        cout << "Invalid choice\n";
        return;
    }
    auto iter = playerDragons.begin();
    advance(iter, choice);
    Dragon* champion = *iter;

    int playerHealthLost = 0;
    int wildHealthLost = 0;

    // loop for battle
    while (champion->getHealth() > 0 && wildDragon->getHealth() > 0) {
        // Player's dragon attacks first
        if (playerTurn) {
            int playerAttack = (rand() % (champion->getFirePower() + 1));
            cout << "Player's dragon attacks with firepower: " << playerAttack << endl;
            wildDragon->setHealth(wildDragon->getHealth() - playerAttack);
            wildHealthLost += playerAttack;
            cout << "Wild dragon's health: " << wildDragon->getHealth() << endl;
        }
        // Wild dragon attacks first
        else {
            int wildAttack = (rand() % (wildDragon->getFirePower() + 1));
            cout << "Wild dragon attacks with firepower: " << wildAttack << endl;
            champion->setHealth(champion->getHealth() - wildAttack);
            playerHealthLost += wildAttack;
            cout << "Player's dragon's health: " << champion->getHealth() << endl;
        }
        playerTurn = !playerTurn;
    }

    // Determine the winner and perform necessary actions
    if (champion->getHealth() <= 0) {
        cout << "Player's dragon lost the battle and is now banished! Wild Dragon is lost...\n\n";
        // Remove player dragon from the list and delete both dragons
        playerDragons.erase(iter);
        delete champion;
        delete wildDragon;
    }
    else {
        cout << "Player's dragon won the battle!\n\n";
        // Move champion to the front of the list
        playerDragons.splice(playerDragons.begin(), playerDragons, iter);
        // Restore health and add adrenaline rush
        champion->setHealth(champion->getHealth() + playerHealthLost + 10);
        if (champion->getHealth() > 100)
            champion->setHealth(100);
        //Add wild dragon to end of list to restore health
        playerDragons.push_back(wildDragon);
        wildDragon->setHealth(wildDragon->getHealth() + wildHealthLost);
    }
 
}


int main() {
    // Set seed for random number generator to time once so it will stop being generated by time
    srand((unsigned int)time(NULL));

    list<Dragon*> playerDragons;
    bool playerTurn;

    // Generate three dragons for the player's allegiance
    for (int i = 0; i < 3; ++i) {
        int type = rand() % 3;
        Dragon* dragon;
        if (type == 0) {
            dragon = new ChineseFireball();
        }
        else if (type == 1) {
            dragon = new CommonWelsh();
        }
        else {
            dragon = new HungarianHorntail();
        }
        playerDragons.push_back(dragon);
    }

    // Game loop
    while (true) {
        cout << "Choose an action:\n";
        cout << "1. Train a dragon\n";
        cout << "2. Recruit a wild dragon\n";
        cout << "3. Battle\n";
        cout << "4. View Dragons\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Select a dragon to train:\n";
            int i = 1;
            for (auto dragon : playerDragons) {
                cout << i << ". ";
                dragon->print();
                cout << endl;
                i++;
            }
            cin >> choice;
            choice--; // Adjust for zero-based indexing
            if (choice < 0 || choice >= playerDragons.size()) {
                cout << "Invalid choice\n";
                continue;
            }
            auto iter = playerDragons.begin();
            advance(iter, choice);
            Dragon* chosenDragon = *iter;
            (chosenDragon)->train();
            int wildChance = rand() % 100;
            //10% chance of battle during training
            if (wildChance < 10) {
                cout << "A wild dragon approaches during training!\n";
                // Generate a random wild dragon
                int type = rand() % 3;
                Dragon* wildDragon;
                if (type == 0) {
                    wildDragon = new ChineseFireball();
                }
                else if (type == 1) {
                    wildDragon = new CommonWelsh();
                }
                else {
                    wildDragon = new HungarianHorntail();
                }
                cout << "A wild dragon appears!\n";
                cout << "Wild dragon details:\n";
                wildDragon->print();
                playerTurn = false;
                battle(playerDragons, playerTurn, wildDragon);
            }
            else {
                // Move trained dragon to end of list to restore health
                playerDragons.splice(playerDragons.end(), playerDragons, iter);
                chosenDragon->setHealth(chosenDragon->getHealth() + 20);
                cout << "Dragon trained successfully\n";
                
            }
        }
        else if (choice == 2) {
            cout << "Select a dragon to recruit with:\n";
            int i = 1;
            for (auto dragon : playerDragons) {
                cout << i << ". ";
                dragon->print();
                cout << endl;
                i++;
            }
            int choice;
            cin >> choice;
            choice--; // Adjust for zero-based indexing
            if (choice < 0 || choice >= playerDragons.size()) {
                cout << "Invalid choice\n";
            }
            auto iter = playerDragons.begin();
            advance(iter, choice);
            Dragon* chosenDragon = *iter;

            // Generate a random wild dragon
            int type = rand() % 3;
            Dragon* wildDragon;
            if (type == 0) {
                wildDragon = new ChineseFireball();
            }
            else if (type == 1) {
                wildDragon = new CommonWelsh();
            }
            else {
                wildDragon = new HungarianHorntail();
            }

            cout << "You've found a wild Dragon!\n";
            cout << "Wild dragon details:\n";
            wildDragon->print();

            // Compare charisma of chosen dragon and wild dragon
            if (chosenDragon->getCharisma() > wildDragon->getCharisma()) {
                cout << "\nRecruitment successful! Your dragon has higher charisma.\n\n";
                chosenDragon->increaseCharisma();
                playerDragons.push_back(wildDragon);
            }
            else {
                cout << "Recruitment failed! Your dragon has lower charisma. Battle begins.\n";
                // Battle if lower charisma
                playerTurn = false;
                battle(playerDragons, playerTurn, wildDragon);
            }
        }
        else if (choice == 3) {
            // Generate a random wild dragon
            int type = rand() % 3;
            Dragon* wildDragon;
            if (type == 0) {
                wildDragon = new ChineseFireball();
            }
            else if (type == 1) {
                wildDragon = new CommonWelsh();
            }
            else {
                wildDragon = new HungarianHorntail();
            }

            cout << "A wild dragon is ready to battle!\n";
            cout << "Wild dragon details:\n";
            wildDragon->print();
            playerTurn = true;
            battle(playerDragons, playerTurn, wildDragon);

        }
        else if (choice == 4) {
            cout << "Players Dragons:\n\n";
            int i = 1;
            for (auto dragon : playerDragons) {
                cout << i << ". ";
                dragon->print();
                cout << endl;
                i++;
            }
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    // Cleanup
    for (auto dragon : playerDragons) {
        delete dragon;
    }

    return 0;


    /* 
    * 
    * Code for Project 1
    * 
    * 
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

    */

}