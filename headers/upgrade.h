#ifndef FARMIG2024_UPGRADE_H
#define FARMIG2024_UPGRADE_H

#include "trader.h"

/**
 * @brief Class representing upgrades in the farming game.
 *
 * The `upgrade` class manages the upgrades available to the player's farm, including text descriptions and levels.
 */
class upgrade {
private:
    string upgradeText[5]={"UPDATE REQUIREMENTS\n  Completion of mission 5\n  At Least 50 000 TL\n\n WHAT YOU WILL GET\n  2nd 3rd Fields unlock\n   Capacity will be 1800 ",
                           "UPDATE REQUIREMENTS\n  Completion of mission 10\n  At Least 150 000 TL\n\n WHAT YOU WILL GET\n  4th 5th Fields unlock\n   Capacity will be 3000",
                           "UPDATE REQUIREMENTS\n  Completion of mission 15\n  At Least 250 000 TL\n\n WHAT YOU WILL GET\n  6th 7th Fields unlock\n   Capacity will be 4200",
                           "UPDATE REQUIREMENTS\n  Completion of mission 20\n  At Least 350 000 TL\n\n WHAT YOU WILL GET\n  8th 9th Fields unlock\n  Capacity will be 5400",
                           "ALL UPGRADE COMPLETED"}; ///< Text descriptions for each upgrade level
    int upgradeLevel;      ///< Current upgrade level

public:
    /**
     * @brief Constructor for the upgrade class.
     */
    upgrade();

    /**
     * @brief Getter method for the current upgrade level.
     *
     * @return The current upgrade level.
     */
    int getUpgradeLevel();

    /**
     * @brief Getter method for the text description of the current upgrade.
     *
     * @return The text description of the current upgrade.
     */
    string getUpgradeText();

    /**
     * @brief Function to upgrade the farm's capacity based on completed missions and funds.
     *
     * @param farm Pointer to the farm object.
     * @param _player Pointer to the player object.
     * @return True if the upgrade is successful, otherwise false.
     */
    bool upgradeCapacity(farm* farm, player* _player);

    /**
     * @brief Function to save upgrade data into an XML node.
     *
     * @param parent Parent XML node to which the upgrade data will be saved.
     */
    void saveToXml(pugi::xml_node& parent) const;

    /**
     * @brief Function to load upgrade data from an XML document.
     *
     * @param parent XML document from which upgrade data will be loaded.
     */
    void loadToClass(pugi::xml_document& parent);
};

#endif //FARMIG2024_UPGRADE_H
