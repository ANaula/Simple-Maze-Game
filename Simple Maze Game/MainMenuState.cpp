#include "MainMenuState.h"



void MainMenuState::initBackground()
{
	//create a background and add a texture to it which is the png. This will act as the Main Menu Screen.

	this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Background/MainMenuBackground.png")) {
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_IMAGE";
	}

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Roboto-Black.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initButtons()
{
	//Create buttons and add them to the buttons MAP container

	this->buttons["GAME_STATE"] = new Button(90, 300, 150, 50, &this->font, "New Game", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["INSTRUCTIONS_STATE"] = new Button(90, 400, 150, 50, &this->font, "How to Play", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(90, 500, 150, 50, &this->font, "Quit", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));


}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states):State(window,states)
{
	this->initBackground();
	this->initFonts();
	this->initButtons();
	
}

MainMenuState::~MainMenuState()
{
	//delete all the buttons in the MAP container

	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != buttons.end(); ++it) {
		delete it->second;
	}
}



void MainMenuState::updateButtons()
{
	//udpate all the buttons in the buttons MAP container and check to see if certain buttons were pressed to create a new state or close the application.

	for (auto& it : this->buttons) {
		it.second->update(this->mousePosView);
	}

	if (this->buttons["EXIT_STATE"]->isPressed()) {
		this->closeApp = true;
	}
	if (this->buttons["GAME_STATE"]->isPressed()) {
		this->states->push(new GameState(this->window, this->states));
	}
	if (this->buttons["INSTRUCTIONS_STATE"]->isPressed()) {
		this->states->push(new InstructionsState(this->window, this->states));
	}

}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	//render all buttons in the MAP container

	for (auto& it : this->buttons) {
		it.second->render(target);
	}
	
}

void MainMenuState::update()
{
	//update mouse position in the window and update buttons 

	this->updateMousePositions();
	this->updateButtons();
}

void MainMenuState::render(sf::RenderTarget* target)
{
	//render background and buttons

	if (!target) {
		target = this->window;
	}
	target->draw(this->background);

	this->renderButtons(target);
	
	

}
