#pragma once


#include "PauseMenu.h"

/**
 * @brief Represents the graphical user interface for the player.
 *
 * The `PlayerGUI` class manages the graphical elements related to the player's interface, including the player's progress, money, timer, missions, and more.
 */
class PlayerGUI
{
private:
    sf::VideoMode& vm;  ///< Reference to the video mode

    sf::Font font;  ///< Font for text rendering
    StateData* stateData;  ///< Pointer to StateData
    // Level element

    AlertDialog* Alertdialog;  ///< Alert dialog for general alerts
    AlertDialog* AlertDialogUpgrade;  ///< Alert dialog for upgrade-related alerts
    bool alertIsActive = false;  ///< Flag for general alert
    bool alertUpgradeIsActive = false;  ///< Flag for upgrade alert

    // Flag for upgrade
    bool upgradeActive = false;  ///< Flag indicating if an upgrade is active
    int eventCounter = 0;  ///< Counter for events

    // Background
    sf::Texture backgroundTexture;  ///< Texture for the background
    sf::RectangleShape background;  ///< Background shape
    sf::RectangleShape traderBackground;  ///< Background shape for the trader screen

    // Trader Screen Images, Text
    sf::RectangleShape WheatTrader;  ///< Shape representing the wheat trader
    sf::Texture WheatTraderTexture;  ///< Texture for the wheat trader
    sf::Text WheatTraderCount;  ///< Text displaying wheat trader count
    sf::RectangleShape TomatoTrader;  ///< Shape representing the tomato trader
    sf::Texture TomatoTraderTexture;  ///< Texture for the tomato trader
    sf::Text TomatoTraderCount;  ///< Text displaying tomato trader count
    sf::RectangleShape CornTrader;  ///< Shape representing the corn trader
    sf::Texture CornTraderTexture;  ///< Texture for the corn trader
    sf::Text CornTraderCount;  ///< Text displaying corn trader count

    sf::Text progressCount;  ///< Text displaying progress count

    bool fieldClick = true;  ///< Flag for field click
    bool traderIsOpen = true;  ///< Flag for trader screen
    bool upgradeIsOpen = true;  ///< Flag for upgrade screen

    bool plantProductRender = false;  ///< Flag for rendering planted products
    int plantProductRender_count = 0;  ///< Counter for rendering planted products
    bool traderClick = false;  ///< Flag for trader click

    std::map<std::string, Animation*> FieldAnim;  ///< Map of field animations

    // Shapes
    sf::RectangleShape MoneyText;  ///< Shape for money text
    sf::RectangleShape MoneyImage;  ///< Shape for money image
    sf::RectangleShape TimerText;  ///< Shape for timer text
    sf::RectangleShape TimerImage;  ///< Shape for timer image
    sf::RectangleShape FarmNameShape;  ///< Shape for farm name
    sf::RectangleShape MissionText;  ///< Shape for mission text
    sf::RectangleShape CornText;  ///< Shape for corn text
    sf::RectangleShape CornImage;  ///< Shape for corn image
    sf::RectangleShape TomatoText;  ///< Shape for tomato text
    sf::RectangleShape TomatoImage;  ///< Shape for tomato image
    sf::RectangleShape WheatText;  ///< Shape for wheat text
    sf::RectangleShape WheatImage;  ///< Shape for wheat image
    sf::RectangleShape TraderText;  ///< Shape for trader text
    sf::RectangleShape TraderImage;  ///< Shape for trader image
    sf::RectangleShape PlayerText;  ///< Shape for player text
    sf::RectangleShape PlayerImage;  ///< Shape for player image
    sf::RectangleShape PlayerLevel;  ///< Shape for player level
    sf::RectangleShape UpgradeText;  ///< Shape for upgrade text
    sf::RectangleShape UpgradeImage;  ///< Shape for upgrade image
    sf::RectangleShape EventText;  ///< Shape for event text
    sf::RectangleShape EventTimer;  ///< Shape for event timer
    sf::RectangleShape Helper;  ///< Shape for helper
    sf::RectangleShape WheatYieldState;  ///< Shape for wheat yield state
    sf::RectangleShape TomatoYieldState;  ///< Shape for tomato yield state
    sf::RectangleShape CornYieldState;  ///< Shape for corn yield state
    sf::RectangleShape WheatSellState;  ///< Shape for wheat sell state
    sf::RectangleShape TomatoSellState;  ///< Shape for tomato sell state
    sf::RectangleShape CornSellState;  ///< Shape for corn sell state

