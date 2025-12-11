#pragma once
#include "BLOCK.h"
#include<iostream>  
using namespace std;

class BlockI : public Block {
    char shape[4][4] = {
     {' ',' ',' ',' '},
     {' ','O','O',' '},
     {' ','O','O',' '},
     {' ',' ',' ',' '},
    };
public:
    using Block::Block;  //O ke thua constructor tu Block
    char getCell(int i, int j) override {
        return shape[i][j];
    }
};

