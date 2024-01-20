#include "../headers/EndAndReportScreen.h"




EndAndReportScreen::EndAndReportScreen(sf::VideoMode &vm, sf::Font &font,GameInfo* gameInfo) : font(font){

    this->gameInfo=gameInfo;
    this->container.setSize(
            sf::Vector2f(
                    static_cast<float>(vm.width) / 2.f,
                    static_cast<float>(vm.height) /2.f
            )
    );


    this->container.setPosition(
            static_cast<float>(vm.width) / 2.f - static_cast<float>(this->container.getSize().x) / 2.f,
            gui::p2pY(30.f, vm)
    );
    Animation* background= new Animation();
    background->loadAnimation("../Resources/Images/Backgrounds/alertbg/EndGame000.png", 1,
                              sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));
    container.setTexture(background->getAnim());

    //	Init text
    this->menuText.setFont(font);
    this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
    this->menuText.setCharacterSize(gui::calcCharSize(vm) * 2);
    this->menuText.setString("Congratulations!");
    this->menuText.setPosition(
            this->container.getPosition().x + (this->container.getSize().x / 2.f) - this->menuText.getGlobalBounds().width+20 / 2.f,
            this->container.getPosition().y + gui::p2pY(3.5f, vm)+5.f
    );
    this->information.setFont(font);
    this->information.setFillColor(sf::Color::Black);
    this->information.setCharacterSize(gui::calcCharSize(vm) * 1);
    this->information.setPosition(
            700 ,
            450
    );

}


const bool EndAndReportScreen::isButtonPressed(std::string key) {
    return this->buttons[key]->isPressed();
}

void EndAndReportScreen::addButton(std::string key, const float y, const float width, const float height,
                                   const unsigned int char_size, const std::string text) {

    float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;
    Animation* buttonbg=new Animation();
    buttonbg->loadAnimation("../Resources/Images/Backgrounds/alertbg/returnMain000.png", 1, sf::Vector2f(800.f, 800.f));
    this->buttons[key] = new gui::Button(
            x, y, width, height,
            &this->font, text, char_size,
            sf::Color(255, 255, 255, 100),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 255),
            sf::Color(255, 255, 255, 255),
            sf::Color(150, 150, 150, 200),
            sf::Color(20, 20, 20, 0),RECTANGLE,1,buttonbg
    );

}

EndAndReportScreen::~EndAndReportScreen() {
    auto it = this->buttons.begin();
    for (; it != buttons.end(); ++it) {
        delete it->second;
    }
}


void EndAndReportScreen::update(const sf::Vector2i &mousePosWindow) {
    for (auto& i : this->buttons)
    {
        i.second->update(mousePosWindow);
    }

    this->information.setString("   Plant piece   Harvest piece   Gain money   \n\n\n\n        " + to_string(
            gameInfo->getWheatPlantPiece()) + "             " + to_string(gameInfo->getWheatHarvestPiece()) + "             " + to_string(gameInfo->getGainMoneyWithWheat()) + "\n\n\n        " + to_string(
            gameInfo->getTomatoPlantPiece()) + "             " + to_string(gameInfo->getTomatoHarvestPiece()) + "             " + to_string(gameInfo->getGainMoneyWithTomato()) + "\n\n\n        " + to_string(
            gameInfo->getCornPlantPiece())
                                + "             " + to_string(gameInfo->getCornHarvestPiece())
                                + "             " + to_string(gameInfo->getGainMoneyWithCorn()));

}

void EndAndReportScreen::render(sf::RenderTarget &target) {
    target.draw(this->container);

    for (auto& i : this->buttons) {
        i.second->render(target);
    }
    target.draw(this->menuText);
    target.draw(this->information);

}
