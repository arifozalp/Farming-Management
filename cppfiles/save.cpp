#include "../headers/save.h"

save::save(StateData *stateData) {
    this->stateData1=stateData;
}

void save::savetoXml() const {
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("generalgame");
    stateData1->gameInfo->saveToXml(root);
    stateData1->player->saveToXml(root);
    stateData1->farm->saveToXml(root);
    stateData1->upgrade->saveToXml(root);
    stateData1->eventManager->saveToXml(root);
    stateData1->soundManager->saveToXml(root);
    doc.save_file("gamesaving.xml");
}

void save::loadToGame() {
    pugi::xml_document readDoc;
    if (readDoc.load_file("gamesaving.xml")) {
        stateData1->gameInfo->loadToClass(readDoc);
        stateData1->player->loadToClass(readDoc);
        stateData1->farm->loadToClass(readDoc);
        stateData1->upgrade->loadToClass(readDoc);
        stateData1->eventManager->loadToClass(readDoc);
        stateData1->soundManager->loadToClass(readDoc);
    } else {
        std::cout << "Failed to load XML file!" << std::endl;
    }
}

void save::resetToXml() {
    this->stateData1->player=new player();
    this->stateData1->farm=new farm(this->stateData1->player);
    this->stateData1->trader=new trader(this->stateData1->player,this->stateData1->farm);
    this->stateData1->upgrade=new upgrade();
    this->stateData1->eventManager=new EventManager(this->stateData1->player,this->stateData1->upgrade,this->stateData1->farm);
    savetoXml();
}
