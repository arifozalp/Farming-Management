#include "../headers/stdafx.h"
#include "../headers/MainMenuState.h"

//	Initializer Functions
void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("../Fonts/tahoma.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}

}

void MainMenuState::initGui()
{
	sf::VideoMode& vm = this->stateData->gfxSettings->resolution;


    bg->loadAnimation("../Resources/Images/Backgrounds/bgfile/tile000.png", 40,
                      sf::Vector2f(this->stateData->gfxSettings->resolution.width,
                                   this->stateData->gfxSettings->resolution.height));

    this->background.setTexture(&this->backgroundTexture);

    btnBackground.setSize(sf::Vector2f(
            static_cast<float>((vm.width / 3)+15),
            static_cast<float>(vm.height)
    ));
    btnText.setSize(sf::Vector2f(
            static_cast<float>((vm.width / 3)),
            static_cast<float>(vm.height/8)
    ));
    this->btnText.setPosition(gui::p2pX(4, vm), 20.f);
    this->backgroundTexture.loadFromFile("../Resources/Images/Backgrounds/gametext000.png");
    this->btnText.setTexture(&this->backgroundTexture);
    this->btnBackground.setPosition(gui::p2pX(3.5, vm), 0.f);
    this->btnBackground.setFillColor(sf::Color(10, 10, 30, 100));


    Animation* a= new Animation();
    a->loadAnimation("../Resources/Images/Backgrounds/button/buttonbg000.png", 1,
                     sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));

    this->buttons["CONTINUE_GAME"] = new gui::Button(gui::p2pX(21.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(50.f, vm) - gui::p2pY(7.f / 2.f, vm), gui::p2pX(15.f, vm), gui::p2pY(7.f, vm),
                                                      &this->font, "Continue", 2 * gui::calcCharSize(vm),
                                                     sf::Color(70, 70, 70, 200),
                                                     sf::Color(250, 250, 250, 200),
                                                     sf::Color(20, 20, 20, 200),
                                                     sf::Color(255, 255, 255),
                                                     sf::Color(112, 146, 190, 255),
                                                     sf::Color(112, 146, 190, 200),RECTANGLE,1,a
    );
    this->buttons["NEW_GAME"] = new gui::Button(gui::p2pX(21.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(60.f, vm) - gui::p2pY(7.f / 2.f, vm), gui::p2pX(15.f, vm), gui::p2pY(7.f, vm),
		&this->font, "New Game", 2 * gui::calcCharSize(vm),
                                                sf::Color(70, 70, 70, 200),
                                                sf::Color(250, 250, 250, 200),
                                                sf::Color(20, 20, 20, 200),
                                                sf::Color(255, 255, 255),
                                                sf::Color(112, 146, 190, 255),
                                                sf::Color(112, 146, 190, 200),RECTANGLE,0,a
	);
	this->buttons["SETTINGS_STATE"] = new gui::Button(gui::p2pX(21.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(70.f, vm) - gui::p2pY(7.f / 2.f, vm), gui::p2pX(15.f, vm), gui::p2pY(7.f, vm),
		&this->font, "Settings", 2 * gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 200),
		sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255),
		sf::Color(112, 146, 190, 255),
		sf::Color(112, 146, 190, 200),RECTANGLE,0,a
	);

    this->buttons["CREDITS_STATE"] = new gui::Button(gui::p2pX(21.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(80.f, vm) - gui::p2pY(7.f / 2.f, vm), gui::p2pX(15.f, vm), gui::p2pY(7.f, vm),
                                                     &this->font, "Credits", 2 * gui::calcCharSize(vm),
                                                     sf::Color(70, 70, 70, 200),
                                                     sf::Color(250, 250, 250, 200),
                                                     sf::Color(20, 20, 20, 200),
                                                     sf::Color(255, 255, 255),
                                                     sf::Color(112, 146, 190, 255),
                                                     sf::Color(112, 146, 190, 200),RECTANGLE,0,a
    );
    this->buttons["EXIT_STATE"] = new gui::Button(gui::p2pX(21.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(90.f, vm) - gui::p2pY(7.f / 2.f, vm), gui::p2pX(15.f, vm), gui::p2pY(7.f, vm),
                                                  &this->font, "Quit", 2 * gui::calcCharSize(vm),
                                                  sf::Color(70, 70, 70, 200),
                                                  sf::Color(250, 250, 250, 200),
                                                  sf::Color(20, 20, 20, 200),
                                                  sf::Color(255, 255, 255),
                                                  sf::Color(112, 146, 190, 255),
                                                  sf::Color(112, 146, 190, 200),RECTANGLE,0,a
    );

}

void MainMenuState::resetGui()
{
	for (auto it = this->buttons.begin(); it != buttons.end(); it++) {
		delete it->second;
	}
	this->buttons.clear();
	this->initGui();
}


MainMenuState::MainMenuState(StateData* state_data)
	: State(state_data)
{
	this->initFonts();
	this->initGui();
	this->resetGui();
    this->stateData->soundManager->getMainMenuSound()->playSound();
    this->stateData->soundManager->getMainMenuSound()->loopSound();
}

MainMenuState::~MainMenuState()
{
	for (auto it = this->buttons.begin(); it != buttons.end(); it++) {
		delete it->second;
	}
}

void MainMenuState::updateInput(const float & dt)
{

}

void MainMenuState::updateButtons()
{
	/*Update all the buttons in the state and handles their functionality*/
	for (auto &it : this->buttons) {
		it.second->update(this->mousePosWindow);
	}

    if(this->buttons["NEW_GAME"]->isPressed()){
        this->stateData->soundManager->getButtonClickSound()->playSound();
        this->stateData->gameInfo=new GameInfo();
        this->loadingStartRender();
        if(this->stateData->gameInfo->getIsFinishProfile()) {
            this->states->push(new GameState(this->stateData));
        }
        else if(!this->stateData->gameInfo->getIsFinishProfile() && !this->stateData->gameInfo->getEndGame()){
            this->states->push(new ProfileState(this->stateData));
        }
    }


	//	New game
	if (this->buttons["CONTINUE_GAME"]->isPressed()&&!this->stateData->gameInfo->getEndGame()) {
        this->stateData->soundManager->getButtonClickSound()->playSound();
        this->loadingStartRender();
        if(this->stateData->gameInfo->getIsFinishProfile()) {
            this->states->push(new GameState(this->stateData));
        }
        else if(!this->stateData->gameInfo->getIsFinishProfile() && !this->stateData->gameInfo->getEndGame()){
            this->states->push(new ProfileState(this->stateData));
        }

    }
    //	Settings
	if (this->buttons["SETTINGS_STATE"]->isPressed()) {
        this->stateData->soundManager->getButtonClickSound()->playSound();
        this->loadingStartRender();
        this->states->push(new SettingsState(this->stateData));

    }

    if (this->buttons["CREDITS_STATE"]->isPressed()) {
        this->stateData->soundManager->getButtonClickSound()->playSound();
        this->loadingStartRender();
        this->states->push(new CreditState(this->stateData));
    }
    //	Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed()) {
        this->stateData->soundManager->getButtonClickSound()->playSound();
        this->loadingStartRender();
        this->stateData->soundManager->closeAllSound();
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}


void MainMenuState::renderButtons(sf::RenderTarget & target)
{
	for (auto &it : this->buttons) {
        if(!it.second->getId()==1){
            it.second->render(target);
        }
        else{
            if(this->stateData->gameInfo->getIsFinishProfile() && this->stateData->gameInfo->getIsFinishTutorial()){
                it.second->render(target);
            }
        }

	}

}
void MainMenuState::loadingRender(sf::RenderTarget* target) {
    loadingScreen.setStartPositionIndex();
    loadingScreen.setAnimIsFinish(false);
    while (!loadingScreen.getAnimIsFinish()) {
        this->stateData->window->display();
        this->bg->drawAnim(*target);
        target->draw(this->btnBackground);
        target->draw(this->btnText);
        this->renderButtons(*target);
        loadingScreen.startRender(*this->stateData->window);

    }
}

void MainMenuState::loadingStartRender() {
    loadingScreen.setEndPositionIndex();
    loadingScreen.setAnimIsFinish(false);
    while (!loadingScreen.getAnimIsFinish()) {
        this->stateData->window->display();
        this->render(this->stateData->window);
        loadingScreen.render(*this->stateData->window);
    }
}


void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
    if(this->stateData->gameInfo->isPassOtherState){
        loadingRender(target);
        this->stateData->gameInfo->isPassOtherState=false;
    }
    this->bg->drawAnim(*target);
        target->draw(this->btnBackground);
        target->draw(this->btnText);
        this->renderButtons(*target);

}
