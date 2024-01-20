#ifndef FARMING_EXE_GAMEINFO_H
#define FARMING_EXE_GAMEINFO_H

#include "warehouse.h"
#include "SoundManager.h"

/**
 * @brief The GameInfo class holds various game-related information and states.
 */
class GameInfo {
private:
    /**
     * @brief Flags indicating game state and progress.
     */
    bool endGame;               /**< Flag indicating if the game has ended. */
    bool isFinishProfile;       /**< Flag indicating if the player has finished the profile. */
    bool isFinishTutorial;      /**< Flag indicating if the player has finished the tutorial. */

    /**
     * @brief Wheat-related information.
     */
    int wheatPlantPiece;        /**< Number of wheat plants planted. */
    int wheatHarvestPiece;      /**< Number of wheat plants harvested. */
    int gainMoneyWithWheat;     /**< Money gained from selling wheat. */

    /**
     * @brief Tomato-related information.
     */
    int tomatoPlantPiece;       /**< Number of tomato plants planted. */
    int tomatoHarvestPiece;     /**< Number of tomato plants harvested. */
    int gainMoneyWithTomato;    /**< Money gained from selling tomatoes. */

    /**
     * @brief Corn-related information.
     */
    int cornPlantPiece;         /**< Number of corn plants planted. */
    int cornHarvestPiece;       /**< Number of corn plants harvested. */
    int gainMoneyWithCorn;      /**< Money gained from selling corn. */

public:
    /**
     * @brief Flag indicating if the player has passed other states.
     */
    bool isPassOtherState = false;

    /**
     * @brief Constructor for the GameInfo class.
     */
    GameInfo();

    /**
     * @brief Getter and setter functions for various game information.
     */
    bool getEndGame() const;
    void setEndGame();

    bool getIsFinishProfile() const;
    void setIsFinishProfile();

    bool getIsFinishTutorial() const;
    void setIsFinishTutorial();

    int getWheatPlantPiece() const;
    void setWheatPlantPiece(int piece);

    int getTomatoPlantPiece() const;
    void setTomatoPlantPiece(int piece);

    int getCornPlantPiece() const;
    void setCornPlantPiece(int piece);

    int getWheatHarvestPiece() const;
    void setWheatHarvestPiece(int piece);

    int getTomatoHarvestPiece() const;
    void setTomatoHarvestPiece(int piece);

    int getCornHarvestPiece() const;
    void setCornHarvestPiece(int piece);

    int getGainMoneyWithWheat() const;
    void setGainMoneyWithWheat(int money);

    int getGainMoneyWithTomato() const;
    void setGainMoneyWithTomato(int money);

    int getGainMoneyWithCorn() const;
    void setGainMoneyWithCorn(int money);

    /**
     * @brief Functions to update product-related information.
     */
    void setProductSell(Product_type productType, int money);
    void setProductHarvest(Product_type productType, int piece);
    void setProductPlant(Product_type productType, int piece);

    /**
     * @brief Functions to save and load game information from XML.
     */
    void saveToXml(pugi::xml_node &parent) const;
    void loadToClass(pugi::xml_document &parent);
};

#endif //FARMING_EXE_GAMEINFO_H
