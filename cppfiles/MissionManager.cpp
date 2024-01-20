#include "../headers/MissionManager.h"

int MissionManager::getProgress() const{
    return currentMissionIndex;
}
void MissionManager::startNextMission() {
    if (currentMissionIndex < numberOfMission) {
        missions[currentMissionIndex].setMissionStatus(IN_PROGRESS);
        missionProgress=0;
        std::cout << "Mission " << currentMissionIndex + 1 << " başlatıldı!" << std::endl;
    } else {
        std::cout << "Tüm görevler tamamlandı." << std::endl;
    }
}
void MissionManager::continueMission() {
    if (currentMissionIndex < numberOfMission) {
        missions[currentMissionIndex].setMissionStatus(IN_PROGRESS);
    }
}
bool MissionManager::completeCurrentMission(SoundManager* soundManager) {
    if (missions[currentMissionIndex].getMissionStatus()== IN_PROGRESS && missionProgress >=
                                                                                  missions[currentMissionIndex].getRequirement()) {
        std::cout << "Mission " << currentMissionIndex + 1 << " tamamlandı!" << std::endl;
        missions[currentMissionIndex].setMissionStatus(COMPLETED);
        soundManager->getEventAlertSound()->playSound();
        currentMissionIndex++;
        return true;
    } else {
        return false;
    }
}

mission* MissionManager::getCurrentMission(){
    return &missions[currentMissionIndex];
}
bool MissionManager::areAllMissionsCompleted() const {
    return currentMissionIndex >= numberOfMission - 1;
}
void MissionManager::updateMissions(int processCount) {
     if((missions[currentMissionIndex].getMissionStatus() == IN_PROGRESS)){
         missionProgress += processCount;
     }
}

MissionManager::MissionManager() {
    currentMissionIndex=0;
    missionProgress=0;
}

int MissionManager::getMissionProgress() {
    return missionProgress;
}

void MissionManager::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("missionmanager");
    root.append_child("currentMissionIndex").text().set(currentMissionIndex);
    root.append_child("missionProgress").text().set(missionProgress);
}

void MissionManager::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("player").child("missionmanager");
    currentMissionIndex=root.child("currentMissionIndex").text().as_int();
    missionProgress=root.child("missionProgress").text().as_int();
}
