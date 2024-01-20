#include "../headers/SoundManager.h"

Sound *SoundManager::getMainMenuSound() {
    return mainMenuSound;
}

Sound *SoundManager::getMoneySound() {
    return moneySound;
}

Sound *SoundManager::getHarvestSound() {
    return harvestSound;
}

Sound *SoundManager::getEventAlertSound() {
    return eventAlertSound;
}

Sound *SoundManager::getThemeSound(){
    return gameSound;
}

Sound *SoundManager::getButtonClickSound() {
    return buttonClickSound;
}

Sound *SoundManager::getUpgradeCompleteSound() {
    return upgradeCompleatedSound;
}

int SoundManager::getSFXSound() {
    return SFXSound;
}

void SoundManager::setSFXSound(int SFXSoundValue) {
    if(SFXSoundValue + SFXSound <= MaxSound && SFXSoundValue + SFXSound >= 0){
        this->SFXSound += SFXSoundValue;
        moneySound->setSoundVolume(SFXSound);
        harvestSound->setSoundVolume(SFXSound);
        eventAlertSound->setSoundVolume(SFXSound);
        buttonClickSound->setSoundVolume(SFXSound);
        upgradeCompleatedSound->setSoundVolume(SFXSound);
    }
}

int SoundManager::getMusicSound() {
    return MusicSound;
}

void SoundManager::setMusicSound(int MusicSoundValue) {
    if(MusicSoundValue + MusicSound <= MaxSound && MusicSoundValue + MusicSound >= 0){
        this->MusicSound += MusicSoundValue;
        mainMenuSound->setSoundVolume(MusicSound);
        gameSound->setSoundVolume(MusicSound);
    }
}

int SoundManager::getMaxSound() {
    return MaxSound;
}

SoundManager::SoundManager() {
    harvestSound = new Sound(SFX,"../sound/beep.mp3",SFXSound);
    buttonClickSound = new Sound(SFX,"../sound/buttonPressed.mp3",SFXSound);
    eventAlertSound = new Sound(SFX,"../sound/eventAlert.mp3",SFXSound);
    gameSound = new Sound(MUSIC, "../sound/gameTheme.mp3",MusicSound);
    mainMenuSound = new Sound(MUSIC,"../sound/menuTheme.mp3",MusicSound);
    moneySound = new Sound(SFX,"../sound/moneysound.mp3",SFXSound);
    upgradeCompleatedSound = new Sound(SFX,"../sound/upgradeSound.mp3",SFXSound);
}

void SoundManager::closeAllSound() {
    mainMenuSound->stopSound();
    gameSound->stopSound();
}

void SoundManager::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("soundmanager");
    root.append_child("sfxsound").text().set(SFXSound);
    root.append_child("musicsound").text().set(MusicSound);
}

void SoundManager::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("soundmanager");
    SFXSound=root.child("sfxsound").text().as_int();
    MusicSound=root.child("musicsound").text().as_int();
}
