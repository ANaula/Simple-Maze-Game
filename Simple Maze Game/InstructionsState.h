#pragma once
#include "State.h"
#include "Button.h"
class InstructionsState :
    public State
{
private:
    //variables for background and instructions screen
    sf::Font font;
    sf::RectangleShape background;
    sf::RectangleShape Instructions;
    sf::Texture texture;

    //buttons container
    std::map<std::string, Button*> buttons;

    //Initializers 
    void initInstructions();
    void initButtons();
    void initFont();
public:
    //constructor/deconstructor
    InstructionsState(sf::RenderWindow* window, std::stack<State*>* states);
    ~InstructionsState();

    //update/render buttons
    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);


    //update/render
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

