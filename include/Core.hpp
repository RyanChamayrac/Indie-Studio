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

class MyEventReceiver : public irr::IEventReceiver
{
public:
    explicit MyEventReceiver(irr::IrrlichtDevice *window, Core &core) : _window(window), _core(core), _keyIsDown() {};
    bool OnEvent(const irr::SEvent &event) override;
    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
    bool clicks(const irr::SEvent &event);
    bool keyInputs(const irr::SEvent &event);

private:
    irr::IrrlichtDevice *_window;
    Core &_core;
    bool _keyIsDown[irr::KEY_KEY_CODES_COUNT];
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
        mainOptions,
        mainPause
    };

    //Setters
    void setState(gameState_e state);

    //Getters
    Menu *getMenu();
    Game *getGame();
    Pause *getPause();
    gameState_e getState();

private:
    Menu *_menu;
    Game *_game;
    Pause *_pause;
    gameState_e _state;
    irr::IrrlichtDevice *_window;
    MyEventReceiver *_receiver;
};
#endif