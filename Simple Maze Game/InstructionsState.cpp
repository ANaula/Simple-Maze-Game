#include "InstructionsState.h"

void InstructionsState::initInstructions()
{
	//creates background and shape which gets a texture that is a png of the instructions

	this->background.setSize(sf::Vector2f(this->window->getSize()));
	this->background.setFillColor(sf::Color(37, 37, 37,255));

	this->Instructions.setSize(sf::Vector2f(1080.0f, 485.0f));
	this->Instructions.setPosition(sf::Vector2f(150.0f, 55.0f));

	if (!this->texture.loadFromFile("Resources/Images/StageScreens/gameinstructions.png")) {
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_IMAGE";
	}
	this->Instructions.setTexture(&this->texture);

}

void InstructionsState::initButtons()
{
	//creates a button and adds it to the button MAP container
	this->buttons["MAIN_MENU_STATE"] = new Button(this->window->getSize().x / 2 - 75, 600, 150, 50, &this->font, "Back to Menu", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

}

void InstructionsState::initFont()
{
	if (!this->font.loadFromFile("Fonts/Roboto-Black.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

InstructionsState::InstructionsState(sf::RenderWindow* window, std::stack<State*>* states): State(window,states)
{
	this->initFont();
	this->initButtons();
	this->initInstructions();
}

InstructionsState::~InstructionsState()
{
	//deletes all the buttons in the button MAP container

	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != buttons.end(); ++it) {
		delete it->second;
	}
}



void InstructionsState::updateButtons()
{
	//Updates all buttons in the button MAP container and checks to see if button is pressed to exit the state

	for (auto& it : this->buttons) {
		it.second->update(this->mousePosView);
	}
	if (this->buttons["MAIN_MENU_STATE"]->isPressed()) {
		this->quit = true;
	}
}

void InstructionsState::renderButtons(sf::RenderTarget* target)
{
	//renders all buttosn in the button MAP container

	for (auto& it : this->buttons) {
		it.second->render(target);
	}
}

void InstructionsState::update()
{
	this->updateButtons();
	this->updateMousePositions();
}

void InstructionsState::render(sf::RenderTarget* target)
{
	//renders the background, the shape with the instructions texture, and the buttons

	if (!target) {
		target = this->window;
	}
	target->draw(background);
	target->draw(Instructions);
	this->renderButtons(target);
}
