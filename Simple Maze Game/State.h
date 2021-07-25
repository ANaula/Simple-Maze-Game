#pragma once

#include "Entity.h"
//base for gamestate, mainmenustate, pausestate, instructionsstate
class State
{private:

protected:
	//window pointer 
	sf::RenderWindow* window;

	//variables that hold mouse position
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//variable that controls if state ends
	bool quit;

	//pointer to state stack in order to add new states
	std::stack<State*>* states;

	//variable that controls if app ends
	bool closeApp;


public:
	//constructor/deconstructor
	State(sf::RenderWindow* window,std::stack<State*>* states);
	virtual ~State();

	//Getters
	bool getCloseApp();
	const bool& getQuit() const;

	//Function for getting mouse location
	void updateMousePositions();

	//update and render virtual functions
	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

