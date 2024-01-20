#ifndef FARMING_EXE_CREDITSTATE_H
#define FARMING_EXE_CREDITSTATE_H

#include "ProfileState.h"

/**
 * @brief CreditState class represents the state for displaying game credits.
 */
class CreditState : public State {
private:
    /**
     * @brief Loading screen for asynchronous tasks.
     */
    gui::LoadingScreen loadingScreen;

    /**
     * @brief Textures for background and group photo.
     */
    sf::Texture backgroundTexture;
    sf::Texture groupFotoTexture;

    /**
     * @brief Rectangle shapes for group photo, background, and shadow background.
     */
    sf::RectangleShape groupFotoShape;
    sf::RectangleShape background;
    sf::RectangleShape shadowBackground;

    /**
     * @brief Font for text rendering.
     */
    sf::Font font;

    /**
     * @brief Text elements for displaying credits.
     */
    sf::Text creditsTitle;
    sf::Text creditsContents1;
    sf::Text creditsContents2;
    sf::Text creditsContents3;
    sf::Text creditsContents4;
    sf::Text creditsContents5;

    /**
     * @brief Button for returning to a previous state.
     */
    gui::Button* back;

    /**
     * @brief Initialize fonts for text rendering.
     */
    void initFonts();

    /**
     * @brief Initialize graphical user interface (GUI) elements.
     */
    void initGui();

public:
    /**
     * @brief Constructor for the CreditState class.
     *
     * @param state_data Pointer to StateData for initialization.
     */
    CreditState(StateData* state_data);

    /**
     * @brief Destructor for the CreditState class.
     */
    ~CreditState();

    /**
     * @brief Render GUI elements on the screen.
     *
     */
    void renderGui(sf::RenderTarget& target);

    /**
     * @brief Update GUI elements.
     *
     */
    void updateGui(const float& dt);

    /**
     * @brief Update logic for the CreditState.
     *
     */
    void update(const float& dt);

    /**
     * @brief Render the CreditState on the screen.
     *
     */
    void render(sf::RenderTarget* target = NULL);

    /**
     * @brief Render loading screen.
     */
    void loadingRender();

    void updateInput(const float& dt);
};

#endif //FARMING_EXE_CREDITSTATE_H
