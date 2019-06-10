/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** anim.cpp
*/

#include "anim.hpp"

int main()
{
    IrrlichtDevice *device = createDevice(video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16, false, false, false, 0);

    if (!device)
        return (84);

    device->setWindowCaption(L"Epibomb - Indie Studio 2019");

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

    IAnimatedMesh* bomberman = smgr->getMesh("assts/Bomberman.MD3");
    if (!bomberman) {
        device->drop();
        return (84);
    }
    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(bomberman);

    if (node) {
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
        node->setMaterialTexture(0, driver->getTexture("assts/WhiteBombermanTextures.png") );
    }
    smgr->addCameraSceneNode(0, vector3df(-50,0,-40), vector3df(0,5,0));

    while (device->run()) {
        driver->beginScene(true, true, SColor(255,100,101,140));

        smgr->drawAll();
        guienv->drawAll();

        driver->endScene();
    }
    device->drop();

    return (0);
}