#include "../headers/EventManager.h"

EventManager::EventManager(class player* player,class upgrade *upgrade,class farm *farm){
    this->player=player;
    this->upgrade=upgrade;
    this->farm=farm;

    events[0]=new event("Sunny Weather\n ","Good News: Ohh the sun is shining brightly\n and the crop yield in the wheat field\n is fantastic",farm->getProduct(WHEAT)->getYield()+70,farm->getProduct(TOMATO)->getYield()+30,farm->getProduct(CORN)->getYield()+40,farm->getProduct(WHEAT)->getSell()*0.5,farm->getProduct(TOMATO)->getSell(),farm->getProduct(CORN)->getSell()*0.6);
    events[1]=new event("Abundant Rainfall\n  ","Good News: The air rejoiced with rain\n and the crops celebrated",farm->getProduct(WHEAT)->getYield()+40,farm->getProduct(TOMATO)->getYield()+40,farm->getProduct(CORN)->getYield()+40,farm->getProduct(WHEAT)->getSell()*0.6,farm->getProduct(TOMATO)->getSell()*0.4,farm->getProduct(CORN)->getSell()*0.5);
    events[2]=new event("Fertilization\n ","Good News: Our farmers did a\n fantastic job ",farm->getProduct(WHEAT)->getYield()+50,farm->getProduct(TOMATO)->getYield()+30,farm->getProduct(CORN)->getYield()+25,farm->getProduct(WHEAT)->getSell()*0.7,farm->getProduct(TOMATO)->getSell()*0.5,farm->getProduct(CORN)->getSell()*0.4);
    events[3]=new event("Use of Agricultural Pesticides\n ","Good News: Thanks to agricultural\n pesticides we protected our crops\n from diseases",farm->getProduct(WHEAT)->getYield()+45,farm->getProduct(TOMATO)->getYield()+25,farm->getProduct(CORN)->getYield()+30,farm->getProduct(WHEAT)->getSell()*0.9,farm->getProduct(TOMATO)->getSell()*0.9,farm->getProduct(CORN)->getSell()*0.9);
    events[4]=new event("High Humidity\n ","Good News: High humidity became\n a friend to our crops",farm->getProduct(WHEAT)->getYield()+50,farm->getProduct(TOMATO)->getYield()+25,farm->getProduct(CORN)->getYield()+35,farm->getProduct(WHEAT)->getSell()*0.8,farm->getProduct(TOMATO)->getSell()*0.7,farm->getProduct(CORN)->getSell()*0.8);
    events[5]=new event("Soil Alkalinity Increase\n ","Bad News: An increase in soil acidity\n made it difficult for our crops to grow",farm->getProduct(WHEAT)->getYield()-10,farm->getProduct(TOMATO)->getYield()-5,farm->getProduct(CORN)->getYield()-5,farm->getProduct(WHEAT)->getSell()*1.5,farm->getProduct(TOMATO)->getSell()*1.3,farm->getProduct(CORN)->getSell()*1.2);
    events[6]=new event("Extreme Heat Wave\n ","Bad News: Unfortunately the extreme\n heat has damaged our crops",farm->getProduct(WHEAT)->getYield()+30,farm->getProduct(TOMATO)->getYield()-5,farm->getProduct(CORN)->getYield()-5,farm->getProduct(WHEAT)->getSell()*0.8,farm->getProduct(TOMATO)->getSell()*1.3,farm->getProduct(CORN)->getSell()*1.4);
    events[7]=new event("Soil Erosion\n ","Bad News: The power of the wind\n has stressed our crops",farm->getProduct(WHEAT)->getYield()-10,farm->getProduct(TOMATO)->getYield()-5,farm->getProduct(CORN)->getYield()-5,farm->getProduct(WHEAT)->getSell()*2,farm->getProduct(TOMATO)->getSell()*1.4,farm->getProduct(CORN)->getSell()*1.9);
    events[8]=new event("Severe Wind\n ","Bad News: Soil erosion caused our crops\n to lose their connection with the soil.",farm->getProduct(WHEAT)->getYield()-5,farm->getProduct(TOMATO)->getYield()-5,farm->getProduct(CORN)->getYield()-5,farm->getProduct(WHEAT)->getSell()*1.7,farm->getProduct(TOMATO)->getSell()*1.4,farm->getProduct(CORN)->getSell()*1.7);
    events[9]=new event("Drought\n ","Bad News: Drought has caused distress",farm->getProduct(WHEAT)->getYield()+30,farm->getProduct(TOMATO)->getYield()-5,farm->getProduct(CORN)->getYield()-10,farm->getProduct(WHEAT)->getSell()*0.7,farm->getProduct(TOMATO)->getSell()*2,farm->getProduct(CORN)->getSell()*1.8);
    events[10]=new event("Low Humidity\n ","Bad News: Unfortunately low humidity\n has made it challenging for our crops ",farm->getProduct(WHEAT)->getYield()+40,farm->getProduct(TOMATO)->getYield()-5,farm->getProduct(CORN)->getYield()+30,farm->getProduct(WHEAT)->getSell()*0.7,farm->getProduct(TOMATO)->getSell()*2,farm->getProduct(CORN)->getSell()*0.5);
    events[11]=new event("Lightning Strike\n ","Bad News: A lightning strike occurred\n and our crops suffered",farm->getProduct(WHEAT)->getYield()-10,farm->getProduct(TOMATO)->getYield()-5,farm->getProduct(CORN)->getYield()-10,farm->getProduct(WHEAT)->getSell()*3,farm->getProduct(TOMATO)->getSell()*3,farm->getProduct(CORN)->getSell()*3);
    events[12]=new event("Normal Day\n ","Everything is okay",farm->getProduct(WHEAT)->getDefaultYield(),farm->getProduct(TOMATO)->getDefaultYield(),farm->getProduct(CORN)->getDefaultYield(),farm->getProduct(WHEAT)->getDefaultSell(),farm->getProduct(TOMATO)->getDefaultSell(),farm->getProduct(CORN)->getDefaultSell());
    events[currentEvent]->setEventTime(chooseRandomTime());
    eventStartTime= player->getTimer()->getCurrentTime();

}

