#ifndef CONFIG_H
#define CONFIG_H
#include <string>
using namespace std;
namespace config{
//int MapSizeX = 30;
    //Static Value
    static int MapSizeX = 30;
    static int MapSizeY = 30;
    static int Player1Life = 5;
    static int Player1Speed = 3;
    static int Player1Score = 0;
    static int Player1StartPosX = 1;
    static int Player1StartPosY = 1;

    //Server Connect
    static string serverName = "The Base";
    static string serverLocal = "http://localhost/";
    static string sverFile = "getPost.php";




}

namespace lang{
    //Menu Lang
    static string mTitle = "The Maze Runner";
    static string mWelCome = "Welcome to";
    static string mPlay_sing = "[1] Single Player";
    static string mPlay_multi = "[2] Multi Player";
    static string mHigh = "[3] Hight Score";
    static string mQuit = "[4] Quit";

    //Error Msg
    static string eFileErr = "File Error";
    static string eFileNotFound = "File Not Found!";
    static string eMapErr = "Cannot Loading Map";
}


#endif // CONFIG_H
