#include "loadMap.h"
#include <iostream>

#include <vector>

#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "cls.h"

#include "config.h"
#include "display.h"

using namespace std;

extern int mSizeX;
extern int mSizeY;

loadMap::loadMap() {
    readFile();
    intialization();
    loadData();

}

void loadMap::intialization() {
    gMap = new char* [mSizeY];
    for(int i=0; i<mSizeY; i++) {
        gMap[i] = new char [mSizeX];
    }

}

void loadMap::loadData() {
    int k=0;
    for(int i=0; i<mSizeY; i++) {
        for(int j=0; j<mSizeX; j++) {
            gMap[i][j] = dataMap[2][k];
            k++;
        }
    }
}

void loadMap::show() {
    Render lk(gMap,mSizeX, mSizeY);
    lk.update();
}

bool loadMap::readFile() {
    string textline;
    string temp="";

    ifstream fa("Level.txt");
    if(fa.is_open()) {
        while(getline(fa, textline));

        for(int i=0; i< textline.size(); i++) {
            if(textline[i]=='x' || textline[i]=='p') {
                dataMap.push_back(temp);
                temp = "";
                i++;
            }
            temp.push_back(textline[i]);
        }
        dataMap.push_back(temp);

        mSizeX = atoi(dataMap[0].c_str());
        mSizeY = atoi(dataMap[1].c_str());


        return true;
    } else {
        return false;
    }

}

char **loadMap::getMap() {
    return gMap;
}

void loadMap::setMap(char** mmp){
    gMap = mmp;
}

vector<string> loadMap::getData() {
    return dataMap;
}
