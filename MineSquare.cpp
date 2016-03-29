/* 
 * File:   MineSquare.cpp
 * Author: Alex Grech IV
 * 
 * Created on March 26, 2016, 4:30 PM
 */

#include "MineSquare.h"

MineSquare::MineSquare(): Square(true) {
}

void MineSquare::uncover() {
    if (!isFlagged()) {
        setSymbol('*');
        uncovered_ = true;
    }
}
