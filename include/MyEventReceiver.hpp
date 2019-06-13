/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MyEventReceiver.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_MYEVENTRECEIVER_HPP
#define OOP_INDIE_STUDIO_2018_MYEVENTRECEIVER_HPP

#include "Core.hpp"

class MyEventReceiver : public irr::IEventReceiver
{
public:
    explicit MyEventReceiver(irr::IrrlichtDevice *window, Core &core) : _window(window), _core(core), _keyIsDown() {};
    bool OnEvent(const irr::SEvent &event) override;
    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
    bool clicks(const irr::SEvent &event);
    bool keyInputs(const irr::SEvent &event);

private:
    irr::IrrlichtDevice *_window;
    Core &_core;
    bool _keyIsDown[irr::KEY_KEY_CODES_COUNT];
};

#endif //OOP_INDIE_STUDIO_2018_MYEVENTRECEIVER_HPP
