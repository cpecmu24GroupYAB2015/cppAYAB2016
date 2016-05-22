#ifndef MENUFUNCTION_H
#define MENUFUNCTION_H
class Menu{
public:


    Menu();
    void loadUI();
    void run();
    int mList();

    int loadMenuStd();

    // Mode
    void loadSingle();
    void loadMulti();
    void loadHigh();
    void loadCreate();
};
#endif
