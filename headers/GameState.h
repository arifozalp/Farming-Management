#pragma once

#include "PlayerGUI.h"
#include "tutorial.h"
#include "EndAndReportScreen.h"
#include "save.h"

/**
 * @brief The GameState class represents the main game state where the player interacts with the game world.
 */
class GameState :
        public State
{
private:
    gui::LoadingScreen loadingScreen;       /**< Loading screen for game state transitions. */
    sf::View view;                          /**< SFML view for managing the game's view. */
    sf::Font font;                          /**< Font used for text rendering. */
    PauseMenu* pauseMenu;                   /**< Pause menu for managing in-game options. */
    EndAndReportScreen* endAndReportScreen; /**< End and report screen for displaying game results. */
    save* gameSave;                         /**< Save object for managing game data. */

    sf::RenderTexture renderTexture;        /**< Render texture for deferred rendering. */
    PlayerGUI* playerGUI;                   /**< Player GUI for displaying player information. */
    sf::Texture texture;                    /**< Texture used for rendering. */
    tutorial* tutorial1;                    /**< Tutorial object for guiding the player. */

    int index = 0;                          /**< Index variable. */

    sf::Texture backgroundTexture;          /**< Texture for the background. */
    sf::RectangleShape background;          /**< Background shape. */

    /**
     * @brief Initialize deferred rendering.
     */
    void initDeferredRender();

    /**
     * @brief Initialize the view.
     */
    void initView();

    /**
     * @brief Initialize fonts.
     */
    void initFonts();

    /**
     * @brief Initialize end screen.
     */
    void initEndScreen();

    /**
     * @brief Initialize textures.
     */
    void initTextures();

    /**
     * @brief Initialize pause menu.
     */
    void initPauseMenu();

    /**
     * @brief Initialize player GUI.
     *
     * @param state_data Pointer to StateData for sharing data among game states.
     */
    void initPlayerGUI(StateData* state_data);

public:
    /**
     * @brief Constructor for the GameState class.
     *
     * @param state_data Pointer to StateData for sharing data among game states.
     */
    GameState(StateData* state_data);

    /**
     * @brief Destructor for the GameState class.
     */
    virtual ~GameState();

    /**
     * @brief Update end screen logic.
     */
    void updateEndScreen();

    /**
     * @brief Update tutorial button logic.
     */
    void updateTutorialButton();

    /**
     * @brief Update input handling.
     *
     * @param dt Delta time between frames.
     */
    void updateInput(const float& dt);

    /**
     * @brief Update player GUI logic.
     */
    void updatePlayerGUI();

    /**
     * @brief Update pause menu buttons logic.
     */
    void updatePauseMenuButtons();

    /**
     * @brief Update game logic.
     *
     * @param dt Delta time between frames.
     */
    void update(const float& dt);

    /**
     * @brief Render loading screen during transitions.
     */
    void loadingRender();

    /**
     * @brief Render the game state.
     *
     * @param target Pointer to the render target.
     */
    void render(sf::RenderTarget* target = NULL);
};
