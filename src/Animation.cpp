/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Render.cpp
*/

#include "Animation.hpp"

int main()
{
    MyEventReceiver receiver;

    IrrlichtDevice *device = createDevice(video::EDT_SOFTWARE, dimension2d<u32>(1920, 1080), 16, false, false, false, &receiver);
    if (!device)
        return (84);

    device->setWindowCaption(L"Epibomb - Indie Studio 2019");

    IVideoDriver *driver = device->getVideoDriver();
    ISceneManager *smgr = device->getSceneManager();
    IGUIEnvironment *guienv = device->getGUIEnvironment();
    IAnimatedMesh *bomberman = smgr->getMesh("assets/models/Bomberman_0.b3d");
    IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(bomberman);
    
    if (node) {
        node->setPosition(vector3df(0,0,30));
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setMaterialTexture(0, driver->getTexture("assets/models/Bomberman_0.png"));
    }
    smgr->addCameraSceneNode(0, vector3df(0,05,-01), vector3df(0,5,0));

    u32 then = device->getTimer()->getTime();
    const f32 MOVEMENT_SPEED = 5.f;

    while (device->run()) {
        const u32 now = device->getTimer()->getTime();
        const f32 frameDeltaTime = (f32)(now - then) / 1000.f;
        then = now;
        vector3df nodePosition = node->getPosition();
        vector3df nodeRotation = node->getRotation();

        if (receiver.IsKeyDown(KEY_KEY_Z)) {
            node->setFrameLoop(140, 160);
            nodeRotation.Y = 180;
            nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
        } else if (receiver.IsKeyDown(KEY_KEY_S)) {
            node->setFrameLoop(140, 160);
            nodeRotation.Y = 0;
            nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
        } else if (receiver.IsKeyDown(KEY_KEY_Q)) {
            node->setFrameLoop(140, 160);
            nodeRotation.Y = 90;
            nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
        } else if (receiver.IsKeyDown(KEY_KEY_D)) {
            node->setFrameLoop(140, 160);
            nodeRotation.Y = 270;
            nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
        } else if (receiver.IsKeyDown(KEY_ESCAPE))
            break;

        node->setRotation(nodeRotation);
        node->setPosition(nodePosition);
        
        driver->beginScene(true, true, SColor(255,100,101,140));

        smgr->drawAll();
        guienv->drawAll();

        driver->endScene();
    }
    device->drop();
    
    return (0);
}