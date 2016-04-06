#ifndef BOTTHINK_H
#define BOTTHINK_H
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
};
#endif // BOTTHINK_H
