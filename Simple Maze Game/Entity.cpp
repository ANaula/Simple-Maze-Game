#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
	this->movementSpeed = 4.0f;
}

Entity::~Entity()
{
}




void Entity::move(const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed, dir_y * this->movementSpeed);
}

void Entity::setSpeed(float movementSpeed)
{
	this->movementSpeed = movementSpeed;
}

void Entity::invertMovement()
{
	this->movementSpeed = -this->movementSpeed;
}

void Entity::setSize(float length, float height)
{
	shape.setSize(sf::Vector2f(length, height));
}


