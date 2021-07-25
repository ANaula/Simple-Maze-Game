#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) :State(window,states)
{	
	this->initVariables();
	this->initFonts();
	this->initStages();
	this->initObstacles();

}

GameState::~GameState()
{
	//Deletes all the buttons created and stored dynamically by the stages
	for (auto& it : stageStates) {
		auto i = it.buttons.begin();
		for (i = it.buttons.begin(); i != it.buttons.end(); ++i) {
			delete i->second;
		}
		}
	

}

void GameState::initStages()
{
	//Creates the stages and adds them to the stageState vector
	this->stageStates.push_back(Stages(0, this->window, &this->font));
	this->stageStates.push_back(Stages(1,this->window,&this->font));
	this->stageStates.push_back(Stages(2, this->window, &this->font));

}

void GameState::initVariables() {
	//Sets the player shape and level
	this->shape = player.getShape();
	this->level = 0;
	
}

void GameState::initObstacles() {
	this->setObstacles();
}

void GameState::checkForPause()
{
	//Checks if esc is pressed to bring up the pause menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->states->push(new PauseState(window, states));
	}
}

void GameState::initFonts() {

	//loads font
	if (!this->font.loadFromFile("Fonts/Roboto-Black.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}


void GameState::updatePlayerMovement()
{
	
	// Checks if w-a-s-d keys are pressed to move player shape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (this->shape->getPosition().x>0)) {
			this->player.move(-1.0f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&(this->shape->getPosition().x+this->shape->getGlobalBounds().width<this->window->getSize().x)) {
			this->player.move(1.0f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (this->shape->getPosition().y > 0)) {
			this->player.move(0.0f, -1.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (this->shape->getPosition().y + this->shape->getGlobalBounds().height < this->window->getSize().y)) {
			this->player.move(0.0f, 1.0f);
		}
	
	

	
}

void GameState::setObstacles()
{
	//sets obstacles depending on what stage the player is on
	this->player.rePosition(0, 0);
	this->movingShapes = stageStates[level].getMovingShapes();
	this->nonMovingShapes = stageStates[level].getNonMovingShapes();

	this->winZone = stageStates[level].getWinZone();
}



void GameState::checkCollision()
{
	//checks for collision between player and obstacles (both stationary and moving)

	for (auto& it : *nonMovingShapes) {
		if (player.getShape()->getGlobalBounds().intersects(it.getGlobalBounds())) {
			this->player.rePosition(0.0f, 0.0f);
			}
		
	}
	for (auto& it : *movingShapes) {
		if (player.getShape()->getGlobalBounds().intersects(it.returnShape()->getGlobalBounds())) {
			this->player.rePosition(0.0f, 0.0f);
		}
	}

	if (player.getShape()->getGlobalBounds().intersects(winZone->getGlobalBounds())) {
		this->stageStates[level].stageCompleted();
		if (this->stageStates[level].getCompleted()) {
			this->nextStage();

		}
		
	}

}

void GameState::update()
{

	this->checkForPause();
	this->updateMousePositions();
	this->updatePlayerMovement();
	this->checkCollision();
	stageStates[level].update(this->mousePosView);
}

void GameState::render(sf::RenderTarget* target)
{
	//Renders the stage, but checks to see if it should render the player. Each stage has three components. The intro screen, game screen which is the stage is played, and outro screen. The intro and outro screens do not display the obstacles nor the player and instead display just a button to continue on to the game portion of the stage. 
	//Only renders the player if the stage is past the intro screen and is on the game part of the stage.


	if (!target) {
		target = this->window;
	}
	stageStates[level].render(target);
	
	if (checkStagePart()) {
		this->player.render(target);

	}

	
	
}

bool GameState::checkStagePart()
{
	//checks to see if the stage is on the game part of the stage.
	if (stageStates[level].getPart() == GAME) {
		return true;
	}
	return false;
}

void GameState::nextStage()
{
	//Moves to the next stage if there is a next stage. If there is not the game state ends.
	if (level + 1 != stageStates.size()) {
		this->level++;
		this->setObstacles();
	}
	else {
		this->quit = true;
	}
}
