/* 
 * File:   Grid.cpp
 * Author: Alex Grech IV
 * 
 * Created on March 26, 2016, 4:46 PM
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Grid.h"
#include "MineSquare.h"
#include "NumberSquare.h"

using namespace std;

Grid::Grid(int height, int width, int mines) : height_(height), width_(width),
mines_(mines) {
    grid_ = new Square**[height];
    for (int i = 0; i < height; i++) {
        grid_[i] = new Square*[width];
        for (int j = 0; j < width; j++) {
            Square *square = new NumberSquare;
            grid_[i][j] = square;
        }
    }
    srand(time(NULL));
    int i, j;
    for (int m = 0; m < mines; m++) {
        do {
            i = rand() % height;
            j = rand() % width;
        } while (grid_[i][j]->isMine());
        Square* mine = new MineSquare;
        grid_[i][j] = mine;
        for (int x = i - 1; x <= i + 1; x++) {
            if (x >= 0 && x < height) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (y >= 0 && y < width) {
                        grid_[x][y]->addNearbyMine();
                    }
                }
            }
        }
    }
}

Grid::Grid(const Grid& orig) : height_(orig.height_), width_(orig.width_),
mines_(orig.mines_) {
    grid_ = new Square**[height_];
    for (int i = 0; i < height_; i++) {
        grid_[i] = new Square*[width_];
    }
    memcpy(grid_, orig.grid_, sizeof (orig.grid_));
}

Grid& Grid::operator=(const Grid &rhs) {
    if (this != &rhs) {
        Square ***newGrid = new Square**[rhs.height_];
        for (int i = 0; i < height_; i++) {
            newGrid[i] = new Square*[rhs.width_];
        }
        memcpy(newGrid, rhs.grid_, sizeof (rhs.grid_));
        for (int i = 0; i < height_; i++) {
            delete[] grid_[i];
        }
        grid_ = newGrid;
        height_ = rhs.height_;
        width_ = rhs.width_;
    }
    return *this;
}

Grid::~Grid() {
    for (int i = 0; i < height_; i++) {
        delete[] grid_[i];
    }
}

int Grid::getMines() const {
    return mines_;
}

void Grid::flag(int i, int j) {
    grid_[i][j]->flag();
}

bool Grid::isWin() const {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            if (!grid_[i][j]->isMine() && !grid_[i][j]->isUncovered())
                return false;
        }
    }
    return true;
}

void Grid::print() const {
    cout << " ";
    for (int j = 0; j < width_; j++)
        cout << "  " << j % 10;
    cout << endl;
    for (int i = 0; i < height_; i++) {
        cout << i % 10;
        for (int j = 0; j < width_; j++) {
            cout << "  " << grid_[i][j]->getSymbol();
        }
        cout << endl;
    }
}

bool Grid::uncover(int i, int j) {
    if (!grid_[i][j]->isUncovered()) {
        grid_[i][j]->uncover();
        if (grid_[i][j]->getSymbol() == '_') {
            for (int x = i - 1; x <= i + 1; x++) {
                if (x >= 0 && x < height_) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (y >= 0 && y < width_) {
                            if (!grid_[x][y]->isUncovered())
                                uncover(x, y);
                        }
                    }
                }
            }
        }
        bool isMine = grid_[i][j]->isMine();
        if (isMine) {
            uncoverMines();
        }
        return isMine;
    }
}

void Grid::uncoverMines() {
    for (int x = 0; x < height_; x++) {
        for (int y = 0; y < width_; y++) {
            if (grid_[x][y]->isMine()) {
                if (grid_[x][y]->isFlagged())
                    grid_[x][y]->flag();
                grid_[x][y]->uncover();
            }
        }
    }
}