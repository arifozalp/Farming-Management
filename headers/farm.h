#ifndef FARMIG2024_FARM_H
#define FARMIG2024_FARM_H

#include <iostream>
#include <string>

#include "field.h"

/**
 * @brief The farm class represents a player's farm in the game.
 */
class farm {
private:
    /**
     * @brief Pointers to products (wheat, corn, tomato) and warehouse.
     */
    product* wheat = new product(50, 400, 10, 10, 4, WHEAT);
    product* corn = new product(30, 800, 40, 10, 3, CORN);
    product* tomato = new product(20, 600, 35, 10, 5, TOMATO);
    warehouse* warehouse;

    /**
     * @brief Array of fields.
     */
    field fields[9] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

public:
    /**
     * @brief Constructor for the farm class.
     *
     * @param _player Pointer to the player object.
     */
    farm(player* _player);

    /**
     * @brief Function to get the warehouse.
     *
     * @return Pointer to the warehouse.
     */
    class warehouse* getWarehouse();

    /**
     * @brief Name of the farm.
     */
    string farmName;

    /**
     * @brief Function to get a specific field by index.
     *
     * @param index Index of the field.
     * @return Pointer to the specified field.
     */
    field* getField(int index);

    /**
     * @brief Function to set a specific field by index.
     *
     * @param index Index of the field to set.
     */
    void setField(int index);

    /**
     * @brief Function to get the farm name.
     *
     * @return Farm name.
     */
    string getFarmName() const;

    /**
     * @brief Function to get a specific product by type.
     *
     * @param productType Type of the product.
     * @return Pointer to the specified product.
     */
    product* getProduct(Product_type productType);

    /**
     * @brief Function to set the farm name.
     *
     * @param _farmName Farm name to set.
     */
    void setFarmName(string _farmName);

    /**
     * @brief Function to save farm information to an XML node.
     *
     * @param parent Parent XML node to save to.
     */
    void saveToXml(pugi::xml_node& parent) const;

    /**
     * @brief Function to load farm information from an XML document.
     *
     * @param parent Parent XML document to load from.
     */
    void loadToClass(pugi::xml_document &parent);
};

#endif //FARMIG2024_FARM_H
