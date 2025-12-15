#pragma once
#include<iostream>
#include<cmath>
using namespace std;

class Block {
protected:
    char shape[4][4];
public:
    int x, y;   

    Block(int _x = 4, int _y = 0) : x(_x), y(_y) {}

    virtual char getCell(int i, int j) = 0; //constructor

    void moveDown() { y++; }
    void moveLeft() { x--; }
    void moveRight() { x++; }
    virtual void rotate() = 0;
    int getX() { return x; }
    int getY() { return y; }
    virtual ~Block() {}
};




