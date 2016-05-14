#include "menuFunc.h"
#include "textColor.h"
#include "cls.h"
#include "config.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

Menu::Menu() {
    run();
    mList();
}

void Menu::run() {
    cout << lang::mWelCome <<endl;
    cout << lang::mTitle << endl;

}

int Menu::mList() {
    cout << lang::mPlay_sing <<endl;
    cout << lang::mPlay_multi <<endl;
    cout << lang::mHigh <<endl;
    cout << lang::mQuit <<endl;
    bool mLoop=false;
    short int key=0;
    while(!mLoop) {
        char k=getch();
        switch(k) {
        case '1':
            key=1;
            mLoop=true;
            break;
        case '2':
            key=2;
            mLoop=true;
            break;
        case '3':
            key=3;
            mLoop=true;
            break;
        case '4':
            key=4;
            mLoop=true;
            break;
        }
    }
    cls();
    return key;
}

