//
// Created by Arif Özalp on 31.12.2023.
//
#include "../headers/stdafx.h"
#include "../headers/CreditState.h"

void CreditState::initFonts()
{
    if (!this->font.loadFromFile("../Fonts/Inconsolata-Bold.ttf")) {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void CreditState::initGui()
{
    sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

    this->font.loadFromFile("../Fonts/tahoma.ttf");
    //	Background
    this->background.setSize(
            sf::Vector2f(
                    static_cast<float>(vm.width),
                    static_cast<float>(vm.height)
            )
    );
    if (!this->backgroundTexture.loadFromFile("../Resources/Images/Backgrounds/SettingImage/settingbg000.png")) {
        throw "ERROR::MAINMENUSTATES::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
    }
    this->background.setTexture(&this->backgroundTexture);

    shadowBackground.setSize(sf::Vector2f(
            static_cast<float>(vm.width ),
            static_cast<float>(vm.height)
    ));
    this->shadowBackground.setFillColor(sf::Color(10, 10, 30, 100));

    this->groupFotoShape.setSize(
            (
                    sf::Vector2f(
                            static_cast<float>(640.f),
                            static_cast<float>(640.f)
                    )
            )
    );
    this->groupFotoShape.setPosition(1000,200);

    if (!this->groupFotoTexture.loadFromFile("../Resources/Images/Backgrounds/grupfoto000.jpg")) {
        throw "ERROR::MAINMENUSTATES::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
    }

    this->groupFotoShape.setTexture(&this->groupFotoTexture);

    Animation* a= new Animation();
    a->loadAnimation("../Resources/Images/Backgrounds/button/buttonbg000.png", 1,
                     sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));

    //	Buttons
    this->back = new gui::Button(
            gui::p2pX(50.f, vm) - gui::p2pX(15.f / 2.f, vm),
            gui::p2pY(90.f, vm) - gui::p2pY(7.f / 2.f, vm),
            gui::p2pX(15.f, vm),
            gui::p2pY(7.f, vm),
            &this->font, "Back", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,a
    );

    //	Text init
    this->creditsTitle.setFont(font);
    this->creditsTitle.setPosition(sf::Vector2f(gui::p2pX(12.f, vm) - gui::p2pX(35.f / 2.f, vm), gui::p2pY(20.f, vm) - gui::p2pY(7.f / 2.f, vm)));
    this->creditsTitle.setCharacterSize(gui::calcCharSize(vm, 125.f));
    this->creditsTitle.setFillColor(sf::Color::White);
    this->creditsTitle.setString("CREDITS:");

    this->creditsContents1.setFont(font);
    this->creditsContents1.setPosition(sf::Vector2f(gui::p2pX(12.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(30.f, vm) - gui::p2pY(7.f / 2.f, vm)));
    this->creditsContents1.setCharacterSize(gui::calcCharSize(vm, 125.f));
    this->creditsContents1.setFillColor(sf::Color::White);
    this->creditsContents1.setString("Arif Ozalp 21050111058 - Backend and Frontend");

    this->creditsContents2.setFont(font);
    this->creditsContents2.setPosition(sf::Vector2f(gui::p2pX(12.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(35.f, vm) - gui::p2pY(7.f / 2.f, vm)));
    this->creditsContents2.setCharacterSize(gui::calcCharSize(vm, 125.f));
    this->creditsContents2.setFillColor(sf::Color::White);
    this->creditsContents2.setString("Bulent Durusoy 21050111029 - Sounds Producer and Frontend");

    this->creditsContents3.setFont(font);
    this->creditsContents3.setPosition(sf::Vector2f(gui::p2pX(12.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(40.f, vm) - gui::p2pY(7.f / 2.f, vm)));
    this->creditsContents3.setCharacterSize(gui::calcCharSize(vm, 125.f));
    this->creditsContents3.setFillColor(sf::Color::White);
    this->creditsContents3.setString("Meric Uysalerler 21050111051 - Graphic Designer and Frontend");

    this->creditsContents4.setFont(font);
    this->creditsContents4.setPosition(sf::Vector2f(gui::p2pX(12.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(45.f, vm) - gui::p2pY(7.f / 2.f, vm)));
    this->creditsContents4.setCharacterSize(gui::calcCharSize(vm, 125.f));
    this->creditsContents4.setFillColor(sf::Color::White);
    this->creditsContents4.setString("Mert Bilgic 2105011180 - Graphic Designer and Frontend");

    this->creditsContents5.setFont(font);
    this->creditsContents5.setPosition(sf::Vector2f(gui::p2pX(12.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(50.f, vm) - gui::p2pY(7.f / 2.f, vm)));
    this->creditsContents5.setCharacterSize(gui::calcCharSize(vm, 125.f));
    this->creditsContents5.setFillColor(sf::Color::White);
    this->creditsContents5.setString("Onur Cokyigit 21050111012 - Backend and Frontend");


}

CreditState::CreditState(StateData *state_data) : State(state_data) {
    this->initFonts();
    this->initGui();
    this->loadingRender();
}

CreditState::~CreditState() {

}

void CreditState::updateInput(const float & dt)
{/**/
}


void CreditState::updateGui(const float &dt) {
    if (this->back->isPressed()) {
        this->stateData->soundManager->getButtonClickSound()->playSound();
        loadingScreen.setEndPositionIndex();
        loadingScreen.setAnimIsFinish(false);
        while (!loadingScreen.getAnimIsFinish()) {
            this->stateData->window->display();
            this->render(this->stateData->window);
            loadingScreen.render(*this->stateData->window);
        }
        this->endState();
        this->stateData->gameInfo->isPassOtherState=true;
    }
}

void CreditState::update(const float &dt) {
    back->update(mousePosWindow);
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateGui(dt);
}

void CreditState::renderGui(sf::RenderTarget &target) {
    back->render(target);
}

void CreditState::loadingRender() {
    loadingScreen.setStartPositionIndex();
    loadingScreen.setAnimIsFinish(false);
    while (!loadingScreen.getAnimIsFinish()) {
        this->render(this->stateData->window);
        loadingScreen.startRender(*this->stateData->window);
        this->stateData->window->display();
    }

}

void CreditState::render(sf::RenderTarget *target) {
    if (!target) {
        target = this->window;
    }
    sf::sleep(sf::milliseconds(40));
    target->draw(this->background);
    target->draw(this->shadowBackground);
    target->draw(this->creditsTitle);
    target->draw(this->creditsContents1);
    target->draw(this->creditsContents2);
    target->draw(this->creditsContents3);
    target->draw(this->creditsContents4);
    target->draw(this->creditsContents5);
    target->draw(this->groupFotoShape);


    this->renderGui(*target);
}