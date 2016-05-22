#include "display.h"
#include "windows.h"
#include "textColor.h"

#include <iostream>
using namespace std;

Render::Render() {}

Render::Render(char **mmp, int const &msx,int const &msy ) {
    gmap = mmp;
    sx = msx;
    sy = msy;
}

void Render::setColor(char& ch) {
    switch(ch) {
    case '1':
        SetTextColorStr(ch, 6,1 );
        break;
    case '2':
        SetTextColorStr(ch,9,8);
        break;
    case '3':
        SetTextColorStr(ch,5,3);
        break;
    case '5':
        SetTextColorStr(ch,9,7);
        break;
    case '7':
        SetTextColorStr(ch,4,5);
        break;
    case '9':
        SetTextColorStr(ch,9,10);
        break;
    default:
        SetTextColorStr(ch,9,10);
        break;

    }
}

int Render::setCursorPositiona(int x, int y) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(output, pos);
}

void Render::update() {
    int ff=0;
    setDisplaySize(sx,sy+2);
    setCursorPositiona(0,0);
    for(int i=0; i<sy; i++) {
        for(int j=0; j<sx; j++) {
            setCursorPositiona(j,i);
            setColor( gmap[i][j]);
            if(j!=sx-1)cout <<"";
        }
        if(i!=sy-1)cout << "\n";
    }
}

void Render::setDisplaySize(int x, int y) {
    SMALL_RECT r = {0, 0, x, y};
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &r);
}
