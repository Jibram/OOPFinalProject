#include "Obstacle.h"
#include <iostream>

Obstacle::Obstacle(char* filename, float x, float y, float w, float h, float speed): TexRect(filename, x, y, w, h), speed(speed){

}

float Obstacle::getSpeed(){
    return this->speed;
}

Obstacle::~Obstacle(){
}