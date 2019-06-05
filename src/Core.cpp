//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#include "Core.hpp"

void Core::loadButtons()
{
    this->_buttons.insert(std::pair<std::string, IGUIButton *>(std::string("menuExit"),
            this->_env->addButton(rect<s32>(0, 0, 425, 77), 0, GUI_ID_QUIT_BUTTON, L"Exit", L"Exits Program")));
    this->_buttons.insert(std::pair<std::string, IGUIButton *>(std::string("menuPlay"),
            this->_env->addButton(rect<s32>(0, 0, 425, 77), 0, GUI_ID_PLAY_BUTTON, L"Play", L"Play game")));
    this->_buttons.insert(std::pair<std::string, IGUIButton *>(std::string("menuOptions"),
            this->_env->addButton(rect<s32>(0, 0, 425, 77), 0, GUI_ID_OPTIONS_BUTTON, L"", L"Set options")));
    this->_buttons["menuExit"]->setImage(this->_textures["menuExitButton"]);
    this->_buttons["menuPlay"]->setImage(this->_textures["menuPlayButton"]);
    this->_buttons["menuOptions"]->setImage(this->_textures["menuOptionsButton"]);
    this->_buttons["menuExit"]->setRelativePosition(position2d<s32>(748, 800));
    this->_buttons["menuPlay"]->setRelativePosition(position2d<s32>(748, 200));
    this->_buttons["menuOptions"]->setRelativePosition(position2d<s32>(748, 500));
}

void Core::loadTextures()
{
    this->_textures.insert(std::pair<std::string, ITexture *>(std::string("menuBackground"),
                                                             this->_driver->getTexture("./ressources/background.jpg")));
    this->_textures.insert(std::pair<std::string, ITexture *>(std::string("menuExitButton"),
                                                             this->_driver->getTexture("./ressources/EXIT.png")));
    this->_textures.insert(std::pair<std::string, ITexture *>(std::string("menuPlayButton"),
                                                             this->_driver->getTexture("./ressources/PLAY.png")));
    this->_textures.insert(std::pair<std::string, ITexture *>(std::string("menuHelpButton"),
                                                             this->_driver->getTexture("./ressources/HELP.png")));
    this->_textures.insert(std::pair<std::string, ITexture *>(std::string("menuOptionsButton"),
                                                             this->_driver->getTexture("./ressources/OPTIONS.png")));
    this->_textures.insert(std::pair<std::string, ITexture *>(std::string("menuTestButton"),
                                                             this->_driver->getTexture("./ressources/test.jpg")));
}

Core::Core()
{
    this->_window = createDevice(EDT_OPENGL, core::dimension2d<u32>(1920, 1080), 16, false, false, false);

    if (!this->_window) {
        std::cerr << "Couldn't open a window" << std::endl;
        return;
    }
    this->_window->setWindowCaption(L"Indie Studio");
    this->_driver = this->_window->getVideoDriver();
    this->_smgr = this->_window->getSceneManager();
    this->_env = this->_window->getGUIEnvironment();
    this->loadTextures();
    this->loadButtons();
	initMenu();
}

void Core::run()
{
    SAppContext context;

    if (!this->_window)
        return;
    context.device = this->_window;
    MyEventReceiver receiver(context);

    this->_window->setEventReceiver(&receiver);
    while (this->_window->run()) {
        this->_driver->draw2DImage(this->_textures["menuBackground"], position2d<s32>(0, 0),
                rect<s32>(0, 0, 1920, 1080), 0, SColor(255, 255, 255, 255), true);
        this->_smgr->drawAll();
        this->_env->drawAll();
        this->_driver->endScene();
	}
}

void Core::initMenu()
{
    //this->_driver->makeColorKeyTexture(this->image, position2d<s32>(0,0));
    //this->_env->addStaticText(L"Transparent Control:", rect<s32>(10, 10, 260, 22), true);
}