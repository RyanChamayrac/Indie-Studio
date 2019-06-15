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
    std::map<std::string, irr::gui::IGUIButton *> getButtons();

    //Loader
    void loadButtons(irr::IrrlichtDevice *windows);
    void loadTextures(irr::IrrlichtDevice *windows);
    irr::video::ITexture *getSkin(int skin);
    void incSkin(int skin);

    void switchSkin(int pos);

private:
    std::map<std::string, irr::video::ITexture *> _textures;
    std::vector<int> _pos;
    std::vector<bool> _playersIA;
    std::map<std::string, irr::gui::IGUIButton *> _buttons;
    std::vector<std::vector<std::string>> selectTab;
    int nbSkin[4] = {0, 1, 2, 3};
};

#endif //OOP_INDIE_STUDIO_2018_SELECT_HPP