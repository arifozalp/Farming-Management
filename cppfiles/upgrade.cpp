#include "../headers/upgrade.h"

upgrade::upgrade() {
    upgradeLevel=0;
}

bool upgrade::upgradeCapacity(farm* farm, player* _player) {
    if (_player->getPlayerProgress() >= 5 && _player->getMoney()>=50000 && upgradeLevel == 0) {
        farm->getWarehouse()->setCapacity(1800);
        farm->setField(1);
        farm->setField(2);
        _player->setMoney(_player->getMoney()-50000);
        upgradeLevel++;
        return true;
    }
    else if (_player->getPlayerProgress() >= 10 && _player->getMoney()>=150000 && upgradeLevel == 1) {
        farm->getWarehouse()->setCapacity(3000);
        farm->setField(3);
        farm->setField(4);
        _player->setMoney(_player->getMoney()-150000);
        upgradeLevel++;
        return true;
    }
    else if (_player->getPlayerProgress() >= 15 && _player->getMoney()>=250000 && upgradeLevel == 2) {
        farm->getWarehouse()->setCapacity(4200);
        farm->setField(5);
        farm->setField(6);
        _player->setMoney(_player->getMoney()-250000);
        upgradeLevel++;
        return true;
    }
    else if (_player->getPlayerProgress() >= 20 && _player->getMoney()>=350000 && upgradeLevel == 3) {
        farm->getWarehouse()->setCapacity(5400);
        farm->setField(7);
        farm->setField(8);
        _player->setMoney(_player->getMoney()-350000);
        upgradeLevel++;
        return true;
    }
    else return false;
}

int upgrade::getUpgradeLevel() {
    return upgradeLevel;
}

string upgrade::getUpgradeText() {
    return upgradeText[upgradeLevel];
}

void upgrade::saveToXml(pugi::xml_node &parent) const {
    pugi::xml_node root = parent.append_child("upgrade");
    root.append_child("upgradeLevel").text().set(upgradeLevel);
}

void upgrade::loadToClass(pugi::xml_document &parent) {
    pugi::xml_node root = parent.child("generalgame").child("upgrade");
    upgradeLevel=root.child("upgradeLevel").text().as_int();
}
