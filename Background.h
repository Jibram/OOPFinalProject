#ifndef Background_h
#define Background_h

#include "TexRect.h"
#include "TextBox.h"
#include <vector>

class Background{
    std::vector<TexRect*> roadHouse;
    TextBox* scoreInfo;
    TextBox* levelInfo;

public:


    Background(char*);

    void setText(int, int);

    void draw(float z) const;

    ~Background();

};

#endif