#include "Map_draw.h"
namespace engine{
    /*bool engine::Map::enterable(unsigned char number){
        if (number==edy::pac::PacEngine::Wall)
            return false;
        return true;
    }*/
    void Map::drawHorizontalLine(sf::RenderTarget& rt,int x1,int x2,int y){
        sf::Vertex arr[4];
        arr[0].color=sf::Color::Blue;
        arr[1].color=sf::Color::Blue;
        arr[2].color=sf::Color::Blue;
        arr[3].color=sf::Color::Blue;
        arr[0].position=sf::Vector2f(16.f*(x1+0.5f),16.f*(y+0.5f)-1.5f);
        arr[1].position=sf::Vector2f(16.f*(x1+0.5f),16.f*(y+0.5f)+1.5f);
        arr[2].position=sf::Vector2f(16.f*(x2+0.5f),16.f*(y+0.5f)+1.5f);
        arr[3].position=sf::Vector2f(16.f*(x2+0.5f),16.f*(y+0.5f)-1.5f);
        rt.draw(arr,4,sf::Quads);
    }

    void Map::drawVerticalLine(sf::RenderTarget& rt,int y1,int y2,int x){
        sf::Vertex arr[4];
        arr[0].color=sf::Color::Blue;
        arr[1].color=sf::Color::Blue;
        arr[2].color=sf::Color::Blue;
        arr[3].color=sf::Color::Blue;
        arr[0].position=sf::Vector2f(16.f*(x+0.5f)-1.5f,16.f*(y1+0.5f));
        arr[1].position=sf::Vector2f(16.f*(x+0.5f)+1.5f,16.f*(y1+0.5f));
        arr[2].position=sf::Vector2f(16.f*(x+0.5f)+1.5f,16.f*(y2+0.5f));
        arr[3].position=sf::Vector2f(16.f*(x+0.5f)-1.5f,16.f*(y2+0.5f));
        rt.draw(arr,4,sf::Quads);
    }

    int Map::fitBetween(int a,int b,int c){
		return std::min(std::max(a,b),c);
	}

	sf::Vector2i getPosFromNode(int x,int y){
		return sf::Vector2i(x*16+8,y*16+8);
	}

	int get2DistanceFromNodes(sf::Vector2i first,sf::Vector2i second){
		return (first.x-second.x)*(first.x-second.x)+(first.y-second.y)*(first.y-second.y);
	}
}

