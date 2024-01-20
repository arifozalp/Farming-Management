#include "../headers/stdafx.h"
#include "../headers/PlayerGUI.h"

void PlayerGUI::initFont()
{
	this->font.loadFromFile("../Fonts/fonttr.ttf");
}

void PlayerGUI::initPlayer(sf::VideoMode& vm) {

    if (!this->backgroundTexture.loadFromFile("../Resources/Images/Backgrounds/gamescreen/background.png")) {
        throw "ERROR::MAINMENUSTATES::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
    }
    this->background.setTexture(&this->backgroundTexture);
    this->background.setSize(
            sf::Vector2f(
                    static_cast<float>((vm.width)),
                    static_cast<float>(vm.height)

            )
    );
    this->PlayerImage.setSize(sf::Vector2f (120.f, 126.f));
    this->PlayerImage.setPosition(52.f, 14.f);
    if(this->stateData->player->getPlayerName() == "Osman")
        this->FarmerTexture.loadFromFile("../Resources/Images/Backgrounds/iconimage/manfarmer000.png");
    else
        this->FarmerTexture.loadFromFile("../Resources/Images/Backgrounds/iconimage/womanfarmer000.png");

    this->PlayerImage.setTexture(&FarmerTexture);

    this->PlayerText.setSize(sf::Vector2f (306.f, 140.f));
    this->PlayerText.setPosition(170.f, 14.f);
    this->playerTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/playertext.png");
    this->PlayerText.setTexture(&playerTextTexture);


    this->PlayerName.setFont(font);
    this->PlayerName.setPosition(265.f,50.f);
    this->PlayerName.setCharacterSize(gui::calcCharSize(vm, 55.f));
    this->PlayerName.setFillColor(sf::Color::White);
    this->PlayerName.setString(this->stateData->player->getPlayerName());
}

void PlayerGUI::initTimer(sf::VideoMode& vm) {
    this->TimerText.setSize(sf::Vector2f (370.f, 65.f));
    this->TimerText.setPosition(1525.f, 120.f);
    timerTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/timertext.png");
    this->TimerText.setTexture(&timerTextTexture);

    this->timer_Text.setFont(font);
    this->timer_Text.setPosition(1630.f,120.f);
    this->timer_Text.setCharacterSize(gui::calcCharSize(vm, 60.f));
    this->timer_Text.setFillColor(sf::Color::Black);

    this->timer->loadAnimation("../Resources/Images/Gui_images/clocks/clock000.gif", 48,
                               sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));

    this->TimerImage.setSize(sf::Vector2f (100.f, 100.f));
    this->TimerImage.setPosition(1500.f, 95.f);

}

void PlayerGUI::initFields(sf::VideoMode& videoMode) {

    for (int fieldIndex = 0; fieldIndex < 9; fieldIndex++) {
        FieldAnim[std::to_string(fieldIndex)] =new Animation();
        progressCheck[fieldIndex]=false;
        FieldAnim[std::to_string(fieldIndex)]->loadAnimation("../Resources/Images/Gui_images/Field_image/field000.png", 1,
                                                             sf::Vector2f(800, 800));
    }
    location="../Resources/Images/Gui_images/Field_image/";
    extension=".png";
    this->fields["0"] = new gui::Button(600.f, 410.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255,0),
                                        sf::Color(250, 250, 70, 0),
                                        sf::Color(20, 20, 20, 0),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190,255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["0"], 145
    );
    this->fields["1"] = new gui::Button(950.f, 410.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255, 100),
                                        sf::Color(250, 250, 70, 100),
                                        sf::Color(20, 20, 20, 100),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190, 255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["1"], 145
    );
    this->fields["2"] = new gui::Button(1300.f, 410.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255, 100),
                                        sf::Color(250, 250, 70, 100),
                                        sf::Color(20, 20, 20, 100),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190, 255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["2"], 145
    );
    this->fields["3"] = new gui::Button(450.f, 530.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255, 100),
                                        sf::Color(250, 250, 70, 100),
                                        sf::Color(20, 20, 20, 100),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190, 255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["3"], 145
    );
    this->fields["4"] = new gui::Button(800.f, 530.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255, 100),
                                        sf::Color(250, 250, 70, 100),
                                        sf::Color(20, 20, 20, 100),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190, 255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["4"], 145
    );
    this->fields["5"] = new gui::Button(1150.f, 530.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255, 100),
                                        sf::Color(250, 250, 70, 100),
                                        sf::Color(20, 20, 20, 100),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190, 255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["5"], 145
    );

    this->fields["6"] = new gui::Button(300.f, 650.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255, 100),
                                        sf::Color(250, 250, 70, 100),
                                        sf::Color(20, 20, 20, 100),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190, 255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["6"], 145
    );
    this->fields["7"] = new gui::Button(650.f, 650.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255, 100),
                                        sf::Color(250, 250, 70, 100),
                                        sf::Color(20, 20, 20, 100),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190, 255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["7"], 145
    );
    this->fields["8"] = new gui::Button(1000.f, 650.f, 200.f, 150.f,
                                        &this->font, "", 2 * gui::calcCharSize(videoMode),
                                        sf::Color(255, 255, 255, 100),
                                        sf::Color(250, 250, 70, 100),
                                        sf::Color(20, 20, 20, 100),
                                        sf::Color(255, 255, 255),
                                        sf::Color(112, 146, 190, 255),
                                        sf::Color(112, 146, 190, 200), PARALLELOGRAM, 0, FieldAnim["8"], 145
    );

    Animation* plantWheatImg = new Animation();
    plantWheatImg->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/wheatwaretexture000.png", 1,
                                 sf::Vector2f(294.f, 88.f));
    Animation* plantTomatoImg = new Animation();
    plantTomatoImg->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/tomatowaretexture000.png", 1,
                                  sf::Vector2f(294.f, 88.f));
    Animation* plantCornImg = new Animation();
    plantCornImg->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/cornwaretexture000.png", 1,
                                sf::Vector2f(294.f, 88.f));
    Animation* plantBackButton = new Animation();
    plantBackButton->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/PlantBackButton000.png", 1,
                                   sf::Vector2f(294.f, 88.f));

    this->products["wheat"]=new gui::Button(850.f,250.f, 100.f,100.f,
                                            &this->font, "", 2 * gui::calcCharSize(videoMode),
                                            sf::Color(255, 255, 255, 100),
                                            sf::Color(250, 250, 70, 100),
                                            sf::Color(20, 20, 20, 100),
                                            sf::Color(255,255,255,255),
                                            sf::Color(112, 146, 190, 255),
                                            sf::Color(112, 146, 190, 200),RECTANGLE,0,plantWheatImg
    );
    this->products["tomato"]=new gui::Button(1000.f,250.f, 100.f,100.f,
                                             &this->font, "", 2 * gui::calcCharSize(videoMode),
                                             sf::Color(255, 255, 255, 100),
                                             sf::Color(250, 250, 70, 100),
                                             sf::Color(20, 20, 20, 100),
                                             sf::Color(255,255,255,255),
                                             sf::Color(112, 146, 190, 255),
                                             sf::Color(112, 146, 190, 200),RECTANGLE,0,plantTomatoImg
    );
    this->products["corn"]=new gui::Button(1150.f,250.f, 100.f,100.f,
                                           &this->font, "", 2 * gui::calcCharSize(videoMode),
                                           sf::Color(255, 255, 255, 100),
                                           sf::Color(250, 250, 70, 100),
                                           sf::Color(20, 20, 20, 100),
                                           sf::Color(255,255,255,255),
                                           sf::Color(112, 146, 190, 255),
                                           sf::Color(112, 146, 190, 200),RECTANGLE,0,plantCornImg
    );
    this->products["back"]=new gui::Button(1270.f,250.f,70.f,55.f,
                                           &this->font, "", 2 * gui::calcCharSize(videoMode),
                                           sf::Color(255, 255, 255, 100),
                                           sf::Color(250, 250, 70, 100),
                                           sf::Color(20, 20, 20, 100),
                                           sf::Color(255,255,255,255),
                                           sf::Color(112, 146, 190, 255),
                                           sf::Color(112, 146, 190, 200),RECTANGLE,0,plantBackButton
    );

    this->fieldProgress["0"]=new gui::ProgressBar(600.f, 387.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);
    this->fieldProgress["1"]=new gui::ProgressBar(950.f, 387.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);
    this->fieldProgress["2"]=new gui::ProgressBar(1300.f, 387.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);
    this->fieldProgress["3"]=new gui::ProgressBar(450.f, 507.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);
    this->fieldProgress["4"]=new gui::ProgressBar(800.f, 507.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);
    this->fieldProgress["5"]=new gui::ProgressBar(1150.f, 507.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);
    this->fieldProgress["6"]=new gui::ProgressBar(300.f, 627.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);
    this->fieldProgress["7"]=new gui::ProgressBar(650.f, 627.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);
    this->fieldProgress["8"]=new gui::ProgressBar(1000.f, 627.f, 200.f, 20.f,
                                                  10, sf::Color::Yellow, 150, videoMode);

}

