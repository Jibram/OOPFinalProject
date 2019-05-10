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
    std::vector<Obstacle*> obstacles;
    bool left;
    bool right;
    bool carVisible;
    bool crashed;
    int level;
    
    //void setObstacleFileNames(std::vector<std::string>);
public:
    //AnimatedRect* explosion;
    Game();
    
    void draw() const ;
    void handleKeyDown(unsigned char, float, float);
    
    void action();

    ~Game();

};

#endif 
