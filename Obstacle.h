#ifndef Obstacle_h
#define Obstacle_h

#include "TexRect.h"
#include <string>

class Obstacle : public TexRect{

    float speed;
public:

    Obstacle(char*, float, float, float, float, float);

    float getSpeed();

    ~Obstacle();

};

#endif