#pragma once
#include "Animation.h"

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

enum ShapeType {
    RECTANGLE,
    PARALLELOGRAM
};

namespace gui
{
    /**
     * @brief Convert percentage to pixels on the x-axis.
     *
     * @param perc Percentage value to convert.
     * @param vm SFML VideoMode object for screen resolution.
     * @return Converted pixel value on the x-axis.
     */
    const float p2pX(const float perc, const sf::VideoMode& vm);

    /**
     * @brief Convert percentage to pixels on the y-axis.
     *
     * @param perc Percentage value to convert.
     * @param vm SFML VideoMode object for screen resolution.
     * @return Converted pixel value on the y-axis.
     */
    const float p2pY(const float perc, const sf::VideoMode& vm);

    /**
     * @brief Calculate character size based on screen resolution.
     *
     * @param vm SFML VideoMode object for screen resolution.
     * @param modifier Modifier value for character size calculation.
     * @return Calculated character size.
     */
    const unsigned calcCharSize(const sf::VideoMode& vm, const unsigned modifier = 150.f);

    /**
     * @brief The Button class represents a GUI button.
     */
    class Button
    {
    private:
        short unsigned buttonState;
        short unsigned id;

        sf::Shape* shape= nullptr;
        sf::RectangleShape rectangleShape;
        sf::ConvexShape parallelogramShape;
        ShapeType shapeType=RECTANGLE;

        sf::Font* font;
        sf::Text text;

        sf::Color textIdleColor;
        sf::Color textHoverColor;
        sf::Color textActiveColor;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

        Animation* bg;
    public:
        /**
         * @brief Constructor for the Button class.
         *
         * @param x X-coordinate of the button.
         * @param y Y-coordinate of the button.
         * @param width Width of the button.
         * @param height Height of the button.
         * @param font Pointer to the SFML Font object.
         * @param text Text to display on the button.
         * @param character_size Character size for the text.
         * @param text_idle_color Color of the text in idle state.
         * @param text_hover_color Color of the text in hover state.
         * @param text_active_color Color of the text in active state.
         * @param idle_color Color of the button in idle state.
         * @param hover_color Color of the button in hover state.
         * @param active_color Color of the button in active state.
         * @param shapeType Type of the button shape (RECTANGLE or PARALLELOGRAM).
         * @param id ID of the button.
         * @param bg Pointer to the Animation object for the button background.
         * @param angle Angle for the PARALLELOGRAM shape.
         */
        Button(float x, float y, float width, float height,
               sf::Font* font, std::string text, unsigned character_size,
               sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
               sf::Color idle_color, sf::Color hover_color, sf::Color active_color,ShapeType shapeType,
               short unsigned id = 0,Animation* bg= nullptr,float angle=110.f);

        /**
         * @brief Destructor for the Button class.
         */
        ~Button();

        /**
         * @brief Check if the button is pressed.
         *
         * @return True if the button is pressed, false otherwise.
         */
        const bool isPressed() const;

        /**
         * @brief Get the ID of the button.
         *
         * @return ID of the button.
         */
        const short unsigned& getId() const;

        /**
         * @brief Create a parallelogram shape.
         *
         * @param x X-coordinate of the shape.
         * @param y Y-coordinate of the shape.
         * @param width Width of the shape.
         * @param height Height of the shape.
         * @param angle Angle for the PARALLELOGRAM shape.
         * @return SFML ConvexShape object representing the parallelogram.
         */
        sf::ConvexShape createParallelogram(float x, float y, float width, float height, float angle);

        /**
         * @brief Update the button state based on mouse position.
         *
         * @param mousePosWindow SFML Vector2i object representing mouse position.
         */
        void update(const sf::Vector2i& mousePosWindow);

        /**
         * @brief Render the button.
         *
         * @param target SFML RenderTarget object for rendering.
         */
        void render(sf::RenderTarget& target);
    };

    /**
     * @brief The LoadingScreen class represents a GUI loading screen.
     */
    class LoadingScreen {
    private:
        Animation* loadingAnim;
        sf::RectangleShape container;
        bool animIsFinish=true;
        int index=0;

    public:
        /**
         * @brief Constructor for the LoadingScreen class.
         */
        LoadingScreen();

        /**
         * @brief Destructor for the LoadingScreen class.
         */
        ~LoadingScreen();

        /**
         * @brief Check if the animation is finished.
         *
         * @return True if the animation is finished, false otherwise.
         */
        bool getAnimIsFinish();

        /**
         * @brief Set the animation finish state.
         *
         * @param finish True to set animation as finished, false otherwise.
         */
        void setAnimIsFinish(bool finish);

        /**
         * @brief Set the start position index for the animation.
         */
        void setStartPositionIndex();

        /**
         * @brief Set the end position index for the animation.
         */
        void setEndPositionIndex();

        /**
         * @brief Start rendering the loading screen.
         *
         * @param target SFML RenderTarget object for rendering.
         */
        void startRender(sf::RenderTarget& target);

        /**
         * @brief Render the loading screen.
         *
         * @param target SFML RenderTarget object for rendering.
         */
        void render(sf::RenderTarget& target);
    };

    /**
     * @brief The ProgressBar class represents a GUI progress bar.
     */
    class ProgressBar {
    private:
        std::string barString;
        sf::Text text;
        float maxWidth;
        int maxValue;
        sf::RectangleShape back;
        sf::RectangleShape inner;

    public:
        /**
         * @brief Constructor for the ProgressBar class.
         *
         * @param x X-coordinate of the progress bar.
         * @param y Y-coordinate of the progress bar.
         * @param width Width of the progress bar.
         * @param height Height of the progress bar.
         * @param max_value Maximum value for the progress bar.
         * @param innerColor Color of the inner part of the progress bar.
         * @param character_size Character size for the text.
         * @param vm SFML VideoMode object for screen resolution.
         * @param font Pointer to the SFML Font object.
         */
        ProgressBar(
                float x, float y, float width, float height,
                int max_value, sf::Color innerColor, unsigned character_size,
                sf::VideoMode& vm, sf::Font* font = NULL);

        /**
         * @brief Destructor for the ProgressBar class.
         */
        ~ProgressBar();

        /**
         * @brief Set the maximum value for the progress bar.
         *
         * @param max Maximum value for the progress bar.
         */
        void setMaxValue(int max);

        /**
         * @brief Set the color of the inner part of the progress bar.
         *
         * @param color Color for the inner part.
         */
        void setInnerColor(sf::Color color);

        /**
         * @brief Update the progress bar based on the current value.
         *
         * @param current_value Current value for the progress bar.
         */
        void update(const int current_value);

        /**
         * @brief Render the progress bar.
         *
         * @param target SFML RenderTarget object for rendering.
         */
        void render(sf::RenderTarget & target);
    };

}
