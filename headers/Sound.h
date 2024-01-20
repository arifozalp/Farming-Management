#ifndef FARMING_EXE_SOUND_H
#define FARMING_EXE_SOUND_H

#include "stdafx.h"

using namespace std;
/**
 * @brief Enum to differentiate between different types of sounds.
 *
 */
enum Sound_type{
    MUSIC, // Represents music sound
    SFX    // Represents sound effects
};

/**
 * @brief Represents a sound object for playing music or sound effects.
 *
 * The `Sound` class encapsulates functionality for playing, stopping, and looping sounds, as well as adjusting volume.
 */
class Sound {

private:
    Sound_type soundType;        ///< Type of the sound (music or SFX)
    sf::SoundBuffer _themeSongBuffer;  ///< Buffer for the sound
    sf::Sound _themeSong;        ///< Sound object
    int volume;                  ///< Volume level of the sound

public:
    /**
     * @brief Constructor to initialize sound properties.
     *
     * This constructor creates a `Sound` object with the specified type, filename, and volume.
     *
     * @param soundType Type of the sound (music or SFX).
     * @param filename Filename of the sound file.
     * @param volume Initial volume level of the sound.
     */
    Sound(Sound_type soundType, string filename, int volume);

    /**
     * @brief Getter for the sound type.
     *
     * The `getSoundType` function returns the type of the sound (music or SFX).
     *
     * @return Type of the sound.
     */
    Sound_type getSoundType();

    /**
     * @brief Getter for the sound volume.
     *
     * The `getSoundVolume` function returns the current volume level of the sound.
     *
     * @return Volume level of the sound.
     */
    float getSoundVolume();

    /**
     * @brief Setter for the sound volume.
     *
     * The `setSoundVolume` function sets the volume level of the sound to the specified value.
     *
     * @param _volume New volume level for the sound.
     */
    void setSoundVolume(int _volume);

    /**
     * @brief Method to play the sound.
     *
     * The `playSound` function plays the sound.
     */
    void playSound();

    /**
     * @brief Method to stop the sound.
     *
     * The `stopSound` function stops the sound.
     */
    void stopSound();

    /**
     * @brief Method to loop the sound.
     *
     * The `loopSound` function sets the sound to loop continuously.
     */
    void loopSound();
};

#endif //FARMING_EXE_SOUND_H
