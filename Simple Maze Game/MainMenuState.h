#pragma once
#include "Button.h"
#include "GameState.h"
#include "InstructionsState.h"
class MainMenuState :
    public State
{
private:
    //background variables
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Font font;

    //buttons container
    std::map<std::string, Button*> buttons;

    //Initializers 
    void initBackground();
    void initFonts();
    void initButtons();

public:
    //constructor/deconstructor
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

  
    //update and render buttons
    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);

    //update/render
    void update();
    void render(sf::RenderTarget* target = nullptr);

};

