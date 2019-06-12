//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#include "Core.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "Pause.hpp"

Core::Core()
{
    this->_window = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080),
                                      16, false, false, false);

    if (!this->_window) {
        std::cerr << "Couldn't open a window" << std::endl;
        return;
    }
    this->_window->setWindowCaption(L"Indie Studio");
    this->_receiver = new MyEventReceiver(this->_window, *this);
    this->_window->setEventReceiver(_receiver);
    this->_state = mainMenu;
    this->_menu = nullptr;
    this->_game = nullptr;
    this->_pause = nullptr;
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

Pause *Core::getPause()
{
    return this->_pause;
}

void Core::run()
{
    while (this->_window->run()) {
        this->_window->getVideoDriver()->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        switch (this->_state) {
            case mainMenu:
                if (!this->_menu)
                    this->_menu = new Menu(this->_window);
                if (this->_game) {
                    for (auto &it : this->_game->getCubes())
                        for (auto &it2 : it) {
                            if (!it2)
                                continue;
                            it2->setVisible(false);
                        }
                    for (auto &it : this->_game->getFloor())
                        for (auto &it2 : it) {
                            if (!it2)
                                continue;
                            it2->setVisible(false);
                        }
                }
                if (this->_menu) {
                    for (auto &it : this->_menu->getButtons())
                        it.second->setVisible(true);
                }
                this->_menu->run(this->_window);
                break;
            case mainGame:
                if (!this->_game) {
                    this->_window->getVideoDriver()->removeAllTextures();
                    this->_game = new Game(this->_window);
                    this->_window->getGUIEnvironment()->clear();
                    delete(this->_menu);
                    this->_menu = nullptr;
                }
                if (this->_menu) {
                    for (auto &it : this->_menu->getButtons())
                        it.second->setVisible(false);
                }
                for (auto &it : this->_game->getCubes())
                    for (auto &it2 : it) {
                        if (!it2)
                            continue;
                        it2->setVisible(true);
                    }
                this->_game->run(this->_window);
                break;
            case mainPause:
                if (!this->_pause)
                    this->_pause = new Pause(this->_window);
                if (this->_game) {
                    for (auto &it : this->_game->getCubes())
                        for (auto &it2 : it) {
                            if (!it2)
                                continue;
                            it2->setVisible(false);
                        }
                }
                this->_pause->run(this->_window);
                break;
            default:
                break;
        }
        this->_window->getSceneManager()->drawAll();
        this->_window->getGUIEnvironment()->drawAll();
        this->_window->getVideoDriver()->endScene();
	}
    this->_window->drop();
}

void Core::initMenu()
{
    //this->_driver->makeColorKeyTexture(this->image, position2d<s32>(0,0));
    //this->_env->addStaticText(L"Transparent Control:", rect<s32>(10, 10, 260, 22), true);
}