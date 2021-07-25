#include "Game.h"

void Game::initWindow()
{
	//Creating the window

	std::string title = "C++ Simple Maze Game";
	sf::VideoMode window_bounds(1280, 720);
	unsigned framerate_limit = 120;

	this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(framerate_limit);
}

void Game::initStates()
{
	//Creating the Main menu state and adding it to the state stack
	this->states.push(new MainMenuState(this->window,&this->states));

}

Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	//deleting the window and all the states in the state stack

	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}


void Game::updateSFMLEvents()
{
	//Checks to see if the close button on the top right part of the window has been clicked.

	while (this->window->pollEvent(this->sfEvent)) {
		switch (this->sfEvent.type) {
		case sf::Event::Closed:
			window->close();
			break;
		}
		
	}
}

void Game::update()
{
	//updates the top state in the stack and checks to see if the the state wants to quit in which if it does it gets deleted and removed from the stack. If the stage wants to close the app the window is closed altogether. If stack is empty the window closes as well.

	this->updateSFMLEvents();
	if (!this->states.empty()) {
		this->states.top()->update();

		if (this->states.top()->getQuit()) {
			delete this->states.top();
			this->states.pop();
		}
		if (this->states.top()->getCloseApp()) {
			window->close();
		}
		
	}
	else {
		window->close();
	}

	
}

void Game::render()
{
	//cleears window screen and renders top state in stack and then displays it

	this->window->clear();

	if (!this->states.empty()) {
		this->states.top()->render();
	}

	this->window->display();
}

void Game::run()
{
	//runs game while window is open

	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
	
}
