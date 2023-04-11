#ifndef GAME_LOADINGSTATE_HPP
#define GAME_LOADINGSTATE_HPP

#include <libStorm.hpp>

#include "MainState.hpp"
#include "../nodes/LoadingState/all.hpp"

using namespace Storm;

class LoadingState : public State
{
public:
    void onInit() override;
    void onDestroy() override;
    void draw() override;
    void update(double dt) override;
};

#endif