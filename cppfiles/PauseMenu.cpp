#include "../headers/PauseMenu.h"


PauseMenu::PauseMenu(StateData* stateData,sf::VideoMode& vm, sf::Font& font)
	: font(font)
{
    this->stateData = stateData;

	//	Init background
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width), 
			static_cast<float>(vm.height)
		)
	);

	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	//	Init container
	this->container.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width) / 4.f,
			static_cast<float>(vm.height) - gui::p2pY(7.f, vm)
		)
	);

	this->container.setFillColor(sf::Color(20, 20, 20, 200));

	this->container.setPosition(
		static_cast<float>(vm.width) / 2.f - static_cast<float>(this->container.getSize().x) / 2.f,
		gui::p2pY(7.5f, vm)
	);
    Animation* buttondown= new Animation();
    buttondown->loadAnimation("../Resources/Images/Backgrounds/SettingImage/buttondown000.png", 1,
                              sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));

    Animation* buttonup= new Animation();
    buttonup->loadAnimation("../Resources/Images/Backgrounds/SettingImage/buttonup000.png", 1,
                            sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));


    this->buttons["Musicup"] = new gui::Button(1038.f,396.f,67.f,67.f
            ,
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
                                               sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,buttonup
    );
    this->buttons["Musicdown"] = new gui::Button(823.f,401.f,67.f,67.f
            ,
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
                                                 sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,buttondown
    );
    this->buttons["Sfxup"] = new gui::Button(
            1038.f,733.f,67.f,67.f,
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,buttonup
    );
    this->buttons["Sfxdown"] = new gui::Button(
            823.f,733.f,67.f,67.f,
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,buttondown
    );
    this->musicBarPause= new gui::ProgressBar(744.f,332.f,430.f,40.f,
                                         this->stateData->soundManager->getMaxSound(),sf::Color::White,150, vm);
    this->sfxBarPause= new gui::ProgressBar(744.f,647.f,430.f,40.f,
                                            this->stateData->soundManager->getMaxSound(),sf::Color::White,30, vm);

    this->musicTextPause.setFont(font);
    this->musicTextPause.setPosition(sf::Vector2f(926.f,235.f));
    this->musicTextPause.setCharacterSize(gui::calcCharSize(vm, 50.f));
    this->musicTextPause.setFillColor(sf::Color::White);

    this->musicTextPause.setString("Music");

    this->sfxTextPause.setFont(font);
    this->sfxTextPause.setPosition(sf::Vector2f(838.f,563.f));
    this->sfxTextPause.setCharacterSize(gui::calcCharSize(vm, 50.f));
    this->sfxTextPause.setFillColor(sf::Color::White);

    this->sfxTextPause.setString("SFX");


    //	Init text
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(gui::calcCharSize(vm) * 4);
	this->menuText.setString("PAUSED");
	this->menuText.setPosition(
		this->container.getPosition().x + (this->container.getSize().x / 2.f) - this->menuText.getGlobalBounds().width / 2.f, 
		this->container.getPosition().y + gui::p2pY(3.5f, vm)
	);


}


void PauseMenu::updateMusicBar()
{
    this->musicBarPause->update(this->stateData->soundManager->getMusicSound());
}

void PauseMenu::updateSfxBar()
{
    this->sfxBarPause->update(this->stateData->soundManager->getSFXSound());
}



PauseMenu::~PauseMenu()
{
	auto it = this->buttons.begin();
	for (; it != buttons.end(); ++it) {
		delete it->second;
	}
}

std::map<std::string, gui::Button*>& PauseMenu::getButtons()
{
	return this->buttons;
}

//	Functions

const bool PauseMenu::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void PauseMenu::addButton(const std::string key, 
	const float y, 
	const float width,
	const float height, 
	const unsigned char_size, const std::string text)
{
	float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;
	this->buttons[key] = new gui::Button(
		x, y, width, height,
		&this->font, text, char_size,
		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0),RECTANGLE
	);
}

void PauseMenu::updateGui() {
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
        this->stateData->soundManager->setSFXSound(-5);

    }
}

void PauseMenu::update(const sf::Vector2i& mousePosWindow)
{
	for (auto& i : this->buttons) 
	{
		i.second->update(mousePosWindow);
	}
    updateMusicBar();
    updateSfxBar();
    updateGui();
}

void PauseMenu::render(sf::RenderTarget & target)
{
	target.draw(this->background);
	target.draw(this->container);

	for (auto& i : this->buttons) {
		i.second->render(target);
	}
    target.draw(this->musicTextPause);
    target.draw(this->sfxTextPause);
    this->musicBarPause->render(target);
    this->sfxBarPause->render(target);
	target.draw(this->menuText);
}


