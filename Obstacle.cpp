#include "Obstacle.h"

Obstacle::Obstacle(char* filename, float x, float y, float w, float h){
    obstacle = new TexRect(filename, x, y, w, h);
}

void Obstacle::draw() const{
    obstacle->draw(.7);
}

void Obstacle::setY(float val){
    obstacle->setY(val);
}

float Obstacle::getY(){
    return obstacle->getY();
}

Obstacle::~Obstacle(){
    
}