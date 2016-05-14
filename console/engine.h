#ifndef GAMENGINE_H
#define GAMENGINE_H
#include "config.h"
class Engine{

    public:
    Engine();
    unsigned char **gMap = new unsigned char* [config::MapSizeX];
    void setStartPos(unsigned char ** gMap, int x, int y);
    void setPosition(unsigned char ** gMap, int x, int y);

    bool scanNum(unsigned char **mmp);
    bool scanReplaceNum(unsigned char **mmp, char num, char rep);
    bool loadMapFile();
    void initializeVar();
};
#endif
