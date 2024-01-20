#include "../headers/tutorial.h"
#include "../headers/Animation.h"
tutorial::tutorial(sf::VideoMode& vm, sf::Font& font)
    : font(font){

    this->background.setSize(
            sf::Vector2f(
                    static_cast<float>(vm.width),
                    static_cast<float>(vm.height)
            )
    );
    textures[0].loadFromFile("../Resources/Images/Tutorial_image/tut1.png");
    textures[1].loadFromFile("../Resources/Images/Tutorial_image/tut2.png");
    textures[2].loadFromFile("../Resources/Images/Tutorial_image/tut3.png");
    textures[3].loadFromFile("../Resources/Images/Tutorial_image/tut4.png");
    textures[4].loadFromFile("../Resources/Images/Tutorial_image/tut5.png");
    textures[5].loadFromFile("../Resources/Images/Tutorial_image/tut6.png");
    textures[6].loadFromFile("../Resources/Images/Tutorial_image/tut7.png");
    textures[7].loadFromFile("../Resources/Images/Tutorial_image/tut8.png");

}

tutorial::~tutorial() {
    auto it = this->buttons.begin();
    for (; it != buttons.end(); ++it) {
        delete it->second;
    }
}

const bool tutorial::isButtonPressed(const std::string key)
{
    return this->buttons[key]->isPressed();
}
void tutorial::addButton(const std::string key,const float x,
                          const float y,
                          const float width,
                          const float height,
                          const unsigned char_size, const std::string text)
{
    Animation* a= new Animation();
    a->loadAnimation("../Resources/Images/Backgrounds/button/buttonbg000.png", 1, sf::Vector2f(800, 800));

    this->buttons[key] = new gui::Button(
            x, y, width, height,
            &this->font, text, char_size,
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,a
    );
}

void tutorial::update(const sf::Vector2i &mousePosWindow) {
    for (auto& i : this->buttons)
    {
        i.second->update(mousePosWindow);
    }
}
void tutorial::render(int index,sf::RenderTarget &target) {
    background.setTexture(&this->textures[index]);
    target.draw(background);
    for (auto& i : this->buttons) {
        i.second->render(target);
    }
}