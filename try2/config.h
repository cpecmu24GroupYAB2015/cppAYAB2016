#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
namespace config {

//Debug! Axis-Y should smaller axis-X and Mod 4 ==0
static int MapSizeX = 30;
static int MapSizeY = 32;

static int maxLive = 2;
static string elemntSpr = "element.tga";
static string fonts = "DejaVuSans.ttf";

static int pacSpeed = 3;
//31

static string str_mTitle = "Lnwza007";
static string mScoreTitleTex = "Hall Of Frame";
}
#endif // CONFIG_H
