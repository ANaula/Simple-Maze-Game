#pragma once

#include "Entity.h"

class State
{private:

protected:
	sf::RenderWindow* window;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	bool quit;

	std::stack<State*>* states;

	bool closeApp;


public:
	State(sf::RenderWindow* window,std::stack<State*>* states);
	virtual ~State();

	bool getCloseApp();

	void updateMousePositions();

	const bool& getQuit() const;

	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

