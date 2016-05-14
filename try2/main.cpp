#include "StateManager.h"
#include "MenuState.h"
#include <iostream>
#include "config.h"
#include "MapGen.h"
#include <algorithm>

#include "fio.h"
#include "Server.h"
using namespace std;

int main() {



    /*FileIO fn;
    fn.addNameToDB("asd",99);
    fn.addNameToDB("asdasdad",12);
    fn.addNameToDB("ddd",95);
    fn.addNameToDB("ddwwww",15);
    fn.addNameToDB("qq eee",56);
    fn.bubleSort(fn.scL, fn.nL);
    //fn.findMaxScore(fn.scL);
    fn.show(fn.scL, fn.nL);*/

    //cout << fn.getNameList();
    //cout << fn.hasName("sara");
    //fn.addName("sara",5);
    //fn.addName("baba",5);
    edy::core::StateManager app;
    app.pushTop(new edy::state::MenuState);
    app.gameRun();
}
