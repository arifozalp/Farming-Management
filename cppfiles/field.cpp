#include "../headers/field.h"

bool field::isUsable() {
    return usable;
}

field::field(class player* _player) {
    this->lock=true;
    this->usable=false;
    this->isGrow=false;
    this->player=_player;
}

bool field::plant(product * _product, class player *_player,MissionManager* _MissionManager,GameInfo* gameInfo){
    if (usable == true){
        if(_product->getPrice()<= _player->getMoney()){
            _player->setMoney(_player->getMoney() - _product->getPrice());
            gameInfo->setProductPlant(_product->getProductType(),1);
            usable = false;
            startTime= this->player->getTimer()->getCurrentTime();
            plantProduct = _product;
            if(_MissionManager->getCurrentMission()->getMissionType()==PLANT){
                if(_MissionManager->getCurrentMission()->getProductType()==_product->getProductType()){
                    _MissionManager->updateMissions(1);
                }
            }
        }
        else{
            cout << "Paran yeterli değil!!!" << endl;
        }
    } else {
        cout << "Şu anda ekim yapamazsın!!!" << endl;
    }
    return usable;
}
bool field::harvest(product *_product, warehouse *_warehouse,MissionManager* _MissionManager,GameInfo* gameInfo, SoundManager* soundManager) {
    if (_warehouse->getLimit(_product)){
        if(isDecay){
            _warehouse->setPiece(_product->getProductType(), 0);
            gameInfo->setProductHarvest(_product->getProductType(),0);
        }else{
            _warehouse->setPiece(_product->getProductType(), _product->getYield());
            gameInfo->setProductHarvest(_product->getProductType(),_product->getYield());
        }
        soundManager->getHarvestSound()->playSound();
        usable = true;
        isGrow=false;
        isDecay=false;
        startTime=0;
        plantProduct= nullptr;
        if(_MissionManager->getCurrentMission()->getMissionType()==HARVEST){
            if(_MissionManager->getCurrentMission()->getProductType()==_product->getProductType()&&!isDecay){
                _MissionManager->updateMissions(_product->getYield());
            }
        }
        return true;
    }
    else return false;
}

void field::setUnlock() {
    lock=false;
    usable=true;
    //Buttonlara bağlı olmak zorunda, True olduğu zaman tıklanabiir olacak.
}

bool field::getUnlock() {
    return lock;
}
bool field::getIsGrow(){
    return isGrow;
}
product* field::getPlantProduct(){
    if(plantProduct != nullptr){
        return plantProduct;
    }

}
bool field::getIsDecay() {
    return isDecay;
}

string field::getProductTypeString(Product_type productName){
    if(productName == WHEAT){
        return "WHEAT";
    }
    else if(productName == CORN){
        return "CORN";
    }
    else if(productName == TOMATO){
        return "TOMATO";
    }
}


bool field::Update() {
    if(!usable){
        if(isGrow){
            if(plantProduct->getDecayTime() <= ((this->player->getTimer()->getCurrentTime()) - startTime) && !isDecay){
                    isDecay=true;
                    return true;
            }
            return false;
        }
        if(plantProduct->getHarvestTime() <= ((this->player->getTimer()->getCurrentTime()) - startTime)){
            isGrow= true;
            startTime= this->player->getTimer()->getCurrentTime();
            return true;
        }
    }
    return false;
}



int field::getTimeRemind(){
    if(isGrow){
        if(plantProduct->getDecayTime() - ((this->player->getTimer()->getCurrentTime()) - startTime) <= 0){
            return 0;
        }else
        return plantProduct->getDecayTime() - ((this->player->getTimer()->getCurrentTime()) - startTime);
    }else{
        if(plantProduct->getHarvestTime() - ((this->player->getTimer()->getCurrentTime()) - startTime) <= 0){
            return 0;
        }else{
            return plantProduct->getHarvestTime() - ((this->player->getTimer()->getCurrentTime()) - startTime);
        }
    }
}

void field::saveToXml(pugi::xml_node &parent,string index) const {
    string fieldname="field"+index;
    pugi::xml_node root = parent.append_child(fieldname.c_str());
    root.append_child("lock").text().set(lock);
    root.append_child("usable").text().set(usable);
    root.append_child("startTime").text().set(startTime);
    root.append_child("isGrow").text().set(isGrow);
    root.append_child("isDecay").text().set(isDecay);
    if(plantProduct == nullptr){
        root.append_child("producttype").text().set(0);
    }else if(plantProduct->getProductType() == WHEAT){
        root.append_child("producttype").text().set(1);
    }else if(plantProduct->getProductType() == TOMATO){
        root.append_child("producttype").text().set(2);
    }
    else if(plantProduct->getProductType() == CORN){
        root.append_child("producttype").text().set(3);
    }



}

void field::loadToClass(pugi::xml_document &parent, string index) {
    string fieldname= "field" + index;
    pugi::xml_node root = parent.child("generalgame").child("farm").child(fieldname.c_str());
    lock=root.child("lock").text().as_bool();
    isDecay= root.child("isDecay").text().as_bool();
    if(isDecay){
        usable=true;
        isGrow=false;
        startTime=0;
        isDecay=false;
    }else{
        usable= root.child("usable").text().as_bool();
        isGrow=root.child("isGrow").text().as_bool();
        startTime=root.child("startTime").text().as_int();
    }
    int productIndex=root.child("producttype").text().as_int();
    if(productIndex==0){
        plantProduct= nullptr;
    }else if(productIndex==1){
        plantProduct=new product(50, 400, 10, 10, 4, WHEAT);
    }else if(productIndex==2){
        plantProduct=new product(20, 600, 35, 10, 5, TOMATO);
    }
    else if(productIndex==3){
        plantProduct=new product(30, 800, 40, 10, 3, CORN);
    }

}



