#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <map>

class Entity
{
private:

protected:
	sf::RectangleShape shape;

public:
	Entity();
	virtual ~Entity();

	float movementSpeed;


	virtual void move(const float dir_x, const float dir_y);
	virtual void setSpeed(float movementSpeed);
	virtual void invertMovement();
	virtual void setSize(float length, float height);

	virtual void update()=0;
	virtual void render(sf::RenderTarget* target)=0;

};

