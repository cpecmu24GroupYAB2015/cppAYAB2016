#ifndef MAPGEN_H
#define MAPGEN_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
class MapGen {
public:
    MapGen();
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

};

#endif
