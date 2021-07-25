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
	//base class for players and moving obstacles
private:

protected:
	sf::RectangleShape shape;

public:
	//constructor/deconstructor
	Entity();
	virtual ~Entity();

	//variable for movement speed
	float movementSpeed;

	//functions that control movement

	virtual void move(const float dir_x, const float dir_y);
	virtual void setSpeed(float movementSpeed);
	virtual void invertMovement();

	//setter
	virtual void setSize(float length, float height);

	//virtual update and render
	virtual void update()=0;
	virtual void render(sf::RenderTarget* target)=0;

};

