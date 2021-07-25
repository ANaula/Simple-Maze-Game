#pragma once
#include "State.h"
#include "Button.h"
class InstructionsState :
    public State
{
private:
    sf::Font font;
    sf::RectangleShape background;
    sf::RectangleShape Instructions;
    sf::Texture texture;

    std::map<std::string, Button*> buttons;

    void initInstructions();
    void initButtons();
    void initFont();
public:
    InstructionsState(sf::RenderWindow* window, std::stack<State*>* states);
    ~InstructionsState();



    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);

    void update();
    void render(sf::RenderTarget* target = nullptr);
};

