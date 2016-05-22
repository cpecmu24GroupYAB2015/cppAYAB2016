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

void Engine::createRoom(){
    cout << endl << createRoomId();
}


int Engine::createRoomId(){
    return time(0)%100000;
}
