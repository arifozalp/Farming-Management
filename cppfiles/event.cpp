#include "../headers/event.h"

event::event(string EventName, string EventDetail, int WheatYield, int TomatoYield, int CornYield, int sellWheat, int sellTomato, int sellCornInt) {
    this->eventName = EventName;
    this->eventDetail=EventDetail;
    this->yieldWheat = WheatYield;
    this->yieldTomato=TomatoYield;
    this->yieldCorn=CornYield;
    this->sellWheat=sellWheat;
    this->sellTomato=sellTomato;
    this->sellCorn=sellCornInt;


}

int event::getYield(Product_type productType) {
    if(productType==WHEAT){
        return yieldWheat;
    }
    else if(productType==TOMATO){
        return yieldTomato;
    }
    else if(productType==CORN){
        return yieldCorn;
    }
}

int event::getSell(Product_type productType) {
    if(productType==WHEAT){
        return sellWheat;
    }
    else if(productType==TOMATO){
        return sellTomato;
    }
    else if(productType==CORN){
        return sellCorn;
    }
}

string event::getEventName() {
    return eventName;
}

void event::setEventTime(int time) {
    this->eventTime=time;
}

int event::getEventTime() {
    return eventTime;
}

string event::getEventDetail() {
    return eventDetail;
}


