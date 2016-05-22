#include "engine.h"
#include "saveName.h"
#include "mapGen.h"
#include "loadMap.h"

#include "display.h"
#include "conio.h"

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

extern int mSizeX;
extern int mSizeY;

extern int playerLife;
extern int playerScore;

void Engine::repPlayerName(char out){
    cout << nPlayer;
    for(int i=0;i<mSizeY; i++){
        for(int j=0;j<mSizeX;j++){
            if(emap[i][j] == '9'){
                emap[i][j] = out ;
            }
        }
    }
}

void Engine::countPlayer(){
    for(int i=0; i<mSizeY; i++){
        for(int j=0; j<mSizeX; j++){
            if(emap[i][j]== '2')nBot++;
            else if(emap[i][j] == '9')nPlayer++;
        }
    }

}

void Engine::addValue(char name , int value){
    switch(name){
        case 'l':
            playerLife+=value;
            break;
        case 's':
            playerScore+=value;
            break;
    }
}


void Engine::subValue(char name , int value){
    switch(name){
        case 'l':
            playerLife-=value;
            break;
        case 's':
            playerScore-=value;
            break;
    }
}
