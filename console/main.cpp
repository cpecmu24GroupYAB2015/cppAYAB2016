#include <iostream>
#include <string>
#include "textColor.h"
#include <windows.h>
#include "cls.h"
#include "engine.h"
#include "menuFunc.h"

#include "mapGen.h"
#include "config.h"

#include "serve.h"

#include <cstdlib>
#include <ctime>
#include <ctime>

#include "loadMap.h"
#include "display.h"

#include "conio.h"

extern int mSizeX;
extern int mSizeY;


using namespace std; // std::cout, std::cin
void SearchWeb( string word )
{
    string base_URL = "http://www.bing.com/search?q=";
    string search_URL = "dummy";
    search_URL = base_URL + word;

    cout << "Searching for: \"" << word << "\"\n";

    ShellExecuteA(NULL, "open", search_URL.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

int main() {
    srand(time(0));
    Menu menu;

    while(1){
        menu.loadMenuStd();
    }


    cout << "ddd";




    /*while(1) {
        m.basic(config::MapSizeX,config::MapSizeY);
        i++;
        m.showMaze(m.t,config::MapSizeX,config::MapSizeY);
        m.setCursorPositiona(0,0);
        cout << "x";
        Sleep(100);
    }*/


}
