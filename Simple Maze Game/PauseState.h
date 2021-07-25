#pragma once
#include "State.h"
#include "Button.h"
#include "MainMenuState.h"
class PauseState :
    public State
{
private:
    //varaibles needed for buttons
    sf::Font font;
    sf::Text text;
    std::map<std::string, Button*> buttons; //buttons container
    

    //Initializers
    void initButtons();
    void initFont();
    void initText();

    //function to see if state wants to end
    void end();

public:
    //constructor/deconstructor
    PauseState(sf::RenderWindow* window, std::stack<State*>* states);
    ~PauseState();
    
    //update/render buttons
    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);

    //render text
    void renderText(sf::RenderTarget* target = nullptr);

    //update/render
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

