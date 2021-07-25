#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:

public:
    //constructor/deconstructor
    Player();
    ~Player();
    
    //getter
    sf::RectangleShape* getShape();

    //reposition player location
    void rePosition(float x, float y);
    
    //update/render
    void update();
    void render(sf::RenderTarget* target);

};

