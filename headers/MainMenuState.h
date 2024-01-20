#pragma once

#include "Gui.h"
#include "CreditState.h"
#include "GraphicsSettings.h"
#include "Animation.h"

/**
 * @brief Class representing the main menu state.
 */
class MainMenuState :
        public State
{
private:
    // Variables
    sf::Sprite bgSprite;        /**< SFML Sprite object for background image. */
    Animation* bg = new Animation();    /**< Pointer to the Animation object for background animation. */
    sf::Texture backgroundTexture;      /**< SFML Texture object for background image. */
    sf::RectangleShape background;      /**< SFML RectangleShape object for background. */
    sf::Font font;                     /**< SFML Font object for text rendering. */
    sf::RectangleShape btnText;        /**< SFML RectangleShape object for button text background. */
    sf::Texture backgroundText;        /**< SFML Texture object for button text background image. */
    sf::RectangleShape btnBackground;   /**< SFML RectangleShape object for button background. */
    std::map<std::string, gui::Button*> buttons;   /**< Map to store GUI buttons. */

    gui::LoadingScreen loadingScreen;   /**< GUI LoadingScreen object for transitions. */
    gui::ProgressBar* musicBar;         /**< Pointer to the GUI ProgressBar object for music volume control. */

    // Functions
    /**
     * @brief Initialize fonts.
     */
    void initFonts();

    /**
     * @brief Initialize graphical user interface elements.
     */
    void initGui();

    /**
     * @brief Reset graphical user interface elements to default state.
     */
    void resetGui();

public:
    /**
     * @brief Constructor for the MainMenuState class.
     *
     * @param state_data Pointer to the StateData object for shared state data.
     */
    MainMenuState(StateData* state_data);

    /**
     * @brief Destructor for the MainMenuState class.
     */
    virtual ~MainMenuState();

    /**
     * @brief Update user input.
     *
     * @param dt Delta time for frame rate independence.
     */
    void updateInput(const float& dt);

    /**
     * @brief Update button states.
     */
    void updateButtons();

    /**
     * @brief Update function for the main menu state.
     *
     * @param dt Delta time for frame rate independence.
     */
    void update(const float& dt);

    /**
     * @brief Render loading screen.
     *
     * @param target SFML RenderTarget object for rendering.
     */
    void loadingRender(sf::RenderTarget* target);

    /**
     * @brief Render loading screen start state.
     */
    void loadingStartRender();

    /**
     * @brief Render buttons.
     *
     * @param target SFML RenderTarget object for rendering.
     */
    void renderButtons(sf::RenderTarget& target);

    /**
     * @brief Render function for the main menu state.
     *
     * @param target SFML RenderTarget object for rendering.
     */
    void render(sf::RenderTarget* target = NULL);
};
