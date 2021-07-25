#pragma once
#include "State.h"
#include "Player.h"
#include "ObstacleM.h"
#include "PauseState.h"
#include "Stages.h"

class GameState :
    public State
{private:
    Player player;
    sf::RectangleShape* shape;
    int level;

    std::vector<Stages> stageStates;
    std::vector <sf::RectangleShape>* nonMovingShapes;
    std::vector <ObstacleM>* movingShapes;
    sf::RectangleShape* winZone;
    
    sf::Font font;


    void initStages();
    void checkForPause();

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void initVariables();
    void initObstacles();
    void initFonts();

    bool checkStagePart();
    void setObstacles();
    void updatePlayerMovement();

    void checkCollision();
    void nextStage();


    void update();
    void render(sf::RenderTarget* target = nullptr);
};