bool EventManager::UpdateEvents(){
    if(events[currentEvent]->getEventTime() <= ((this->player->getTimer()->getCurrentTime()) - eventStartTime)){
        return true;
    }
    return false;
}

int EventManager::getTimeRemain(){
    return events[currentEvent]->getEventTime() - ((this->player->getTimer()->getCurrentTime()) - eventStartTime);
}

int EventManager::getEventIndex() {
    return currentEvent;
}

event *EventManager::getCurrentEvent() {
    return events[currentEvent];
}

void EventManager::setEventStartTime(int time) {
    eventStartTime=time;
}

int EventManager::chooseRandomEvent() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Belirli bir aralıktaki rastgele tamsayıyı seç
    std::uniform_int_distribution<> dis(0, 12); // Değer aralığını isteğinize göre ayarlayın
    return dis(gen);

}
int EventManager::chooseRandomTime(){
    std::random_device rd;
    std::mt19937 gen(rd());

    // Belirli bir aralıktaki rastgele tamsayıyı seç
    std::uniform_int_distribution<> dis(30, 60); // Değer aralığını isteğinize göre ayarlayın
    return dis(gen);
}

void EventManager::setCurrentEvent(int index) {
    currentEvent=index;
    farm->getProduct(WHEAT)->setYield(events[currentEvent]->getYield(WHEAT));
    farm->getProduct(TOMATO)->setYield(events[currentEvent]->getYield(TOMATO));
    farm->getProduct(CORN)->setYield(events[currentEvent]->getYield(CORN));
    farm->getProduct(WHEAT)->setSell(events[currentEvent]->getSell(WHEAT));
    farm->getProduct(TOMATO)->setSell(events[currentEvent]->getSell(TOMATO));
    farm->getProduct(CORN)->setSell(events[currentEvent]->getSell(CORN));
}

void EventManager::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("eventmanager");
    root.append_child("currentEvent").text().set(currentEvent);
    root.append_child("eventStartTime").text().set(eventStartTime);
}

void EventManager::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("eventmanager");
    currentEvent=root.child("currentEvent").text().as_int();
    eventStartTime=root.child("eventStartTime").text().as_int();
}

