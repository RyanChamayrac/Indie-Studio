//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#include <Option.hpp>
#include "Core.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "Pause.hpp"
#include "Select.hpp"
#include "MyEventReceiver.hpp"

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
    this->_select = nullptr;
    this->_option = nullptr;
    this->_isNew = false;
    this->_music = new sf::Music;
}

void Core::stopMusic()
{
    if (this->getMusic()->getStatus() == 2) {
        this->getMusic()->pause();
        this->getOption()->getButtons()["mute"]->setImage(this->getOption()->getTextures()["muted"]);
    } else if (this->getMusic()->getStatus() == 1) {
        this->getMusic()->play();
        this->getOption()->getButtons()["mute"]->setImage(this->getOption()->getTextures()["mute"]);
    }
}

void Core::changeVolume()
{
    this->getMusic()->setVolume(this->getOption()->getScrollBars()["volume"]->getPos());
}

sf::Music *Core::getMusic()
{
    return this->_music;
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

Option *Core::getOption()
{
    return this->_option;
}

Menu *Core::getMenu()
{
    return this->_menu;
}

Pause *Core::getPause()
{
    return this->_pause;
}

SelectPlayer *Core::getSelect()
{
    return this->_select;
}

irr::IrrlichtDevice * Core::getWindow()
{
    return this->_window;
}

bool Core::getIsNew()
{
    return this->_isNew;
}

void Core::setIsNew(bool isNew)
{
    this->_isNew = isNew;
}

int Core::saveMap(std::vector<std::vector<char>> map, std::vector<irr::core::vector3df> positions)
{
    std::ofstream file;
    file.open ("assets/map/map.txt");

    map[static_cast<int>(-round(positions[0].Y) / 2)][static_cast<int>(round(positions[0].X) / 2)] = ',';
    map[static_cast<int>(-round(positions[1].Y) / 2)][static_cast<int>(round(positions[1].X) / 2)] = ';';
    map[static_cast<int>(-round(positions[2].Y) / 2)][static_cast<int>(round(positions[2].X) / 2)] = ':';
    map[static_cast<int>(-round(positions[3].Y) / 2)][static_cast<int>(round(positions[3].X) / 2)] = '!';
    for (auto &it : map) {
        for (auto &it2 : it) {
            std::cout << it2;
            if (it2 == 'e')
                file << 'x';
            else
                file << it2;
        }
        file << "\n";
    }
    file.close();
    return 1;
}

void Core::menuCase()
{
    if (!this->_menu)
        this->_menu = new Menu(this->_window);
    if (this->_game) {
        this->_window->getSceneManager()->clear();
        delete(this->_game);
        this->_game = nullptr;
    }
    if (this->_select) {
        for (auto &it : this->_select->getButtons())
            it.second->setVisible(false);
    }
    if (this->_pause) {
        for (auto &it : this->_pause->getButtons())
            it.second->setVisible(false);
    }
    if (this->_option) {
        for (auto &it : this->_option->getButtons())
            it.second->setVisible(false);
        for (auto &it : this->_option->getScrollBars())
            it.second->setVisible(false);
    }
    for (auto &it : this->_menu->getButtons())
        it.second->setVisible(true);
    this->_menu->run(this->_window);
}

void Core::gameCase()
{
    std::vector<std::vector<int>> IA = {{0, 1}, {1, 0}, {1, 0}, {1, 0}};
    if (!this->_game) {
        if (this->_select)
            this->_game = new Game(this->_window, this->_isNew, this->_select->getNbRole());
        else
            this->_game = new Game(this->_window, this->_isNew, IA);
    }
    if (this->_menu) {
        for (auto &it : this->_menu->getButtons())
            it.second->setVisible(false);
    }
    if (this->_pause) {
        for (auto &it : this->_pause->getButtons())
            it.second->setVisible(false);
    }
    if (this->_select) {
        for (auto &it : this->_select->getButtons())
            it.second->setVisible(false);
    }
    for (auto &it : this->_game->getCubes())
        for (auto &it2 : it) {
            if (!it2)
                continue;
            it2->setVisible(true);
        }
    for (auto &it : this->_game->getFloor())
        for (auto &it2 : it) {
            if (!it2)
                continue;
            it2->setVisible(true);
        }
    for (auto &it : this->_game->getPlayers())
        if (it->getIsAlive())
            it->getNode()->setVisible(true);
    this->_game->run(this->_window);
}

void Core::pauseCase()
{
    if (!this->_pause)
        this->_pause = new Pause(this->_window);
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
    for (auto &it : this->_pause->getButtons())
            it.second->setVisible(true);
    for (auto &it : this->_game->getPlayers()) {
        it->getNode()->setVisible(false);
        if (it->getBombCube().second)
            it->getBombCube().second->setVisible(false);
    }
    this->_pause->run(this->_window);
}

void Core::selectCase()
{
    if(!this->_select)
        this->_select = new SelectPlayer(this->_window);
    for (auto &it : this->_menu->getButtons())
        it.second->setVisible(false);
    for (auto &it : this->_select->getButtons())
        it.second->setVisible(true);
    this->_select->run(this->_window);
}

void Core::optionCase()
{
    if(!this->_option)
        this->_option = new Option(this->_window);
    for (auto &it : this->_menu->getButtons())
        it.second->setVisible(false);
    for (auto &it : this->_option->getButtons())
        it.second->setVisible(true);
    this->_option->run(this->_window);
}

void Core::run()
{
    if (!this->getMusic()->openFromFile("assets/bomber_music.ogg"))
        return;
    this->getMusic()->play();
    while (this->_window->run()) {
        this->_window->getVideoDriver()->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        switch (this->_state) {
            case mainMenu:
                this->menuCase();
                break;
            case mainSelect:
                this->selectCase();
                break;
            case mainGame:
                this->gameCase();
                break;
            case mainPause:
                this->pauseCase();
                break;
            case mainOptions:
                this->optionCase();
                break;
            default:
                break;
        }
        if (this->_receiver->IsKeyDown(irr::KEY_ESCAPE)) {
            this->setState(Core::mainPause);
        } if ((this->_receiver->IsKeyDown(irr::KEY_KEY_Z) || this->_receiver->IsKeyDown(irr::KEY_UP)) && this->getGame()) {
            if (this->_receiver->IsKeyDown(irr::KEY_KEY_Z))
                this->getGame()->getPlayers()[0]->MoveUp();
            else
                this->getGame()->getPlayers()[1]->MoveUp();
        } if ((this->_receiver->IsKeyDown(irr::KEY_KEY_D) || this->_receiver->IsKeyDown(irr::KEY_RIGHT)) && this->getGame()) {
            if (this->_receiver->IsKeyDown(irr::KEY_KEY_D))
                this->getGame()->getPlayers()[0]->MoveRight();
            else
                this->getGame()->getPlayers()[1]->MoveRight();
        } if ((this->_receiver->IsKeyDown(irr::KEY_KEY_Q) || this->_receiver->IsKeyDown(irr::KEY_LEFT)) && this->getGame()) {
            if (this->_receiver->IsKeyDown(irr::KEY_KEY_Q))
                this->getGame()->getPlayers()[0]->MoveLeft();
            else
                this->getGame()->getPlayers()[1]->MoveLeft();
        } if ((this->_receiver->IsKeyDown(irr::KEY_KEY_S) || this->_receiver->IsKeyDown(irr::KEY_DOWN)) && this->getGame()) {
            if (this->_receiver->IsKeyDown(irr::KEY_KEY_S))
                this->getGame()->getPlayers()[0]->MoveDown();
            else
                this->getGame()->getPlayers()[1]->MoveDown();
        } if ((this->_receiver->IsKeyDown(irr::KEY_SPACE) || this->_receiver->IsKeyDown(irr::KEY_RETURN)) && this->getGame()) {
            if (this->_receiver->IsKeyDown(irr::KEY_SPACE))
                this->getGame()->getPlayers()[0]->action();
            else
                this->getGame()->getPlayers()[1]->action();
        }
        this->_window->getSceneManager()->drawAll();
        this->_window->getGUIEnvironment()->drawAll();
        this->_window->getVideoDriver()->endScene();
	}
    this->_window->closeDevice();
}

void Core::initMenu()
{
    //this->_driver->makeColorKeyTexture(this->image, position2d<s32>(0,0));
    //this->_env->addStaticText(L"Transparent Control:", rect<s32>(10, 10, 260, 22), true);
}