#pragma once
#include "BLOCK.h"
#include<iostream>  
using namespace std;

class BlockI : public Block {
    char shape[4][4] = {
        {' ',' ',' ',' '},
     {' ','S','S',' '},
     {'S','S',' ',' '},
     {' ',' ',' ',' '}
    };
public:
    using Block::Block;  //I ke thua constructor tu Block
    char getCell(int i, int j) override {
        return shape[i][j];
    }
};
