#include "MenuState.h"
#include "StateManager.h"
#include <SFML/Window/Event.hpp>
#include "ScoreState.h"
#include "GameState.h"
#include "MapGen.h"
#include <SFML/Graphics.hpp>
namespace edy {
namespace state {
void MenuState::run(core::PointerPack& pack) {
    MapGen eee;
    mTitle.setFont(*pack.Font);
    mPlay.setFont(*pack.Font);
    mMul.setFont(*pack.Font);
    mHigh.setFont(*pack.Font);
    mQuit.setFont(*pack.Font);

    mTitle.setString("Copy & Paste\n Project");
    mPlay.setString("[P]lay Single!");
    mMul.setString("[M]ulti Player");
    mHigh.setString("[H]igh Scores!");
    mQuit.setString("[Q]uit!");




    //mTitle.setPosition(0.f,75.f);
    mTitle.setCharacterSize(50);
    mTitle.setPosition(pack.Window->getSize().x/2 - (mTitle.getLocalBounds().width/2),50.f );
    //std::cout << "\ndddd" << mTitle.getGlobalBounds();
    mPlay.setPosition(150.f,200.f);
    mMul.setPosition(150.f,235.f);
    mHigh.setPosition(150.f,270.f);
    mQuit.setPosition(150.f,305.f);


    /*if (!BackgroundTexture.loadFromFile("bg.jpg", sf::IntRect(10, 10, 32, 32)))
        throw "Failure!";
    windowBg.setTexture(BackgroundTexture);*/

    sf::Event eve;
    while(true) {
        while(pack.Window->pollEvent(eve)) {
            if(eve.type==sf::Event::Closed||(eve.type==sf::Event::KeyPressed&&eve.key.code==sf::Keyboard::Q)) {
                mQuit.setColor(sf::Color(255,0,0));
                mQuit.setStyle(sf::Text::Underlined);
                pack.Window->draw(mQuit);
                pack.Window->display();
                sf::sleep(sf::Time(sf::seconds(1.f)));
                mQuit.setColor(sf::Color(255,255,255));
                mQuit.setStyle(sf::Text::Regular);
                pack.Manager->popTop(100);
                return;
            } else if(eve.type==sf::Event::KeyPressed) {
                if(eve.key.code==sf::Keyboard::P) {
                    mPlay.setColor(sf::Color(255,0,0));
                    mPlay.setStyle(sf::Text::Underlined);
                    pack.Window->draw(mPlay);
                    pack.Window->display();
                    sf::sleep(sf::Time(sf::seconds(1.f)));
                    mPlay.setColor(sf::Color(255,255,255));
                    mPlay.setStyle(sf::Text::Regular);
                    pack.Manager->pushTop(new GameState());
                    return;
                }
                if(eve.key.code==sf::Keyboard::H) {
                    mHigh.setColor(sf::Color(255,0,0));
                    mHigh.setStyle(sf::Text::Underlined);
                    pack.Window->draw(mHigh);
                    pack.Window->display();
                    sf::sleep(sf::Time(sf::seconds(1.f)));
                    mHigh.setColor(sf::Color(255,255,255));
                    mHigh.setStyle(sf::Text::Regular);
                    pack.Manager->pushTop(new ScoreState(-1));
                    return;
                }
                if(eve.key.code==sf::Keyboard::M) {
                    mMul.setColor(sf::Color(255,0,0));
                    mMul.setStyle(sf::Text::Underlined);
                    pack.Window->draw(mMul);
                    pack.Window->display();
                    sf::sleep(sf::Time(sf::seconds(1.f)));
                    mMul.setColor(sf::Color(255,255,255));
                    mMul.setStyle(sf::Text::Regular);

                }
            }
        }
        pack.Window->clear();
        pack.Window->clear(sf::Color(5,220,15));
        pack.Window->draw(windowBg);
        pack.Window->draw(mTitle);
        pack.Window->draw(mPlay);
        pack.Window->draw(mMul);
        pack.Window->draw(mHigh);
        pack.Window->draw(mQuit);
        pack.Window->display();

    }
}
}
}
