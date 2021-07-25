#include "ObstacleM.h"

ObstacleM::ObstacleM(float xPos, float yPos, float length, float height, float movementSpeed, bool vMove) : Entity()
{
	//creates obstacle depending on what is given in the argument

	this->shape.setPosition(sf::Vector2f(xPos, yPos));
	this->shape.setFillColor(sf::Color::Red);
	setSpeed(movementSpeed);
	setSize(length, height);
	this->vMove = vMove;

}

ObstacleM::~ObstacleM()
{
}

sf::RectangleShape* ObstacleM::returnShape()
{
	return &shape;
}

void ObstacleM::update()
{
}

void ObstacleM::render(sf::RenderTarget* target)
{
	//renders moving obstacle
	target->draw(this->shape);
}


