#include "engine.h"
#include "saveName.h"
#include "mapGen.h"
#include "loadMap.h"
#include <iostream>
#include <string>
#include "display.h"
#include "conio.h"
#include <windows.h>

using namespace std;

extern int mSizeX;
extern int mSizeY;

extern int playerLife;
extern int playerScore;


bool Engine::isTouch(char sp){
    int couter=0;
    if(fourVision[0] == sp||fourVision[1] == sp||fourVision[2] == sp||fourVision[3] == sp){
        for(int i=0; i<sizeof(fourVision); i++){
            if(fourVision[i]==sp)couter++;
        }
        if(couter>0){ //Edit in one day

        }
    }
}

void Engine::findVision(){
    fourVision[0] = emap[playerPos[0][1]-1][playerPos[0][0]+0];
    fourVision[1] = emap[playerPos[0][1]+0][playerPos[0][0]+1];
    fourVision[2] = emap[playerPos[0][1]+1][playerPos[0][0]+0];
    fourVision[3] = emap[playerPos[0][1]+0][playerPos[0][0]-1];
}
