/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MyEventReceiver.cpp
*/

#include "MyEventReceiver.hpp"

bool MyEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return this->_keyIsDown[keyCode];
}

bool MyEventReceiver::clicks(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
            case irr::gui::EGET_BUTTON_CLICKED:
                switch (id) {
                    case GUI_ID_QUIT_BUTTON:
                        this->_window->closeDevice();
                        return true;
                    case GUI_ID_NEW_BUTTON:
                        this->_core.setState(Core::mainSelect);
                        return true;
                    case GUI_ID_LOAD_BUTTON:
                        this->_core.setState(Core::mainGame);
                        return true;
                    case GUI_ID_PLAY_SELECT:
                        this->_core.setState(Core::mainGame);
                        return true;
                    case GUI_ID_OPTIONS_BUTTON:
                        this->_core.setState(Core::mainOptions);
                        return true;
                    case GUI_ID_RETURN_SELECT_PLAY:
                        this->_core.setState(Core::mainMenu);
                        return true;
                    case GUI_ID_RETURN_MENU_BUTTON:
                        this->_core.setState(Core::mainMenu);
                        return true;
                    case GUI_ID_RESUME_BUTTON:
                        this->_core.setState(Core::mainGame);
                        return true;
                    case GUI_ID_OPTION_1:
                        this->_core.setState(Core::mainMenu);
                        return true;
                    default:
                        return false;
                }
            default:
                break;
        }
    }
    return false;
}

bool MyEventReceiver::keyInputs(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        _keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        if (this->_core.getState() == Core::mainGame) {
            if (event.KeyInput.PressedDown && !this->_core.getGame()->getPlayers()[0]->getIsWalking()) {
                this->_core.getGame()->getPlayers()[0]->Animate(140, 160);
                this->_core.getGame()->getPlayers()[0]->setIsWalking(true);
            }
            else if (!event.KeyInput.PressedDown && this->_core.getGame()->getPlayers()[0]->getIsWalking()) {
                this->_core.getGame()->getPlayers()[0]->Animate(230, 270);
                this->_core.getGame()->getPlayers()[0]->setIsWalking(false);
            }
            return false;
    } else if (this->_core.getState() == Core::mainMenu) {
            if (this->IsKeyDown(irr::KEY_ESCAPE)) {
                this->_window->closeDevice();
                return true;
            }
        }
    }
    return false;
}


bool MyEventReceiver::OnEvent(const irr::SEvent &event)
{
    for (bool & i : _keyIsDown)
        i = false;
    if (this->clicks(event))
        return true;
    if (this->keyInputs(event))
        return true;
    return false;
}
