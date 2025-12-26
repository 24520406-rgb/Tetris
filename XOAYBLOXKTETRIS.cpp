#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include "BLOCK.h"
#include "BLOCKI.h"
#include "BLOCKO.h"
#include "BLOCKT.h"
#include "BLOCKL.h"
#include "BLOCK_J.h"
#include "BLOCKS.h"
#include "BLOCKZ.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;
#define H 20
#define W 15
char board[H][W] = {};


int x = 4, y = 0, b = 1;
int speed = 200;
const int MIN_SPEED = 50;
const int SPEED_STEP = 20;
bool removed = false;




void hideCursor() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 1;
    SetConsoleCursorInfo(handle, &info);
}

void gotoxy(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void boardDelBlock(Block& Khoi) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (Khoi.getCell(i, j) != ' ' && Khoi.y + i < H)
                board[Khoi.y + i][Khoi.x + j] = ' ';
}
void block2Board(Block& Khoi) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (Khoi.getCell(i, j) != ' ')
                board[Khoi.y + i][Khoi.x + j] = Khoi.getCell(i, j);
}
void initBoard() {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if ((i == H - 1) || (j == 0) || (j == W - 1)) board[i][j] = '#';
            else board[i][j] = ' ';
}

static Block* spawnBlock() {
    int r = rand() % 7;
    switch (r) {
    case 0: return new BlockI();
    case 1: return new BlockS();
    case 2: return new BlockO();
    case 3: return new BlockT();
    case 4: return new BlockL();
    case 5: return new BlockZ();
    case 6: return new Block_J();
    }
    return new BlockI();
};

bool canMove(Block& Khoi, int dx, int dy) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (Khoi.getCell(i, j) != ' ') {
                int tx = Khoi.x + j + dx;
                int ty = Khoi.y + i + dy;
                if (tx < 1 || tx >= W - 1 || ty >= H - 1) return false;
                if (board[ty][tx] != ' ') return false;
            }
        }
    }
    return true;
};
void draw() {
    gotoxy(0, 0);
    for (int i = 0; i < H; i++, cout << endl)
        for (int j = 0; j < W; j++) {
            char c = board[i][j];

            if (c == ' ') {
                cout << "  ";
            }
            else if (c == '#') {
                cout << char(219) << char(219);
            }
            else {
                cout << "[]";
            }
        }
}

void removeLine() {
    removed = false;

    for (int i = H - 2; i > 0; i--) {
        bool full = true;

        for (int j = 1; j < W - 1; j++)
            if (board[i][j] == ' ') {
                full = false;
                break;
            }

        if (full) {
            removed = true;

            for (int ii = i; ii > 0; ii--)
                for (int j = 1; j < W - 1; j++)
                    board[ii][j] = board[ii - 1][j];

            draw();
            Sleep(120);
            i++;
        }
    }
}
bool isGameOver(Block& Khoi) {

    return !canMove(Khoi, 0, 0);
}

int main()
{
    hideCursor();
    srand(time(0));
    PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    Block* currentBlock = spawnBlock();
    system("cls");
    initBoard();
    while (1) {
        boardDelBlock(*currentBlock);
        if (_kbhit()) {
            char c = _getch();
            if (c == 'a' && canMove(*currentBlock, -1, 0)) {
                currentBlock->moveLeft();
                   Beep(900, 20);}
            if (c == 'd' && canMove(*currentBlock, 1, 0)) {
                currentBlock->moveRight();
                Beep(900, 20);}
            if (c == 's' && canMove(*currentBlock, 0, 1)) {
                currentBlock->moveDown();
                Beep(900, 20);}
            if (c == 'w' && canMove(*currentBlock, 0, 0)) {
                currentBlock->rotate();
                Beep(900, 20);
            }
            if (c == ' ') {
               
               boardDelBlock(*currentBlock);

                
                currentBlock->hardDrop(canMove);

               
                block2Board(*currentBlock);

                
                removeLine();
                delete currentBlock;
                currentBlock = spawnBlock();

                
                draw();
                continue; 
            }
            if (c == 'q') break;
        }
        if (canMove(*currentBlock, 0, 1)) currentBlock->moveDown();
        else {
            block2Board(*currentBlock);
            removeLine();
            PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            delete currentBlock;
            x = 5; y = 0; b = rand() % 7;
            currentBlock = spawnBlock();
        }

        if (isGameOver(*currentBlock)) {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("game_over.wav"), NULL, SND_FILENAME | SND_SYNC);
            system("cls");
            gotoxy(W / 2, H / 2);
            cout << "GAME OVER!" << endl;
            delete currentBlock;
            system("pause");
            break;
        }
        block2Board(*currentBlock);
        draw();
        Sleep(100);
    }
    return 0;
}






