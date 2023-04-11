#ifndef LIBSTORM_EXAMPLE_MAIN_TEXT_HPP
#define LIBSTORM_EXAMPLE_MAIN_TEXT_HPP

#include <libStorm.hpp>

using namespace Storm;

struct MainTextConfig
{
    // Denotes how often does the framerate update, default is once per second
    Vec2<double> padding = {
        .x = 0.5,
        .y = 0.5
    };
    double scale = 0.5;
    Prefabs::TextNodeConfig textcfg;
};

class MainText : public Prefabs::TextNode
{
public:
    // Constructor
    MainText(MainTextConfig config);
};

#endif
