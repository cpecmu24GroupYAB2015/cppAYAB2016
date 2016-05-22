#ifndef CONFIG_H
#define CONFIG_H

#include <string>
using namespace std;

namespace config {
//Server Connect
static string serverName = "The Base";
static string serverLocal = "http://4nd.me";
static string sverFile = "getPost.php";

}







namespace lang {
//Menu Lang
static string mTitle = "The Maze Runner";
static string mWelCome = "Welcome to";
static string mPlay_sing = "[1] Single Player";
static string mPlay_multi = "[2] Multi Player";
static string mHigh = "[3] Hight Score";
static string mNewMap = "[4] Create New Map";
static string mQuit = "[5] Quit";

//Error Msg
static string eFileErr = "File Error";
static string eFileNotFound = "File Not Found!";
static string eMapErr = "Cannot Loading Map";

//Game Engine
static string gamePause = "Game Pause";
static string gamePauseMsg = "please select menu";
static string gamePauseM1 = "[Q] Resume";
static string gamePauseM2 = "[W] Goto main menu";
static string gamePauseM3 = "[E] Save and Exit";


}


#endif // CONFIG_H
