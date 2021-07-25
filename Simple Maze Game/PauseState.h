#pragma once
#include "State.h"
#include "Button.h"
#include "MainMenuState.h"
class PauseState :
    public State
{
private:

    sf::Font font;
    sf::Text text;

    std::map<std::string, Button*> buttons;

    void initButtons();
    void initFont();
    void initText();
    void end();

public:
    PauseState(sf::RenderWindow* window, std::stack<State*>* states);
    ~PauseState();

    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);

    void renderText(sf::RenderTarget* target = nullptr);

    void update();
    void render(sf::RenderTarget* target = nullptr);
};

