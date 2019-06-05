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
	Core();
	~Core() = default;
	void run();
    void game();

    //Loaders
    void loadTextures();
    void loadButtons();

private:
    IrrlichtDevice *_window;
    IGUIEnvironment *_env;
    IVideoDriver *_driver;
    ISceneManager *_smgr;
    std::map<std::string, ITexture *> _textures;
    std::map<std::string, IGUIButton *> _buttons;
	void initMenu();
};

class MyEventReceiver : public IEventReceiver
{
public:
    MyEventReceiver(SAppContext &context);
    virtual bool OnEvent(const SEvent &event);
private:
    SAppContext &_Context;
};

enum button{
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_PLAY_BUTTON = 102,
    GUI_ID_OPTIONS_BUTTON = 103,
};

#endif