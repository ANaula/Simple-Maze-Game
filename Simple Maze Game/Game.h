#pragma once


#include "MainMenuState.h"

class Game
{
private:
	//variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	//Initilization
	void initWindow();
	void initStates();

	//States Container
	std::stack <State*> states;

public:
	//Constructor/Destructor

	Game();
	virtual ~Game();

	//Functions


	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

