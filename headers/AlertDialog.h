#ifndef FARMING_ALERTDIALOG_H
#define FARMING_ALERTDIALOG_H

#include "Gui.h"

/**
 * @brief AlertDialog class for creating and managing alert dialogs.
 */
class AlertDialog {
private:
    /**
     * @brief Font for text rendering.
     */
    sf::Font& font;

    /**
     * @brief Text for the menu.
     */
    sf::Text menuText;

    /**
     * @brief Container shape for the alert dialog.
     */
    sf::RectangleShape container;

    /**
     * @brief Text for the alert message.
     */
    sf::Text Alert_text;

    /**
     * @brief Map to store buttons in the alert dialog.
     */
    std::map<std::string, gui::Button*> buttons;

public:
    /**
     * @brief Constructor for AlertDialog class.
     *
     * @param vm VideoMode for the AlertDialog.
     * @param font Font for text rendering.
     */
    AlertDialog(sf::VideoMode& vm, sf::Font& font);

    /**
     * @brief Destructor for AlertDialog class.
     */
    virtual ~AlertDialog();

    /**
     * @brief Accessor to get the buttons in the alert dialog.
     *
     */
    std::map<std::string, gui::Button*>& getButtons();

    /**
     * @brief Function to set the alert message text.
     *
     */
    void setAlert_text(std::string key);

    /**
     * @brief Function to check if a specific button is pressed.
     *
     * @return True if the button is pressed, false otherwise.
     */
    const bool isButtonPressed(std::string key);

    /**
     * @brief Function to add a button to the alert dialog.
     *
     */
    void addButton(std::string key, const float y,
                   const float width, const float height,
                   const unsigned char_size, const std::string text);

    /**
     * @brief Function to update the alert dialog based on mouse position.
     *
     */
    void update(const sf::Vector2i& mousePosWindow);

    /**
     * @brief Function to render the alert dialog on the screen.
     *
     */
    void render(sf::RenderTarget& target);
};

#endif //FARMING_ALERTDIALOG_H
