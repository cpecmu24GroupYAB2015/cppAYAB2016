#include "windows.h"
#include <iostream>
#include <string>

void SetTextColorStr(char text, int font=1, int bg=0) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(bg>0) {
        if(font<0||font>16)font=1;
        if(bg>15)bg=1;
        SetConsoleTextAttribute(hConsole, (16*(bg))-1-(16-font));

    } else {
        if(font<0||font>15)font=1;
        SetConsoleTextAttribute(hConsole, font);
    }
    std::cout << text;
    SetConsoleTextAttribute(hConsole, 15);

}

void SetTextColorStr(int text, int font=1, int bg=0) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(bg>0) {
        if(font<0||font>16)font=1;
        if(bg>15)bg=1;
        SetConsoleTextAttribute(hConsole, (16*(bg))-1-(16-font));

    } else {
        if(font<0||font>15)font=1;
        SetConsoleTextAttribute(hConsole, font);
    }
    std::cout << text;
    SetConsoleTextAttribute(hConsole, 15);

}

void render() {
    //// unit Test Function
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i=0; i<255; i++) {
        SetConsoleTextAttribute(hConsole, i);
        std::cout << i << " ffffffffffff"<<std::endl;
    }

}
