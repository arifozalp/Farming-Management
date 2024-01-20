#include "../headers/stdafx.h"
#include "../headers/Game.h"

//	Static Functions

//	Initializer Functions

void Game::initVariables()
{
	this->window = NULL;
	this->dt = 0.f;
	this->gridSize = 64.f;


}

void Game::initGraphicsSettings()
{
	this->gfxSettings.loadFromFile("../Config/graphics.ini");
}

void Game::initWindow()
{
	/* Create an SFML window */

	if (this->gfxSettings.fullscreen) {
		this->window = new sf::RenderWindow(
			this->gfxSettings.resolution,
			this->gfxSettings.title,
			sf::Style::Fullscreen,
			this->gfxSettings.contextSettings
		);
	}
	else {
        this->window = new sf::RenderWindow(
                this->gfxSettings.resolution,
                this->gfxSettings.title,
                sf::Style::Titlebar | sf::Style::Close,
                this->gfxSettings.contextSettings
        );
    }
	this->window->setFramerateLimit(this->gfxSettings.framerateLimit);
}

void Game::initStateData()
{
    this->stateData.soundManager = new SoundManager();
    this->stateData.gameInfo= new GameInfo();
    this->stateData.player=new player();
    this->stateData.farm=new farm(this->stateData.player);
    this->stateData.trader=new trader(this->stateData.player,this->stateData.farm);
    this->stateData.upgrade=new upgrade();
    this->stateData.eventManager=new EventManager(this->stateData.player,this->stateData.upgrade,this->stateData.farm);
    save1=new save(&stateData);
    save1->loadToGame();
    this->stateData.soundManager->setMusicSound(0);
    this->stateData.soundManager->setSFXSound(0);
    this->stateData.window = this->window;
    this->stateData.gfxSettings = &this->gfxSettings;
    this->stateData.states = &this->states;
    this->stateData.gridSize = this->gridSize;
}

void Game::initStates()
{
	this->states.push(new MainMenuState(&this->stateData));
}


//	Constructors/Destructors

Game::Game()
{
	this->initVariables();
	this->initGraphicsSettings();
	this->initWindow();
	this->initStateData();
	this->initStates();

}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

//	Functions

void Game::endApplication()
{
	std::cout << "Ending application!" << "\n";

}

void Game::updateDt()
{
	/* Updates the dt variable with the time it takes to update and render one frame */
	this->dt = this->dtClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		if (this->window->hasFocus()) {
			this->states.top()->update(this->dt);

			if (this->states.top()->getQuit()) {
				this->states.top()->endState();
				delete this->states.top();
				this->states.pop();
			}
		}
	}
	// Application end
	else {
		this->endApplication();
		this->window->close();
	}



}

void Game::render()
{
	this->window->clear();

	//	Render items
	if (!this->states.empty()) {
		this->states.top()->render();
	}

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}


}
