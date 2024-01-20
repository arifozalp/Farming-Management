#include "../headers/stdafx.h"
#include "../headers/GameState.h"


void GameState::initDeferredRender()
{
    this->renderTexture.create(
            this->stateData->gfxSettings->resolution.width,
            this->stateData->gfxSettings->resolution.height
    );

}

void GameState::initView()
{
    this->view.setSize(sf::Vector2f(
            static_cast<float>(this->stateData->gfxSettings->resolution.width),
            static_cast<float>(this->stateData->gfxSettings->resolution.height)
    ));
    this->view.setCenter(sf::Vector2f(
            static_cast<float>(this->stateData->gfxSettings->resolution.width)/2.f,
            static_cast<float>(this->stateData->gfxSettings->resolution.height)/2.f
    ));
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("../Fonts/Inconsolata-Bold.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}

}

void GameState::initTextures()
{
    const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
    this->tutorial1=new tutorial(this->stateData->gfxSettings->resolution,this->font);
    this->tutorial1->addButton("CONTINUE",gui::p2pY(20.f, vm), gui::p2pY(90.f, vm), gui::p2pX(20.f, vm), gui::p2pY(10.f, vm), gui::calcCharSize(vm), "Continue");
    this->tutorial1->addButton("SKIP",gui::p2pY(110.f, vm), gui::p2pY(90.f, vm), gui::p2pX(20.f, vm), gui::p2pY(10.f, vm), gui::calcCharSize(vm), "Skip");

}

void GameState::initPauseMenu()
{
    const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->pauseMenu = new PauseMenu(this->stateData, this->stateData->gfxSettings->resolution, this->font);

	this->pauseMenu->addButton("QUIT", gui::p2pY(85.f, vm), gui::p2pX(20.f, vm), gui::p2pY(10.f, vm), gui::calcCharSize(vm), "Quit");
}

void GameState::initEndScreen() {
    const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
    this->endAndReportScreen = new EndAndReportScreen(this->stateData->gfxSettings->resolution, this->font,this->stateData->gameInfo);
    this->endAndReportScreen->addButton("MENU", gui::p2pY(85.f, vm), gui::p2pX(20.f, vm), gui::p2pY(10.f, vm), gui::calcCharSize(vm), "Return The Menu");
}


void GameState::initPlayerGUI(StateData* state_data)
{
    this->playerGUI = new PlayerGUI( this->stateData->gfxSettings->resolution,state_data);
}

//	Constructors / Destructors

GameState::GameState(StateData* state_data)
	: State(state_data)
{
    this->initDeferredRender();
    this->initView();
    this->initFonts();
    this->initTextures();
    this->initPauseMenu();
    this->initEndScreen();
    this->initPlayerGUI(state_data);
    this->stateData->soundManager->getMainMenuSound()->stopSound();
    this->stateData->soundManager->getThemeSound()->playSound();
    this->stateData->soundManager->getThemeSound()->loopSound();
    this->gameSave= new save(state_data);
    this->loadingRender();
}


GameState::~GameState()
{
	delete this->pauseMenu;
    delete this->tutorial1;
	delete this->playerGUI;
}

//	Functions



void GameState::updateInput(const float & dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && this->getKeytime())
	{
		if (!this->paused) {
			this->pauseState();
		}
		else {
			this->unpauseState();
		}
	}
}


void GameState::updatePlayerGUI()
{
    this->playerGUI->update( this->mousePosWindow);
}

void GameState::updatePauseMenuButtons()
{
    if (this->pauseMenu->isButtonPressed("QUIT")) {
        this->stateData->soundManager->getThemeSound()->stopSound();
        this->stateData->soundManager->getMainMenuSound()->playSound();
        this->stateData->soundManager->getMainMenuSound()->loopSound();
        this->gameSave->savetoXml();
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

void GameState::updateEndScreen() {
    if (this->endAndReportScreen->isButtonPressed("MENU")) {
        this->stateData->soundManager->getThemeSound()->stopSound();
        this->stateData->soundManager->getMainMenuSound()->playSound();
        this->stateData->soundManager->getMainMenuSound()->loopSound();
        this->stateData->gameInfo= new GameInfo();
        loadingScreen.setEndPositionIndex();
        loadingScreen.setAnimIsFinish(false);
        this->gameSave->resetToXml();
        while (!loadingScreen.getAnimIsFinish()) {
            this->stateData->window->display();
            this->render(this->stateData->window);
            loadingScreen.render(*this->stateData->window);
        }
        this->endState();
    }
}

void GameState::updateTutorialButton(){
    if(this->tutorial1->isButtonPressed("CONTINUE")){
        if(index<this->tutorial1->arraySize){
        index++;
        sf::sleep(sf::milliseconds(200.f));
        }
    }
    if(index>=this->tutorial1->arraySize)
        this->stateData->gameInfo->setIsFinishTutorial();
    if(this->tutorial1->isButtonPressed("SKIP")){
        index=tutorial1->arraySize;
    }
}

void GameState::update(const float& dt)
{
    this->updateMousePositions(&this->view);
	this->updateKeytime(dt);
	this->updateInput(dt);


    if(!this->stateData->gameInfo->getEndGame()){
        if(this->stateData->gameInfo->getIsFinishTutorial()){
            if (!this->paused)	//	Unpaused update
            {
                updatePlayerGUI();
                this->stateData->player->getTimer()->updateSeconds();
            }
            else {
                this->pauseMenu->update(this->mousePosWindow);
                this->updatePauseMenuButtons();
            }
        }else{
            this->tutorial1->update(this->mousePosWindow);
            updateTutorialButton();
        }
    }else{
        this->endAndReportScreen->update(this->mousePosWindow);
        this->updateEndScreen();
    }
}

void GameState::loadingRender() {
    loadingScreen.setStartPositionIndex();
    loadingScreen.setAnimIsFinish(false);
    updatePlayerGUI();
    while (!loadingScreen.getAnimIsFinish()){
        this->render(this->stateData->window);
        loadingScreen.startRender(*this->stateData->window);
        this->stateData->window->display();
    }
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target) {
        target = this->window;
    }
    sf::sleep(sf::milliseconds(40));
    this->renderTexture.clear();
    this->renderTexture.setView(this->view);


    if(this->stateData->gameInfo->getIsFinishTutorial()){
        this->playerGUI->render(this->renderTexture);

        if(this->stateData->gameInfo->getEndGame()){
            this->endAndReportScreen->render(this->renderTexture);
        }
        else if (this->paused)	//	pause menu render
        {
        this->pauseMenu->render(this->renderTexture);
        }

}else{
        if(index<this->tutorial1->arraySize){
            this->tutorial1->render(index,this->renderTexture);
        }
    }
//	Final Render
    this->renderTexture.display();
    target->draw(sf::Sprite(this->renderTexture.getTexture()));

}




