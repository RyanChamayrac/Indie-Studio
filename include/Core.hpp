//
// EPITECH PROJECT, 2019
// Core
// File description:
// Indie Studio
//

#ifndef __CORE_HPP__
#define __CORE_HPP__

#include <iostream>
#include "irrlicht.h"

using namespace irr;
using namespace video;

class Core
{
public:
	Core(IrrlichtDevice *const window);
	~Core(){}
	void run();

private:
	IrrlichtDevice *_window;

	void initMenu();
};

#endif