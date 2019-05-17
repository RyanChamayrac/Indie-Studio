//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#include "Core.hpp"

Core::Core(IrrlichtDevice *const window) : _window(window)
{
	initMenu();
}

void Core::run()
{
	while (_window->run()) {

	}
}

void Core::initMenu()
{
}