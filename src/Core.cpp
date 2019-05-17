//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#include "Core.hpp"

Core::Core(IrrlichtDevice *const window) : _window(window)
{
    this->driver = window->getVideoDriver();
    this->image = this->driver->getTexture("./resources/background.jpg");
    this->button1 = this->driver->getTexture("./resources/EXIT.png");
    this->smgr = window->getSceneManager();
    this->env = window->getGUIEnvironment();
	initMenu();
}

void Core::run()
{
	while (_window->run()) {
	    this->driver->beginScene(true, true, SColor(255, 100, 101, 140));
	    this->driver->draw2DImage(this->image, position2d<s32>(0, 0), rect<s32>(0, 0, 1920, 1080), 0, SColor(255, 255, 255, 255), true);
	    this->driver->draw2DImage(this->button1, position2d<s32>(900, 400), rect<s32>(0, 0, 425, 77), 0, SColor(255, 255, 255, 255), true);
	    this->smgr->drawAll();
        this->env->drawAll();
        this->driver->endScene();
	}
}

void Core::initMenu()
{
    //this->driver->makeColorKeyTexture(this->image, position2d<s32>(0,0));
    //this->env->addStaticText(L"Transparent Control:", rect<s32>(10, 10, 260, 22), true);
}