#include "menuFunc.h"
#include "textColor.h"
#include "cls.h"
#include "config.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <conio.h>

#include <cstdlib>
#include <ctime>
#include <ctime>

#include "loadMap.h"
#include "display.h"
#include "engine.h"
#include "mapGen.h"
#include "serve.h"

#include "conio.h"
#include <windows.h>


#include <cstdlib>//exit

using namespace std;
extern int mSizeX;
extern int mSizeY;
extern int menuMode;

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
    cout << lang::mNewMap <<endl;
    cout << lang::mQuit <<endl;
    bool mLoop=false;
    short int key=0;
    while(!mLoop) {
        char k=getch();
        switch(k) {
        case '1':
            key=1;
            menuMode = 1;
            mLoop=true;
            break;
        case '2':
            key=2;
            menuMode = 2;
            mLoop=true;
            break;
        case '3':
            key=3;
            menuMode = 3;
            mLoop=true;
            break;
        case '4':
            key=4;
            menuMode = 4;
            mLoop=true;
            break;
        case '5':
            exit(0);
        }
    }
    cout << "\a";
    cls();
    return key;
}

void Menu::loadSingle() {
    cls();
    srand(time(0));
    int i=1;

    loadMap lm;
    Engine engine(lm.getMap());
    engine.repPlayerName('X');

    engine.createRoom();

    Sleep(5000);

    while(engine.gameActive()) {
        engine.findPlayer('X');
        engine.getGameUI();
        engine.setMap(engine.getNewMap());
        engine.keypress();
        //engine.defTime(5);
        Sleep(1);

    }
}

void Menu::loadMulti() {
    //try connect
    char t;
    //cls();
    Serv sv;
    sv.createRoom(time(0));
    cout <<sv.ping <<endl;
    //Sleep(100);
    //sv.test();



}

void Menu::loadHigh() {
    menuMode = 0;
}

void Menu::loadCreate() {
    MapGen m(mSizeX,mSizeY);
}

int Menu::loadMenuStd() {
    if(menuMode == 0) {
        cls();
        run();
        mList();
    } else if(menuMode == 1) {
        loadSingle();
    } else if(menuMode == 2) {
        loadMulti();
    } else if(menuMode == 3) {

    } else if(menuMode == 4) {
        loadCreate();
        cout << "Create New map Completed\n";
        Sleep(1200);
        cout << "Return to Main menu";
        Sleep(1500);
        menuMode = 0;
    } else {
        cls();
        cout << "Error: I don't know you Command?";
        Sleep(5000);
        menuMode = 0;
    }
    return 1;
}

