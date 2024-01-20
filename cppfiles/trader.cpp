#include "../headers/trader.h"

int trader::getAmount(int index) {
    return amount[index];
}


void trader::setAmount(int newAmount, int index) {
    this->amount[index] = newAmount;
}


void trader::sell(int index , Product_type productName, MissionManager* _MissionManager, GameInfo* gameInfo, SoundManager* soundManager){
    if(farm->getWarehouse()->getPiece(productName) >= amount[index]){
        farm->getWarehouse()->setPiece(productName, -amount[index]);
        player->setMoney(farm->getProduct(productName)->getSell() * amount[index] + player->getMoney());
        gameInfo->setProductSell(productName, farm->getProduct(productName)->getSell() * amount[index]);
        if(amount[index] != 0){
            soundManager->getMoneySound()->playSound();
        }
        if(_MissionManager->getCurrentMission()->getMissionType()==SELL){
            if(_MissionManager->getCurrentMission()->getProductType() == productName){
                _MissionManager->updateMissions(amount[index]);
            }
        }

    }
}

trader::trader(class player *player,class farm *farm) {
    this->player = player;
    this->farm =farm;
}