void PlayerGUI::initMoney(sf::VideoMode& vm) {
    this->MoneyText.setSize(sf::Vector2f (333.f, 71.f));
    this->MoneyText.setPosition(1523.f, 29.f);
    this->moneyTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/moneytext.png");
    this->MoneyText.setTexture(&moneyTextTexture);

    this->money->loadAnimation("../Resources/Images/Gui_images/Money_Sprite/tile000.png", 11,
                               sf::Vector2f(gui::p2pX(15.f, vm), gui::p2pY(7.f, vm)));

    this->MoneyImage.setSize(sf::Vector2f (58.f, 59.f));
    this->MoneyImage.setPosition(1550.f, 33.f);

    this->Money_text.setFont(font);
    this->Money_text.setFillColor(sf::Color::Black);
    this->Money_text.setPosition(1600.f,25.f);
    this->Money_text.setCharacterSize(gui::calcCharSize(vm, 50.f));

}

void PlayerGUI::initEvent(sf::VideoMode &vm) {

    this->EventText.setSize(sf::Vector2f (450.f,370.f));
    this->EventText.setPosition(10.f,160.f);
    this->eventTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/eventtexture.png");
    this->EventText.setTexture(&eventTextTexture);

    this->Event_text.setFont(font);
    this->Event_text.setFillColor(sf::Color::Black);
    this->Event_text.setPosition(130.f,180.f);
    this->Event_text.setCharacterSize(gui::calcCharSize(vm, 120.f));

    this->Event_text_detail.setFont(font);
    this->Event_text_detail.setFillColor(sf::Color::Black);
    this->Event_text_detail.setPosition(100.f,320.f);
    this->Event_text_detail.setCharacterSize(gui::calcCharSize(vm, 150.f));

    this->Event_timer_text.setFont(font);
    this->Event_timer_text.setFillColor(sf::Color::Black);
    this->Event_timer_text.setPosition(200.f,230.f);
    this->Event_timer_text.setCharacterSize(gui::calcCharSize(vm, 120.f));

    this->EventTimer.setSize(sf::Vector2f (80.f,40.f));
    this->EventTimer.setPosition(185.f,225.f);
    this->eventTimer.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/timertext.png");
    this->EventTimer.setTexture(&eventTimer);

    this->WheatYieldState.setSize(sf::Vector2f (40.f,40.f));
    this->WheatYieldState.setPosition(340.f,310.f);

    this->TomatoYieldState.setSize(sf::Vector2f (40.f,40.f));
    this->TomatoYieldState.setPosition(340.f,335.f);

    this->CornYieldState.setSize(sf::Vector2f (40.f,40.f));
    this->CornYieldState.setPosition(340.f,360.f);

    this->WheatSellState.setSize(sf::Vector2f (40.f,40.f));
    this->WheatSellState.setPosition(340.f,385.f);

    this->TomatoSellState.setSize(sf::Vector2f (40.f,40.f));
    this->TomatoSellState.setPosition(340.f,410.f);

    this->CornSellState.setSize(sf::Vector2f (40.f,40.f));
    this->CornSellState.setPosition(340.f,435.f);

    this->eventUp.loadFromFile("../Resources/Images/Gui_images/Tradeicon/up.png");

    this->eventNormal.loadFromFile("../Resources/Images/Gui_images/Tradeicon/normal.png");

    this->eventDown.loadFromFile("../Resources/Images/Gui_images/Tradeicon/down.png");

    this->updateProductState();
}

void PlayerGUI::initMission(sf::VideoMode& vm) {
    this->MissionText.setSize(sf::Vector2f (350.f, 350.f));
    this->MissionText.setPosition(1531.f, 160.f);
    this->missionTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/missiontext000.png");
    this->MissionText.setTexture(&missionTextTexture);

    this->Mission_text.setFont(font);
    this->Mission_text.setFillColor(sf::Color::Black);
    this->Mission_text.setPosition(1570.f,330.f);
    this->Mission_text.setCharacterSize(gui::calcCharSize(vm, 130.f));
    this->stateData->player->getMission()->continueMission();
    missionProgress=new gui::ProgressBar(1608.f, 448.f, 200.f, 20.f,
                                         this->stateData->player->getMission()->getCurrentMission()->getRequirement(), sf::Color::Yellow, 150, vm);

    this->progressCount.setFont(font);
    this->progressCount.setPosition(1668.f,455.f);
    this->progressCount.setFillColor(sf::Color::Black);
    this->progressCount.setCharacterSize(gui::calcCharSize(vm, 70.f));


}

