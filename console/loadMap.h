#ifndef LOADMAP_H
#define LOADMAP_H

#include <vector>
#include <string>

using namespace  std;

class loadMap{
    private:
        vector<string> dataMap;
        char **gMap;
    public:
     loadMap();

     void intialization();
     void loadData();
     void show();

     bool readFile();

     void setMap(char**);

     char ** getMap();
     vector<string> getData();
};

#endif
