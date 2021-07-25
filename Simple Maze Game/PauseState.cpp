#include "PauseState.h"

void PauseState::initButtons()
{
	this->buttons["RETURN"] = new Button(this->window->getSize().x/2-75, 400, 150, 50, &this->font, "Continue", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["MAIN_MENU_STATE"] = new Button(this->window->getSize().x / 2 - 75, 500, 150, 50, &this->font, "Return to Main Menu", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void PauseState::initFont()
{
	if (!this->font.loadFromFile("Fonts/Roboto-Black.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void PauseState::initText()
{
	this->text.setFont(font);
	this->text.setCharacterSize(100);
	this->text.setString("Paused");
	this->text.setPosition(sf::Vector2f(this->window->getSize().x / 2 - text.getGlobalBounds().width / 2, 150));

}

void PauseState::end()
{
	this->quit = true;
}

PauseState::PauseState(sf::RenderWindow* window, std::stack<State*>* states): State(window,states)
{
	this->initFont();
	this->initText();
	this->initButtons();

}

PauseState::~PauseState()
{

	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != buttons.end(); ++it) {
		delete it->second;
	}
}




void PauseState::updateButtons()
{
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosView);
	}

	if (this->buttons["RETURN"]->isPressed()) {
		this->end();
	}
	if (this->buttons["MAIN_MENU_STATE"]->isPressed()) {
		this->states->push(new MainMenuState(this->window, this->states));
	}
}

void PauseState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : buttons) {
		it.second->render(target);
	}
}

void PauseState::renderText(sf::RenderTarget* target)
{
	target->draw(text);
}

void PauseState::update()
{
	this->updateMousePositions();
	this->updateButtons();
}

void PauseState::render(sf::RenderTarget* target )
{
	if (!target) {
		target = this->window;
	}

	this->renderButtons(target);
	this->renderText(target);
}