void PlayerGUI::initUpgrade(sf::VideoMode& vm) {
    this->UpgradeText.setSize(sf::Vector2f (369.f, 350.f));
    this->UpgradeText.setPosition(1520.f, 600.f);
    this->upgradeTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/u.png");
    this->UpgradeText.setTexture(&upgradeTextTexture);

    this->Upgrade_text.setFont(font);
    this->Upgrade_text.setFillColor(sf::Color::Black);
    this->Upgrade_text.setPosition(1595.f,650.f);
    this->Upgrade_text.setCharacterSize(gui::calcCharSize(vm, 120.f));

    this->upgrade->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/upgradebutton000.png", 1,
                                 sf::Vector2f(800.f, 800.f));


   this->upg=new gui::Button(1360.f,680.f,
           192.f,187.f,
            &this->font, "", 2 * gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 200),
            sf::Color(20, 20, 20, 200),
            sf::Color(255, 255, 255, 255),
            sf::Color(112, 146, 190, 255),
            sf::Color(112, 146, 190, 200),RECTANGLE,1,upgrade
    );
}

void PlayerGUI::initWarehouse(sf::VideoMode& vm) {
    this->WheatText.setSize(sf::Vector2f (325.f, 68.f));
    this->WheatText.setPosition(631.f, 963.f);
    this->wheatWareTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/wheatwaretext.png");
    this->WheatText.setTexture(&wheatWareTextTexture);

    this->WheatPieceAndCapacity.setFont(font);
    this->WheatPieceAndCapacity.setFillColor(sf::Color::Black);
    this->WheatPieceAndCapacity.setPosition(681.f, 955.f);
    this->WheatPieceAndCapacity.setCharacterSize(gui::calcCharSize(vm, 45.f));

    this->WheatImage.setSize(sf::Vector2f (110.f, 110.f));
    this->WheatImage.setPosition(585.f, 935.f);
    this->wheatWareTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/wheatwaretexture.png");
    this->WheatImage.setTexture(&wheatWareTexture);

    this->TomatoText.setSize(sf::Vector2f (300.f, 68.f));
    this->TomatoText.setPosition(1073.f, 960.f);
    this->tomatoWareTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/tomatowaretext.png") ;
    this->TomatoText.setTexture(&tomatoWareTextTexture);

    this->TomatoPieceAndCapacity.setFont(font);
    this->TomatoPieceAndCapacity.setFillColor(sf::Color::Black);
    this->TomatoPieceAndCapacity.setPosition(1115.f, 955.f);
    this->TomatoPieceAndCapacity.setCharacterSize(gui::calcCharSize(vm, 45.f));

    this->TomatoImage.setSize(sf::Vector2f(110.f, 110.f));
    this->TomatoImage.setPosition(1005.f, 950.f);
    this->tomatoWareTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/tomatowaretexture.png");
    this->TomatoImage.setTexture(&tomatoWareTexture);

    this->CornText.setSize(sf::Vector2f (300.f, 68.f));
    this->CornText.setPosition(1504.f, 961.f);
    this->cornWareTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/cornwaretext.png") ;
    this->CornText.setTexture(&cornWareTextTexture);

    this->CornPieceAndCapacity.setFont(font);
    this->CornPieceAndCapacity.setFillColor(sf::Color::Black);
    this->CornPieceAndCapacity.setPosition(1545.f, 955.f);
    this->CornPieceAndCapacity.setCharacterSize(gui::calcCharSize(vm, 45.f));

    this->CornImage.setSize(sf::Vector2f (91.f, 102.f));
    this->CornImage.setPosition(1450.f, 932.f);
    this->cornWareTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/cornwaretexture.png");
    this->CornImage.setTexture(&cornWareTexture);

}

void PlayerGUI::initFarmName(sf::VideoMode& videoMode) {

    this->FarmNameShape.setSize(sf::Vector2f (491.f, 84.f));
    this->FarmNameShape.setPosition(716.f, 22.f);
    this->farmNameShapeTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/farmNameShapeTexture.png") ;
    this->FarmNameShape.setTexture(&farmNameShapeTexture);

    this->FarmName.setFont(font);
    this->FarmName.setPosition(830.f,23.f);
    this->FarmName.setCharacterSize(gui::calcCharSize(videoMode, 58.f));
    this->FarmName.setFillColor(sf::Color::White);
    this->FarmName.setString(this->stateData->farm->getFarmName());

}

