#include "serve.h"
#include "config.h"
#include "windows.h"
#include "cls.h"

#include <string>
#include <strstream>
#include <ctime>
using namespace std;

string Serv::connect(string comm) {
    int cc=0;
    int maxTry=5;
    clock_t tStart=clock();
    //while(1) {
        sf::Http::Request request("maze/maze.php", sf::Http::Request::Post);
        request.setBody(comm);

        sf::Http http(config::serverLocal);
        sf::Http::Response response = http.sendRequest(request);

        // check the status
        if (response.getStatus() == sf::Http::Response::Ok) {
            // check the contents of the response
            ping = clock()-tStart;
            return response.getBody().c_str();
            //break;
        } else {
            cc++;
            if(cc>maxTry) {
                cout << "Cannot connect, try New agin";
                exit(0);
            } else {
                cls();
                cout << "try connect [" << cc << "]/"<<maxTry<<"\n";
                for(int i=0; i<10; i++) {
                    cout << ".";
                    Sleep(100);
                }
                cout << endl;
                sf::Time t = sf::seconds(0.5f);
                sf::sleep(t);
            }

        }

    //}

}

void Serv::createRoom(int roomID) {
    ostringstream stream;
    stream << "rid=" <<roomID <<"&type=create";
    cout << connect(stream.str()) << " //";

}

void Serv::joinRoom(int roomID) {
    ostringstream stream;
    stream << "rid=" <<roomID <<"&type=join";
    connect(stream.str());
}

void Serv::sendPos(int x, int y){
    //return 0;
}



void Serv::test() {
    sf::Http http;
// We'll work on http://www.sfml-dev.org
    http.setHost("http://qwe.in.th/");
// Prepare a request to get the 'features.php' page
    //sf::Http::Request request("maze.php?rid=55&type=create");
    sf::Http::Request request("maze/maze.php",sf::Http::Request::Post);
    ostringstream stream;
    stream << "rid=1&type=create";
    request.setBody(stream.str());
// Send the request
    sf::Http::Response response = http.sendRequest(request);
// Check the status code and display the result
    sf::Http::Response::Status status = response.getStatus();
    if (status == sf::Http::Response::Ok) {
        std::cout << response.getBody() << std::endl;
    } else {
        std::cout << "Error " << status << std::endl;
    }
}



