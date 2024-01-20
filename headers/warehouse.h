#ifndef FARMIG2024_WAREHOUSE_H
#define FARMIG2024_WAREHOUSE_H

#include "product.h"

/**
 * @brief Class representing a warehouse in the farming game.
 *
 * The `warehouse` class manages the storage of different products on the farm.
 */
class warehouse {
private:
    int capacity=600; ///< Capacity of the warehouse
    bool limit;   ///< Flag determining the limit of the warehouse capacity

public:
    /**
     * @brief Constructor for the warehouse class.
     *
     * Initializes default values when a warehouse object is created.
     */
    warehouse();

    /**
     * @brief Getter method for the capacity of the warehouse.
     *
     * @return The capacity of the warehouse.
     */
    int getCapacity() const;

    /**
     * @brief Setter method for the capacity of the warehouse.
     *
     * @param newCapacity The new capacity to be set for the warehouse.
     */
    void setCapacity(int newCapacity);

    /**
     * @brief Function that checks the storage limits of a specific product.
     *
     * @param product Pointer to the product object.
     * @return True if the storage limit is reached, otherwise false.
     */
    bool getLimit(product* product);

    /**
     * @brief Function that sets the amount of a stored product for a given product type.
     *
     * @param productType Type of the product to set the amount.
     * @param piece The amount to set for the product.
     */
    void setPiece(Product_type productType, int piece);

    /**
     * @brief Function that gets the amount of a stored product for a given product type.
     *
     * @param _productName Type of the product to get the amount.
     * @return The amount of the specified product type.
     */
    int getPiece(Product_type _productName);

    /**
     * @brief Function used to save warehouse data into an XML node.
     *
     * @param parent Parent XML node to which the warehouse data will be saved.
     */
    void saveToXml(pugi::xml_node& parent) const;

    /**
     * @brief Function used to load warehouse data from an XML document.
     *
     * @param parent XML document from which warehouse data will be loaded.
     */
    void loadToClass(pugi::xml_document& parent);
};

#endif //FARMIG2024_WAREHOUSE_H
