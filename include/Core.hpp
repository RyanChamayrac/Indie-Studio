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

struct SAppContext {
    irr::IrrlichtDevice *device;
};


class MyEventReceiver : public irr::IEventReceiver
{
public:
    explicit MyEventReceiver(SAppContext &context, Core &core) : _Context(context), _core(core) {};
    bool OnEvent(const irr::SEvent &event) override;
private:
    SAppContext &_Context;
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
    SAppContext _context{};
    MyEventReceiver *_receiver;
};
#endif