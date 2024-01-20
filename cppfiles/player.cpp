#include "../headers/player.h"

player::player() {
    this->playerName="";
    this->money=2000;
    this->mission = *new MissionManager();
}

string player::getPlayerName() const{
    return playerName;
}

void player::setPlayerName(string name) {
    this->playerName = name;
}

int player::getMoney() const {
    return money;
}

void player::setMoney(int _money){
    this->money = _money;
}
int player::getPlayerProgress() const {
    return mission.getProgress();
}

MissionManager* player::getMission() {
    return &mission;
}

class timer *player::getTimer() {
    return &timer;
}

void player::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("player");
    root.append_child("name").text().set(playerName.c_str());
    root.append_child("money").text().set(money);
    mission.saveToXml(root);
    timer.saveToXml(root);
}

void player::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("player");
    playerName=root.child("name").text().as_string();
    money=root.child("money").text().as_int();
    mission.loadToClass(parent);
    timer.loadToClass(parent);
}


