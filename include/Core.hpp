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
#include "Graphic.hpp"
//#include "driverChoice.h"

/*
using namespace irr;
using namespace video;
using namespace gui;
using namespace scene;
using namespace io;
using namespace core;
*/

class Menu;

struct SAppContext {
    irr::IrrlichtDevice *device;
};

class MyEventReceiver : public irr::IEventReceiver
{
public:
    explicit MyEventReceiver(SAppContext &context);
    bool OnEvent(const irr::SEvent &event) override;
private:
    SAppContext &_Context;
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

private:
    Menu *menu;
    gameState_e state;
    Graphic *graphic;
    SAppContext context;
    MyEventReceiver *receiver;
};
#endif