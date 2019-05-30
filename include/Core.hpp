//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#ifndef __CORE_HPP__
#define __CORE_HPP__

#include <iostream>
#include "irrlicht.h"
//#include "driverChoice.h"

using namespace irr;
using namespace video;
using namespace gui;
using namespace scene;
using namespace io;
using namespace core;

struct SAppContext {
    IrrlichtDevice *device;
};

class Core
{
public:
	Core(IrrlichtDevice *const window);
	~Core(){}
	void run();
    void game();
    IrrlichtDevice *_window;

private:
    IGUIEnvironment *env;
    IVideoDriver *driver;
    ISceneManager *smgr;
    ITexture *image;
    ITexture *button1;
    ITexture *button2;
    ITexture *button3;
    ITexture *button4;
    ITexture *button5;
	void initMenu();
};

class MyEventReceiver : public IEventReceiver
{
public:
    MyEventReceiver(SAppContext &context);
    virtual bool OnEvent(const SEvent &event);
private:
    SAppContext &Context;
};

enum button{
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_PLAY_BUTTON = 102,
    GUI_ID_OPTIONS_BUTTON = 103,
};

#endif