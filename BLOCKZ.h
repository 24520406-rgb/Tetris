#pragma once
#include "BLOCK.h"
#include<iostream>  
using namespace std;

class BlockZ : public Block {
    char shape[4][4] = {
    { ' ',' ',' ',' ' },
    { 'Z','Z',' ',' '},
    { ' ','Z','Z',' ' },
    { ' ',' ',' ',' ' } };
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
    };
};