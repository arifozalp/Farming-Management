#include "../headers/timer.h"
#include "iostream"
#include "chrono"

timer::timer(){

}

void timer::updateSeconds() {
    if(static_cast<int>(clock.getElapsedTime().asSeconds())>0.7){
        seconds++;
        clock.restart();
    }
}
int timer::getCurrentTime() const {
    return seconds;
}
int timer::getSeconds() const {
    return seconds%60;
}
int timer::getMinutes() const {
    return seconds/60;
}

void timer::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("timer");
    root.append_child("second").text().set(seconds);
}

void timer::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("player").child("timer");
    seconds=root.child("second").text().as_int();
}




