#include <utility>

#include "../headers/farm.h"

string farm::getFarmName() const{
    return farmName;
}

void farm::setFarmName(std::string _farmName) {
    this->farmName = std::move(_farmName);
}

void farm::setField(int index) {
    fields[index].setUnlock();
}
field* farm::getField(int index){
    return &fields[index];
}
class warehouse* farm::getWarehouse() {
    return warehouse;
}

product *farm::getProduct(Product_type productType) {
    if(productType == WHEAT){
        return wheat;
    }
    else if(productType == CORN){
        return corn;
    }
    else if(productType == TOMATO){
        return tomato;
    }
}


farm::farm(player *_player) {
    for(int i=0;i<9;i++){
        fields[i]=*new field(_player);
    }
    fields[0].setUnlock();
    this->warehouse=new class warehouse();
}

void farm::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("farm");
    root.append_child("farmname").text().set(farmName.c_str());
    warehouse->saveToXml(root);
    for(int i=0;i<9;i++){
        fields[i].saveToXml(root,to_string(i));
    }
}

void farm::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("farm");
    farmName=root.child("farmname").text().as_string();
    warehouse->loadToClass(parent);
    for(int i=0;i<9;i++){
        fields[i].loadToClass(parent, to_string(i));
    }

}




