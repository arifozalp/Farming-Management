#ifndef FARMIG2024_MISSIONMANAGER_H
#define FARMIG2024_MISSIONMANAGER_H


#include "mission.h"
#include "timer.h"
#include "SoundManager.h"

/**
 * @brief Class representing a mission manager.
 */

class MissionManager {
private:
    int numberOfMission = 25;
    mission mission1=*new mission{PLANT, 5, "                    MISSION  1 \n\n        Plant wheat 5 times", NOT_STARTED, WHEAT};
    mission mission2=*new mission{HARVEST, 100, "                    MISSION  2 \n\n        Harvest 100 kg of tomatoes", NOT_STARTED, TOMATO};
    mission mission3=*new mission{SELL, 300, "                    MISSION  3 \n\n        Sell 300 kg of corn", NOT_STARTED, CORN};
    mission mission4=*new mission{SELL, 500, "                    MISSION  4 \n\n        Sell 500 kg of wheat", NOT_STARTED, WHEAT};
    mission mission5=*new mission{SELL, 200, "                    MISSION  5 \n\n        Sell 200 kg of tomatoes", NOT_STARTED, TOMATO};

    mission mission6=*new mission{HARVEST, 300, "                    MISSION  6 \n\n        Harvest 300 kg of tomatoes", NOT_STARTED, TOMATO};
    mission mission7=*new mission{PLANT, 15, "                    MISSION  7 \n\n        Plant corn 15 times", NOT_STARTED, CORN};
    mission mission8=*new mission{SELL, 600, "                    MISSION  8 \n\n        Sell 600 kg of tomatoes", NOT_STARTED, TOMATO};
    mission mission9=*new mission{SELL, 900, "                    MISSION  9 \n\n        Sell 900 kg of corn", NOT_STARTED, CORN};
    mission mission10=*new mission{SELL, 1500, "                    MISSION  10 \n\n        Sell 1500 kg of wheat", NOT_STARTED, WHEAT};

    mission mission11=*new mission{HARVEST, 1250, "                    MISSION  11 \n\n        Harvest 1250 kg of wheat", NOT_STARTED, WHEAT};
    mission mission12=*new mission{PLANT, 25, "                    MISSION  12 \n\n        Plant tomato 25 times", NOT_STARTED, TOMATO};
    mission mission13=*new mission{SELL, 1500, "                    MISSION  13 \n\n        Sell 1500 kg of corn", NOT_STARTED, CORN};
    mission mission14=*new mission{SELL, 2500, "                    MISSION  14 \n\n        Sell 2500 kg of wheat", NOT_STARTED, WHEAT};
    mission mission15=*new mission{SELL, 1000, "                    MISSION  15 \n\n        Sell 1000 kg of tomato", NOT_STARTED, TOMATO};

    mission mission16=*new mission{HARVEST, 1050, "                    MISSION  16 \n\n        Harvest 1050 kg of corn", NOT_STARTED, CORN};
    mission mission17=*new mission{HARVEST, 1750, "                    MISSION  17 \n\n        Harvest 1750 kg of wheat", NOT_STARTED, WHEAT};
    mission mission18=*new mission{SELL, 1400, "                    MISSION  18 \n\n        Sell 1400 kg of tomatoes", NOT_STARTED, TOMATO};
    mission mission19=*new mission{SELL, 2100, "                    MISSION  19 \n\n        Sell 2100 kg of corn", NOT_STARTED, CORN};
    mission mission20=*new mission{SELL, 3500, "                    MISSION  20 \n\n        Sell 3500 kg of wheat", NOT_STARTED, WHEAT};

    mission mission21=*new mission{HARVEST, 2250, "                    MISSION  21 \n\n        Harvest 2250 kg of wheat", NOT_STARTED, WHEAT};
    mission mission22=*new mission{HARVEST, 900, "                    MISSION  22 \n\n        Harvest 900 kg of tomatoes", NOT_STARTED, TOMATO};
    mission mission23=*new mission{SELL, 2700, "                    MISSION  23 \n\n        Sell 2700 kg of corn", NOT_STARTED, CORN};
    mission mission24=*new mission{SELL, 4500, "                    MISSION  24 \n\n        Sell 4500 kg of wheat", NOT_STARTED, WHEAT};
    mission mission25=*new mission{SELL, 25, "                    CONGRATULATIONS \n\n        All Missions Completed", NOT_STARTED, TOMATO};


    // An array containing 25 missions
    mission missions[25] = {mission1, mission2, mission3, mission4, mission5
            ,mission6, mission7, mission8, mission9, mission10
            ,mission11, mission12, mission13, mission14, mission15
            ,mission16, mission17, mission18, mission19, mission20
            ,mission21, mission22, mission23, mission24, mission25
            ,};/**< An array containing 25 missions. */

    size_t currentMissionIndex; /**< Index of the current mission. */

    int missionProgress;   /**< Player's progress within missions. */

public:
    /**
    * @brief Constructor for the MissionManager class.
    */
    MissionManager();

    /**
     * @brief Get overall progress.
     *
     * @return Overall progress.
     */
    int getProgress() const;

    /**
     * @brief Get progress in the current mission.
     *
     * @return Progress in the current mission.
     */
    int getMissionProgress();

    /**
     * @brief Continue the current mission.
     */
    void continueMission();

    /**
     * @brief Start the next mission.
     */
    void startNextMission();

    /**
     * @brief Complete the current mission.
     *
     * @param soundManager Sound manager for playing sounds.
     * @return True if the current mission is completed, false otherwise.
     */
    bool completeCurrentMission(SoundManager* soundManager);

    /**
     * @brief Get the current mission.
     *
     * @return Pointer to the current mission.
     */
    mission* getCurrentMission();

    /**
     * @brief Check if all missions are completed.
     *
     * @return True if all missions are completed, false otherwise.
     */
    bool areAllMissionsCompleted() const;

    /**
     * @brief Update mission progress based on the processing count.
     *
     * @param processCount Number of processes to update the progress.
     */
    void updateMissions(int processCount);

    /**
     * @brief Load mission data from an XML document.
     *
     * @param parent XML document to load mission data from.
     */
    void loadToClass(pugi::xml_document &parent);

    /**
     * @brief Save mission data to an XML node.
     *
     * @param parent XML node to save mission data to.
     */
    void saveToXml(pugi::xml_node &parent) const;
};
#endif //FARMIG2024_MISSIONMANAGER_H
