#include "GraphicsSettings.h"
#include "EventManager.h"


class StateData;
class GraphicsSettings;
class State;

/**
 * @brief Represents the shared data between different game states.
 *
 * The `StateData` class holds various pointers to game-related data, such as player information, trader data, upgrade data, and more.
 */
class StateData {
public:
    /**
     * @brief Constructor for the `StateData` class.
     *
     * This constructor initializes the `StateData` with default values.
     */
    StateData();

    // Variables
    float gridSize;                ///< Size of the grid

    // Pointers to various game data
    GameInfo* gameInfo;             ///< Pointer to GameInfo object
    player* player;                 ///< Pointer to player object
    trader* trader;                 ///< Pointer to trader object
    upgrade* upgrade;               ///< Pointer to upgrade object
    farm* farm;                     ///< Pointer to farm object
    EventManager* eventManager;     ///< Pointer to EventManager object
    SoundManager* soundManager;     ///< Pointer to SoundManager object

    sf::RenderWindow* window;       ///< Pointer to the game window
    GraphicsSettings* gfxSettings;  ///< Pointer to GraphicsSettings object

    std::map<std::string, int>* supportedKeys;  ///< Pointer to supported keys map

    std::stack<State*>* states;     ///< Pointer to the stack of game states
};
/**
 * @brief Represents the base class for different game states.
 *
 * The `State` class provides basic functionality for game states, such as handling keybindings, mouse positions, and resource management.
 */
class State
{
private:

protected:
    StateData* stateData;               ///< Pointer to shared game data
    std::stack<State*>* states;         ///< Pointer to the stack of game states

    sf::RenderWindow* window;           ///< Pointer to the game window
    std::map<std::string, int>* supportedKeys;  ///< Pointer to supported keys map
    std::map<std::string, int> keybinds; ///< Map to hold key bindings

    bool quit;                          ///< Flag to indicate if the state should quit
    bool paused;                        ///< Flag to indicate if the state is paused

    float keytime;                      ///< Current key time
    float keytimeMax;                   ///< Maximum key time
    float gridSize;                     ///< Size of the grid

    sf::Vector2i mousePosScreen;        ///< Mouse position relative to the screen
    sf::Vector2i mousePosWindow;        ///< Mouse position relative to the window
    sf::Vector2f mousePosView;          ///< Mouse position relative to the view
    sf::Vector2i mousePosGrid;          ///< Mouse position relative to the grid

    /**
     * @brief Resources: Map to store textures.
     *
     */
    std::map<std::string, sf::Texture> textures;

public:
    /**
     * @brief Constructor for the `State` class.
     *
     * This constructor initializes the `State` with shared game data.
     *
     * @param state_data Pointer to the shared game data.
     */
    State(StateData* state_data);

    /**
     * @brief Destructor for the `State` class.
     *
     * This destructor cleans up dynamically allocated resources.
     */
    virtual ~State();

    // Accessors
    /**
     * @brief Returns the quit flag.
     *
     * @return Boolean value indicating whether the state should quit.
     */
    const bool& getQuit() const;

    /**
     * @brief Returns the key time flag.
     *
     * @return Boolean value indicating key time.
     */
    const bool getKeytime();

    /**
     * @brief Ends the current state.
     *
     * This function sets the quit flag to true, indicating that the current state should end.
     */
    void endState();

    /**
     * @brief Pauses the current state.
     *
     * This function sets the paused flag to true, indicating that the current state is paused.
     */
    void pauseState();

    /**
     * @brief Unpauses the current state.
     *
     * This function sets the paused flag to false, indicating that the current state is unpaused.
     */
    void unpauseState();

    /**
     * @brief Updates mouse positions.
     *
     * This function updates the mouse positions relative to the view, window, and grid.
     *
     * @param view Pointer to the SFML view.
     */
    virtual void updateMousePositions(sf::View* view = NULL);

    /**
     * @brief Updates key time.
     *
     * This function updates the key time based on the elapsed time.
     *
     * @param dt Elapsed time.
     */
    virtual void updateKeytime(const float& dt);

    /**
     * @brief Updates input handling.
     *
     * This pure virtual function should be implemented in derived classes to handle input updates.
     *
     * @param dt Elapsed time.
     */
    virtual void updateInput(const float& dt) = 0;

    /**
     * @brief Updates the state.
     *
     * This pure virtual function should be implemented in derived classes to handle state updates.
     *
     * @param dt Elapsed time.
     */
    virtual void update(const float& dt) = 0;

    /**
     * @brief Renders the state.
     *
     * This pure virtual function should be implemented in derived classes to handle state rendering.
     *
     * @param target Pointer to the render target.
     */
    virtual void render(sf::RenderTarget* target = NULL) = 0;
};


