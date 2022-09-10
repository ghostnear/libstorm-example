#ifndef LIBSTORM_EXAMPLE_SIMPLE_NODE_HPP
#define LIBSTORM_EXAMPLE_SIMELE_NODE_HPP

#include <libstorm.hpp>

using namespace Storm;

struct simpleNodeConfig
{
    std::string message = "test";
};

class simpleNode : public Node
{
public:
    // Constructor
    simpleNode(simpleNodeConfig config);
};

#endif
