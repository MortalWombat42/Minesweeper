/* 
 * File:   NumberSquare.cpp
 * Author: Alex Grech IV
 * 
 * Created on March 26, 2016, 2:34 PM
 */

#include "NumberSquare.h"

NumberSquare::NumberSquare(): Square(false) {
}

void NumberSquare::uncover() {
    if (!isFlagged()) {
        if (nearbyMines_ == 0) {
            setSymbol('_');
        } else {
            setSymbol(nearbyMines_ + '0');
        }
        uncovered_ = true;
    }
}