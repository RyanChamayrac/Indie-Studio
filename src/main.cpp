//
// EPITECH PROJECT, 2019
// main
// File description:
// tom
//

#include <iostream>
#include "irrlicht.h"
#include "Core.hpp"

int main()
{
	SIrrlichtCreationParameters params;
	E_DRIVER_TYPE driverType = EDT_OPENGL;

	IrrlichtDevice *window = createDevice(driverType, core::dimension2d<u32>(1920, 1080), 16, false, false, false);

	if (!window)
		return 1;
    window->setWindowCaption(L"Indie Studio");
	Core launch(window);
	launch.run();
	return 0;
}
