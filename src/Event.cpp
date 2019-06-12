//
// EPITECH PROJECT, 2019
// Event
// File description:
// Indie Studio
//

#include "Core.hpp"
#include "GameStat.hpp"

bool MyEventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
            case irr::gui::EGET_BUTTON_CLICKED:
                switch (id) {
                    case GUI_ID_QUIT_BUTTON:
                        this->_window->closeDevice();
                        return true;
                    case GUI_ID_PLAY_BUTTON:
                        this->_core.setState(Core::mainGame);
                        std::cout << "print game" << std::endl;
                        return true;
                    case GUI_ID_OPTIONS_BUTTON:
                        std::cout << "print options" << std::endl;
                        return true;
                    default:
                        return false;
                }
            default:
                break;
        }
    }
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        if (this->IsKeyDown(irr::KEY_ESCAPE) && this->_core.getState() == Core::mainGame)
            std::cout << "enter pause menu" << std::endl;
        if (this->IsKeyDown(irr::KEY_KEY_Z))
            std::cout << "z pressed" << std::endl;
        else if (this->IsKeyDown(irr::KEY_KEY_S))
            std::cout << "s pressed" << std::endl;
    }
    return false;
}
