/* 
 * File:   MineSquare.h
 * Author: Alex Grech IV
 *
 * Created on March 26, 2016, 4:30 PM
 */

#ifndef MINESQUARE_H
#define	MINESQUARE_H

#include "Square.h"

class MineSquare: public Square {
public:
    MineSquare();
    virtual void uncover();
private:

};

#endif	/* MINESQUARE_H */

