#ifndef FARMING_EXE_ENDANDREPORTSCREEN_H
#define FARMING_EXE_ENDANDREPORTSCREEN_H

#include "Gui.h"
#include "GameInfo.h"

/**
 * @brief EndAndReportScreen class for displaying the end and report screen.
 */
class EndAndReportScreen {

private:
    /**
     * @brief Font for text rendering.
     */
    sf::Font& font;

    /**
     * @brief Texts for menu and information.
     */
    sf::Text menuText;
    sf::Text information;

    /**
     * @brief Pointer to the GameInfo object.
     */
    GameInfo* gameInfo;

    /**
     * @brief Rectangle shape for the container.
     */
    sf::RectangleShape container;

    /**
     * @brief Map to store buttons in the end and report screen.
     */
    std::map<std::string, gui::Button*> buttons;

public:
    /**
     * @brief Constructor for the EndAndReportScreen class.
     *
     */
    EndAndReportScreen(sf::VideoMode& vm, sf::Font& font, GameInfo* gameInfo);

    /**
     * @brief Destructor for the EndAndReportScreen class.
     */
    virtual ~EndAndReportScreen();

    /**
     * @brief Function to check if a specific button is pressed.
     *
     */
    const bool isButtonPressed(std::string key);

    /**
     * @brief Function to add a button to the end and report screen.
     *
     */
    void addButton(std::string key, const float y,
                   const float width, const float height,
                   const unsigned char_size, const std::string text);

    /**
     * @brief Function to update the end and report screen based on mouse position.
     *
     */
    void update(const sf::Vector2i& mousePosWindow);

    /**
     * @brief Function to render the end and report screen on the screen.
     *
     */
    void render(sf::RenderTarget& target);
};

#endif //FARMING_EXE_ENDANDREPORTSCREEN_H
