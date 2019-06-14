/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Select.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SELECT_HPP
#define OOP_INDIE_STUDIO_2018_SELECT_HPP

#include "Core.hpp"

class SelectPlayer {
public:
    explicit SelectPlayer(irr::IrrlichtDevice *windows);
    ~SelectPlayer() = default;
    void run(irr::IrrlichtDevice *windows);

    //Getter
    //std::map<std::string, irr::gui::IGUIButton *> getButtons();

    //Loader
    //void loadButtons(irr::IrrlichtDevice *windows);
    void loadTextures(irr::IrrlichtDevice *windows);

private:
    std::map<std::string, irr::video::ITexture *> _textures;
    std::map<std::string, irr::gui::IGUIButton *> _buttons;
};

#endif //OOP_INDIE_STUDIO_2018_SELECT_HPP