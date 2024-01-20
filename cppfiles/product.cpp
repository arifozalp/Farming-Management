#include "../headers/product.h"


Product_type product::getProductType() const {
    return productType;
}

int product::getYield() {
    return yield;
}
void product::setYield(int newYield) {
    this->yield = newYield;
}

int product::getPrice() {
    return price;
}

float product::getHarvestTime() {
    return harvestTime;
}

float product::getDecayTime() {
    return decayTime;
}

product::product(int defaultyield, int price,int defaultSell, float harvestTime, float decayTime, Product_type productName) {
    this->defaultYield=defaultyield;
    this->yield=defaultyield;
    this->price=price;
    this->defaultSell=defaultSell;
    this->sell=defaultSell;
    this->harvestTime=harvestTime;
    this->decayTime=decayTime;
    this->productType=productName;
}
int product::getDefaultSell() {
    return defaultSell;
}

int product::getSell() {
    return sell;
}

int product::getDefaultYield() {
    return defaultYield;
}
void product::setSell(int newSell) {
    this->sell=newSell;
}


