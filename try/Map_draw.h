#ifndef GE_MAPDRAW_H
#define GE_MAPDRAW_H
#include <SFML/Graphics.hpp>
#include <fstream>
namespace engine{
    class Map{
    public:
        bool enterable(unsigned char );
        void drawHorizontalLine(sf::RenderTarget& rt,int y1,int y2,int x);
        void drawVerticalLine(sf::RenderTarget& rt,int y1,int y2,int x);
        int fitBetween(int a,int b,int c);
        sf::Vector2i getPosFromNode(int x,int y);
        int get2DistanceFromNodes(sf::Vector2i first,sf::Vector2i second);

    };
}
#endif // GE_MAPDRAW_H
