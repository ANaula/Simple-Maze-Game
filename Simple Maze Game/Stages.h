#pragma once
#include "ObstacleM.h"
#include "Button.h"
enum stage_num { FIRST = 0, SECOND, THIRD };
enum stage_part {INTRO = 0, GAME, END};


class Stages 
{
private:

	sf::RectangleShape winZone;
	sf::Font* font;

	std::vector<sf::RectangleShape> shapes;
	std::vector<ObstacleM> movingShapes;

	int numberStage;
	stage_num stageLevel;
	stage_part part;
	bool levelCompleted;
	
	sf::RectangleShape stageScreen;
	sf::Texture texture;

	sf::RenderWindow* window;


	void initVariables(int num);
	void initFont();
	void initButtons();
	void initwinZone(stage_num stageLevel);
	void setObstacles(stage_num stageLevel);

	void initStageScreen();
	void setStageScreen();

public:
	Stages(int num, sf::RenderWindow* window, sf::Font* font);
	~Stages();

	std::map<stage_part, Button*> buttons;
	std::vector<sf::RectangleShape>* getNonMovingShapes();
	std::vector<ObstacleM>* getMovingShapes();
	sf::RectangleShape* getWinZone();
	bool getCompleted();
	stage_part getPart();
	void stageCompleted();

	void updateButtons(const sf::Vector2f mousePos);
	void renderButtons(sf::RenderTarget* target);
	void renderStageScreen(sf::RenderTarget* target);

	void renderObstacles(sf::RenderTarget* target);
	void renderMovingObstacles(sf::RenderTarget* target);
	

	void updateMovingObstacle(stage_num stageLevel);

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

