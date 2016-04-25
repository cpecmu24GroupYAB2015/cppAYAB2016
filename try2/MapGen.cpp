#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "MapGen.h"
#include "config.h"

using namespace std;

void MapGen::showMaze(int **ptr, int sm[]) {
    for(int i=0; i<sm[0]; i++) {
        for(int j=0; j<sm[1]; j++) {
            cout << ptr[i][j];
            if(j!=sm[1]-1)cout <<"*";
        }
        if(i!=sm[0]-1)cout << "\n";
    }
}

void MapGen::writeFile(int **ptr, int sm[]) {
    ofstream fn("Level1.txt",ios::out);
    for(int i=0; i<sm[0]; i++) {
        for(int j=0; j<sm[1]; j++) {
            fn << ptr[i][j];
            if(j!=sm[1]-1) fn <<" ";
        }
        if(i!=sm[0]-1)fn << endl;
    }
    fn.close();
}

void MapGen::initialze(int **t, int sm[]) {
    for(int i=0; i<sm[0]; i++) {
        t[i]=new int[sm[1]];
        for(int j=0; j<sm[1]; j++)
            if(i==0||i==sm[0]-1 || j==0 || j==sm[1]-1) {
                t[i][j] = 1;
            } else {
                t[i][j] = 7;
            }
    }
}
int MapGen::randBoxSize() {
    return 2+rand()%3;
}
int MapGen::randPos(int posMax) {
    return 1+rand()%(posMax);
}


void MapGen::playerRes(int **t, int sm[], int p) {
    int posx = 1;
    int posy = 1;
    bool isPut = false;
    while(!isPut) {
        posx = rand()%sm[0];
        posy = rand()%sm[0];
        if(t[posy][posx]==7) {
            t[posy][posx] = p;
            isPut = true;
        }
    }
}

void MapGen::writeBoxLine(int **t, int x1, int y1, int w, int h, int sm[]) {
    for(int i=x1; i<x1+h-2; i++) {
        for(int j=y1; j<y1+w-1; j++ ) {
            t[i][j] = 8;
            if(t[i+1][j]==1||t[i][j+1]==1||t[i-1][j]==1||t[i][j-1]==1) {
                t[i][j] = 7;
            }
        }
    }
    return;
}

void MapGen::makePattBox(int **t, int sm[]) {
    int MaxSize;
    int numx=0,numy=0;

    if(sm[0]*sm[1] > 20) {
        numx = sm[0]/4;
        numy = sm[1]/4;
        MaxSize = (numx+numy)/2;
    } else {
        MaxSize = 4;
    }

    for(int i=2; i<sm[0]-2; i+=MaxSize-2) {
    cout << MaxSize << endl;
        for(int j=2; j<sm[1]-2; j+=MaxSize-1) {
            writeBoxLine(t, i,j, MaxSize-1, MaxSize-1, sm);
        }
    }
}

void MapGen::setNewKey(int **t, int sm[]) {
    for(int i=0; i<sm[0]; i++) {
        for(int j=0; j<sm[1]; j++) {
            if(t[i][j] == 1) {
                t[i][j] = 3;
            } else if(t[i][j] == 7) {
                t[i][j] = 1;
            } else if(t[i][j] == 8) {
                t[i][j] = 3;
            } else if(t[i][j] == 1) {
                t[i][j] = 3;
            }

        }
    }
}

void MapGen::drawBorder(int **t, int sm[]) {
    for(int i=0; i<sm[0]; i++) {
        for(int j=0; j<sm[1]; j++)
            if(i==0||i==sm[0]-1 || j==0 || j==sm[1]-1) {
                t[i][j] = 3;
        }
    }
    int n=rand()%sm[0];
    t[n][0] = 7;
    t[n][sm[1]-1] = 7;

}

MapGen::MapGen(){
    srand(time(0));
    int sm[2] = {0,0};
    sm[1] = config::MapSizeX;
    sm[0] = config::MapSizeY;

    int **t=new int*[sm[0]];
    initialze(t, sm);


    makePattBox(t, sm);cout << "genCom";
    playerRes(t, sm, 5);
    playerRes(t, sm, 2);
    playerRes(t, sm, 2);
    playerRes(t, sm, 2);
    playerRes(t, sm, 2);
    playerRes(t, sm, 2);
    playerRes(t, sm, 2);
    playerRes(t, sm, 2);

    playerRes(t, sm, 9);
    playerRes(t, sm, 9);
    playerRes(t, sm, 9);
    playerRes(t, sm, 9);

    //playerRes(t, sm, 0);

    setNewKey(t, sm);
    drawBorder(t, sm);
    writeFile(t, sm);
    showMaze(t, sm);

}
