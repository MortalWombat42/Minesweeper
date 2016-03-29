/* 
 * File:   Square.cpp
 * Author: Alex Grech IV
 * 
 * Created on March 26, 2016, 2:02 PM
 */

#include "Square.h"

Square::Square(bool mine): flag_(false), mine_(mine), nearbyMines_(0), 
        uncovered_(false), symbol_('X'){
}

void Square::addNearbyMine() {
    nearbyMines_++;
}

void Square::flag() {
    if (!isUncovered()) {
        if (!isFlagged()) {
            setSymbol('f');
        } else {
            setSymbol('X');
        }
        flag_ = !flag_;
    }
}

char Square::getSymbol() const {
    return symbol_;
}

bool Square::isFlagged() const {
    return flag_;
}

bool Square::isMine() const {
    return mine_;
}

bool Square::isUncovered() const {
    return uncovered_;
}

void Square::setSymbol(char sym) {
    symbol_ = sym;
}