    // Images
    sf::Texture wheatWareTexture;  ///< Texture for wheat warehouse
    sf::Texture wheatWareTextTexture;  ///< Texture for wheat warehouse text
    sf::Texture tomatoWareTexture;  ///< Texture for tomato warehouse
    sf::Texture tomatoWareTextTexture;  ///< Texture for tomato warehouse text
    sf::Texture cornWareTexture;  ///< Texture for corn warehouse
    sf::Texture cornWareTextTexture;  ///< Texture for corn warehouse text
    sf::Texture traderTexture;  ///< Texture for trader
    sf::Texture traderTextTexture;  ///< Texture for trader text
    sf::Texture wheatTraderImage;  ///< Texture for wheat trader image
    sf::Texture tomatoTraderImage;  ///< Texture for tomato trader image
    sf::Texture cornTraderImage;  ///< Texture for corn trader image
    sf::Texture upgradeTextTexture;  ///< Texture for upgrade text
    sf::Texture upgradeTexture;  ///< Texture for upgrade
    sf::Texture missionTextTexture;  ///< Texture for mission text
    sf::Texture missionTexture;  ///< Texture for mission
    sf::Texture moneyTextTexture;  ///< Texture for money text
    sf::Texture moneyTexture;  ///< Texture for money
    sf::Texture timerTextTexture;  ///< Texture for timer text
    sf::Texture timerTexture;  ///< Texture for timer
    sf::Texture playerTextTexture;  ///< Texture for player text
    sf::Texture playerTexture;  ///< Texture for player
    sf::Texture farmNameShapeTextTexture;  ///< Texture for farm name text
    sf::Texture farmNameShapeTexture;  ///< Texture for farm name
    sf::Texture TraderTexture;  ///< Texture for trader
    sf::Texture eventTextTexture;  ///< Texture for event text
    sf::Texture eventTimer;  ///< Texture for event timer
    sf::Texture helper;  ///< Texture for helper
    sf:: Texture FarmerTexture;  ///< Texture for farmer
    sf::Texture eventUp;  ///< Texture for event up
    sf::Texture eventNormal;  ///< Texture for event normal
    sf::Texture eventDown;  ///< Texture for event down

    // Texts
    sf::Text PlayerName;  ///< Text for player name
    sf::Text FarmName;  ///< Text for farm name
    sf::Text timer_Text;  ///< Text for timer
    sf::Text Money_text;  ///< Text for money
    sf::Text Mission_text;  ///< Text for mission
    sf::Text WheatPieceAndCapacity;  ///< Text for wheat piece and capacity
    sf::Text TomatoPieceAndCapacity;  ///< Text for tomato piece and capacity
    sf::Text CornPieceAndCapacity;  ///< Text for corn piece and capacity
    sf::Text Upgrade_text;  ///< Text for upgrade
    sf::Text Event_text;  ///< Text for event
    sf::Text Event_text_detail;  ///< Text for event details
    sf::Text Event_timer_text;  ///< Text for event timer
    sf::Text traderWheatAmount;  ///< Text for trader wheat amount
    sf::Text traderTomatoAmount;  ///< Text for trader tomato amount
    sf::Text traderCornAmount;  ///< Text for trader corn amount

    // Location and extension as String
    std::string location;  ///< String representing location
    std::string extension;  ///< String representing extension

    gui::Button* upg;  ///< Button for upgrade
    gui::Button* traderMainBtn;  ///< Button for main trader
    gui::ProgressBar* missionProgress;  ///< Progress bar for mission progress
    std::map<std::string, gui::Button*> fields;  ///< Map of buttons representing different fields in the game
    std::map<std::string, gui::ProgressBar*> fieldProgress;  ///< Map of progress bars for field progress
    std::map<std::string, gui::Button*> products;  ///< Map of buttons representing various products
    std::map<std::string, gui::Button*> traderBtn;  ///< Map of buttons related to the trader

    // Anim Player GUI Tabs
    Animation *money = new Animation();  ///< Animation for money tab
    Animation *timer = new Animation();  ///< Animation for timer tab
    Animation *upgrade = new Animation();  ///< Animation for upgrade tab

    bool progressCheck[9];  ///< Array of booleans to track progress for progress

    void initFont();  ///< Initializes the font used in the GUI.
    void initEvent(sf::VideoMode &videoMode);  ///< Initializes the event-related GUI elements.
    void initFields(sf::VideoMode &videoMode);  ///< Initializes the field-related GUI elements.
    void initPlayer(sf::VideoMode &videoMode);  ///< Initializes the player-related GUI elements.
    void initTimer(sf::VideoMode &videoMode);  ///< Initializes the timer-related GUI elements.
    void initMoney(sf::VideoMode &videoMode);  ///< Initializes the money-related GUI elements.
    void initMission(sf::VideoMode &videoMode);  ///< Initializes the mission-related GUI elements.
    void initUpgrade(sf::VideoMode &videoMode);  ///< Initializes the upgrade-related GUI elements.
    void initWarehouse(sf::VideoMode &videoMode);  ///< Initializes the Warehouse-related GUI elements.
    void initFarmName(sf::VideoMode &videoMode);  ///< Initializes the farmname-related GUI elements.
    void initTrader(sf::VideoMode &videoMode);  ///< Initializes the Trader-related GUI elements.

public:
    /**
     * @brief Constructor for the PlayerGUI class.
     *
     * This constructor initializes the PlayerGUI with the specified video mode and StateData.
     *
     * @param vm Reference to the video mode of the application window.
     * @param state_data Pointer to the StateData object.
     */
    PlayerGUI(sf::VideoMode& vm, StateData* state_data);

    /**
     * @brief Destructor for the PlayerGUI class.
     *
     * This destructor cleans up dynamically allocated resources.
     */
    virtual ~PlayerGUI();

