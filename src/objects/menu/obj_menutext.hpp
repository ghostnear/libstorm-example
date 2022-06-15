#ifndef GAME_OBJ_MENUTEXT_HPP
#define GAME_OBJ_MENUTEXT_HPP

#include <libstorm.hpp>

using namespace Storm;

class obj_menutext : public TextObject
{
public:
    void onInit() override
    {
        TextObject::_s = "libStorm";
        TextObject::_font = TTF_OpenFont("assets/fonts/SourceCodePro-SemiboldIt.otf", 64);
        TextObject::setColor(255, 255, 255);
        TextObject::setSize(0.6, 0.2);
        TextObject::setPosition(0.5, 0.5);
        TextObject::setOffset(0.5, 0.5);
        TextObject::setPositionScreenRelative(true);
        TextObject::setSizeScreenRelative(true);
        TextObject::onInit();
    }

    void update(OOPState* gm, double dt) override
    {
        TextObject::update(gm, dt);
    }
};

#endif