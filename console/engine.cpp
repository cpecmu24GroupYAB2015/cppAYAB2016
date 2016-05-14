#include "engine.h"
#include "Fio.h"
#include "config.h"
#include "mapGen.h"
#include <iostream>
#include <string>


Engine::Engine() {
    initializeVar();
    loadMapFile();

}

void Engine::initializeVar() {
    //Do not forget this
    for(int i=0; i<config::MapSizeY; i++) {
        gMap[i] = new unsigned char[config::MapSizeY];
    }
}


void Engine::setPosition(unsigned char **mmp, int x, int y) {
}

bool Engine::scanNum(unsigned char **mmp) {
    return 0;
}

bool Engine::scanReplaceNum(unsigned char **mmp, char num, char rep) {
    bool bk=false;
    for(int i=0; i<config::MapSizeX; i++) {
        for(int j=0; j<config::MapSizeY; j++) {
            if(mmp[i][j] == num) {
                mmp[i][j] = rep;
                bk=true;
            }
        }
        if(bk)break;
    }
}

bool Engine::loadMapFile() {


}
