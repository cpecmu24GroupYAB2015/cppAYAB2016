#include "timer.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

Timmer::Timmer(){
}

bool Timmer::defTime(int delay){
    int time1=time(0);
    if(activeTimeCout){
        time0 = time(0);
        activeTimeCout = false;
    }else{
        if(time1-time0 == delay){
            activeTimeCout = true;
            return true;
        }
    }return false;
}
