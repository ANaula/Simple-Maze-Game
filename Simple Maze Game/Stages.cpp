#include "Stages.h"

void Stages::initVariables(int num)
{
	switch (num) {
		case 0:
			stageLevel = FIRST;
			break;
		case 1:
			stageLevel = SECOND;
			break;
		case 2:
			stageLevel = THIRD;
			break;
		default:
			throw "ERROR::COULD_NOT_LOAD_STAGE";
			break;

	}

	this->numberStage = num;
	this->part = INTRO;
	this->levelCompleted = false;
}

void Stages::initFont()
{
	
}

void Stages::initButtons()
{
	std::string buttonText;

	if (stageLevel == 2) {
		buttonText = "Back to Main Menu";
	}
	else {
		buttonText = "Next Level";
	}

	this->buttons[INTRO] = new Button(this->window->getSize().x/2-75, 550, 150, 50, this->font, "Start", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons[END] = new Button(this->window->getSize().x/2-75, 500, 150, 50, this->font, buttonText, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void Stages::initwinZone(stage_num stageLevel)
{
	switch (stageLevel) {
	case FIRST:
		this->winZone.setSize(sf::Vector2f(80.0f, 120.0f));
		this->winZone.setPosition(sf::Vector2f(1200.0f, 600.0f));
		break;
	case SECOND:
		this->winZone.setSize(sf::Vector2f(140.0f, 70.0f));
		this->winZone.setPosition(sf::Vector2f(1110.0f, 0.0f));
		break;
	case THIRD:
		this->winZone.setSize(sf::Vector2f(70.0f, 70.0f));
		this->winZone.setPosition(sf::Vector2f(1210.0f, 510.0f));
		break;
	default:
		throw "ERROR::NOT_ABLE_TO_LOAD_WINZONE";
		break;
	}
	
	


	this->winZone.setFillColor(sf::Color::Green);
}

void Stages::setObstacles(stage_num stageLevel)
{
	switch (stageLevel) {
	case FIRST:
		shapes.push_back(sf::RectangleShape(sf::Vector2f(850, 170)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(1050, 400)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(230, 50)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(160, 50)));

		shapes[0].setPosition(sf::Vector2f(200, 0));
		shapes[1].setPosition(sf::Vector2f(0, 320));
		shapes[2].setPosition(sf::Vector2f(1050, 0));
		shapes[3].setPosition(sf::Vector2f(1120, 550));

		


	movingShapes.push_back(ObstacleM(600.0f, 170.0f,50.0f,50.0f,2.0f,true));
	movingShapes.push_back(ObstacleM(1050.0f, 50.0f, 230.0f,50.0f,2.0f,true));

		break;
	case SECOND:
		shapes.push_back(sf::RectangleShape(sf::Vector2f(30.0f, 565.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(1280.0f, 30.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(230.0f, 590.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(230.0f, 560.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(490.0f, 30.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(230.0f, 590.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(30.0f, 690.0f)));

		shapes[0].setPosition(sf::Vector2f(0.0f, 125.0f));
		shapes[1].setPosition(sf::Vector2f(0.0f, 690.0f));
		shapes[2].setPosition(sf::Vector2f(160.0f, 0.0f));
		shapes[3].setPosition(sf::Vector2f(520.0f, 130.0f));
		shapes[4].setPosition(sf::Vector2f(390.0f, 0.0f));
		shapes[5].setPosition(sf::Vector2f(880.0f, 0.0f));
		shapes[6].setPosition(sf::Vector2f(1250.0f, 0.0f));

		

		movingShapes.push_back(ObstacleM(30.0f, 330.0f, 50.0f, 50.0f, 1.5f, false));
		movingShapes.push_back(ObstacleM(390.0f, 330.0f, 50.0f, 50.0f, 1.5f, false));
		movingShapes.push_back(ObstacleM(815.0f, 30.0f, 50.0f, 50.0f, 1.5f, true));

		break;
	case THIRD:
		shapes.push_back(sf::RectangleShape(sf::Vector2f(1210.0f, 30.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(1100.0f, 50.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(70.0f, 180.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(30.0f, 510.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(30.0f, 170.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(1050.0f, 50.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(470.0f, 70.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(450.0f, 70.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(1250.0f, 30.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(30.0f, 180.0f)));
		shapes.push_back(sf::RectangleShape(sf::Vector2f(30.0f, 100.0f)));

		shapes[0].setPosition(sf::Vector2f(70.0f, 0.0f));
		shapes[1].setPosition(sf::Vector2f(0.0f, 160.0f));
		shapes[2].setPosition(sf::Vector2f(1210.0f, 30.0f));
		shapes[3].setPosition(sf::Vector2f(0.0f, 210.0f));
		shapes[4].setPosition(sf::Vector2f(230.0f, 440.0f));
		shapes[5].setPosition(sf::Vector2f(230.0f, 390.0f));
		shapes[6].setPosition(sf::Vector2f(260.0f, 440.0f));
		shapes[7].setPosition(sf::Vector2f(830.0f, 440.0f));
		shapes[8].setPosition(sf::Vector2f(30.0f, 690.0f));
		shapes[9].setPosition(sf::Vector2f(1250.0f, 210.0f));
		shapes[10].setPosition(sf::Vector2f(1180.0f, 510.0f));

		movingShapes.push_back(ObstacleM(390.0f, 30.0f, 50.0f, 50.0f, 1.5f, true));//
		movingShapes.push_back(ObstacleM(815.0f, 30.0f, 50.0f, 50.0f, 1.5f, true));//
		movingShapes.push_back(ObstacleM(30.0f, 310.0f, 50.0f, 50.0f, 1.5f, false));//
		movingShapes.push_back(ObstacleM(390.0f, 240.0f, 50.0f, 50.0f, 1.5f, false));//
		movingShapes.push_back(ObstacleM(30.0f, 210.0f, 200.0f, 50.0f, 1.5f, true));//
		movingShapes.push_back(ObstacleM(1150.0f, 510.0f, 30.0f, 180.0f, 1.5f, false));//



		break;
	default:
		throw "ERROR::NO_STAGE_SELECTED";
		break;
	}
	
	for (auto& it : shapes) {
		it.setFillColor(sf::Color::Red);
	}


}

void Stages::initStageScreen()
{
	this->stageScreen.setSize(sf::Vector2f(380.0f, 340.0f));
	this->stageScreen.setPosition(sf::Vector2f(this->window->getSize().x/2-stageScreen.getSize().x/2, 110.0f));
}

void Stages::setStageScreen()
{

	switch (stageLevel) {
	case 0:
		if (part == INTRO) {
			this->texture.loadFromFile("Resources/Images/StageScreens/Level1intro.png");
		}
		break;
	case 1:
		if (part == INTRO) {
			this->texture.loadFromFile("Resources/Images/StageScreens/Level2Intro.png");
		}
		break;
	case 2:
		if (part == INTRO) {
			this->texture.loadFromFile("Resources/Images/StageScreens/Level3intro.png");
		}
		else if (part == END) {
			this->texture.loadFromFile("Resources/Images/StageScreens/gameEnd.png");
		}
		break;
	}

	if (part == END && stageLevel != 2) {
		this->texture.loadFromFile("Resources/Images/StageScreens/levelEnd.png");
	}

	this->stageScreen.setTexture(&this->texture);
}

Stages::Stages(int num,sf::RenderWindow* window, sf::Font* font)
{
	this->window = window;
	this->font = font;
	initVariables(num);
	initStageScreen();
	setStageScreen();
	initButtons();
	initFont();
	initwinZone(stageLevel);
	setObstacles(stageLevel);
}

Stages::~Stages()
{
	
}


std::vector<sf::RectangleShape>* Stages::getNonMovingShapes()
{
	return &shapes;
}

std::vector<ObstacleM>* Stages::getMovingShapes()
{
	return &movingShapes;
}

sf::RectangleShape* Stages::getWinZone()
{
	return &winZone;
}

bool Stages::getCompleted()
{
	return levelCompleted;
}

stage_part Stages::getPart()
{
	return part;
}

void Stages::stageCompleted()
{
	this->part = END;
}

void Stages::updateButtons(const sf::Vector2f mousePos)
{
	this->buttons[part]->update(mousePos);


		switch (part) {
		case INTRO:
			if (this->buttons[INTRO]->isPressed()) {
				part = GAME;
			}
			break;
		case END:
			if (this->buttons[END]->isPressed()) {
				levelCompleted = true;
			}
			break;
		default:
			throw "ERROR::BUTTON_ISSUES";
			break;
		}
	
	

	
}

void Stages::renderButtons(sf::RenderTarget* target)
{
	this->buttons[part]->render(target);
}

void Stages::renderStageScreen(sf::RenderTarget* target)
{
	target->draw(this->stageScreen);
}



void Stages::renderObstacles(sf::RenderTarget* target)
{
	for (auto& it : shapes) {
		target->draw(it);
	}

}

void Stages::renderMovingObstacles(sf::RenderTarget* target)
{
	for (auto& it : movingShapes) {
		it.render(target);
	}
}

void Stages::updateMovingObstacle(stage_num stageLevel)
{
	for (auto& it : movingShapes) {
		if (it.vMove == true) {
			it.move(0, 1);
		}
		else {
			it.move(1, 0);
		}

		for (auto& obj : shapes) {
			if (it.returnShape()->getGlobalBounds().intersects(obj.getGlobalBounds())) {
				it.invertMovement();
			}
		}
	
	}
}

void Stages::update(const sf::Vector2f mousePos)
{
	if (part == GAME) {
		this->updateMovingObstacle(stageLevel);

		}
	else {
		this->setStageScreen();
		this->updateButtons(mousePos);

	}
	
	
}

void Stages::render(sf::RenderTarget* target)
{
	if (part == GAME) {
		renderObstacles(target);
		renderMovingObstacles(target);
		target->draw(winZone);
	}
	else {
		this->renderStageScreen(target);
		this->renderButtons(target);

	}

		
	
	


}
