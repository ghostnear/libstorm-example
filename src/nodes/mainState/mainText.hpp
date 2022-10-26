#ifndef LIBSTORM_EXAMPLE_MAIN_TEXT_HPP
#define LIBSTORM_EXAMPLE_MAIN_TEXT_HPP

#include <libstorm.hpp>
#include <prefabs/all.hpp>

using namespace Storm;

struct mainTextConfig
{
    // Denotes how often does the framerate update, default is once per second
    Vec2<double> padding = {
        .x = 0.5,
        .y = 0.5
    };
    double scale = 0.5;
    TextNodeConfig textcfg;
};

class mainText : public TextNode
{
public:
    // Constructor
    mainText(mainTextConfig config);
};

#endif
