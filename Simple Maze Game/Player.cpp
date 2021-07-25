#include "Player.h"

Player::Player():Entity()
{
	
}

Player::~Player()
{
}


sf::RectangleShape* Player::getShape()
{
	return &shape;
}

void Player::rePosition(float x, float y)
{
	this->shape.setPosition(sf::Vector2f(x, y));
}





void Player::update()
{
	
}

void Player::render(sf::RenderTarget* target)
{
		target->draw(this->shape);

	
}
