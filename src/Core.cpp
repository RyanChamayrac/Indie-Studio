//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#include "Core.hpp"

Core::Core(IrrlichtDevice *const device) : _device(device)
{
	initMenu();
}

void Core::run()
{
	while (_device->run()) {

	}
}

void Core::initMenu()
{
}