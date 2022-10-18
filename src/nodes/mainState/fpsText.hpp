#ifndef LIBSTORM_EXAMPLE_FPS_TEXT_HPP
#define LIBSTORM_EXAMPLE_FPS_TEXT_HPP

#include <libstorm.hpp>
#include <prefabs/all.hpp>

using namespace Storm;

struct fpsTextConfig
{
    // Denotes how often does the framerate update, default is once per second
    double update_rate = 1.0;
    TextNodeConfig textcfg;
};

class fpsText : public TextNode
{
public:
    // Constructor
    fpsText(fpsTextConfig config);
};

#endif
