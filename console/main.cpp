#include <iostream>
#include <string>
#include "textColor.h"
#include <windows.h>
#include "cls.h"
#include "engine.h"
#include "menuFunc.h"

#include "mapGen.h"
#include "config.h"

#include <cstdlib>
#include <ctime>
#include <ctime>



using namespace std; // std::cout, std::cin

int main(){
srand(time(0));
    Menu menu;
    Engine engine;
    srand(time(0));
    MapGen m(config::MapSizeX,config::MapSizeY);
    int i=1;
    while(1){
        if(i%2==0){
            config::MapSizeX = 20+rand()%30;
            config::MapSizeY = 20+rand()%30;
            m.basic(config::MapSizeX,config::MapSizeY);
        }
        i++;
        cout << config::MapSizeX << endl;
        cout << config::MapSizeY << endl;
        m.showMaze(m.t,m.sm);

        Sleep(1000);
        system("cls");
    }


}
