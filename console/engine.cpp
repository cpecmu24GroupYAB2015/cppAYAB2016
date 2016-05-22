#include "engine.h"
#include "saveName.h"
#include "mapGen.h"
#include "loadMap.h"
#include <iostream>
#include <string>
#include "display.h"
#include "conio.h"
#include <windows.h>

#include "cls.h"

using namespace std;

extern int mSizeX;
extern int mSizeY;
extern int menuMode;

extern int playerLife;
extern int playerScore;

Engine::Engine() {
    cout << "Cannot create 'Engine Obj' because Have not Map";
}

Engine::Engine(char** mp) {
    setMap(mp);
    countPlayer();
    intializ();

}

void Engine::intializ() {
    playerPos = new int *[nBot+nPlayer];
    for(int i=0; i<(nBot+nPlayer); i++) {
        playerPos[i] = new int [2];
    }
}

void Engine::findPlayer(char player) {
    for(int i=0; i<mSizeY; i++) {
        for(int j=0; j<mSizeX; j++) {
            if(emap[i][j] == player) {
                playerPos[0][0] = j;
                playerPos[0][1] = i;
            }
        }
    }
}


void Engine::moveToPos(char pz, int x, int y) {
    if((playerPos[0][0]+x >= 0 && playerPos[0][0]+x < mSizeX)&&(playerPos[0][1]+y >= 0 && playerPos[0][1]+y < mSizeY)) {
        if( emap[playerPos[0][1]+y][playerPos[0][0]+x] != '3') {
            emap[playerPos[0][1]][playerPos[0][0]] = '1';
            emap[playerPos[0][1]+y][playerPos[0][0]+x] = pz;

        }
    }
}

void Engine::setMap(char **mp) {
    emap = mp;
    Render lk(emap,mSizeX, mSizeY);
    lk.update();
}

char **Engine::getNewMap() {
    return emap;
}

int Engine::getPlayerPos(char axis) {
    if(axis = 'X')return playerPos[0][0];
    else return playerPos[0][1];
}

void reversrp() {

}

void Engine::gamePause() {
    bool pauseState=true;
    char keylog;
    while(pauseState) {
        cls();
        cout << lang::gamePause<<endl<<endl;
        cout << lang::gamePauseMsg<<endl;
        cout << lang::gamePauseM1<<endl;
        cout << lang::gamePauseM2<<endl;
        cout << lang::gamePauseM3<<endl;

        keylog = getch();
        switch(keylog) {
        case 'q':
            pauseState = false;
            break;
        case 'w':
            pauseState = false;
            active = false;
            menuMode = 0;
            break;
        }
    }
}

void Engine::keypress() {
findVision();
    if (kbhit()) {
        psk = getch();
    }else{
        psk = '0';
    }
    switch(psk) {
    case 'w':
        kex=0;
        key =-1;
        break;
    case 's':
        kex=0;
        key =1;
        break;
    case 'a':
        kex=-1;
        key =0;
        break;
    case 'd':
        kex=1;
        key =0;
        break;
    case 'q' :
        gamePause();
        psk = 'a';
        break;
    case '0' :
        kex=0;
        key =0;
        break;
    }
    moveToPos('X', kex,key);
}

bool Engine::gameActive() {
    return active;
}

void Engine::getGameUI() {
    cout << "\nLife: "<< playerLife <<"   Score: "<< playerScore <<endl;
    cout << "Ping: "<< 150+(10-(rand()%10)) <<" ms Sn: "<< config::serverName <<endl;
    //cout << "Pos: x" << playerPos[0][0] << " y" << playerPos[0][1]    ;
    cout << fourVision[0] <<fourVision[1]<<fourVision[2]<<fourVision[3] << "   ";

}



