#pragma once
#include "Entity.h"
class ObstacleM :
    public Entity
{
private:
public:
    ObstacleM(float xPos, float yPos, float length, float height, float movementSpeed, bool vMove);
    ~ObstacleM();

    sf::RectangleShape* returnShape();
    bool vMove;

    void update();
    void render(sf::RenderTarget* target);
};

