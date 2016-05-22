#ifndef GAMENGINE_H
#define GAMENGINE_H
#include "config.h"
#include <string>
using namespace std;
#include "conio.h"

#include "timer.h"

class Engine{


    private:
    char **emap;
    int **playerPos;
    int nBot=0,nPlayer=0;
    int key=1,kex=0;
    char psk;
    bool active=true;

    Timmer t0;




    //Static Data
    char charOfName[2] = {'X','Y'};

    //Direction Data
    char fourVision[4] = {'1','1','1','1'};
    char postPos[2];



    public:
    Engine();
    Engine(char **);

    void intializ();
    bool gameActive();


    void setStartPos(unsigned char ** gMap, int x, int y);
    void setPosition(unsigned char ** gMap, int x, int y);

    //Algorithm
    void findPlayer(char);
    void moveToPos(char , int x, int y);
    int getPlayerPos(char axis);

    //Game
    bool isTouch(char);
    void gameCollision();


    void setMap(char **);
    char **getNewMap();

    //Game Control
    void keypress();
    void findVision();

    //Game Interface
    void getGameUI();

    //Game Function
    void gamePause();
    void addValue(char, int);
    void subValue(char, int);



    //Player Configuration
    void countPlayer();
    void repPlayerName( char);

    //On line Function
    void createRoom();
    void joinRoom();

    int createRoomId();


};
#endif
