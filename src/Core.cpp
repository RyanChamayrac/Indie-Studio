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
    this->image = this->driver->getTexture("./ressources/background.jpg");
    this->button1 = this->driver->getTexture("./ressources/EXIT.png");
    this->button2 = this->driver->getTexture("./ressources/PLAY.png");
    this->button3 = this->driver->getTexture("./ressources/HELP.png");
    this->button4 = this->driver->getTexture("./ressources/OPTIONS.png");
    this->button5 = this->driver->getTexture("./ressources/test.jpg");

    this->smgr = window->getSceneManager();
    this->env = window->getGUIEnvironment();
	initMenu();
}

void Core::run()
{
    SAppContext context;
    context.device = this->_window;
    MyEventReceiver receiver(context);
    this->_window->setEventReceiver(&receiver);
    IGUIButton *button_quit = this->env->addButton(rect<s32>(0, 0, 425, 77), 0, GUI_ID_QUIT_BUTTON, L"Quit", L"Exits Program");
    IGUIButton *button_play = this->env->addButton(rect<s32>(0, 0, 425, 77), 0, GUI_ID_PLAY_BUTTON, L"Play", L"Play game");
    IGUIButton *button_option = this->env->addButton(rect<s32>(0, 0, 425, 77), 0, GUI_ID_OPTIONS_BUTTON, L"", L"Set options");

    while (_window->run()) {
        button_quit->setImage(this->button1);
        button_play->setImage(this->button2);
        button_option->setImage(this->button4);
        button_quit->setRelativePosition(position2d<s32>(748, 800));
        button_play->setRelativePosition(position2d<s32>(748, 200));
        button_option->setRelativePosition(position2d<s32>(748, 500));
        this->driver->beginScene(true, true, SColor(255, 100, 101, 140));
        this->driver->draw2DImage(this->image, position2d<s32>(0, 0), rect<s32>(0, 0, 1920, 1080), 0, SColor(255, 255, 255, 255), true);
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