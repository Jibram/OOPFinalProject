#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
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
    obstacles.push_back(new Obstacle("mushroom.png", -0.25, 1.0, .5, .5));
    //explosion = new AnimatedRect(fireballFileName, 6, 6, 64, false, false, -0.25, 0.8, 0.5, 0.5);

    left = false;
    right = false;
    carVisible = true;
    crashed = false;
    level = 1;
    
    setRate(1);
    start();
}

void Game::action(){
    // THis is cursed code, fix this
    for (int i = 0; i < obstacles.size(); i++){
        if (obstacles[i]->getY() < -1){
            obstacles.push_back(new Obstacle("mushroom.png", 0.5, 0.5, 0.5, 0.5));
            obstacles.erase(obstacles.begin()+i);
            i--;
        } else {
            obstacles[i]->setY(obstacles[i]->getY()-0.001);
        }
    }
}

void Game::draw() const {
    background->draw(0);
    if (carVisible){
        car->draw(0.2);
    }
    for (auto it = obstacles.begin(); it != obstacles.end(); ++it){
        (*it)->draw();
    }
}

void Game::handleKeyDown(unsigned char key, float x, float y){
    if (key == 'p'){
        stop();
    }
    else if (key == 'r'){
        start();
    }
    else if (key == 'a'){
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

Game::~Game(){
    stop();
    delete car;
    //delete explosion;
}
