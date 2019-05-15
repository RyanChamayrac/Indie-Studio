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

	params.DriverType = driverType;

	IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(1024, 980), 16, false, false, false);

	if (!device)
		return 1;
	device->setWindowCaption(L"Indie Studio");
	Core app(device);
	app.run();
	return 0;
}
