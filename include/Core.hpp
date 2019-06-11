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

class MyEventReceiver : public irr::IEventReceiver
{
public:
    explicit MyEventReceiver(irr::IrrlichtDevice *window, Core &core) : _window(window), _core(core) {};
    bool OnEvent(const irr::SEvent &event) override;
private:

    irr::IrrlichtDevice *_window;
    Core &_core;
};


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
        mainOptions
    };

    //Setters
    void setState(gameState_e state);

    //Getters
    Menu *getMenu();
    Game *getGame();
    gameState_e getState();

private:
    Menu *_menu;
    Game *_game;
    gameState_e _state;
    irr::IrrlichtDevice *_window;
    MyEventReceiver *_receiver;
};
#endif