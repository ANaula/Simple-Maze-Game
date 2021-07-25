#pragma once
#include "Entity.h"
class ObstacleM :
    public Entity
{
    //class for moving obstacles

private:
public:
    //constructor/deconstructor
    ObstacleM(float xPos, float yPos, float length, float height, float movementSpeed, bool vMove);
    ~ObstacleM();

    //getters
    sf::RectangleShape* returnShape();

    //bool to see if moving vertically or side to side
    bool vMove;

    //update/render
    void update();
    void render(sf::RenderTarget* target);
};

