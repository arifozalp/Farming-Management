#ifndef FARMING_TUTORIAL_H
#define FARMING_TUTORIAL_H

#include "stdafx.h"
#include "Gui.h"

/**
 * @brief Class representing a tutorial in the farming game.
 *
 * The `tutorial` class manages the tutorial's graphical elements, including textures, background, and buttons.
 */
class tutorial {
private:
    sf::Font& font;                          ///< Font for the tutorial
    sf::Texture textures[8];                 ///< Textures for the tutorial
    sf::RectangleShape background;           ///< Background shape for the tutorial
    std::map<std::string, gui::Button*> buttons; ///< Buttons used in the tutorial

public:
    const int arraySize = 8;                 ///< Size of the array

    /**
     * @brief Constructor for the tutorial class.
     *
     * @param vm Reference to the video mode of the application window.
     * @param font Reference to the font used in the tutorial.
     */
    tutorial(sf::VideoMode& vm, sf::Font& font);

    /**
     * @brief Destructor for the tutorial class.
     */
    ~tutorial();

    /**
     * @brief Function to check if a specific button is pressed.
     *
     * @param key Key identifying the button.
     * @return True if the specified button is pressed, otherwise false.
     */
    const bool isButtonPressed(const std::string key);

    /**
     * @brief Function to update the tutorial based on mouse position.
     *
     * @param mousePosWindow Current mouse position relative to the window.
     */
    void update(const sf::Vector2i& mousePosWindow);

    /**
     * @brief Function to add a button to the tutorial.
     *
     * @param key Key identifying the button.
     * @param x X-coordinate of the button.
     * @param y Y-coordinate of the button.
     * @param width Width of the button.
     * @param height Height of the button.
     * @param char_size Character size of the text on the button.
     * @param text Text displayed on the button.
     */
    void addButton(const std::string key, const float x, const float y,
                   const float width, const float height,
                   const unsigned char_size, const std::string text);

    /**
     * @brief Function to render a specific index of the tutorial.
     *
     * @param index Index of the tutorial to render.
     * @param target Render target for rendering the tutorial.
     */
    void render(int index, sf::RenderTarget& target);
};

#endif //FARMING_TUTORIAL_H
