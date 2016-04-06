#ifndef BOT_H
#define BOT_H

#include <string>
#include <iostream>
#include <string>
using namespace std;

class Bot{
private:
    int x;
    int y;
    string name;
public:
    Bot();
    Bot(string);
    void think();
    string getName();
    void getPos();
    void setName(string);
    void showName();

    ~Bot();
};

#endif // BOT_H