    /**
     * @brief Updates field progress related to GUI elements.
     *
     * This function updates the graphical elements related to field progress based on the current state of the game.
     */
    void updateFieldProgress();

    /**
     * @brief Checks the yield state of a product.
     *
     * This function checks the yield state of the specified product and returns the corresponding texture.
     *
     * @param productType Type of the product.
     * @return Texture pointer representing the yield state of the product.
     */
    sf::Texture *checkProductYieldState(Product_type productType);

    /**
     * @brief Checks the sell state of a product.
     *
     * This function checks the sell state of the specified product and returns the corresponding texture.
     *
     * @param productType Type of the product.
     * @return Texture pointer representing the sell state of the product.
     */
    sf::Texture *checkProductSellState(Product_type productType);

    /**
     * @brief Updates product states in the GUI.
     *
     * This function updates the graphical representation of product states based on the current state of the game.
     */
    void updateProductState();

    /**
     * @brief Updates event-related GUI elements.
     *
     * This function updates the graphical elements related to events based on the current state of the game.
     */
    void updateEvent();

    /**
     * @brief Updates money-related GUI elements.
     *
     * This function updates the graphical elements related to money based on the current state of the game.
     */
    void updateMoney();

    /**
     * @brief Updates warehouse-related GUI elements.
     *
     * This function updates the graphical elements related to the warehouse based on the current state of the game.
     */
    void updateWarehouse();

    /**
 * @brief Updates timer-related GUI elements.
 *
 * This function updates the graphical elements related to the timer based on the current state of the game.
 */
    void updateTimer();

/**
 * @brief Updates mission-related GUI elements.
 *
 * This function updates the graphical elements related to missions based on the current state of the game.
 */
    void updateMission();

/**
 * @brief Updates trader-related GUI elements.
 *
 * This function updates the graphical elements related to the trader based on the current state of the game.
 */
    void updateTrader();

/**
 * @brief Updates upgrade-related GUI elements.
 *
 * This function updates the graphical elements related to upgrades based on the current state of the game.
 */
    void updateUpgrade();

/**
 * @brief Updates general GUI elements.
 *
 * This function updates the graphical elements related to the general interface based on the current state of the game.
 */
    void updateGui();

/**
 * @brief Updates buttons in the alert menu.
 *
 * This function updates the buttons in the alert menu based on the current state of the game.
 */
    void updateAlertMenuButtons();

/**
 * @brief Updates buttons in the upgrade alert menu.
 *
 * This function updates the buttons in the upgrade alert menu based on the current state of the game.
 */
    void updateAlertUpgradeButtons();

/**
 * @brief Updates field animations.
 *
 * This function updates the animations related to fields based on the current state of the game.
 */
    void updateFieldAnim();

/**
 * @brief Updates field state.
 *
 * This function updates the state of the fields based on the current state of the game.
 */
    void updateFieldState();

/**
 * @brief Updates the GUI based on mouse position.
 *
 * This function updates the graphical interface based on the current mouse position.
 *
 * @param mousePosWindow The mouse position relative to the window.
 */
    void update(const sf::Vector2i& mousePosWindow);

/**
 * @brief Renders warehouse-related GUI elements.
 *
 * This function renders the graphical elements related to the warehouse.
 *
 * @param target The render target.
 */
    void renderWarehouse(sf::RenderTarget &target);

/**
 * @brief Renders event-related GUI elements.
 *
 * This function renders the graphical elements related to events.
 *
 * @param target The render target.
 */
    void renderEvent(sf::RenderTarget &target);

/**
 * @brief Renders player-related GUI elements.
 *
 * This function renders the graphical elements related to the player.
 *
 * @param target The render target.
 */
    void renderPlayer(sf::RenderTarget &target);

/**
 * @brief Renders timer-related GUI elements.
 *
 * This function renders the graphical elements related to the timer.
 *
 * @param target The render target.
 */
    void renderTimer(sf::RenderTarget &target);

/**
 * @brief Renders trader-related GUI elements.
 *
 * This function renders the graphical elements related to the trader.
 *
 * @param target The render target.
 */
    void renderTrader(sf::RenderTarget &target);

/**
 * @brief Renders mission-related GUI elements.
 *
 * This function renders the graphical elements related to missions.
 *
 * @param target The render target.
 */
    void renderMission(sf::RenderTarget &target);

/**
 * @brief Renders upgrade-related GUI elements.
 *
 * This function renders the graphical elements related to upgrades.
 *
 * @param target The render target.
 */
    void renderUpgrade(sf::RenderTarget &target);

/**
 * @brief Renders money-related GUI elements.
 *
 * This function renders the graphical elements related to money.
 *
 * @param target The render target.
 */
    void renderMoney(sf::RenderTarget &target);

/**
 * @brief Renders trader menu.
 *
 * This function renders the graphical elements related to the trader menu.
 *
 * @param target The render target.
 */
    void renderTraderMenu(sf::RenderTarget &target);

/**
 * @brief Renders GUI elements.
 *
 * This function renders the entire graphical user interface.
 *
 * @param target The render target.
 */
    void render(sf::RenderTarget& target);

};
