#ifndef FARMING_EXE_SOUNDMANAGER_H
#define FARMING_EXE_SOUNDMANAGER_H

#include "Sound.h"

/**
 * @brief Represents the manager class for handling sounds in the game.
 *
 * The `SoundManager` class manages various sounds used in the game, such as main menu music, in-game sounds, and button clicks.
 */
class SoundManager {
private:
    Sound* mainMenuSound;           ///< Sound object for the main menu
    Sound* moneySound;              ///< Sound object for money-related actions
    Sound* gameSound;               ///< Sound object for general in-game actions
    Sound* harvestSound;            ///< Sound object for harvesting actions
    Sound* eventAlertSound;         ///< Sound object for event alerts
    Sound* buttonClickSound;        ///< Sound object for button clicks
    Sound* upgradeCompleatedSound;  ///< Sound object for upgrade completion

    int SFXSound = 10;              ///< Sound effects volume level
    int MaxSound = 100;             ///< Maximum sound volume
    int MusicSound = 0;             ///< Music volume level

public:
    /**
     * @brief Getter method for the main menu sound.
     *
     * @return Pointer to the Sound object for the main menu.
     */
    Sound* getMainMenuSound();

    /**
     * @brief Getter method for the money-related sound.
     *
     * @return Pointer to the Sound object for money-related actions.
     */
    Sound* getMoneySound();

    /**
     * @brief Getter method for the harvesting sound.
     *
     * @return Pointer to the Sound object for harvesting actions.
     */
    Sound* getHarvestSound();

    /**
     * @brief Getter method for the event alert sound.
     *
     * @return Pointer to the Sound object for event alerts.
     */
    Sound* getEventAlertSound();

    /**
     * @brief Getter method for the theme sound.
     *
     * @return Pointer to the Sound object for the theme.
     */
    Sound* getThemeSound();

    /**
     * @brief Getter method for the button click sound.
     *
     * @return Pointer to the Sound object for button clicks.
     */
    Sound* getButtonClickSound();

    /**
     * @brief Getter method for the upgrade completion sound.
     *
     * @return Pointer to the Sound object for upgrade completion.
     */
    Sound* getUpgradeCompleteSound();

    /**
     * @brief Getter method for the sound effects volume level.
     *
     * @return Sound effects volume level.
     */
    int getSFXSound();

    /**
     * @brief Setter method for the sound effects volume level.
     *
     * @param SFXSoundValue New sound effects volume level.
     */
    void setSFXSound(int SFXSoundValue);

    /**
     * @brief Getter method for the music volume level.
     *
     * @return Music volume level.
     */
    int getMusicSound();

    /**
     * @brief Setter method for the music volume level.
     *
     * @param MusicSoundValue New music volume level.
     */
    void setMusicSound(int MusicSoundValue);

    /**
     * @brief Getter method for the maximum sound volume.
     *
     * @return Maximum sound volume.
     */
    int getMaxSound();

    /**
     * @brief Closes all sounds managed by the `SoundManager`.
     */
    void closeAllSound();

    /**
     * @brief Constructor for the `SoundManager` class.
     *
     * This constructor initializes the `SoundManager` with default volume levels.
     */
    SoundManager();

    /**
     * @brief Saves sound settings to an XML node.
     *
     * @param parent Parent XML node to save sound settings.
     */
    void saveToXml(pugi::xml_node& parent) const;

    /**
     * @brief Loads sound settings from an XML document.
     *
     * @param parent Parent XML document containing sound settings.
     */
    void loadToClass(pugi::xml_document &parent);
};

#endif //FARMING_EXE_SOUNDMANAGER_H
