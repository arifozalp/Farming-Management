#include "../headers/stdafx.h"
#include "../headers/SettingsState.h"



//	Initializer Functions
void SettingsState::initVariables()
{
}

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("../Fonts/Inconsolata-Bold.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void SettingsState::initGui()
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
    btnBackground.setSize(sf::Vector2f(
            static_cast<float>(vm.width ),
            static_cast<float>(vm.height)
    ));
	if (!this->backgroundTexture.loadFromFile("../Resources/Images/Backgrounds/SettingImage/settingbg000.png")) {
		throw "ERROR::MAINMENUSTATES::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
    this->btnBackground.setFillColor(sf::Color(10, 10, 30, 100));

	//	Buttons
    Animation* buttondown= new Animation();
    buttondown->loadAnimation("../Resources/Images/Backgrounds/SettingImage/buttondown000.png", 1,
                              sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));

    Animation* buttonup= new Animation();
    buttonup->loadAnimation("../Resources/Images/Backgrounds/SettingImage/buttonup000.png", 1,
                            sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));

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
    this->buttons["Musicup"] = new gui::Button(
            gui::p2pX(90.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(20.f, vm) - gui::p2pY(7.f / 2.f, vm),
            gui::p2pX(10.f, vm),
            gui::p2pY(10.f, vm),
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,buttonup
    );
    this->buttons["Musicdown"] = new gui::Button(
            gui::p2pX(75.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(20.f, vm) - gui::p2pY(7.f / 2.f, vm),
            gui::p2pX(10.f, vm),
            gui::p2pY(10.f, vm),
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,buttondown
    );
    this->buttons["Sfxup"] = new gui::Button(
            gui::p2pX(90.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(50.f, vm) - gui::p2pY(7.f / 2.f, vm),
            gui::p2pX(10.f, vm),
            gui::p2pY(10.f, vm),
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,buttonup
    );
    this->buttons["Sfxdown"] = new gui::Button(
            gui::p2pX(75.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(50.f, vm) - gui::p2pY(7.f / 2.f, vm),
            gui::p2pX(10.f, vm),
            gui::p2pY(10.f, vm),
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,buttondown
    );
    this->musicBar= new gui::ProgressBar(gui::p2pX(25.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(20.f, vm) - gui::p2pY(7.f / 2.f, vm),
                                         gui::p2pX(40.f, vm),
                                         gui::p2pY(10.f, vm),
                                         this->stateData->soundManager->getMaxSound(),sf::Color::White,150, vm);

    this->sfxBar= new gui::ProgressBar(gui::p2pX(25.f, vm) - gui::p2pX(15.f / 2.f, vm),
                                       gui::p2pY(50.f, vm) - gui::p2pY(7.f / 2.f, vm),
                                       gui::p2pX(40.f, vm),
                                       gui::p2pY(10.f, vm),
                                       this->stateData->soundManager->getMaxSound(),sf::Color::White,30, vm);



	//	Text init
	this->musicText.setFont(font);
	this->musicText.setPosition(sf::Vector2f(gui::p2pX(12.f, vm) - gui::p2pX(15.f / 2.f, vm), gui::p2pY(22.f, vm) - gui::p2pY(7.f / 2.f, vm)));
	this->musicText.setCharacterSize(gui::calcCharSize(vm, 50.f));
	this->musicText.setFillColor(sf::Color::White);

    this->musicText.setString("Music:");

    this->sfxText.setFont(font);
    this->sfxText.setPosition(sf::Vector2f(gui::p2pX(15.f, vm) - gui::p2pX(15.f / 2.f, vm),gui::p2pY(52.f, vm) - gui::p2pY(7.f / 2.f, vm)));
    this->sfxText.setCharacterSize(gui::calcCharSize(vm, 50.f));
    this->sfxText.setFillColor(sf::Color::White);

    this->sfxText.setString("SFX:");

}

//		CONSTRUCTOR / DESTRUCTOR

SettingsState::SettingsState(StateData* state_data)
	:	State(state_data)
{
	this->initVariables();
	this->initFonts();
	this->initGui();
    this->updateMusicBar();
    this->updateSfxBar();
    this->loadingRender();
}


SettingsState::~SettingsState()
{
	for (auto it = this->buttons.begin(); it != buttons.end(); ++it) {
		delete it->second;
	}

}


void SettingsState::updateInput(const float & dt)
{
/*

*/
}

void SettingsState::updateGui(const float& dt)
{
	/*Update all the GUI elements in the state and handles their functionality*/
	//	Buttons
	for (auto &it : this->buttons) {
		it.second->update(this->mousePosWindow);
	}

	//	Button Functionality
	//	Quit the game
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

    if (this->buttons["Musicup"]->isPressed()) {
            this->stateData->soundManager->setMusicSound(5);
    }
    if (this->buttons["Musicdown"]->isPressed()) {
            this->stateData->soundManager->setMusicSound(-5);
    }
    if (this->buttons["Sfxup"]->isPressed()) {
            this->stateData->soundManager->setSFXSound(5);
    }
    if (this->buttons["Sfxdown"]->isPressed()) {
            this->stateData->soundManager->setSFXSound( - 5);
    }

}

void SettingsState::update(const float& dt)
{
    this->updateMusicBar();
    this->updateSfxBar();
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateGui(dt);

}
void SettingsState::updateMusicBar()
{
    this->musicBar->update(this->stateData->soundManager->getMusicSound());
}

void SettingsState::updateSfxBar()
{
    this->sfxBar->update(this->stateData->soundManager->getSFXSound());
}

void SettingsState::renderMusicBar(sf::RenderTarget & target)
{
    this->musicBar->render(target);
}

void SettingsState::renderSfxBar(sf::RenderTarget & target)
{
    this->sfxBar->render(target);
}

void SettingsState::renderGui(sf::RenderTarget & target)
{
    for (auto &it : this->buttons) {
		it.second->render(target);
	}


    this->renderMusicBar(target);
    this->renderSfxBar(target);

}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
    sf::sleep(sf::milliseconds(40));
	target->draw(this->background);
    target->draw(this->btnBackground);
    target->draw(this->musicText);
    target->draw(this->sfxText);
    this->renderGui(*target);
}

void SettingsState::loadingRender() {
    loadingScreen.setStartPositionIndex();
    loadingScreen.setAnimIsFinish(false);
    while (!loadingScreen.getAnimIsFinish()) {
        this->render(this->stateData->window);
        loadingScreen.startRender(*this->stateData->window);
        this->stateData->window->display();
    }

}



