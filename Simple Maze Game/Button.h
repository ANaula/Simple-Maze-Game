#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

//to differentiate button reactions
enum button_states {BTN_IDLE=0, BTN_HOVER,BTN_ACTIVE};

class Button
{
private:
	//button variables
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	//constructor/deconstructor
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	//function that checks if button is pressed
	const bool isPressed() const;

	//getter
	int getWidth();

	//update/render
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

