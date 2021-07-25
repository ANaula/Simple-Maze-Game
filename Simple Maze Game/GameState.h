#pragma once
#include "State.h"
#include "Player.h"
#include "ObstacleM.h"
#include "PauseState.h"
#include "Stages.h"

class GameState :
    public State
{private:

    //Player variables
    Player player;
    sf::RectangleShape* shape;

    //Variables/functions for stage control
    int level;
    void initStages();

    std::vector<Stages> stageStates;
    std::vector <sf::RectangleShape>* nonMovingShapes;
    std::vector <ObstacleM>* movingShapes;
    sf::RectangleShape* winZone;
    void checkForPause();


    //font 
    sf::Font font;


public:
    //Constructor/Deconstructor
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //Initializations
    void initVariables();
    void initObstacles();
    void initFonts();

    //Functions for stage control
    bool checkStagePart();
    void setObstacles();
    void updatePlayerMovement();
    void nextStage();

    //Collision detection
    void checkCollision();

    //Update and Render functions
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

