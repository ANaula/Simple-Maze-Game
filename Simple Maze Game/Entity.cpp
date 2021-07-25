#include "Entity.h"

Entity::Entity()
{
	//default size and speed
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
	this->movementSpeed = 4.0f;
}

Entity::~Entity()
{
}




void Entity::move(const float dir_x, const float dir_y)
{
	//moves entity depending on argument and movementspeed
	this->shape.move(dir_x * this->movementSpeed, dir_y * this->movementSpeed);
}

void Entity::setSpeed(float movementSpeed)
{
	this->movementSpeed = movementSpeed;
}

void Entity::invertMovement()
{
	//inverts movemement sppeed, makes entity go the opposite way of the direction they were going in.

	this->movementSpeed = -this->movementSpeed;
}

void Entity::setSize(float length, float height)
{
	shape.setSize(sf::Vector2f(length, height));
}


