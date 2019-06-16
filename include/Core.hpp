//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#ifndef __CORE_HPP__
#define __CORE_HPP__

#include <iostream>
#include <map>
#include <irrlicht.h>
#include <SFML/Audio.hpp>
#include "Option.hpp"
#include <thread>

//#include "driverChoice.h"
class Menu;
class Game;
class Core;
class Pause;
class SelectPlayer;
class MyEventReceiver;

class Option;

class Core
{
public:
	Core();
	~Core() = default;
	void run();
	void th();
    void initMenu();

    enum gameState_e {
        mainMenu,
        mainGame,
        mainOptions,
        mainPause,
        mainSelect,
    };

    void menuCase();
    void pauseCase();
    void gameCase();
    void selectCase();
    void optionCase();

    int saveMap(std::vector<std::vector<char>> map, std::vector<irr::core::vector3df> positions);

    //Setters
    void setState(gameState_e state);
    void stopMusic();
    void setIsNew(bool isNew);
    void changeVolume();

    //Getters
    Menu *getMenu();
    Game *getGame();
    Pause *getPause();
    SelectPlayer *getSelect();
    gameState_e getState();
    Option *getOption();
    irr::IrrlichtDevice *getWindow();
    sf::Music *getMusic();
    bool getIsNew();
    void changeRole();

private:
    Menu *_menu;
    Game *_game;
    Pause *_pause;
    SelectPlayer *_select;
    Option *_option;
    gameState_e _state;
    irr::IrrlichtDevice *_window;
    MyEventReceiver *_receiver;
    bool _isNew;
    sf::Music *_music;
};

#include "Game.hpp"
#include "Select.hpp"

#endif