#ifndef GAME_OBJ_VERSIONTEXT_HPP
#define GAME_OBJ_VERSIONTEXT_HPP

#include <libstorm.hpp>

using namespace Storm;

class obj_versiontext : public TextObject
{
public:
    void onInit() override
    {
        TextObject::_s = "v. 0.0.1 pre-alpha";
        TextObject::_font = TTF_OpenFont("assets/fonts/SourceCodePro-SemiboldIt.otf", 64);
        TextObject::setColor(255, 255, 255);
        TextObject::setSize(0.4, 0.05);
        TextObject::setPosition(1, 1);
        TextObject::setOffset(1, 1);
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