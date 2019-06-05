//
// EPITECH PROJECT, 2019
// Event
// File description:
// Indie Studio
//

#include "Core.hpp"

MyEventReceiver::MyEventReceiver(SAppContext &context): _Context(context)
{

}

bool MyEventReceiver::OnEvent(const SEvent &event)
{
    if (event.EventType == EET_GUI_EVENT) {
        s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
            case EGET_BUTTON_CLICKED:
                switch (id) {
                    case GUI_ID_QUIT_BUTTON:
                        this->_Context.device->closeDevice();
                        return true;
                    case GUI_ID_PLAY_BUTTON:
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
    return false;
}