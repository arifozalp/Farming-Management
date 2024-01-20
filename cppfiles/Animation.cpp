#include "../headers/stdafx.h"
#include "../headers/Animation.h"


Animation::Animation()
{
    m_numberOfSprite = 0;
    m_numberOfTexture = 0;
    m_animationTime = 40;
    m_currentTexture = 0;
}

void Animation::loadAnimation(std::string firstFileName, int numberOfFrame, sf::Vector2f size)
{
    m_Sprites.clear();
    m_Textures.clear();

    m_numberOfSprite = numberOfFrame;
    for (int i = 0; i < numberOfFrame; i++)
    {
        sf::Sprite *newSprite = new sf::Sprite;

        sf::Texture *newTexture = new sf::Texture;

        std::string pieceOfFileName = firstFileName.substr(0, firstFileName.length() - 7);

        std::string fileExtension = firstFileName.substr(firstFileName.length() - 4, 4);

        if(i<10){
            fileName = pieceOfFileName + std::to_string(0) + std::to_string(0) + std::to_string(i) + fileExtension;
        }else
        {
            fileName = pieceOfFileName + std::to_string(0) + std::to_string(i) + fileExtension;
        }

        newTexture->loadFromFile(fileName);
        newSprite->setTexture(*newTexture);
        newSprite->setScale(size.x / newSprite->getLocalBounds().width, size.y / newSprite->getLocalBounds().height);

        m_Sprites.push_back(newSprite);
        m_Textures.push_back(newTexture);
    }
}

void Animation::drawAnim(sf::RenderTarget &renderTarget)
{
        renderTarget.draw(*m_Sprites[m_numberOfTexture]);
        sf::sleep(sf::milliseconds(m_animationTime));
    m_numberOfTexture = (m_numberOfTexture + 1) % m_numberOfSprite;

}
sf::Texture* Animation::getAnim(){
    m_currentTexture = (m_currentTexture + 1) % m_numberOfSprite;
    return m_Textures[m_currentTexture];
}
sf::Texture* Animation::getAnimIndex(int index){
    return m_Textures[index];
}




