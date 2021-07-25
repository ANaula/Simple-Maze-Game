#pragma once
#include "Button.h"
#include "GameState.h"
#include "InstructionsState.h"
class MainMenuState :
    public State
{
private:
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Font font;

    std::map<std::string, Button*> buttons;


    void initBackground();
    void initFonts();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

  

    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);

    void update();
    void render(sf::RenderTarget* target = nullptr);

};

