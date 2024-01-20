#ifndef FIELD_H
#define FIELD_H

#include "player.h"
#include "timer.h"
#include "GameInfo.h"

/**
 * @brief The field class represents a field in the game where plants can be grown.
 */
class field{

private:
    /**
     * @brief Flag indicating whether the field is locked.
     */
    bool lock = false;

    /**
     * @brief Flag indicating whether the field is usable or not.
     */
    bool usable = true;

    /**
     * @brief Start time for the field's activity.
     */
    int startTime = 0;

    /**
     * @brief Pointer to the player associated with the field.
     */
    player* player;

    /**
     * @brief Flag indicating whether the plant in the field is decaying.
     */
    bool isDecay = false;

    /**
     * @brief Pointer to the product planted in the field.
     */
    product* plantProduct = nullptr;

public:
    /**
     * @brief Flag indicating whether the plant in the field is growing.
     */
    bool isGrow;

    /**
     * @brief Constructor for the field class.
     *
     * @param _player Pointer to the player associated with the field.
     */
    field(class player* _player);

    /**
     * @brief Function to update the field's state.
     *
     * @return True if the field is successfully updated, false otherwise.
     */
    bool Update();

    /**
     * @brief Function to get the time remaining for the field's activity.
     *
     * @return Time remaining for the field's activity.
     */
    int getTimeRemind();

    /**
     * @brief Function to check if the field is unlocked.
     *
     * @return True if the field is unlocked, false otherwise.
     */
    bool getUnlock();

    /**
     * @brief Function to check if the field is usable.
     *
     * @return True if the field is usable, false otherwise.
     */
    bool isUsable();

    /**
     * @brief Function to set the field as unlocked.
     */
    void setUnlock();

    /**
     * @brief Function to plant a product in the field.
     *
     * @param _product Pointer to the product to plant.
     * @param _player Pointer to the player associated with the field.
     * @param _MissionManager Pointer to the MissionManager object.
     * @param gameInfo Pointer to the GameInfo object.
     * @return True if the planting is successful, false otherwise.
     */
    bool plant(product* _product, class player* _player, MissionManager* _MissionManager, GameInfo* gameInfo);

    /**
     * @brief Function to harvest the planted product in the field.
     *
     * @param _product Pointer to the product to harvest.
     * @param _warehouse Pointer to the warehouse for storing the harvested product.
     * @param _MissionManager Pointer to the MissionManager object.
     * @param gameInfo Pointer to the GameInfo object.
     * @param soundManager Pointer to the SoundManager object.
     * @return True if the harvesting is successful, false otherwise.
     */
    bool harvest(product* _product, warehouse* _warehouse, MissionManager* _MissionManager, GameInfo* gameInfo, SoundManager* soundManager);

    /**
     * @brief Function to check if the plant in the field is growing.
     *
     * @return True if the plant is growing, false otherwise.
     */
    bool getIsGrow();

    /**
     * @brief Function to check if the plant in the field is decaying.
     *
     * @return True if the plant is decaying, false otherwise.
     */
    bool getIsDecay();

    /**
     * @brief Function to get the pointer to the planted product.
     *
     * @return Pointer to the planted product.
     */
    product* getPlantProduct();

    /**
     * @brief Function to get a string representation of the product type.
     *
     * @param productName Type of the product.
     * @return String representation of the product type.
     */
    string getProductTypeString(Product_type productName);

    /**
     * @brief Function to save field information to an XML node.
     *
     * @param parent Parent XML node to save to.
     * @param index Index of the field.
     */
    void saveToXml(pugi::xml_node &parent, string index) const;

    /**
     * @brief Function to load field information from an XML document.
     *
     * @param parent Parent XML document to load from.
     * @param index Index of the field.
     */
    void loadToClass(pugi::xml_document &parent, string index);
};

#endif // FIELD_H
