# Simple-Maze-Game

A simple game consisting of three stages where the player controls the white square using the w-a-s-d keys and must get to the green square (called win zones) without touching any of the red obstacles. If a red obstacle is touched the player is sent back to the beginning to the stage. All three stages must be completed to win the game. The game also includes a main menu screen, instructions on how to play, and a pause screen.

![Alt Text](https://media.giphy.com/media/EEfytjRHns62LJeAHH/giphy.gif)

## How it works
The game uses the SFML library (which could be downloaded here- https://www.sfml-dev.org/download/sfml/2.5.1/) for the window creation and the multimedia components. The game is organized into states with each aspect of the game being its own state. There is a game state, a main menu state, a pause state, and an instructions state. These states are created when needed and stored dynamically in a stack, with the top state in the stack being update and rendered. The game state has a smaller version of this, organizing the stages and obstacles in those stages in vectors. The game state keeps track of what stage the player is on and updates and renders the appropriate obstacles and win zones. The player controlled white square is also updated and rendered in game state.

![Alt Text](https://media.giphy.com/media/h6084L81fSgFQq1nxC/giphy.gif)

## Download

To download the game, go to the releases and download either the msi or exe file.
