#ifndef FARMIG2024_TRADER_H
#define FARMIG2024_TRADER_H

#include "farm.h"

/**
 * @brief Class representing a trader in the farming game.
 *
 * The `trader` class manages the trader's inventory of different products and provides functionality to interact with the game elements.
 */
class trader {
private:
    int amount[3] = {0,0,0}; ///< Amount of different products held by the trader
    player* player;          ///< Pointer to the player object
    farm* farm;              ///< Pointer to the farm object

public:
    /**
     * @brief Constructor initializing the trader with player and farm objects.
     *
     * @param player Pointer to the player object.
     * @param farm Pointer to the farm object.
     */
    trader(class player* player, class farm* farm);

    /**
     * @brief Function to get the amount of a specific product held by the trader.
     *
     * @param index Index of the product type.
     * @return Amount of the specified product held by the trader.
     */
    int getAmount(int index);

    /**
     * @brief Function to set the amount of a specific product held by the trader.
     *
     * @param newAmount New amount to be set.
     * @param index Index of the product type.
     */
    void setAmount(int newAmount, int index);

    /**
     * @brief Function to sell a product, updating game elements accordingly.
     *
     * This function handles the selling of a product, updating the trader's inventory, mission manager, game info, and sound manager accordingly.
     *
     * @param index Index of the product type.
     * @param productName Type of the product to be sold.
     * @param _MissionManager Pointer to the MissionManager object.
     * @param gameInfo Pointer to the GameInfo object.
     * @param soundManager Pointer to the SoundManager object.
     */
    void sell(int index, Product_type productName, MissionManager* _MissionManager, GameInfo* gameInfo, SoundManager* soundManager);
};

#endif // FARMIG2024_TRADER_H
