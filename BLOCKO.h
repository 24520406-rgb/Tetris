#pragma once
#include "BLOCK.h"
#include<iostream>  
using namespace std;

class BlockO : public Block {
    char shape[4][4] =   {{' ',' ',' ',' '},
     {' ',char(219),char(219),' '},
     {' ',char(219),char(219),' '},
     {' ',' ',' ',' '}};

public:
   void rotate() override {
        // BlockO does not change shape on rotation
   }
    char getCell(int i, int j) override {
        return shape[i][j];
    }
};


