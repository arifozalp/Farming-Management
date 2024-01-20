#ifndef FARMIG2024_TIMER_H
#define FARMIG2024_TIMER_H


#include "stdafx.h"

// Class representing a timer in the farming game
class timer {
private:
    sf::Clock clock; // SFML clock object to manage time
    int seconds=0; // Current time in seconds

public:
    // Constructor initializing the timer
    timer();

    // Function to update the elapsed time in seconds
    void updateSeconds();

    // Function to get the current time in seconds
    int getCurrentTime() const;

    // Function to get the seconds part of the current time
    int getSeconds() const;

    // Function to get the minutes part of the current time
    int getMinutes() const;

    // Function to save timer data to an XML node
    void saveToXml(pugi::xml_node& parent) const;

    // Function to load timer data from an XML document
    void loadToClass(pugi::xml_document &parent);
};




#endif //FARMIG2024_TIMER_H
