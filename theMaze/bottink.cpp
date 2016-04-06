#include <iostream>
#include <string>
#include "bottink.h"
using namespace std;

Bot::Bot(){
    setName("default");
}

Bot::Bot(string name){
    setName(name);

}

string Bot::getName(){
    return name;
}

void Bot::setName(string n){
    name = n;
}

void Bot::showName(){
    cout << getName();
}
