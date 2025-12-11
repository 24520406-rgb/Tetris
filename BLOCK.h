#pragma 
#include<iostream>
#include<cmath>

class Block {
public:
    int x, y;   

    Block(int _x = 4, int _y = 0) : x(_x), y(_y) {}

    virtual char getCell(int i, int j) = 0; 
    virtual ~Block() {}
};


