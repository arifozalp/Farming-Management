#pragma once

#include "MainMenuState.h"
#include "save.h"

/**
 * @brief The Game class represents the main class of the game.
 */
class Game
{
private:
    /**
     * @brief Variables for the Game class.
     */
    GraphicsSettings gfxSettings;  /**< Graphics settings for the game. */
    StateData stateData;           /**< Data shared among game states. */
    sf::RenderWindow *window;      /**< SFML window for rendering. */
    sf::Event sfEvent;             /**< SFML event handler. */
    sf::Clock dtClock;              /**< Clock for measuring delta time. */
    float dt;                       /**< Delta time between frames. */
    save *save1;                   /**< Pointer to the save object. */
    std::stack<State *> states;     /**< Stack to manage game states. */
    float gridSize;                /**< Size of the grid in the game. */

    /**
     * @brief Initialization functions for the Game class.
     */
    void initVariables();           /**< Initialize variables. */
    void initGraphicsSettings();    /**< Initialize graphics settings. */
    void initWindow();              /**< Initialize SFML window. */
    void initStateData();           /**< Initialize state data. */
    void initStates();              /**< Initialize game states. */

public:

    /**
     * @brief Constructor for the Game class.
     */
    Game();

    /**
     * @brief Destructor for the Game class.
     */
    virtual ~Game();

    /**
     * @brief Function to end the application.
     */
    void endApplication();

    /**
     * @brief Function to update the delta time.
     */
    void updateDt();

    /**
     * @brief Function to update SFML events.
     */
    void updateSFMLEvents();

    /**
     * @brief Function to update the game logic.
     */
    void update();

    /**
     * @brief Function to render the game.
     */
    void render();

    /**
     * @brief Function to run the game.
     */
    void run();
};
