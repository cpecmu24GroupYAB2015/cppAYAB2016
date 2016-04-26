#include "ScoreState.h"
#include "StateManager.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include <SFML/Window/Event.hpp>
#include "EEToString.h"

#include "fio.h"

using namespace std;
namespace edy {
namespace state {
ScoreState::ScoreState(int score):mWritingTo(-1),mScore(score) {
    mLines.resize(10);
    mLine.resize(10);

    mScoreTitle.setString("Hall Of Frame");
    mScoreTitle.setPosition(100.f,25.f);
    mScoreTitle.setCharacterSize(46);


    FileIO fn;

    int fnC = fn.nL.size();

    cout << fnC << endl;
    cout << "setData\n";
    if(mScore != -1){
        fn.addNameToDB("Player"+sup::toString(sup::toString(mScore)), mScore);
    }
    fn.bubleSort(fn.scL,fn.nL);
    fn.show(fn.scL, fn.nL);
    for(int i=0; i<fnC; i++){
        mLines[i].setPosition(100.f,150.f+25.f*i);
        mLine[i].setPosition(150.f,150.f+25.f*i);
        mLines[i].setCharacterSize(20);
        mLine[i].setCharacterSize(20);


        mLines[i].setString(sup::toString(fn.scL[i]));
        mLine[i].setString(sup::toString(sup::toString(fn.nL[i])));
    }
    cout << mScore;


    /*std::ifstream file("High.txt");
    int tmpscores[10];
    for(int i=0; i<10; ++i) { //wypelniamy liste
        mLines[i].setCharacterSize(20);
        //mLines[i].setPosition(100.f,25.f+25.f*i);
        //int tmp;
        std::string temp;
        file>>temp;
        file>>tmpscores[i];
        mLines[i].setString(temp+" "+sup::toString(tmpscores[i]));
    }
    for(int i=0; i<10; ++i) {
        if(tmpscores[i]<mScore&&mWritingTo<0) {
            sf::Text temp;
            temp.setCharacterSize(20);
            //temp.setPosition(100.f,25.f+25.f*i);
            temp.setString(" "+sup::toString(mScore));
            mWritingTo=i;
            mLines.insert(mLines.begin()+i,temp);
        }
    }
    mLines.resize(10);
    for(int i=0; i<10; ++i) {
        mLines[i].setPosition(100.f,25.f+i*25.f);
    }*/
    std::cout << "sss";
}
ScoreState::~ScoreState() {
    std::ofstream file("High.txt");
    for(int i=0; i<10; ++i) {
        file<<mLines[i].getString().operator std::string()<<std::endl;
        //file<<mLines2[i].getString().operator std::string()<<std::endl;
    }
}
void ScoreState::run(core::PointerPack& pack) {
    for(int i=0; i<10; ++i) {
        mLines[i].setFont(*pack.Font);
         mLine[i].setFont(*pack.Font);
    }
    mScoreTitle.setFont(*pack.Font);
    sf::Event eve;
    while(1) {
        while(pack.Window->pollEvent(eve)) {
            if(eve.type==sf::Event::Closed || eve.key.code==sf::Keyboard::Escape) {
                pack.Manager->leaveBottom(1);
                return;
            }
            if(eve.type==sf::Event::KeyPressed&&eve.key.code==sf::Keyboard::Return) {
                if(mWritingTo>=0) {
                    mWritingTo=-1;
                } else {
                    pack.Manager->leaveBottom(1);
                    return;
                }
            }
            if(eve.type==sf::Event::KeyPressed&&eve.key.code==sf::Keyboard::BackSpace) {
                if(!mWritingLine.empty()) {
                    mWritingLine.erase(--mWritingLine.end());
                    mLines[mWritingTo].setString(mWritingLine+sup::toString(mScore));
                }
            }
            if(eve.type==sf::Event::TextEntered&&eve.text.unicode>31&&eve.text.unicode<127&&eve.text.unicode!=' ') {
                if(mWritingTo>=0) {
                    mWritingLine+=static_cast<char>(eve.text.unicode);
                    mLines[mWritingTo].setString(mWritingLine+" "+sup::toString(mScore));
                }
            }
        }
        pack.Window->clear(sf::Color(255, 0 ,102));
        for(int i=0; i<10; ++i){
            pack.Window->draw(mLines[i]);
            pack.Window->draw(mLine[i]);
        }pack.Window->draw(mScoreTitle);


        pack.Window->display();
    }
}
}
}
