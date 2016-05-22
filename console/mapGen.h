#ifndef MAPGEN_H
#define MAPGEN_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;
class MapGen {
public:
    int sm[2] = {0,0};
    int **t;
    MapGen();
    MapGen( int mSx, int mSy);
    void showMaze(int **ptr, int x, int y);
    void writeFile(int **ptr, int sm[]);
    void initialze(int **t, int sm[]);
    int randBoxSize() ;
    int randPos(int posMax);
    void writeBoxLine(int **t, int x1, int y1, int w, int h);
    void playerRes(int **t, int sm[], int p);
    void makePattBox(int **t, int x, int y);
    void setNewKey(int **t, int sm[]);
    void drawBorder(int **t, int sm[]);

    void setColor(int &ptr);
    void basic(int mSx, int mSy);

    void delStrack(int **ptr, int x, int y);

    int setCursorPositiona(int , int );

};

#endif
