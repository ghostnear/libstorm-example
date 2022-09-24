#ifndef LIBSTORM_EXAMPLE_SIMPLE_NODE_HPP
#define LIBSTORM_EXAMPLE_SIMPLE_NODE_HPP

#include <libstorm.hpp>

using namespace Storm;

struct scrollingRectanglesConfig
{
    double size = 60;
    double speed = 60;
    SDL_Color primary = {.r = 50, .g = 100, .b = 200};
    SDL_Color secondary = {.r = 50, .g = 50, .b = 160};
};

class scrollingRectangles : public Node
{
public:
    // Constructor
    scrollingRectangles(scrollingRectanglesConfig config);
};

#endif
