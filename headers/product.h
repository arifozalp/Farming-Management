#ifndef FARMIG2024_PRODUCT_H
#define FARMIG2024_PRODUCT_H

#include "stdafx.h"

/**
 * @brief Enum defining different product types.
 */
enum Product_type { WHEAT, CORN, TOMATO };

/**
 * @brief Represents a product in the farm simulation.
 */
class product {
private:
    Product_type productType; ///< Type of the product.
    int yield;                ///< Current yield.
    int defaultYield;         ///< Default yield.
    int price;                ///< Price of the product.
    int defaultSell;          ///< Default selling price.
    int sell;                 ///< Current selling price.
    float harvestTime;        ///< Time required for harvest.
    float decayTime;          ///< Time for decay.

public:
    /**
     * @brief Constructor for the Product class.
     *
     * @param yield Initial yield of the product.
     * @param price Initial price of the product.
     * @param sell Initial selling price of the product.
     * @param harvestTime Time required for harvest.
     * @param decayTime Time for decay.
     * @param productType Type of the product.
     */
    product(int yield, int price, int sell, float harvestTime, float decayTime, Product_type productType);

    /**
     * @brief Gets the type of the product.
     *
     * @return Product_type representing the type of the product.
     */
    Product_type getProductType() const;

    /**
     * @brief Gets the default yield of the product.
     *
     * @return Default yield of the product.
     */
    int getDefaultYield();

    /**
     * @brief Gets the current yield of the product.
     *
     * @return Current yield of the product.
     */
    int getYield();

    /**
     * @brief Sets the yield of the product.
     *
     * @param newYield New yield value to be set.
     */
    void setYield(int newYield);

    /**
     * @brief Gets the price of the product.
     *
     * @return Price of the product.
     */
    int getPrice();

    /**
     * @brief Gets the default selling price of the product.
     *
     * @return Default selling price of the product.
     */
    int getDefaultSell();

    /**
     * @brief Gets the current selling price of the product.
     *
     * @return Current selling price of the product.
     */
    int getSell();

    /**
     * @brief Sets the selling price of the product.
     *
     * @param newSell New selling price value to be set.
     */
    void setSell(int newSell);

    /**
     * @brief Gets the time required for harvest.
     *
     * @return Time required for harvest.
     */
    float getHarvestTime();

    /**
     * @brief Gets the time for decay.
     *
     * @return Time for decay.
     */
    float getDecayTime();
};

#endif //FARMIG2024_PRODUCT_H
