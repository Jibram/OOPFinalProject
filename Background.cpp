#include "Background.h"

Background::Background(char* roadImage){
    roadHouse.push_back(new TexRect(roadImage, -2, 1, 4, 2));
}

void Background::draw(float z) const{
    info->draw(.1);
    for (int i = 0; i < roadHouse.size(); i++){
        roadHouse[i]->draw(z);
    }
}

Background::~Background(){
    delete info;
    
    for (int i = 0; i < roadHouse.size(); i++){
        delete roadHouse[i];
    }
}