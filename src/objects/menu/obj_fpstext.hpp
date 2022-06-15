#ifndef GAME_OBJ_FPSTEXT_HPP
#define GAME_OBJ_FPSTEXT_HPP

#include <libstorm.hpp>

using namespace Storm;

class obj_fpstext : public TextObject
{
public:
    void onInit() override
    {
        TextObject::_font = TTF_OpenFont("assets/fonts/SourceCodePro-SemiboldIt.otf", 64);
        TextObject::setColor(255, 255, 255);
        TextObject::setSize(0.15, 0.05);
        TextObject::setPositionScreenRelative(true);
        TextObject::setSizeScreenRelative(true);
        TextObject::onInit();
    }

    void update(OOPState* gm, double dt) override
    {
        TextObject::setString(Utils::to_string<int>((int)(1.0 / dt)) + " fps");
        TextObject::update(gm, dt);
    }
};

#endif