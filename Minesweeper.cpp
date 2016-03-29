/* 
 * File:   Minesweeper.cpp
 * Author: Alex Grech IV
 * 
 * Created on March 27, 2016, 11:05 PM
 */

#include <iostream>
#include "Minesweeper.h"

using namespace std;

Minesweeper::Minesweeper() {
    cout << "Welcome!" << endl << endl;
    cout << "What level would you like to play?" << endl;
    cout << "1-Beginner, 2-Intermediate, 3-Advanced, 0-Quit" << endl;
    int choice;
    cin >> choice;
    while (choice < 0 || choice > 3) {
        cout << "Invalid Choice" << endl;
        cout << "1-Beginner, 2-Intermediate, 3-Advanced, 0-Quit" << endl;
    }
    int h, w, m;
    switch (choice) {
        case 0:
            return;
        case 1:
            h = 8;
            w = 8;
            m = 10;
            break;
        case 2:
            h = 16;
            w = 16;
            m = 40;
            break;
        case 3:
            h = 16;
            w = 30;
            m = 99;
            break;
    }
    gameGrid_ = new Grid(h, w, m);
    play();
}

void Minesweeper::play() {
    bool endGame = false;
    while (!endGame) {
        cout << endl;
        gameGrid_->print();
        cout << endl << "What next?" << endl;
        cout << "Options: (U)ncover r c, (F)lag r c, (Q)uit" << endl;
        char action;
        cin >> action;
        int r, c;
        switch (action) {
            case 'U':
            case 'u':
                cin >> r >> c;
                endGame = gameGrid_->uncover(r, c);
                if (gameGrid_->isWin()) {
                    endGame = true;
                    gameGrid_->uncoverMines();
                }
                break;
            case 'F':
            case 'f':
                cin >> r >> c;
                gameGrid_->flag(r, c);
                break;
            case 'q':
            case 'Q':
                endGame = true;
            default:
                break;
        }
    }
    gameGrid_->print();
    if (gameGrid_->isWin()) {
        cout << "Congratulations!!" << endl << "You win!!!";
    } else {
        cout << endl << "Better luck next time!";
    }
}