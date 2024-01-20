#include "../headers/stdafx.h"
#include "../headers/ProfileState.h"

void ProfileState::initFonts()
{
    if (!this->font.loadFromFile("../Fonts/Inconsolata-Bold.ttf")) {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}
void ProfileState::initGui()
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
    btnBackground.setSize(sf::Vector2f(
            static_cast<float>(vm.width ),
            static_cast<float>(vm.height)
    ));
    this->btnBackground.setFillColor(sf::Color(10, 10, 30, 100));

    btnText.setSize(
            sf::Vector2f(
                    static_cast<float>((vm.width / 3)),
                    static_cast<float>(vm.height/8))
    );
    this->btnText.setPosition(gui::p2pX(35, vm), 20.f);
    this->textBackgroundTexture.loadFromFile("../Resources/Images/Backgrounds/iconimage/characterscreen000.png");
    this->btnText.setTexture(&this->textBackgroundTexture);



    Animation* farmer1= new Animation();
    farmer1->loadAnimation("../Resources/Images/Backgrounds/iconimage/manfarmer000.png", 1, sf::Vector2f(800, 800));

    Animation* farmer2= new Animation();
    farmer2->loadAnimation("../Resources/Images/Backgrounds/bgfile/womanfarmer000.png", 1, sf::Vector2f(800, 800));
    //	Buttons

    this->buttons["FARMER_MAN"] = new gui::Button(
            gui::p2pX(40.f, vm) - gui::p2pX(15.f / 2.f, vm),
            gui::p2pY(33.5f, vm) - gui::p2pY(7.f / 2.f, vm),
            300.f,
            320.f,
            &this->font, "OSMAN", 2 * gui::calcCharSize(vm),
            sf::Color(250, 250, 250, 200),
            sf::Color(0, 128, 0, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,0,farmer1
    );
    this->buttons["FARMER_WOMAN"] = new gui::Button(
            gui::p2pX(60.f, vm) - gui::p2pX(15.f / 2.f, vm),
            gui::p2pY(35.f, vm) - gui::p2pY(7.f / 2.f, vm),
            300.f,
            300.f,
            &this->font, "FATMA", 2 * gui::calcCharSize(vm),
            sf::Color(250, 250, 250, 200),
            sf::Color(0, 128, 0, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,0,farmer2
    );
    Animation* a= new Animation();
    a->loadAnimation("../Resources/Images/Backgrounds/button/buttonbg000.png", 1,
                     sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));


    this->buttons["BACK"] = new gui::Button(
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
}

ProfileState::ProfileState(StateData* state_data)
    : State(state_data)
{
    this->initFonts();
    this->initGui();
    this->save1=new save(state_data);
    try{
        save1->resetToXml();
    }catch(const std::exception& e){
        std::cout << "Hata: " << e.what() << std::endl;
    }

    this->stateData->player=new player();
    this->stateData->farm=new farm(this->stateData->player);
    this->stateData->trader=new trader(this->stateData->player,this->stateData->farm);
    this->stateData->upgrade=new upgrade();
    this->stateData->eventManager=new EventManager(this->stateData->player,this->stateData->upgrade,this->stateData->farm);
    this->loadingRender();
}

ProfileState::~ProfileState()
{
    for (auto it = this->buttons.begin(); it != buttons.end(); it++) {
        delete it->second;
    }
}

void ProfileState::updateGui(const float& dt)
{
    for (auto &it : this->buttons) {
        it.second->update(this->mousePosWindow);
    }

    //	Button Functionality
    if(this->buttons["FARMER_MAN"]->isPressed()){
        this->stateData->soundManager->getButtonClickSound()->playSound();
        this->stateData->player->setPlayerName("Osman");
        this->stateData->farm->setFarmName("Osman's Farm");
        this->stateData->gameInfo->setIsFinishProfile();
        loadingScreen.setEndPositionIndex();
        loadingScreen.setAnimIsFinish(false);
        while (!loadingScreen.getAnimIsFinish()) {
            this->stateData->window->display();
            this->render(this->stateData->window);
            loadingScreen.render(*this->stateData->window);
        }
        this->states->push(new GameState(this->stateData));
        this->endState();
        this->stateData->gameInfo->isPassOtherState=true;

    } else if (this->buttons["FARMER_WOMAN"]->isPressed()){
        this->stateData->soundManager->getButtonClickSound()->playSound();
        this->stateData->player->setPlayerName("Fatma");
        this->stateData->farm->setFarmName("Fatma's Farm");
        this->stateData->gameInfo->setIsFinishProfile();
        loadingScreen.setEndPositionIndex();
        loadingScreen.setAnimIsFinish(false);
        while (!loadingScreen.getAnimIsFinish()) {
            this->stateData->window->display();
            this->render(this->stateData->window);
            loadingScreen.render(*this->stateData->window);
        }
        this->states->push(new GameState(this->stateData));
        this->endState();
        this->stateData->gameInfo->isPassOtherState=true;
    }

    if (this->buttons["BACK"]->isPressed()) {
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

void ProfileState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateGui(dt);
}

void ProfileState::updateInput(const float &dt) {

}

void ProfileState::renderButtons(sf::RenderTarget & target)
{
    for (auto &it : this->buttons) {
        it.second->render(target);
    }

}
void ProfileState::loadingRender() {
    loadingScreen.setStartPositionIndex();
    loadingScreen.setAnimIsFinish(false);
    while (!loadingScreen.getAnimIsFinish()) {
        this->render(this->stateData->window);
        loadingScreen.startRender(*this->stateData->window);
        this->stateData->window->display();
    }

}

void ProfileState::render(sf::RenderTarget* target)
{
    if (!target) {
        target = this->window;
    }
    sf::sleep(sf::milliseconds(40));
    target->draw(this->background);
    target->draw(this->btnBackground);
    target->draw(this->btnText);
    this->renderButtons(*target);
}