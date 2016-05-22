#ifndef DISPLAYRENDER_H
#define DISPLAYRENDER_H
class Render {
private:
    char **gmap;
    int sx;
    int sy;
public:
    Render();
    Render(char **, int const &, int const&);
    void setColor(char&);
    int setCursorPositiona(int x, int y);
    void update();

    void setDisplaySize(int x, int y);
};



#endif
