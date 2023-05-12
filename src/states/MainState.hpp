#pragma once

#include <libStorm.hpp>

#include "../nodes/MainState/all.hpp"

class MainState : public Storm::State
{
public:
    void on_init() override;
};
