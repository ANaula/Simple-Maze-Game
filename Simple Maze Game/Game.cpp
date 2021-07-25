#include "Game.h"

void Game::initWindow()
{
	std::string title = "C++ Simple Maze Game";
	sf::VideoMode window_bounds(1280, 720);
	unsigned framerate_limit = 120;

	this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(framerate_limit);
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window,&this->states));

}

Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}


void Game::updateSFMLEvents()
{
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
	this->window->clear();

	if (!this->states.empty()) {
		this->states.top()->render();
	}

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
	
}
