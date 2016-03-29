/* 
 * File:   Square.h
 * Author: Alex Grech IV
 *
 * Created on March 26, 2016, 2:02 PM
 */

#ifndef SQUARE_H
#define	SQUARE_H

class Square {
public:
    Square(bool);
    void addNearbyMine();
    void flag();
    char getSymbol() const;
    bool isFlagged() const;
    bool isMine() const;
    bool isUncovered() const;
    virtual void uncover() = 0;
protected:
    void setSymbol(char);
    bool flag_;
    bool mine_;
    int nearbyMines_;
    bool uncovered_;
    char symbol_;
};

#endif	/* SQUARE_H */

