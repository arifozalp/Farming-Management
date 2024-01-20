#ifndef Animation_h
#define Animation_h

#include <SFML\Graphics.hpp>
#include <vector>
#include <string>

/**
 * @brief The Animation class for handling sprite animations.
 */
class Animation
{
public:
    /**
     * @brief Constructor for the Animation class.
     */
    Animation();

    /**
     * @brief Load animation frames from file.
     *
     * @param firstFileName The file name of the first frame.
     * @param numberOfFrame The number of frames in the animation.
     * @param size The size of each frame.
     */
    void loadAnimation(std::string firstFileName, int numberOfFrame, sf::Vector2f size);

    /**
     * @brief Draw the animation on the render target.
     *
     * @param renderTarget The render target to draw the animation on.
     */
    void drawAnim(sf::RenderTarget &renderTarget);

    /**
     * @brief Get the base texture of the animation.
     *
     * @return A pointer to the base texture of the animation.
     */
    sf::Texture* getAnim();

    /**
     * @brief Get the texture at a specific index.
     *
     * @param index The index of the texture to retrieve.
     * @return A pointer to the texture at the specified index.
     */
    sf::Texture* getAnimIndex(int index);

    /**
     * @brief Rectangle shape for the animation.
     *
     */
    sf::RectangleShape shp;

    /**
     * @brief Vectors to store sprites for each frame
     *
     */
    std::vector<sf::Sprite*> m_Sprites;

    /**
     * @brief Vectors to store textures for each frame
     *
     */
    std::vector<sf::Texture*> m_Textures;

private:
    /**
     * @brief The file name of the animation.
     */
    std::string fileName;

    /**
     * @brief The number of sprites in the animation.
     */
    int m_numberOfSprite;

    /**
     * @brief The total number of frames in the animation.
     */
    int m_numberOfTexture;

    /**
     * @brief The frames per second (fps) for the animation.
     */
    int m_animationTime;

    /**
     * @brief The index of the currently active texture.
     */
    int m_currentTexture;
};

#endif