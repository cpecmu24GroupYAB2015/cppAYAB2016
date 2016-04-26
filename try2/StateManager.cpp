#include "StateManager.h"
#include "State.h"
#include "config.h"
namespace edy {
namespace core {
StateManager::StateManager() {

    int wgetx = (448*config::MapSizeX)/28;
    int wgety = (576*config::MapSizeY)/31;
    /*if(wgetx<448||wgety<576) {
        wgetx = 448;
        wgety = 576;
    }*/
    mWindow.create(sf::VideoMode(wgetx,wgety),"Copy&Paste Project",sf::Style::Close|sf::Style::Titlebar);//448 576
    //mWindow.setFramerateLimit(60);//60 fps max
    mFont.loadFromFile("DejaVuSans.ttf");
    mPack.Font=&mFont;
    mPack.Manager=this;
    mPack.Window=&mWindow;
}
StateManager::~StateManager() {
    popTop(mStates.size());
    clearStacks();
}
void StateManager::popTop(int amount) {
    amount=std::min(amount,static_cast<int>(mStates.size()));
    for(int i=0; i<amount; ++i) {
        mClear.push(mStates.top());
        mStates.pop();
    }
}
void StateManager::leaveBottom(int amount) {
    popTop(mStates.size()-amount);
}
void StateManager::pushTop(State * state) {
    mStates.push(state);
}
void StateManager::gameRun() {
    while(!mStates.empty()) {
        mStates.top()->run(mPack);
        clearStacks();
    }
}
void StateManager::clearStacks() {
    while(!mClear.empty()) {
        delete mClear.top();
        mClear.pop();
    }
}
}
}
