// Pacman.cpp : Defines the entry point for the console application.
//

#include "StateManager.h"
#include "MenuState.h"
#include <iostream>
#include "config.h"
#include "MapGen.h"

#include "fio.h"

int main() {

    FileIO fn("nano mota3");
    cout << fn.getNameList();
    //cout << fn.hasName("sara");
    //fn.addName("sara",5);
    //fn.addName("baba",5);
    /*edy::core::StateManager app;
    app.pushTop(new edy::state::MenuState);
    app.gameRun();*/
}
