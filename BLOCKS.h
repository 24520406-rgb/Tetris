#pragma once
#include "BLOCK.h"
#include<iostream>  
using namespace std;

class BlockS : public Block {
    char shape[4][4] = {
     {' ',' ',' ',' '},
     {' ',char(219),char(219),' '},
     {char(219),char(219),' ',' '},
     {' ',' ',' ',' '}
    };
public:
    void rotate() override {
        char temp[4][4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                temp[j][3 - i] = shape[i][j];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                shape[i][j] = temp[i][j];
	}
    char getCell(int i, int j) override {
        return shape[i][j];
    }
};

