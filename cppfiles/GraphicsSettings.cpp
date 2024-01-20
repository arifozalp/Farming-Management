#include "../headers/stdafx.h"
#include "../headers/GraphicsSettings.h"



GraphicsSettings::GraphicsSettings()
{
	this->resolution = sf::VideoMode::getDesktopMode();
	this->fullscreen = true;
	this->framerateLimit = 120;
	this->contextSettings.antialiasingLevel = 0;
}

void GraphicsSettings::loadFromFile(const std::string path)
{
	std::ifstream ifs(path);

	if (ifs.is_open()) {
		std::getline(ifs, this->title);
		ifs >> this->resolution.width >> this->resolution.height;
        ifs >> this->framerateLimit;
		ifs >> this->contextSettings.antialiasingLevel;

	}

	ifs.close();

}
