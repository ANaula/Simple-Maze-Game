#include "Button.h"

Button::Button(float x, float y,  float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	// creates button depending on what is given in the argument

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.0f) - this->text.getGlobalBounds().width / 2.0f, this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.0f) - this->text.getGlobalBounds().height / 2.0f);

	this->buttonState = NULL;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{
}

const bool Button::isPressed() const
{
	//checks to see if button is pressed
	if (this->buttonState == BTN_ACTIVE) {
		return true;
	}
	return false;
}

int Button::getWidth()
{
	return shape.getSize().y;
}

void Button::update(const sf::Vector2f mousePos)
{
	//checks to see if buttons is idle, if mouse is hovering over the button, or if button is clicked and changes button color depending on this.
	this->buttonState = BTN_IDLE;

	if (this->shape.getGlobalBounds().contains(mousePos)) {
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState) {
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}


void Button::render(sf::RenderTarget* target)
{
	//renders button
	target->draw(this->shape);
	target->draw(this->text);
}
