#ifndef FARMIG2024_EVENT_H
#define FARMIG2024_EVENT_H

#include "product.h"

using namespace std;
/**
 * @brief The event class represents an event in the game.
 */
class event {

private:
    /**
     * @brief Name of the event.
     */
    string eventName;

    /**
     * @brief Details or description of the event.
     */
    string eventDetail;

    /**
     * @brief Yield values for different types of products (wheat, tomato, corn).
     */
    int yieldWheat;
    int yieldTomato;
    int yieldCorn;

    /**
     * @brief Sell prices for different types of products (wheat, tomato, corn).
     */
    int sellWheat;
    int sellTomato;
    int sellCorn;

    /**
     * @brief Time duration of the event.
     */
    int eventTime = 0;

public:
    /**
     * @brief Constructor for the event class.
     *
     * @param EventName Name of the event.
     * @param EventDetail Details or description of the event.
     * @param WheatYield Yield value for wheat.
     * @param TomatoYield Yield value for tomato.
     * @param CornYield Yield value for corn.
     * @param sellWheat Sell price for wheat.
     * @param sellTomato Sell price for tomato.
     * @param sellCorn Sell price for corn.
     */
    event(string EventName, string EventDetail, int WheatYield, int TomatoYield, int CornYield, int sellWheat, int sellTomato, int sellCornInt);

    /**
     * @brief Function to get the yield value for a specific product type.
     *
     * @param productType Type of the product.
     * @return Yield value for the specified product type.
     */
    int getYield(Product_type productType);

    /**
     * @brief Function to get the details or description of the event.
     *
     * @return Details or description of the event.
     */
    string getEventDetail();

    /**
     * @brief Function to get the sell price for a specific product type.
     *
     * @param productType Type of the product.
     * @return Sell price for the specified product type.
     */
    int getSell(Product_type productType);

    /**
     * @brief Function to set the time duration of the event.
     *
     * @param time Time duration of the event.
     */
    void setEventTime(int time);

    /**
     * @brief Function to get the time duration of the event.
     *
     * @return Time duration of the event.
     */
    int getEventTime();

    /**
     * @brief Function to get the name of the event.
     *
     * @return Name of the event.
     */
    string getEventName();
};

#endif //FARMIG2024_EVENT_H