void PlayerGUI::initTrader(sf::VideoMode& vm) {
    this->traderBackground.setFillColor(sf::Color(10, 10, 30, 100));

    this->TraderImage.setSize(sf::Vector2f (114.f, 161.f));
    this->TraderImage.setPosition(72.f, 905.f);
    this->traderTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/traderTexture.png") ;
    this->TraderImage.setTexture(&traderTexture);

    this->TraderText.setSize(sf::Vector2f (294.f, 88.f));
    this->TraderText.setPosition(173.f, 957.f);
    this->traderTextTexture.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/tradertext000.png");
    this->TraderText.setTexture(&traderTextTexture);



    this->Helper.setSize(sf::Vector2f (900.f,613.f));
    this->Helper.setPosition(120.f,300.f);
    this->helper.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/helper.png");
    this->Helper.setTexture(&helper);

    this->WheatTrader.setSize(sf::Vector2f (130.f,130.f));
    this->WheatTrader.setPosition(590.f,320.f);
    this->wheatTraderImage.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/wheatWareTexture.png");
    this->WheatTrader.setTexture(&wheatTraderImage);


    this->TomatoTrader.setSize(sf::Vector2f (150.f,150.f));
    this->TomatoTrader.setPosition(570.f,470.f);
    this->tomatoTraderImage.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/tomatoWareTexture.png");
    this->TomatoTrader.setTexture(&tomatoTraderImage);

    this->CornTrader.setSize(sf::Vector2f (100.f,100.f));
    this->CornTrader.setPosition(620.f,620.f);
    this->cornTraderImage.loadFromFile("../Resources/Images/Gui_images/Warehouse_image/cornWareTexture.png");
    this->CornTrader.setTexture(&cornTraderImage);

    this->WheatTraderCount.setFont(font);
    this->WheatTraderCount.setPosition(875.f,333.f);
    this->WheatTraderCount.setCharacterSize(gui::calcCharSize(vm, 55.f));
    this->WheatTraderCount.setFillColor(sf::Color::White);

    this->traderWheatAmount.setFont(font);
    this->traderWheatAmount.setPosition(1050.f, 333.f);
    this->traderWheatAmount.setCharacterSize(gui::calcCharSize(vm, 55.f));
    this->traderWheatAmount.setFillColor(sf::Color::White);

    this->TomatoTraderCount.setFont(font);
    this->TomatoTraderCount.setPosition(875.f,483.f);
    this->TomatoTraderCount.setCharacterSize(gui::calcCharSize(vm, 55.f));
    this->TomatoTraderCount.setFillColor(sf::Color::White);

    this->traderTomatoAmount.setFont(font);
    this->traderTomatoAmount.setPosition(1050.f, 483.f);
    this->traderTomatoAmount.setCharacterSize(gui::calcCharSize(vm, 55.f));
    this->traderTomatoAmount.setFillColor(sf::Color::White);

    this->CornTraderCount.setFont(font);
    this->CornTraderCount.setPosition(875.f,633.f);
    this->CornTraderCount.setCharacterSize(gui::calcCharSize(vm, 55.f));
    this->CornTraderCount.setFillColor(sf::Color::White);

    this->traderCornAmount.setFont(font);
    this->traderCornAmount.setPosition(1050.f, 633.f);
    this->traderCornAmount.setCharacterSize(gui::calcCharSize(vm, 55.f));
    this->traderCornAmount.setFillColor(sf::Color::White);



    this->traderBackground.setSize(sf::Vector2f(
            static_cast<float>((vm.width)-50),
            static_cast<float>(vm.height)-275)
    );
    this->traderBackground.setPosition(25.f, 25.f);
    this->traderBackground.setFillColor(sf::Color(10, 10, 30, 100));

    Animation* traderButton = new Animation();
    traderButton->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/tradertext000.png", 1,
                                sf::Vector2f(294.f, 88.f));


    this->traderMainBtn = new gui::Button(180.f,957.f,294.f,88.f,
                                          &this->font, "Trader", 2 * gui::calcCharSize(vm),
                                          sf::Color::White,
                                          sf::Color(250, 250, 250, 200),
                                          sf::Color(20, 20, 20, 200),
                                          sf::Color(255, 255, 255, 255),
                                          sf::Color(112, 146, 190, 255),
                                          sf::Color(112, 146, 190, 200),RECTANGLE,1,traderButton

    );
    Animation* backButton = new Animation();
    backButton->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/backButton000.png", 1,
                              sf::Vector2f(294.f, 88.f));
    this->traderBtn["TRADERBACK"]=new gui::Button(1500,800.f, 300.f,125.f,
                                                  &this->font, "Back", 2 * gui::calcCharSize(vm),
                                                  sf::Color(255, 255, 255, 100),
                                                  sf::Color(250, 250, 70, 100),
                                                  sf::Color(200, 200, 200, 100),
                                                  sf::Color(255,255,255,255),
                                                  sf::Color(112, 146, 190, 255),
                                                  sf::Color(112, 146, 190, 200),RECTANGLE,0,backButton
    );
    Animation* sellButton = new Animation();
    sellButton->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/sellbutton000.png", 1,
                              sf::Vector2f(294.f, 88.f));
    this->traderBtn["WHEATSELL"]=new gui::Button(1250.f,330.f,250.f,70.f,
                                                 &this->font, "  WHEATSELL", 2 * gui::calcCharSize(vm),
                                                 sf::Color::Black,
                                                 sf::Color(250, 250, 70, 100),
                                                 sf::Color(20, 20, 20, 100),
                                                 sf::Color(255,255,255,255),
                                                 sf::Color(112, 146, 190, 255),
                                                 sf::Color(112, 146, 190, 200),RECTANGLE,0,sellButton
    );
    this->traderBtn["TOMATOSELL"]=new gui::Button(1250.f,480.f,250.f,70.f,
                                                  &this->font, "  TOMATOSELL", 2 * gui::calcCharSize(vm),
                                                  sf::Color::Black,
                                                  sf::Color(250, 250, 70, 100),
                                                  sf::Color(20, 20, 20, 100),
                                                  sf::Color(255,255,255,255),
                                                  sf::Color(112, 146, 190, 255),
                                                  sf::Color(112, 146, 190, 200),RECTANGLE,0,sellButton
    );
    this->traderBtn["CORNSELL"]=new gui::Button(1250.f,630.f,250.f,70.f,
                                                &this->font, "  CORNSELL", 2 * gui::calcCharSize(vm),
                                                sf::Color::Black,
                                                sf::Color(250, 250, 70, 100),
                                                sf::Color(20, 20, 20, 100),
                                                sf::Color(255,255,255,255),
                                                sf::Color(112, 146, 190, 255),
                                                sf::Color(112, 146, 190, 200),RECTANGLE,0,sellButton
    );
    Animation* increaseButton = new Animation();
    increaseButton->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/plusButton000.png", 1,
                                  sf::Vector2f(294.f, 88.f));
    this->traderBtn["INCREASEWHEAT"]=new gui::Button(1000.f,350.f,50.f,50.f,
                                                     &this->font, "", 2 * gui::calcCharSize(vm),
                                                     sf::Color(255, 255, 255, 100),
                                                     sf::Color(250, 250, 70, 100),
                                                     sf::Color(20, 20, 20, 100),
                                                     sf::Color(255, 255, 255, 255),
                                                     sf::Color(112, 146, 190, 255),
                                                     sf::Color(112, 146, 190, 255),RECTANGLE,0,increaseButton
    );
    this->traderBtn["INCREASETOMATO"]=new gui::Button(1000.f,500.f,50.f,50.f,
                                                      &this->font, "", 2 * gui::calcCharSize(vm),
                                                      sf::Color(255, 255, 255, 100),
                                                      sf::Color(250, 250, 70, 100),
                                                      sf::Color(20, 20, 20, 100),
                                                      sf::Color(255, 255, 255, 255),
                                                      sf::Color(112, 146, 190, 255),
                                                      sf::Color(112, 146, 190, 255),RECTANGLE,0,increaseButton
    );
    this->traderBtn["INCREASECORN"]=new gui::Button(1000.f,650.f,50.f,50.f,
                                                    &this->font, "", 2 * gui::calcCharSize(vm),
                                                    sf::Color(255, 255, 255, 100),
                                                    sf::Color(250, 250, 70, 100),
                                                    sf::Color(20, 20, 20, 100),
                                                    sf::Color(255, 255, 255, 255),
                                                    sf::Color(112, 146, 190, 255),
                                                    sf::Color(112, 146, 190, 255),RECTANGLE,0,increaseButton
    );
    Animation* decreaseButton = new Animation();
    decreaseButton->loadAnimation("../Resources/Images/Gui_images/Warehouse_image/minusButton000.png", 1,
                                  sf::Vector2f(294.f, 88.f));
    this->traderBtn["DECREASEWHEAT"]=new gui::Button(750.f,350.f,50.f,50.f,
                                                     &this->font, "", 2 * gui::calcCharSize(vm),
                                                     sf::Color(255, 255, 255, 100),
                                                     sf::Color(250, 250, 70, 100),
                                                     sf::Color(20, 20, 20, 100),
                                                     sf::Color(255, 255, 255, 255),
                                                     sf::Color(112, 146, 190, 255),
                                                     sf::Color(112, 146, 190, 255),RECTANGLE,0,decreaseButton
    );
    this->traderBtn["DECREASETOMATO"]=new gui::Button(750.f,500.f,50.f,50.f,
                                                      &this->font, "", 2 * gui::calcCharSize(vm),
                                                      sf::Color(255, 255, 255, 100),
                                                      sf::Color(250, 250, 70, 100),
                                                      sf::Color(20, 20, 20, 100),
                                                      sf::Color(255, 255, 255, 255),
                                                      sf::Color(112, 146, 190, 255),
                                                      sf::Color(112, 146, 190, 255),RECTANGLE,0,decreaseButton
    );
    this->traderBtn["DECREASECORN"]=new gui::Button(750.f,650.f,50.f,50.f,
                                                    &this->font, "", 2 * gui::calcCharSize(vm),
                                                    sf::Color(255, 255, 255, 100),
                                                    sf::Color(250, 250, 70, 100),
                                                    sf::Color(20, 20, 20, 100),
                                                    sf::Color(255, 255, 255, 255),
                                                    sf::Color(112, 146, 190, 255),
                                                    sf::Color(112, 146, 190, 255),RECTANGLE,0,decreaseButton
    );
}


