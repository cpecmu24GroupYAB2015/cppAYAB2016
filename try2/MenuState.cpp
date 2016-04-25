#include "MenuState.h"
#include "StateManager.h"
#include <SFML/Window/Event.hpp>
#include "ScoreState.h"
#include "GameState.h"
#include "MapGen.h"
namespace edy {
namespace state {
void MenuState::run(core::PointerPack& pack) {
    MapGen eee;
    mTitle.setFont(*pack.Font);
    mPlay.setFont(*pack.Font);
    mMul.setFont(*pack.Font);
    mHigh.setFont(*pack.Font);
    mQuit.setFont(*pack.Font);

    mTitle.setString("PakMan");
    mPlay.setString("[P]lay!");
    mMul.setString("Muti Player");
    mHigh.setString("[H]igh Scores!");
    mQuit.setString("[Q]uit!");

    mTitle.setPosition(0.f,75.f);
    mPlay.setPosition(150.f,200.f);
    mMul.setPosition(150.f,235.f);
    mHigh.setPosition(150.f,270.f);
    mQuit.setPosition(150.f,305.f);
    sf::Event eve;
    while(true) {
        while(pack.Window->pollEvent(eve)) {
            if(eve.type==sf::Event::Closed||(eve.type==sf::Event::KeyPressed&&eve.key.code==sf::Keyboard::Q)) {
                pack.Manager->popTop(100);
                return;
            } else if(eve.type==sf::Event::KeyPressed) {
                if(eve.key.code==sf::Keyboard::P) {
                    pack.Manager->pushTop(new GameState());
                    return;
                }
                if(eve.key.code==sf::Keyboard::H) {
                    pack.Manager->pushTop(new ScoreState(-1));
                    return;
                }
            }
        }
        pack.Window->clear();
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
