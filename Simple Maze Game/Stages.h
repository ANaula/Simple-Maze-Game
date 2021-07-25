#pragma once
#include "ObstacleM.h"
#include "Button.h"
//to seperate each stage, and each part in the stage
enum stage_num { FIRST = 0, SECOND, THIRD };
enum stage_part {INTRO = 0, GAME, END};


class Stages 
{
private:
	//Green Square
	sf::RectangleShape winZone;

	//font pointer
	sf::Font* font;

	//vectors that hold obstacles
	std::vector<sf::RectangleShape> shapes;
	std::vector<ObstacleM> movingShapes;

	//stage control variables
	int numberStage;
	stage_num stageLevel;
	stage_part part;
	bool levelCompleted;
	
	//Intro and End Screen variables
	sf::RectangleShape stageScreen;
	sf::Texture texture;

	//window pointer
	sf::RenderWindow* window;

	//initializers
	void initVariables(int num);
	void initButtons();
	void initwinZone(stage_num stageLevel);
	void initStageScreen();

	//setters
	void setObstacles(stage_num stageLevel);
	void setStageScreen();

public:
	//constructor/deconstructor
	Stages(int num, sf::RenderWindow* window, sf::Font* font);
	~Stages();

	//stage variables crucial to gameplay (buttons, obstacles, winzones)
	std::map<stage_part, Button*> buttons;
	std::vector<sf::RectangleShape>* getNonMovingShapes();
	std::vector<ObstacleM>* getMovingShapes();
	sf::RectangleShape* getWinZone();

	//getters
	bool getCompleted();
	stage_part getPart();

	//function that checks to see if stage completed
	void stageCompleted();


	//update/render
	void updateButtons(const sf::Vector2f mousePos);
	void updateMovingObstacle(stage_num stageLevel);

	void renderButtons(sf::RenderTarget* target);
	void renderStageScreen(sf::RenderTarget* target);
	void renderObstacles(sf::RenderTarget* target);
	void renderMovingObstacles(sf::RenderTarget* target);
	


	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

