#ifndef Game_hpp
#define Game_hpp
#include <vector>

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Background.h"
#include "Obstacle.h"

class Game: public AppComponent, private Timer{
    TexRect* car;
    Background* background; 
    Obstacle* object1;
    Obstacle* object2;
    TexRect* prof;
    bool left;
    bool right;
    bool carVisible;
    int level;
    int score;
    
    //void setObstacleFileNames(std::vector<std::string>);
public:
    AnimatedRect* explosion;
    Game();
    
    void draw() const ;
    int getScore() const;
    void handleKeyDown(unsigned char, float, float);
    
    void action();

    ~Game();

};

#endif 
