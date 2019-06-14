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
//#include "driverChoice.h"
class Menu;
class Game;
class Core;
class Pause;
class SelectPlayer;
class MyEventReceiver;

class Core
{
public:
	Core();
	~Core() = default;
	void run();
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

    //Setters
    void setState(gameState_e state);

    //Getters
    Menu *getMenu();
    Game *getGame();
    Pause *getPause();
    SelectPlayer *getSelect();
    gameState_e getState();
    irr::IrrlichtDevice *getWindow();

private:
    Menu *_menu;
    Game *_game;
    Pause *_pause;
    SelectPlayer *_select;
    gameState_e _state;
    irr::IrrlichtDevice *_window;
    MyEventReceiver *_receiver;
};

#include "Game.hpp"

#endif