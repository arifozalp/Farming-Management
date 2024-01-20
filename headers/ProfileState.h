#ifndef FARMING_PROFILESTATE_H
#define FARMING_PROFILESTATE_H

#include "GameState.h"
#include "save.h"

/**
 * @brief Represents the profile state in the game.
 *
 * The `ProfileState` class handles the profile-related functionalities and provides the user with options to manage game profiles.
 */
class ProfileState : public State {
private:
    gui::LoadingScreen loadingScreen;        ///< Loading screen GUI element.
    sf::Texture backgroundTexture;          ///< Texture for the background.
    sf::Texture textBackgroundTexture;      ///< Texture for text background.
    sf::RectangleShape background;          ///< Background shape.
    sf::Font font;                          ///< Font for text elements.
    sf::RectangleShape btnText;             ///< Button text shape.
    sf::RectangleShape btnBackground;       ///< Button background shape.
    std::map<std::string, gui::Button*> buttons; ///< Map storing GUI buttons.
    save* save1;                            ///< Pointer to a 'save' object.


    /**
     * @brief
     * Functions to initialize fonts and GUI elements
    */
    void initFonts();
    void initGui();

public:
    /**
     * @brief Constructor for the ProfileState class.
     *
     * @param state_data Pointer to the StateData object.
     */
    ProfileState(StateData* state_data);

    /**
     * @brief Destructor for the ProfileState class.
     */
    ~ProfileState();

    /**
     * @brief Updates GUI elements.
     *
     * This function updates the graphical user interface related to the profile state.
     *
     * @param dt Delta time.
     */
    void updateGui(const float& dt);

    /**
     * @brief General update function.
     *
     * @param dt Delta time.
     */
    void update(const float& dt);

    /**
     * @brief Main rendering function.
     *
     * @param target Render target.
     */
    void render(sf::RenderTarget* target = NULL);

    /**
     * @brief Render for loading.
     */
    void loadingRender();

    /**
     * @brief Update input handling.
     *
     * @param dt Delta time.
     */
    void updateInput(const float& dt);

    /**
     * @brief Render buttons.
     *
     * @param target Render target.
     */
    void renderButtons(sf::RenderTarget& target);
};

#endif //FARMING_PROFILESTATE_H
