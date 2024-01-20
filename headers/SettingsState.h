#pragma once

#include "State.h"
#include "Gui.h"
#include "GraphicsSettings.h"

/**
 * @brief Represents the state for game settings.
 *
 * The `SettingsState` class is responsible for managing and displaying game settings, including volume controls.
 */
class SettingsState :
        public State
{
private:
    // Variables
    sf::Texture backgroundTexture; ///< Texture for the background
    sf::RectangleShape background; ///< Background shape
    sf::Font font;                 ///< Font for text elements
    sf::RectangleShape btnBackground; ///< Button background shape
    std::map<std::string, gui::Button*> buttons; ///< Map storing GUI buttons

    gui::LoadingScreen loadingScreen; ///< Loading screen GUI element
    gui::ProgressBar* musicBar;       ///< Progress bar for music volume
    gui::ProgressBar* sfxBar;         ///< Progress bar for sound effects volume
    sf::Text musicText;               ///< Text for music volume
    sf::Text sfxText;                 ///< Text for sound effects volume


    void initVariables(); ///< Initializes member variables
    void initFonts();     ///< Initializes fonts
    void initGui();       ///< Initializes GUI elements

public:
    /**
     * @brief Constructor for the SettingsState class.
     *
     * @param state_data Pointer to the StateData object.
     */
    SettingsState(StateData* state_data);

    /**
     * @brief Destructor for the SettingsState class.
     */
    virtual ~SettingsState();

    /**
 * @brief Updates the music volume progress bar based on user input.
 *
 * The `updateMusicBar` function handles the updating of the music volume progress bar based on the user's input.
 */
    void updateMusicBar();

/**
 * @brief Updates the sound effects volume progress bar based on user input.
 *
 * The `updateSfxBar` function handles the updating of the sound effects volume progress bar based on the user's input.
 */
    void updateSfxBar();

/**
 * @brief Renders the music volume progress bar.
 *
 * The `renderMusicBar` function is responsible for rendering the music volume progress bar on the specified render target.
 *
 * @param target Render target.
 */
    void renderMusicBar(sf::RenderTarget& target);

/**
 * @brief Renders the sound effects volume progress bar.
 *
 * The `renderSfxBar` function is responsible for rendering the sound effects volume progress bar on the specified render target.
 *
 * @param target Render target.
 */
    void renderSfxBar(sf::RenderTarget& target);

    /**
     * @brief Updates input handling for the SettingsState.
     *
     * @param dt Delta time.
     */
    void updateInput(const float& dt);

    /**
     * @brief Updates the GUI elements of the SettingsState.
     *
     * @param dt Delta time.
     */
    void updateGui(const float& dt);

    /**
     * @brief General update function for the SettingsState.
     *
     * @param dt Delta time.
     */
    void update(const float& dt);

    /**
     * @brief Renders the loading screen.
     */
    void loadingRender();

    /**
     * @brief Renders the GUI elements of the SettingsState.
     *
     * @param target Render target.
     */
    void renderGui(sf::RenderTarget& target);

    /**
     * @brief Renders the SettingsState.
     *
     * @param target Render target.
     */
    void render(sf::RenderTarget* target = NULL);
};
