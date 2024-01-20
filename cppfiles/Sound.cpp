#include "../headers/Sound.h"

Sound::Sound(Sound_type soundType, string filename, int volume1) {

    this->soundType = soundType;
    this->_themeSongBuffer.loadFromFile(filename);
    this->_themeSong.setBuffer(_themeSongBuffer);
    this->volume = volume1;
    _themeSong.setVolume(static_cast<float>(volume));

}

Sound_type Sound::getSoundType() {
    return soundType;
}

float Sound::getSoundVolume() {
    return 0;
}

void Sound::setSoundVolume(int _volume) {
    this->volume = _volume;
    _themeSong.setVolume(static_cast<float>(volume));
}

void Sound::playSound(){
    _themeSong.play();
}

void Sound::stopSound() {
    _themeSong.stop();
}

void Sound::loopSound() {
    _themeSong.setLoop(true);
}


