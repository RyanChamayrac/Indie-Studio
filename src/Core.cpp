//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#include "Core.hpp"
#include "Menu.hpp"

Core::Core()
{
    this->graphic = new Graphic();
    if (!this->graphic->getWindow())
        return;
    this->receiver = new MyEventReceiver(this->context);
    context.device = this->graphic->getWindow();
    this->graphic->getWindow()->setEventReceiver(receiver);
    this->state = mainMenu;
    this->menu = nullptr;
}

void Core::run()
{
    if (!this->graphic->getWindow())
        return;
    while (this->graphic->getWindow()->run()) {
        switch (this->state) {
            case mainMenu:
                if (!menu)
                    this->menu = new Menu(this->graphic);
                menu->run(this->graphic);
            default:
                break;
        }
        this->state = mainMenu;
        this->graphic->getsmgr()->drawAll();
        this->graphic->getEnv()->drawAll();
        this->graphic->getDriver()->endScene();
	}
}

void Core::initMenu()
{
    //this->_driver->makeColorKeyTexture(this->image, position2d<s32>(0,0));
    //this->_env->addStaticText(L"Transparent Control:", rect<s32>(10, 10, 260, 22), true);
}