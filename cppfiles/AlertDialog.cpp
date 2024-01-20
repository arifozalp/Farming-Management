//
// Created by Arif Özalp on 22.12.2023.
//

#include "../headers/stdafx.h"
#include "../headers/AlertDialog.h"

AlertDialog::AlertDialog(sf::VideoMode& vm, sf::Font& font)
        : font(font)
{
    //	Init container
    this->container.setSize(
            sf::Vector2f(
                    static_cast<float>(vm.width) / 4.f,
                    static_cast<float>(vm.height) /3.f
            )
    );


    this->container.setPosition(
            static_cast<float>(vm.width) / 2.f - static_cast<float>(this->container.getSize().x) / 2.f,
            gui::p2pY(30.f, vm)
    );
    Animation* background= new Animation();
    background->loadAnimation("../Resources/Images/Backgrounds/alertbg/alertdialog000.png", 1,
                              sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));
    container.setTexture(background->getAnim());

    //	Init text
    this->menuText.setFont(font);
    this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
    this->menuText.setCharacterSize(gui::calcCharSize(vm) * 2);
    this->menuText.setString("Alert");
    this->menuText.setPosition(
            this->container.getPosition().x + (this->container.getSize().x / 2.f) - this->menuText.getGlobalBounds().width / 2.f -10.f,
            this->container.getPosition().y + gui::p2pY(3.5f, vm)+5.f
    );
    this->Alert_text.setFont(font);
    this->Alert_text.setPosition(this->container.getPosition().x-100.f + (this->container.getSize().x / 2.f) - this->menuText.getGlobalBounds().width / 2.f,this->container.getPosition().y + gui::p2pY(13.f, vm));
    this->Alert_text.setFillColor(sf::Color::Black);
    this->Alert_text.setCharacterSize(gui::calcCharSize(vm));
}

AlertDialog::~AlertDialog()
{
    auto it = this->buttons.begin();
    for (; it != buttons.end(); ++it) {
        delete it->second;
    }
}

void AlertDialog::setAlert_text(std::string key){
    Alert_text.setString(key);
}

std::map<std::string, gui::Button*>& AlertDialog::getButtons()
{
    return this->buttons;
}

//	Functions

const bool AlertDialog::isButtonPressed(std::string key)
{
    return this->buttons[key]->isPressed();
}

void AlertDialog::addButton(std::string key,
                            const float y,
                            const float width,
                            const float height,
                            const unsigned char_size, const std::string text)
{
    float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;
    Animation* buttonbg=new Animation();
    buttonbg->loadAnimation("../Resources/Images/Backgrounds/alertbg/alertdialogbutton000.png", 1,
                            sf::Vector2f(800.f, 800.f));
    this->buttons[key] = new gui::Button(
            x, y, width, height,
            &this->font, text, char_size,
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190,255),
            sf::Color(20, 20, 20, 0),RECTANGLE,1,buttonbg
    );
}



void AlertDialog::update(const sf::Vector2i& mousePosWindow)
{
    for (auto& i : this->buttons)
    {
        i.second->update(mousePosWindow);
    }
}

void AlertDialog::render(sf::RenderTarget & target)
{
    target.draw(this->container);

    for (auto& i : this->buttons) {
        i.second->render(target);
    }
    target.draw(this->menuText);
    target.draw(this->Alert_text);
}