#include "ObstacleM.h"

ObstacleM::ObstacleM(float xPos, float yPos, float length, float height, float movementSpeed, bool vMove) : Entity()
{
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
	target->draw(this->shape);
}


