#pragma once

#include "AlertDialog.h"
#include "SettingsState.h"

/**
 * @brief PauseMenu class represents the pause menu in the game.
 *
 * The pause menu provides options to resume the game, adjust volume settings, and return to the main menu.
 */
class PauseMenu
{
private:
    StateData* stateData;       ///< Pointer to StateData
    sf::Font& font;             ///< Reference to font
    sf::Text menuText;          ///< Text for menu

    sf::RectangleShape background;  ///< Background shape
    sf::RectangleShape container;   ///< Container for menu items

    gui::ProgressBar* musicBarPause;    ///< Progress bar for music volume
    gui::ProgressBar* sfxBarPause;      ///< Progress bar for sound effects volume
    sf::Text musicTextPause;            ///< Text for music volume
    sf::Text sfxTextPause;              ///< Text for sound effects volume

    std::map<std::string, gui::Button*> buttons;  ///< Map to hold buttons

    /**
     * @brief Update music volume progress bar.
     */
    void updateMusicBar();

    /**
     * @brief Update sound effects volume progress bar.
     */
    void updateSfxBar();

    /**
     * @brief Update the graphical user interface (GUI).
     */
    void updateGui();

public:
    /**
     * @brief Constructor for the PauseMenu class.
     *
     * @param stateData Pointer to StateData.
     * @param vm Video mode for the game.
     * @param font Reference to the font used for text rendering.
     */
    PauseMenu(StateData* stateData, sf::VideoMode& vm, sf::Font& font);

    /**
     * @brief Destructor for the PauseMenu class.
     */
    virtual ~PauseMenu();

    /**
     * @brief Get the map of buttons.
     *
     * @return Map of buttons.
     */
    std::map<std::string, gui::Button*>& getButtons();

    /**
     * @brief Check if a button is pressed.
     *
     * @param key Key representing the button.
     * @return True if the button is pressed, otherwise false.
     */
    const bool isButtonPressed(const std::string key);

    /**
     * @brief Add a button to the menu.
     *
     * @param key Key representing the button.
     * @param y Y-coordinate for the button.
     * @param width Width of the button.
     * @param height Height of the button.
     * @param char_size Character size for the button text.
     * @param text Text displayed on the button.
     */
    void addButton(const std::string key, const float y, const float width,
                   const float height, const unsigned char_size, const std::string text);

    /**
     * @brief Update the pause menu.
     *
     * @param mousePosWindow Mouse position relative to the window.
     */
    void update(const sf::Vector2i& mousePosWindow);

    /**
     * @brief Render the pause menu.
     *
     * @param target Render target.
     */
    void render(sf::RenderTarget& target);
};
