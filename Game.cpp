#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#include "Game.h"
#include "./images/filenames.h"

#define LEFT_BOUND 
#define SHIFT_OFFSET 

Game::Game(){
	const char* carFileName;
    const char* fireballFileName;

	carFileName = "./images/carWithProf.png";
	fireballFileName = "fireball.bmp";

    background = new Background("./images/road2.png");
    car = new TexRect(carFileName, -0.25, -0.5, .5, .5);
    object1 = new Obstacle("mushroom.png", -0.25, 1.0, .5, .5, 0.001);
    object2 = new Obstacle("mushroom.png", 5, 5, .5, .5, 0.001);
    prof = new TexRect("./images/prof.png", 5, 5, .2, .35);

    left = false;
    right = false;
    carVisible = true;
    level = 1;
    score = 0;
    setRate(1);
    stop();
}

void Game::action(){
    if (carVisible){

        if (object1->contains(car->getX()+car->getW()/2, car->getY()) || 
            object1->contains(car->getX()+car->getW()/2, car->getY()-car->getH()/2) || 
            object2->contains(car->getX()+car->getW()/2, car->getY()) || 
            object2->contains(car->getX()+car->getW()/2, car->getY()-car->getH()/2)){

            carVisible = false;
            prof->setX(car->getX());
            prof->setY(car->getY());
        
        } else if (object1->getY() < -1 || object2->getY() < -1){
            object1->setX(rand()%3*1.25-1.5);
            object1->setY(1.5);
            if (level > 1){
                object2->setX(rand()%3*1.25-1.5);
                object2->setY(1.5);
            }
            score++;
            level = score / 10 + 1;
            background->setText(score, level);
        } else {
            object1->setY(object1->getY()-level*object1->getSpeed());
            if (level > 1){
                object2->setY(object2->getY()-level*object2->getSpeed());
            }
        }
    }
    else {
        if (prof->getY() < 1.5){
            prof->setY(prof->getY() + 0.0025);
        }
    }
}

void Game::draw() const {
    background->draw(0);
    if (carVisible){
        car->draw(0.1);
        object1->draw(0.2);
        object2->draw(0.2);
    }
    else{
        prof->draw(0.3);
    }
    
}

int Game::getScore() const{
    return this->score;
}

void Game::handleKeyDown(unsigned char key, float x, float y){
    if (key == 'p'){
        stop();
    }
    else if (key == 'r'){
        start();
    }
    else if (carVisible){
        if (key == 'a'){
            // Case where it's on the right
            if (right == true){
                right = false;
                car->setX(-0.25);
            }
            // Case where it's in the middle
            else if (left == false){
                left = true;
                car->setX(-1.50);
            }
            // Nothing happens unless right or middle.
        }
        else if (key == 'd'){
            // Case where it's on the left
            if (left == true){
                left = false;
                car->setX(-0.25);
            }
            // Case where it's in the middle
            else if (right == false){
                right = true;
                car->setX(1);
            }
            // Nothing happens unless left or middle.
        }
    } 
    
    
    
}

Game::~Game(){
    stop();
    delete car;
    delete background;
    delete object1;
    delete object2;
    //delete explosion;
}
