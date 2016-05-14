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
    int **t=new int*[sm[0]];
    MapGen();
    MapGen( int mSx, int mSy);
    void showMaze(int **ptr, int sm[]);
    void writeFile(int **ptr, int sm[]);
    void initialze(int **t, int sm[]);
    int randBoxSize() ;
    int randPos(int posMax);
    void writeBoxLine(int **t, int x1, int y1, int w, int h, int sm[]);
    void playerRes(int **t, int sm[], int p);
    void makePattBox(int **t, int sm[]);
    void setNewKey(int **t, int sm[]);
    void drawBorder(int **t, int sm[]);

    void setColor(int &ptr);
    void basic(int mSx, int mSy);

    void delStrack(int **ptr, int sm[]);

};

#endif
