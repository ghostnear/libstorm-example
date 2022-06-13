#ifndef GAME_OOPMAINSTATE_HPP
#define GAME_OOPMAINSTATE_HPP

#include <libstorm.hpp>
#include "../objects/objects.hpp"

using namespace Storm;

class mainState : public OOPState
{
public:
    void onInit() override;
    void onDestroy() override;
    void draw() override;
    void update(double dt) override;
};

#endif