#ifndef FARMING_EXE_SAVE_H
#define FARMING_EXE_SAVE_H

#include "PauseMenu.h"

/**
 * @brief Represents the save functionality for the game.
 *
 * The `save` class is responsible for handling game saving, loading, and resetting functionalities.
 */
class save {
private:
    StateData* stateData1;  ///< Holds the game state data.

public:
    /**
     * @brief Constructor for the save class.
     *
     * @param stateData Pointer to the StateData object.
     */
    save(StateData* stateData);

    /**
     * @brief Saves game progress to an XML file.
     *
     * This function saves the current state of the game to an XML file.
     */
    void savetoXml() const;

    /**
     * @brief Loads game progress from an XML file.
     *
     * This function loads the game progress from an XML file.
     */
    void loadToGame();

    /**
     * @brief Resets game progress by clearing XML data.
     *
     * This function resets the game progress by clearing the XML data.
     */
    void resetToXml();
};

#endif //FARMING_EXE_SAVE_H
