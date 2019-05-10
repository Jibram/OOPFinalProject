#ifndef Obstacle_h
#define Obstacle_h

#include "TexRect.h"
#include <string>

class Obstacle{

    char* filename;

    TexRect* obstacle;

public:

    Obstacle(char*, float, float, float, float);

    void draw() const;

    void setY(float);

    float getY();

    ~Obstacle();

};

#endif