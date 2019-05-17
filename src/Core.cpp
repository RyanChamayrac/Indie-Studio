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
    this->smgr = window->getSceneManager();
    this->env = window->getGUIEnvironment();
	initMenu();
}

void Core::run()
{
	while (_window->run()) {
	    this->driver->beginScene(true, true, SColor(255, 100, 101, 140));
	    this->smgr->drawAll();
        this->env->drawAll();
        this->driver->endScene();
	}
}

void Core::initMenu()
{
    this->env->addStaticText(L"Transparent Control:", rect<s32>(10, 10, 260, 22), true);
}