#ifndef FARMIG2024_MISSION_H
#define FARMIG2024_MISSION_H

#include "product.h"

using namespace std;

/**
 * @brief Enumeration representing different types of missions.
 */
enum MissionType {
    PLANT,    /**< Mission type for planting. */
    HARVEST,  /**< Mission type for harvesting. */
    SELL      /**< Mission type for selling. */
};

/**
 * @brief Enumeration representing the status of a mission.
 */
enum MissionStatus {
    NOT_STARTED, /**< Mission status indicating that the mission has not started. */
    IN_PROGRESS, /**< Mission status indicating that the mission is in progress. */
    COMPLETED    /**< Mission status indicating that the mission has been completed. */
};

/**
 * @brief Class representing a mission.
 */
class mission {
private:
    MissionType missionType;    /**< Type of the mission. */
    int requirement;            /**< Requirement for the mission. */
    std::string missionDetail;  /**< Details about the mission. */
    MissionStatus status;       /**< Status of the mission. */
    Product_type productType;   /**< Type of product related to the mission. */

public:
    /**
     * @brief Constructor for the mission class.
     *
     * @param missionType1 Type of the mission.
     * @param requirement Requirement for the mission.
     * @param missionDetail Details about the mission.
     * @param status Status of the mission.
     * @param productType Type of product related to the mission.
     */
    mission(MissionType missionType1, int requirement, std::string missionDetail, MissionStatus status, Product_type productType);

    /**
     * @brief Set the status of the mission.
     *
     * @param _missionStatus Status to be set for the mission.
     */
    void setMissionStatus(MissionStatus _missionStatus);

    /**
     * @brief Get the type of the mission.
     *
     * @return Type of the mission.
     */
    MissionType getMissionType() const;

    /**
     * @brief Get the requirement for the mission.
     *
     * @return Requirement for the mission.
     */
    int getRequirement();

    /**
     * @brief Get the status of the mission.
     *
     * @return Status of the mission.
     */
    MissionStatus getMissionStatus() const;

    /**
     * @brief Get the type of product related to the mission.
     *
     * @return Type of product related to the mission.
     */
    Product_type getProductType();

    /**
     * @brief Get details about the mission.
     *
     * @return Details about the mission.
     */
    string getMissionDetail();
};

#endif //FARMIG2024_MISSION_H
