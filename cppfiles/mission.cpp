#include "../headers/mission.h"


mission::mission(MissionType missionType1,int requirement, std::string missionDetail,MissionStatus status,Product_type productType){
    this->missionType=missionType1;
    this->requirement=requirement;
    this->missionDetail=missionDetail;
    this->status=status;
    this->productType=productType;
}
void mission::setMissionStatus(MissionStatus _missionStatus){
    status=_missionStatus;
}

MissionType mission::getMissionType() const{
    return missionType;
}
int mission::getRequirement() {
    return requirement;
}
MissionStatus mission::getMissionStatus() const{
    return status;
}
Product_type mission::getProductType(){
    return productType;
}

string mission::getMissionDetail() {
    return missionDetail;
}
