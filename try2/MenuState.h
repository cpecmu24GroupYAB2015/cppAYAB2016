#ifndef EE_MENUSTATE_H_INCLUDED
#define EE_MENUSTATE_H_INCLUDED
#include "State.h"
#include <SFML/Graphics.hpp>
namespace edy {
namespace state {
class MenuState : public core::State {
public:
    virtual void run(core::PointerPack& pack);
private:

    sf::Texture BackgroundTexture;
    sf::Sprite windowBg;
    sf::Text mTitle,mPlay,mHigh,mMul,mQuit;
    sf::Text mSave, mLoad;
};
}
}
#endif
