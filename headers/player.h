#ifndef FARMIG2024_PLAYER_H
#define FARMIG2024_PLAYER_H

#include <iostream>
#include <string>
#include "MissionManager.h"
#include "stdafx.h"
using namespace std;

/**
 * @brief Player class represents the player in the game.
 *
 * The player class manages the player's attributes such as name, money, timer, and missions.
 */
class player
{
private:
    timer timer;            ///< Timer object for the player
    string playerName;      ///< Player's name
    int money;              ///< Player's money
    MissionManager mission; ///< Mission manager for the player

public:
    /**
     * @brief Constructor for the player class.
     */
    player();

    // Getters and setters for player attributes
    MissionManager* getMission();           ///< Get player's missions
    int getPlayerProgress()const;           ///< Get player's progress
    string getPlayerName() const;           ///< Get player's name
    void setPlayerName(string name);        ///< Set player's name
    int getMoney() const;                   ///< Get player's money
    void setMoney(int _money);              ///< Set player's money
    class timer* getTimer();                ///< Get player's timer

    // Functions to save and load player data
    void saveToXml(pugi::xml_node& parent) const;        ///< Save player data to XML
    void loadToClass(pugi::xml_document &parent);        ///< Load player data from XML
};

#endif //FARMIG2024_PLAYER_H
