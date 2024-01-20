#ifndef FARMIG2024_EVENTMANAGER_H
#define FARMIG2024_EVENTMANAGER_H

#include "event.h"
#include "upgrade.h"
#include <random>

/**
 * @brief The EventManager class handles the events in the game.
 */
class EventManager {
private:
    /**
     * @brief Array to store pointers to events.
     */
    event* events[13] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    /**
     * @brief Index of the current event.
     */
    int currentEvent = 12;

    /**
     * @brief Start time of the current event.
     */
    int eventStartTime = 0;

    /**
     * @brief Pointers to player, farm, and upgrade objects.
     */
    player* player;
    farm* farm;
    upgrade* upgrade;

public:
    /**
     * @brief Constructor for the EventManager class.
     *
     * @param player Pointer to the player object.
     * @param upgrade Pointer to the upgrade object.
     * @param farm Pointer to the farm object.
     */
    EventManager(class player* player, class upgrade* upgrade, class farm* farm);

    /**
     * @brief Destructor for the EventManager class.
     */
    ~EventManager();

    /**
     * @brief Function to get the index of the current event.
     *
     * @return Index of the current event.
     */
    int getEventIndex();

    /**
     * @brief Function to choose a random time for the event.
     *
     * @return Random time for the event.
     */
    int chooseRandomTime();

    /**
     * @brief Function to get the time remaining for the current event.
     *
     * @return Time remaining for the current event.
     */
    int getTimeRemain();

    /**
     * @brief Function to get the pointer to the current event.
     *
     * @return Pointer to the current event.
     */
    event* getCurrentEvent();

    /**
     * @brief Function to set the index of the current event.
     *
     * @param index Index to set for the current event.
     */
    void setCurrentEvent(int index);

    /**
     * @brief Function to choose a random event.
     *
     * @return Index of the chosen random event.
     */
    int chooseRandomEvent();

    /**
     * @brief Function to update events.
     *
     * @return True if events are updated, false otherwise.
     */
    bool UpdateEvents();

    /**
     * @brief Function to set the start time of the event.
     *
     * @param time Start time of the event.
     */
    void setEventStartTime(int time);

    /**
     * @brief Function to save event manager information to an XML node.
     *
     * @param parent Parent XML node to save to.
     */
    void saveToXml(pugi::xml_node& parent) const;

    /**
     * @brief Function to load event manager information from an XML document.
     *
     * @param parent Parent XML document to load from.
     */
    void loadToClass(pugi::xml_document &parent);
};

#endif //FARMIG2024_EVENTMANAGER_H