PlayerGUI::PlayerGUI( sf::VideoMode& vm,StateData* state_data)
	:	vm(vm)
{
    this->stateData=state_data;
    this->initFont();
    this->initFields(vm);
    this->initPlayer(vm);
    this->initTimer(vm);
    this->initMoney(vm);
    this->initUpgrade(vm);
    this->initWarehouse(vm);
    this->initFarmName(vm);
    this->initTrader(vm);
    this->initEvent(vm);
    this->initMission(vm);

    Alertdialog= new AlertDialog(this->stateData->gfxSettings->resolution, this->font);
    this->Alertdialog->addButton("OK", gui::p2pY(55.f, vm), gui::p2pX(10.f, vm), gui::p2pY(5.f, vm), gui::calcCharSize(vm), "OK");


    AlertDialogUpgrade= new AlertDialog(this->stateData->gfxSettings->resolution, this->font);
    this->AlertDialogUpgrade->addButton("OK", gui::p2pY(50.f, vm), gui::p2pX(10.f, vm), gui::p2pY(5.f, vm), gui::calcCharSize(vm), "OK");
    this->AlertDialogUpgrade->addButton("BACK", gui::p2pY(55.f, vm), gui::p2pX(10.f, vm), gui::p2pY(5.f, vm), gui::calcCharSize(vm), "BACK");
    AlertDialogUpgrade->setAlert_text("Do you approve upgrades?");
    updateFieldAnim();

}


PlayerGUI::~PlayerGUI()
{


}

//	Functions
void PlayerGUI::updateFieldAnim(){
    for (int fieldIndex = 0; fieldIndex < 9; fieldIndex++) {
        if (!this->stateData->farm->getField(fieldIndex)->getUnlock()) {
            if (!this->stateData->farm->getField(fieldIndex)->isUsable()) {
                if (this->stateData->farm->getField(fieldIndex)->getIsGrow()) {
                    if (this->stateData->farm->getField(fieldIndex)->getIsDecay()) {
                        FieldAnim[std::to_string(fieldIndex)]->loadAnimation(location + "decay000" + extension, 1,
                                                                             sf::Vector2f(800, 800));
                    } else {
                        FieldAnim[std::to_string(fieldIndex)]->loadAnimation(location + this->stateData->farm->getField(
                                                                                 fieldIndex)->getProductTypeString(
                                                                                 this->stateData->farm->getField(fieldIndex)->getPlantProduct()->getProductType()) +
                                                                             "harvest000" + extension, 1,
                                                                             sf::Vector2f(800, 800));
                    }
                } else {
                    FieldAnim[std::to_string(fieldIndex)]->loadAnimation(location + this->stateData->farm->getField(
                            fieldIndex)->getProductTypeString(
                            this->stateData->farm->getField(fieldIndex)->getPlantProduct()->getProductType()) +
                                                                         "plant000" + extension, 1, sf::Vector2f(800, 800));
                }
            } else {
                FieldAnim[std::to_string(fieldIndex)]->loadAnimation(location + "field000" + extension, 1,
                                                                     sf::Vector2f(800, 800));
            }
        } else {
            FieldAnim[std::to_string(fieldIndex)]->loadAnimation(location + "lockfield000" + extension, 1,
                                                                 sf::Vector2f(800, 800));
        }
    }
}

void PlayerGUI::updateGui() {

    for (int fieldIndex = 0; fieldIndex < 9; fieldIndex++) {
        if (this->fields[std::to_string(fieldIndex)]->isPressed()) {
            if (!this->stateData->farm->getField(fieldIndex)->getUnlock()) {
                if (this->stateData->farm->getField(fieldIndex)->isUsable()) {
                    plantProductRender=true;
                    plantProductRender_count=fieldIndex;
                    traderIsOpen=false;
                    upgradeIsOpen=false;
                 }else{
                    if (this->stateData->farm->getField(fieldIndex)->getIsGrow()) {
                        if(!this->stateData->farm->getField(fieldIndex)->harvest(
                                this->stateData->farm->getField(fieldIndex)->getPlantProduct(),
                                this->stateData->farm->getWarehouse(), this->stateData->player->getMission(),
                                this->stateData->gameInfo, this->stateData->soundManager)){ alertIsActive=true;
                            Alertdialog->setAlert_text("Warehouse is full!");
                        }else{
                            updateFieldAnim();
                        }
                    }else{
                        alertIsActive=true;
                        Alertdialog->setAlert_text("The crop is still not growed.");
                    }
                }
            }
             sf::sleep(sf::milliseconds(60.f));
        }
    }

    if(plantProductRender){
        if(this->products["wheat"]->isPressed()){
            if(!this->stateData->farm->getField(plantProductRender_count)->plant(this->stateData->farm->getProduct(WHEAT), this->stateData->player,
                                                                                 this->stateData->player->getMission(), this->stateData->gameInfo)){
                traderIsOpen=true;
                upgradeIsOpen=true;
                plantProductRender=false;
                progressCheck[plantProductRender_count]=true;
                updateFieldAnim();
                this->fieldProgress[to_string(plantProductRender_count)]->setInnerColor(sf::Color::Yellow);
                this->fieldProgress[to_string(plantProductRender_count)]->setMaxValue(
                        this->stateData->farm->getProduct(WHEAT)->getHarvestTime());
                sf::sleep(sf::milliseconds(60.f));
            }else{
                alertIsActive=true;
                Alertdialog->setAlert_text("You do not enough money!");
            }
        }
        else if(this->products["corn"]->isPressed()){
            if(!this->stateData->farm->getField(plantProductRender_count)->plant(this->stateData->farm->getProduct(CORN), this->stateData->player,
                                                                                 this->stateData->player->getMission(), this->stateData->gameInfo)){
                traderIsOpen=true;
                upgradeIsOpen=true;
                plantProductRender=false;
                progressCheck[plantProductRender_count]=true;
                updateFieldAnim();
                this->fieldProgress[to_string(plantProductRender_count)]->setInnerColor(sf::Color::Yellow);
                this->fieldProgress[to_string(plantProductRender_count)]->setMaxValue(
                        this->stateData->farm->getProduct(CORN)->getHarvestTime());
                sf::sleep(sf::milliseconds(60.f));
            }else{
                alertIsActive=true;
                Alertdialog->setAlert_text("You do not enough money!");
            }
        }
        else if(this->products["tomato"]->isPressed()){
            if(!this->stateData->farm->getField(plantProductRender_count)->plant(this->stateData->farm->getProduct(TOMATO), this->stateData->player,
                                                                                 this->stateData->player->getMission(), this->stateData->gameInfo)){
                traderIsOpen=true;
                upgradeIsOpen=true;
                plantProductRender=false;
                updateFieldAnim();
                progressCheck[plantProductRender_count]=true;
                this->fieldProgress[to_string(plantProductRender_count)]->setInnerColor(sf::Color::Yellow);
                this->fieldProgress[to_string(plantProductRender_count)]->setMaxValue(
                        this->stateData->farm->getProduct(TOMATO)->getHarvestTime());
                sf::sleep(sf::milliseconds(60.f));
            }else{
                alertIsActive=true;
                Alertdialog->setAlert_text("You do not enough money!");
            }
        }
        else if(this->products["back"]->isPressed()){
            traderIsOpen=true;
            upgradeIsOpen=true;
            plantProductRender=false;
            sf::sleep(sf::milliseconds(60.f));
        }

    }
}

