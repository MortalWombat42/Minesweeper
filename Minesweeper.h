/* 
 * File:   Minesweeper.h
 * Author: Alex Grech IV
 *
 * Created on March 27, 2016, 11:05 PM
 */

#ifndef MINESWEEPER_H
#define	MINESWEEPER_H

#include "Grid.h"

class Minesweeper {
public:
    Minesweeper();
    void play();
private:
    Grid *gameGrid_;
};

#endif	/* MINESWEEPER_H */

