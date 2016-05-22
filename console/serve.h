#ifndef SERVER_H
#define SERVER_H

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Serv{
    public:
    int ping=0;
    string connect(string);
    void createRoom(int );
    void joinRoom(int );

    //Data Sender
    void sendPos(int , int);
    void sendMao(string);

    void test();

};

#endif // SERVER_H
