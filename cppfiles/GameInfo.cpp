#include "../headers/GameInfo.h"


bool GameInfo::getEndGame() const{
    return endGame;
}

void GameInfo::setEndGame() {
    endGame= true;
}

bool GameInfo::getIsFinishProfile() const{
    return isFinishProfile;
}

void GameInfo::setIsFinishProfile() {
    isFinishProfile=true;
}

bool GameInfo::getIsFinishTutorial() const{
    return isFinishTutorial;
}

void GameInfo::setIsFinishTutorial() {
    isFinishTutorial= true;
}

int GameInfo::getWheatPlantPiece() const{
    return wheatPlantPiece;
}

void GameInfo::setWheatPlantPiece(int piece) {
    wheatPlantPiece+=piece;
}

int GameInfo::getTomatoPlantPiece() const{
    return tomatoPlantPiece;
}

void GameInfo::setTomatoPlantPiece(int piece) {
    tomatoPlantPiece+=piece;
}

int GameInfo::getCornPlantPiece() const{
    return cornPlantPiece;
}

void GameInfo::setCornPlantPiece(int piece) {
    cornPlantPiece+=piece;
}

int GameInfo::getWheatHarvestPiece() const{
    return wheatHarvestPiece;
}

void GameInfo::setWheatHarvestPiece(int piece) {
    wheatHarvestPiece+=piece;
}

int GameInfo::getTomatoHarvestPiece() const{
    return tomatoHarvestPiece;
}

void GameInfo::setTomatoHarvestPiece(int piece) {
    tomatoHarvestPiece+=piece;
}

int GameInfo::getCornHarvestPiece() const{
    return cornHarvestPiece;
}

void GameInfo::setCornHarvestPiece(int piece) {
    cornHarvestPiece+=piece;
}

int GameInfo::getGainMoneyWithWheat() const{
    return gainMoneyWithWheat;
}

void GameInfo::setGainMoneyWithWheat(int money) {
    gainMoneyWithWheat+=money;
}

int GameInfo::getGainMoneyWithTomato() const{
    return gainMoneyWithTomato;
}

void GameInfo::setGainMoneyWithTomato(int money) {
    gainMoneyWithTomato+=money;
}

int GameInfo::getGainMoneyWithCorn() const{
    return gainMoneyWithCorn;
}

void GameInfo::setGainMoneyWithCorn(int money) {
    gainMoneyWithCorn+=money;
}

GameInfo::GameInfo() {
    endGame=false;
    isFinishProfile=false;
    isFinishTutorial=false;
    wheatPlantPiece=0;
    wheatHarvestPiece=0;
    gainMoneyWithWheat=0;
    tomatoPlantPiece=0;
    tomatoHarvestPiece=0;
    gainMoneyWithTomato=0;
    cornPlantPiece=0;
    cornHarvestPiece=0;
    gainMoneyWithCorn=0;
}

void GameInfo::setProductSell(Product_type productType, int money) {
    if(productType==WHEAT)
        setGainMoneyWithWheat(money);
    else if(productType==TOMATO)
        setGainMoneyWithTomato(money);
    else if(productType==CORN)
        setGainMoneyWithCorn(money);
}

void GameInfo::setProductHarvest(Product_type productType, int piece) {
    if(productType==WHEAT)
        setWheatHarvestPiece(piece);
    else if(productType==TOMATO)
        setTomatoHarvestPiece(piece);
    else if(productType==CORN)
        setCornHarvestPiece(piece);
}

void GameInfo::setProductPlant(Product_type productType, int piece) {
    if(productType==WHEAT)
        setWheatPlantPiece(piece);
    else if(productType==TOMATO)
        setTomatoPlantPiece(piece);
    else if(productType==CORN)
        setCornPlantPiece(piece);
}

void GameInfo::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("gameinfo");
    root.append_child("endGame").text().set(endGame);
    root.append_child("isFinishProfile").text().set(isFinishProfile);
    root.append_child("isFinishTutorial").text().set(isFinishTutorial);
    root.append_child("wheatPlantPiece").text().set(wheatPlantPiece);
    root.append_child("wheatHarvestPiece").text().set(wheatHarvestPiece);
    root.append_child("gainMoneyWithWheat").text().set(gainMoneyWithWheat);
    root.append_child("tomatoPlantPiece").text().set(tomatoPlantPiece);
    root.append_child("tomatoHarvestPiece").text().set(tomatoHarvestPiece);
    root.append_child("gainMoneyWithTomato").text().set(gainMoneyWithTomato);
    root.append_child("cornPlantPiece").text().set(cornPlantPiece);
    root.append_child("cornHarvestPiece").text().set(cornHarvestPiece);
    root.append_child("gainMoneyWithCorn").text().set(gainMoneyWithCorn);

}

void GameInfo::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("gameinfo");
    endGame=root.child("endGame").text().as_bool();
    isFinishProfile=root.child("isFinishProfile").text().as_bool();
    isFinishTutorial=root.child("isFinishTutorial").text().as_bool();
    wheatPlantPiece=root.child("wheatPlantPiece").text().as_int();
    wheatHarvestPiece=root.child("wheatHarvestPiece").text().as_int();
    gainMoneyWithWheat=root.child("gainMoneyWithWheat").text().as_int();
    tomatoPlantPiece=root.child("tomatoPlantPiece").text().as_int();
    tomatoHarvestPiece=root.child("tomatoHarvestPiece").text().as_int();
    gainMoneyWithTomato=root.child("gainMoneyWithTomato").text().as_int();
    cornPlantPiece=root.child("cornPlantPiece").text().as_int();
    cornHarvestPiece=root.child("cornHarvestPiece").text().as_int();
    gainMoneyWithCorn=root.child("gainMoneyWithCorn").text().as_int();



}
