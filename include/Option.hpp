/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Option.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_OPTION_HPP
#define OOP_INDIE_STUDIO_2018_OPTION_HPP

#include "Core.hpp"

class Option {
public:
    explicit Option(irr::IrrlichtDevice *window);
    ~Option() = default;
    void run(irr::IrrlichtDevice *window);

    //Getter
    std::map<std::string, irr::gui::IGUIButton *> getButtons();
    std::map<std::string, irr::gui::IGUIScrollBar *> getScrollBars();

    //Loader
    void loadButtons(irr::IrrlichtDevice *window);
    void loadTextures(irr::IrrlichtDevice *window);

private:
    std::map<std::string, irr::video::ITexture *> _textures;
    std::map<std::string, irr::gui::IGUIButton *> _buttons;
    std::map<std::string, irr::gui::IGUIScrollBar *> _scrollbars;
};

#endif //OOP_INDIE_STUDIO_2018_OPTION_HPP