#pragma once

/**
 * @brief The GraphicsSettings class holds settings related to graphics and window configuration.
 */
class GraphicsSettings {
public:
    /**
     * @brief Constructor for the GraphicsSettings class.
     */
    GraphicsSettings();

    /**
     * @brief Variables for the GraphicsSettings class.
     */
    std::string title = "DEFAULT";              /**< Title of the window. */
    sf::VideoMode resolution;                   /**< Video mode (screen resolution). */
    bool fullscreen;                            /**< Fullscreen mode flag. */
    unsigned framerateLimit;                    /**< Framerate limit. */
    sf::ContextSettings contextSettings;        /**< Context settings for rendering. */

    /**
     * @brief Load graphics settings from a file.
     *
     * @param path Path to the file containing graphics settings.
     */
    void loadFromFile(const std::string path);
};