void PlayerGUI::updateMoney() {
    this->Money_text.setString(std::to_string(this->stateData->player->getMoney()));
}

void PlayerGUI::updateWarehouse() {
    this->WheatPieceAndCapacity.setString(std::to_string(this->stateData->farm->getWarehouse()->getPiece(WHEAT)) + "/" + std::to_string(
            this->stateData->farm->getWarehouse()->getCapacity()));
    this->TomatoPieceAndCapacity.setString(std::to_string(this->stateData->farm->getWarehouse()->getPiece(TOMATO)) + "/" + std::to_string(
            this->stateData->farm->getWarehouse()->getCapacity()));
    this->CornPieceAndCapacity.setString(std::to_string(this->stateData->farm->getWarehouse()->getPiece(CORN)) + "/" + std::to_string(
            this->stateData->farm->getWarehouse()->getCapacity()));
}

void PlayerGUI::updateTimer() {
    string a="";
    string b="";
    if(this->stateData->player->getTimer()->getMinutes() < 10){
        a="0"+std::to_string(this->stateData->player->getTimer()->getMinutes());
    }
    else{
        a=std::to_string(this->stateData->player->getTimer()->getMinutes());
    }
    if(this->stateData->player->getTimer()->getSeconds() < 10){
        b="0"+std::to_string(this->stateData->player->getTimer()->getSeconds());
    }else{
        b= std::to_string(this->stateData->player->getTimer()->getSeconds());
    }

    this->timer_Text.setString(a+":"+b);
}

void PlayerGUI::updateTrader() {
    this->WheatTraderCount.setString((std::to_string(this->stateData->trader->getAmount(0))));
    this->TomatoTraderCount.setString((std::to_string(this->stateData->trader->getAmount(1))));
    this->CornTraderCount.setString((std::to_string(this->stateData->trader->getAmount(2))));

    this->traderWheatAmount.setString(std::to_string(this->stateData->trader->getAmount(0) * this->stateData->farm->getProduct(WHEAT)->getSell()));
    this->traderTomatoAmount.setString(std::to_string(this->stateData->trader->getAmount(1) * this->stateData->farm->getProduct(TOMATO)->getSell()));
    this->traderCornAmount.setString(std::to_string(this->stateData->trader->getAmount(2) * this->stateData->farm->getProduct(CORN)->getSell()));
    if(traderClick){
        if(this->traderBtn["INCREASEWHEAT"]->isPressed()){
            if(this->stateData->trader->getAmount(0)< this->stateData->farm->getWarehouse()->getPiece(WHEAT))
                this->stateData->trader->setAmount(this->stateData->trader->getAmount(0)+5,0);
        }if(this->traderBtn["DECREASEWHEAT"]->isPressed()){
            if(!this->stateData->trader->getAmount(0)<=0)
                this->stateData->trader->setAmount(this->stateData->trader->getAmount(0)-5,0);
        }if(this->traderBtn["INCREASETOMATO"]->isPressed()){
            if(this->stateData->trader->getAmount(1)< this->stateData->farm->getWarehouse()->getPiece(TOMATO))
                this->stateData->trader->setAmount(this->stateData->trader->getAmount(1)+5,1);
        }if(this->traderBtn["DECREASETOMATO"]->isPressed()){
            if(!this->stateData->trader->getAmount(1)<=0)
                this->stateData->trader->setAmount(this->stateData->trader->getAmount(1)-5,1);
        }if(this->traderBtn["INCREASECORN"]->isPressed()){
            if(this->stateData->trader->getAmount(2)< this->stateData->farm->getWarehouse()->getPiece(CORN))
                this->stateData->trader->setAmount(this->stateData->trader->getAmount(2)+5,2);
        }if(this->traderBtn["DECREASECORN"]->isPressed()){
            if(!this->stateData->trader->getAmount(2)<=0)
                this->stateData->trader->setAmount(this->stateData->trader->getAmount(2)-5,2);
        }if(this->traderBtn["WHEATSELL"]->isPressed()){
            this->stateData->trader->sell(0, WHEAT, this->stateData->player->getMission(), this->stateData->gameInfo, this->stateData->soundManager);
            this->stateData->trader->setAmount(0,0);
        }if(this->traderBtn["TOMATOSELL"]->isPressed()){
            this->stateData->trader->sell(1, TOMATO, this->stateData->player->getMission(), this->stateData->gameInfo, this->stateData->soundManager);
            this->stateData->trader->setAmount(0,1);
        }if(this->traderBtn["CORNSELL"]->isPressed()){
            this->stateData->trader->sell(2, CORN, this->stateData->player->getMission(), this->stateData->gameInfo, this->stateData->soundManager);
            this->stateData->trader->setAmount(0,2);
        }if(this->traderBtn["TRADERBACK"]->isPressed()){
            traderMainBtn->update(sf::Vector2i (0,0));
            traderClick=false;
            traderIsOpen=true;
            upgradeIsOpen=true;
            fieldClick=true;
            sf::sleep(sf::milliseconds(60.f));
        }
    }
    if(this->traderMainBtn->isPressed()){
        traderClick = true;
        fieldClick=false;
        upgradeIsOpen=false;
        sf::sleep(sf::milliseconds(60.f));
    }
}

