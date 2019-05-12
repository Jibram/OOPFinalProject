#include "Background.h"
#include <sstream>
#include <string>
#include <iostream>

Background::Background(char* roadImage){
    levelInfo = new TextBox("LEVEL:1", -1.50, .9, GLUT_BITMAP_HELVETICA_18, 0, 1, 0, 14);
    scoreInfo = new TextBox("DODGED:0", 1.25, .9, GLUT_BITMAP_HELVETICA_18, 0, 1, 0, 14);
    roadHouse.push_back(new TexRect(roadImage, -2, 1, 4, 2));
}

void Background::draw(float z) const{
    levelInfo->draw();
    scoreInfo->draw();
    for (int i = 0; i < roadHouse.size(); i++){
        roadHouse[i]->draw(z);
    }
}

void Background::setText(int score, int level){
    std::stringstream str;
    str << score;
    scoreInfo->setText("DODGED:" + str.str());
    str.str(std::string());
    str << level;
    levelInfo->setText("LEVEL:" + str.str());
}

Background::~Background(){
    delete scoreInfo;
    delete levelInfo;
    
    for (int i = 0; i < roadHouse.size(); i++){
        delete roadHouse[i];
    }
}