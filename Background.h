#ifndef Background_h
#define Background_h

#include "TexRect.h"
#include <vector>

class Background{
    TexRect* info;
    std::vector<TexRect*> roadHouse;

public:

    Background(char*);

    void draw(float z) const;

    ~Background();

};

#endif