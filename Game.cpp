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
    //const char* fireballFileName;

	carFileName = "./images/carWithProf.png";
	//fireballFileName = "fireball.bmp";

    background = new Background("./images/road2.png");
    car = new TexRect(carFileName, -0.25, -0.5, .5, .5);
    obstacles.push_back(new Rect( -0.25, 1.0, .5, .5, 1, 1, 1));
    //explosion = new AnimatedRect(fireballFileName, 6, 6, 64, false, false, -0.25, 0.8, 0.5, 0.5);

    left = false;
    right = false;
    carVisible = true;
    level = 1;
    score = 0;
    setRate(1);
    start();
}

void Game::action(){
    bool passed = false;
    for (int i = 0; i < obstacles.size(); i++){
        if (obstacles[i]->contains(car->getX()+car->getW()/2, car->getY()) || obstacles[i]->contains(car->getX()+car->getW()/2, car->getY()-car->getH()/2)){
            carVisible = false;
        } else if (obstacles[i]->getY() < -1){
            obstacles.erase(obstacles.begin()+i);
            i--;
            obstacles.push_back(new Rect(rand()%3*1.25-1.5, 1.5, 0.5, 0.5, 1, 1, 1));
            passed = true;
        } else {
            obstacles[i]->setY(obstacles[i]->getY()-level*0.001);
        }
    }
    if (passed){
        score++;
        level = score / 10 + 1;
        background->setText(score, level);
        passed = false;
    }
    if (level > 1 && obstacles.size() < 2){
        obstacles.push_back(new Rect(rand()%3*1.25-1.5, 1.5, 0.5, 0.5, 1, 1, 1));
    }
}

void Game::draw() const {
    background->draw(-0.2);
    if (carVisible){
        car->draw(-0.1);
    }
    for (auto it = obstacles.begin(); it != obstacles.end(); ++it){
        (*it)->draw();
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
    obstacles.empty();
    //delete explosion;
}
