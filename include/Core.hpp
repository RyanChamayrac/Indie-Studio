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

using namespace irr;
using namespace video;
using namespace gui;
using namespace scene;
using namespace io;
using namespace core;

class Core
{
public:
	Core(IrrlichtDevice *const window);
	~Core(){}
	void run();

private:
	IrrlichtDevice *_window;
    IGUIEnvironment *env;
    IVideoDriver *driver;
    ISceneManager *smgr;
    ITexture *image;
    ITexture *button1;
    ITexture *button2;
    ITexture *button3;
	void initMenu();
};

#endif