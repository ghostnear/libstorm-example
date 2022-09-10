#include "simpleNode.hpp"

void simpleNodePrint(Node* slf)
{
    std::string* text = slf -> getComponent<std::string>("message");
    printf(text -> c_str());
}

simpleNode::simpleNode(simpleNodeConfig config)
{
    this -> addComponent<std::string>(new std::string(config.message), "message");
    this -> addFunction(simpleNodePrint, "draw");
}
