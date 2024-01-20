cmake_minimum_required(VERSION 3.26)
project(farming)

set(CMAKE_CXX_STANDARD 17)

add_executable(farming cppfiles/main.cpp
        cppfiles/Animation.cpp
        cppfiles/Game.cpp
        cppfiles/Gui.cpp
        cppfiles/GameState.cpp
        cppfiles/PlayerGUI.cpp
        cppfiles/GraphicsSettings.cpp
        cppfiles/MainMenuState.cpp
        cppfiles/PauseMenu.cpp
        cppfiles/ProfileState.cpp
        cppfiles/SettingsState.cpp
        cppfiles/State.cpp
        cppfiles/stdafx.cpp
        cppfiles/field.cpp
        cppfiles/farm.cpp
        cppfiles/EventManager.cpp
        cppfiles/event.cpp
        cppfiles/mission.cpp
        cppfiles/MissionManager.cpp
        cppfiles/player.cpp
        cppfiles/product.cpp
        cppfiles/timer.cpp
        cppfiles/trader.cpp
        cppfiles/upgrade.cpp
        cppfiles/warehouse.cpp
        cppfiles/tutorial.cpp
        cppfiles/AlertDialog.cpp
        cppfiles/EndAndReportScreen.cpp
        cppfiles/GameInfo.cpp
        cppfiles/Sound.cpp
        cppfiles/SoundManager.cpp
        cppfiles/pugixml.cpp
        cppfiles/save.cpp
        cppfiles/CreditState.cpp


)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(farming sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
