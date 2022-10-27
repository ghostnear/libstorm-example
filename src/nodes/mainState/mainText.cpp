#include "mainText.hpp"

void mainTextUpdate(Node* slf)
{
    auto boundaries = slf -> getComponent<Rect<double>>("boundaries");
    auto scaling = *(slf -> getComponent<double>("mainText_scaling"));
    Vec2<int> position = Window::getSize().multiplyByComponents(*slf -> getComponent<Vec2<double>>("mainText_padding"));
    boundaries -> position.x = position.x;
    boundaries -> position.y = position.y;

    Vec2<int> winSize = Window::getSize();
    auto ratio = 1.0 * winSize.x / winSize.y;

    auto text_size = slf -> getComponent<size_t>("text_size");
    size_t new_value = (size_t)(std::min(winSize.x, winSize.y) / 540.0 * 128);
    if(new_value != *text_size)
    {
        *text_size = new_value;
        mainText::redrawTextNode(slf);
    }
    
    if(winSize.x > winSize.y)
    {
        boundaries -> size.x = winSize.x * scaling * ratio;
        boundaries -> size.y = winSize.y * scaling;
    }
    else
    {
        boundaries -> size.x = winSize.x * scaling;
        boundaries -> size.y = winSize.y * scaling * ratio;
    }
}

mainText::mainText(mainTextConfig config) : TextNode(config.textcfg)
{
    // Set stuff to a desired value to make all look nice
    this -> setComponent<std::string>(
        "text",
        new std::string("LibStorm"),
        true
    );
    this -> setComponent<Vec2<double>>(
        "text_offset",
        new Vec2<double>{
            .x = 0.5,
            .y = 0.5
        },
        true
    );

    // Init values
    this -> addComponent<double>(
        "mainText_scaling",
        new double(config.scale)
    );
    this -> addComponent<Vec2<double>>(
        "mainText_padding",
        new Vec2<double>(config.padding)
    );
    this -> addFunction(mainTextUpdate, "update");
}