//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#include "Core.hpp"
#include "Menu.hpp"
#include "Game.hpp"

Core::Core() : _context()
{
    this->_window = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080),
                                      16, false, false, false);

    if (!this->_window) {
        std::cerr << "Couldn't open a window" << std::endl;
        return;
    }
    this->_window->setWindowCaption(L"Indie Studio");
    _context.device = this->_window;
    this->_receiver = new MyEventReceiver(this->_context, *this);
    this->_window->setEventReceiver(_receiver);
    this->_state = mainMenu;
    this->_menu = nullptr;
    this->_game = nullptr;
}

void Core::setState(Core::gameState_e state)
{
    this->_state = state;
}

Core::gameState_e Core::getState()
{
    return this->_state;
}

Game *Core::getGame()
{
    return this->_game;
}

Menu *Core::getMenu()
{
    return this->_menu;
}

void Core::run()
{
    while (this->_window->run()) {
        switch (this->_state) {
            case mainMenu:
                if (!this->_menu)
                    this->_menu = new Menu(this->_window);
                this->_menu->run(this->_window);
                break;
            case mainGame:
                if (!this->_game) {
                    this->_game = new Game(this->_window);
                    this->_window->getVideoDriver()->removeAllTextures();
                    this->_window->getGUIEnvironment()->clear();
                    delete(this->_menu);
                }
                this->_game->run(this->_window);
                break;
            default:
                break;
        }
        this->_window->getSceneManager()->drawAll();
        this->_window->getGUIEnvironment()->drawAll();
        this->_window->getVideoDriver()->endScene();
	}
}

void Core::initMenu()
{
    //this->_driver->makeColorKeyTexture(this->image, position2d<s32>(0,0));
    //this->_env->addStaticText(L"Transparent Control:", rect<s32>(10, 10, 260, 22), true);
}