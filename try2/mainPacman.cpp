// Pacman.cpp : Defines the entry point for the console application.
//

#include "StateManager.h"
#include "MenuState.h"
#include <iostream>
#include "config.h"
#include "MapGen.h"

int main() {
    edy::core::StateManager app;
    app.pushTop(new edy::state::MenuState);
    app.gameRun();
}