void PlayerGUI::updateUpgrade() {
    if(upg->isPressed()){
        alertUpgradeIsActive=true;
        fieldClick=false;
        traderIsOpen=false;
        sf::sleep(sf::milliseconds(60.f));
    }

    Upgrade_text.setString(this->stateData->upgrade->getUpgradeText());

    if(upgradeActive){
        if(!this->stateData->upgrade->upgradeCapacity(this->stateData->farm,this->stateData->player)) {
            alertUpgradeIsActive=false;
            alertIsActive = true;
            Alertdialog->setAlert_text("You don't have enough requirements.");
        } else {
            this->stateData->soundManager->getUpgradeCompleteSound()->playSound();
        }
        upgradeActive=false;
        updateFieldAnim();
    }
}

sf::Texture* PlayerGUI::checkProductYieldState(Product_type productType){
    if(this->stateData->eventManager->getCurrentEvent()->getYield(productType) < this->stateData->farm->getProduct(productType)->getDefaultYield())
        return &eventDown;
    else if(this->stateData->eventManager->getCurrentEvent()->getYield(productType) > this->stateData->farm->getProduct(productType)->getDefaultYield())
        return &eventUp;
    else
        return &eventNormal;
}

sf::Texture* PlayerGUI::checkProductSellState(Product_type productType){
    if(this->stateData->eventManager->getCurrentEvent()->getSell(productType) < this->stateData->farm->getProduct(productType)->getDefaultSell())
        return &eventDown;
    else if(this->stateData->eventManager->getCurrentEvent()->getSell(productType) > this->stateData->farm->getProduct(productType)->getDefaultSell())
        return &eventUp;
    else
        return &eventNormal;
}

void PlayerGUI::updateProductState(){
    WheatYieldState.setTexture(checkProductYieldState(WHEAT));
    TomatoYieldState.setTexture(checkProductYieldState(TOMATO));
    CornYieldState.setTexture(checkProductYieldState(CORN));

    WheatSellState.setTexture(checkProductSellState(WHEAT));
    TomatoSellState.setTexture(checkProductSellState(TOMATO));
    CornSellState.setTexture(checkProductSellState(CORN));
};

void PlayerGUI::updateEvent() {
    this->Event_text.setString(this->stateData->eventManager->getCurrentEvent()->getEventName());
    this->Event_text_detail.setString("Wheat Yield                                " + to_string(
            this->stateData->eventManager->getCurrentEvent()->getYield(WHEAT)) + "\nTomato Yield                               " + to_string(
            this->stateData->eventManager->getCurrentEvent()->getYield(TOMATO)) + "\nCorn Yield                                   " + to_string(
            this->stateData->eventManager->getCurrentEvent()->getYield(CORN)) + "\nWheat Selling Price                    " + to_string(
            this->stateData->eventManager->getCurrentEvent()->getSell(WHEAT)) + "\nTomato Selling Price                  " + to_string(
            this->stateData->eventManager->getCurrentEvent()->getSell(TOMATO)) + "\nCorn Selling Price                      " + to_string(
            this->stateData->eventManager->getCurrentEvent()->getSell(CORN)));

    string a="";
    string b="";
    if(this->stateData->eventManager->getTimeRemain()/60<10){
        a="0"+std::to_string(this->stateData->eventManager->getTimeRemain()/60);
    }
    else{
        a=std::to_string(this->stateData->eventManager->getTimeRemain()/60);
    }
    if(this->stateData->eventManager->getTimeRemain()%60<10){
        b="0"+std::to_string(this->stateData->eventManager->getTimeRemain()%60);
    }else{
        b= std::to_string(this->stateData->eventManager->getTimeRemain()%60);
    }

    this->Event_timer_text.setString(a+":"+b);

    if(this->stateData->eventManager->UpdateEvents()){
        this->stateData->soundManager->getEventAlertSound()->playSound();
        this->stateData->eventManager->setEventStartTime(this->stateData->player->getTimer()->getCurrentTime());
        eventCounter++;
        int index;
        if(eventCounter % 2 == 1){
            do{
                index= this->stateData->eventManager->chooseRandomEvent();
            }while(index== this->stateData->eventManager->getEventIndex());
        }else{
            index=12;
        }
        this->stateData->eventManager->setCurrentEvent(index);
        this->stateData->eventManager->getCurrentEvent()->setEventTime(
                this->stateData->eventManager->chooseRandomTime());
        this->updateProductState();
        alertIsActive=true;
        Alertdialog->setAlert_text(this->stateData->eventManager->getCurrentEvent()->getEventName() + "\n" +
                                   this->stateData->eventManager->getCurrentEvent()->getEventDetail() );
    }
}

void PlayerGUI::updateFieldProgress() {

    for (int fieldIndex = 0; fieldIndex < 9; fieldIndex++) {
        if(!this->stateData->farm->getField(fieldIndex)->getUnlock()){
            if (!this->stateData->farm->getField(fieldIndex)->isUsable()) {
                if(this->stateData->farm->getField(fieldIndex)->getIsGrow()){
                    if(progressCheck){
                        this->fieldProgress[to_string(fieldIndex)]->setInnerColor(sf::Color::Red);
                        this->fieldProgress[to_string(fieldIndex)]->setMaxValue(
                                this->stateData->farm->getField(fieldIndex)->getPlantProduct()->getDecayTime());
                        progressCheck[plantProductRender_count]=false;
                    }
                    this->fieldProgress[to_string(fieldIndex)]->update(this->stateData->farm->getField(fieldIndex)->getTimeRemind());
                }
                else{
                    this->fieldProgress[to_string(fieldIndex)]->update(this->stateData->farm->getField(fieldIndex)->getTimeRemind());
                }
            }
        }
    }
}

void PlayerGUI::updateFieldState(){
    for (int fieldIndex = 0; fieldIndex < 9; fieldIndex++) {
        if(!this->stateData->farm->getField(fieldIndex)->getUnlock()){
            if(this->stateData->farm->getField(fieldIndex)->Update()){
                updateFieldAnim();
            }
        }
    }
}

