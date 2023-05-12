#pragma once

#include <libStorm.hpp>

#include "MainState.hpp"
#include "../nodes/LoadingState/all.hpp"

class LoadingState : public Storm::State
{
public:
    void on_init() override;
    void update() override;
};