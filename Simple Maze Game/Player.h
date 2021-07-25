#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:

public:
    Player();
    ~Player();
    
    sf::RectangleShape* getShape();

    void rePosition(float x, float y);
    

    void update();
    void render(sf::RenderTarget* target);

};