void PlayerGUI::updateMission() {
    if(!this->stateData->player->getMission()->areAllMissionsCompleted()){
        if(this->stateData->player->getMission()->completeCurrentMission(this->stateData->soundManager)){
            alertIsActive=true;
            Alertdialog->setAlert_text("       CONGRATULATIONS \n       MISSION " + std::to_string(
                    this->stateData->player->getMission()->getProgress()) + " IS COMPLETED" );
            this->stateData->player->getMission()->startNextMission();
            this->missionProgress->setMaxValue(
                    this->stateData->player->getMission()->getCurrentMission()->getRequirement());
        }
    }else{
        this->stateData->gameInfo->setEndGame();
        cout<<"Game Over";
    }
    this->Mission_text.setString(this->stateData->player->getMission()->getCurrentMission()->getMissionDetail());
    this->missionProgress->update(this->stateData->player->getMission()->getMissionProgress());
    this->progressCount.setString(std::to_string(this->stateData->player->getMission()->getMissionProgress()) + "/" + std::to_string(
            this->stateData->player->getMission()->getCurrentMission()->getRequirement()));

}

void PlayerGUI::updateAlertMenuButtons()
{
    if (this->Alertdialog->isButtonPressed("OK")) {
        alertIsActive=false;
        alertUpgradeIsActive=false;
        sf::sleep(sf::milliseconds(60.f));
    }
}

void PlayerGUI::updateAlertUpgradeButtons(){
    if (this->AlertDialogUpgrade->isButtonPressed("OK")){
        alertUpgradeIsActive=false;
        upgradeActive=true;
        sf::sleep(sf::milliseconds(60.f));
    }
    if(this->AlertDialogUpgrade->isButtonPressed("BACK")){
        traderIsOpen=true;
        fieldClick=true;
        alertUpgradeIsActive=false;
        upgradeActive=false;
        upg->update(sf::Vector2i (0,0));
        sf::sleep(sf::milliseconds(60.f));
    }
}

void PlayerGUI::update(const sf::Vector2i& mousePosWindow)
{
    if(!alertIsActive){
        if(traderIsOpen){
            if (traderClick){
                for (auto &it: this->traderBtn) {
                    it.second->update(mousePosWindow);
                }
            }else{
                traderMainBtn->update(mousePosWindow);
            }
        }
        if(upgradeIsOpen){
            if (!alertUpgradeIsActive) {
                if(this->stateData->upgrade->getUpgradeLevel() != 4)
                upg->update(mousePosWindow);
            }else {
                this->AlertDialogUpgrade->update(mousePosWindow);
                this->updateAlertUpgradeButtons();
            }
        }
        if(fieldClick) {
            for (auto &it : this->products) {
                it.second->update(mousePosWindow);
            }
            if(!plantProductRender){
                for (int i=0;i<9;i++) {
                    if(!this->stateData->farm->getField(i)->getUnlock())
                    this->fields[to_string(i)]->update(mousePosWindow);
                }}
            this->updateGui();
        }
    }else {
        this->Alertdialog->update(mousePosWindow);
        this->updateAlertMenuButtons();
    }


    this->updateMoney();
    this->updateEvent();
    this->updateWarehouse();
    this->updateTimer();
    this->updateTrader();
    this->updateUpgrade();
    this->updateMission();
    this->updateFieldState();
    this->updateFieldProgress();

}

void PlayerGUI::renderEvent(sf::RenderTarget &target) {
    target.draw(EventText);
    target.draw(Event_text);
    target.draw(Event_text_detail);
    target.draw(EventTimer);
    target.draw(Event_timer_text);
    target.draw(WheatYieldState);
    target.draw(TomatoYieldState);
    target.draw(CornYieldState);
    target.draw(WheatSellState);
    target.draw(TomatoSellState);
    target.draw(CornSellState);

}

void PlayerGUI::renderMoney(sf::RenderTarget & target){
    TimerImage.setTexture(timer->getAnim());
    MoneyImage.setTexture(money->getAnim());
    target.draw(this->MoneyText);
    target.draw(this->MoneyImage);
    target.draw(this->Money_text);
}

void PlayerGUI::renderWarehouse(sf::RenderTarget &target) {
    target.draw(this->WheatText);
    target.draw(this->WheatImage);
    target.draw(this->WheatPieceAndCapacity);

    target.draw(this->TomatoText);
    target.draw(this->TomatoImage);
    target.draw(this->TomatoPieceAndCapacity);

    target.draw(this->CornText);
    target.draw(this->CornImage);
    target.draw(this->CornPieceAndCapacity);
}

void PlayerGUI::renderPlayer(sf::RenderTarget &target) {
    target.draw(this->PlayerImage);
    target.draw(this->PlayerText);
    target.draw(this->PlayerName);
    target.draw(this->FarmNameShape);
    target.draw(this->FarmName);
}

void PlayerGUI::renderTimer(sf::RenderTarget &target) {
    target.draw(this->TimerText);
    target.draw(this->timer_Text);
    target.draw(this->TimerImage);
}

void PlayerGUI::renderTrader(sf::RenderTarget &target) {
    target.draw(this->traderBackground);
    target.draw(this->Helper);
    target.draw(this->WheatTrader);
    target.draw(this->TomatoTrader);
    target.draw(this->CornTrader);
    target.draw(this->WheatTraderCount);
    target.draw(this->TomatoTraderCount);
    target.draw(this->CornTraderCount);
    target.draw(this->traderWheatAmount);
    target.draw(this->traderTomatoAmount);
    target.draw(this->traderCornAmount);
}

void PlayerGUI::renderTraderMenu(sf::RenderTarget &target){
    target.draw(this->TraderImage);
    traderMainBtn->render(target);
}

void PlayerGUI::renderMission(sf::RenderTarget &target) {
    target.draw(this->MissionText);
    target.draw(this->Mission_text);
    target.draw(this->progressCount);
    this->missionProgress->render(target);
}

void PlayerGUI::renderUpgrade(sf::RenderTarget &target) {

    target.draw(this->UpgradeText);
    target.draw(this->Upgrade_text);
    upg->render(target);
}

void PlayerGUI::render(sf::RenderTarget & target)
{
    target.draw(this->background);
    for (auto &it : this->fields) {
        it.second->render(target);
    }
    if(plantProductRender){
    for (auto &it : this->products) {
        it.second->render(target);
    }
    }
    for (int fieldIndex=0;fieldIndex<9;fieldIndex++) {
        if(!this->stateData->farm->getField(fieldIndex)->isUsable() && !this->stateData->farm->getField(
                fieldIndex)->getUnlock())
            this->fieldProgress[to_string(fieldIndex)]->render(target);
    }

    this->renderMoney(target);
    this->renderEvent(target);
    this->renderUpgrade(target);
    this->renderMission(target);
    this->renderTraderMenu(target);
    this->renderTimer(target);
    this->renderPlayer(target);
    this->renderWarehouse(target);


    if(traderClick){
        this->renderTrader(target);
        for (auto &it : this->traderBtn) {
            it.second->render(target);
        }
    }
    if(alertIsActive){
        this->Alertdialog->render(target);
    }else if(alertUpgradeIsActive){
        this->AlertDialogUpgrade->render(target);
    }
}










