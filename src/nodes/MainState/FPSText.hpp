#ifndef LIBSTORM_EXAMPLE_FPS_TEXT_HPP
#define LIBSTORM_EXAMPLE_FPS_TEXT_HPP

#include <libStorm.hpp>
#include <prefabs/all.hpp>

using namespace Storm;

struct FPSTextConfig
{
    // Denotes how often does the framerate update, default is once per second
    double update_rate = 1.0;
    Prefabs::TextNodeConfig textcfg;
};

class FPSText : public Prefabs::TextNode
{
public:
    // Constructor
    FPSText(FPSTextConfig config);
};

#endif
