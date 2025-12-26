#include <iostream>
#include <conio.h>
#include <windows.h>
#include "menu.h"

using namespace std;

int showMenu() {
    char choice;

    system("cls");
    cout << "=================================\n";
    cout << "           T E T R I S           \n";
    cout << "=================================\n\n";

    cout << "1. Play Game\n";
    cout << "2. How to Play\n";
    cout << "3. Exit\n\n";

    cout << "Choose (1-3): ";
    choice = _getch();   

    if (choice == '1') return 1;
    if (choice == '2') return 2;
    if (choice == '3') return 3;

    return 0; 