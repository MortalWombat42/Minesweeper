/* 
 * File:   Grid.h
 * Author: Alex Grech IV
 *
 * Created on March 26, 2016, 4:46 PM
 */

#ifndef GRID_H
#define	GRID_H

#include "Square.h"

class Grid {
public:
    Grid(int,int,int);
    Grid(const Grid& orig);
    Grid& operator=(const Grid&);
    virtual ~Grid();
    void flag(int,int);
    int getMines() const;
    bool isWin() const;
    void print() const;
    bool uncover(int,int);
    void uncoverMines();
private:
    Square ***grid_;
    int width_;
    int height_;
    int mines_;
};

#endif	/* GRID_H */

