#include "scrollingRectangles.hpp"

#define renderer Graphics::getSDL()

void rectangleDraw(Node* slf)
{
    auto primary_color = *(slf -> getComponent<SDL_Color>("primary_color"));
    auto secondary_color = *(slf -> getComponent<SDL_Color>("secondary_color"));
    auto offset = *(slf -> getComponent<double>("offset"));
    auto size = *(slf -> getComponent<double>("size"));
    auto w_size = Window::getSize();
    for(size_t i = 0; i <= size_t(w_size.x / size) + 1; i++)
        for(size_t j = 0; j <= size_t(w_size.y / size) + 1; j++)
        {
            Graphics::setColor((i + j) % 2 ? primary_color : secondary_color);
            SDL_Rect r = {
                .x = int(i * size + offset),
                .y = int(j * size + offset),
                .w = int(size),
                .h = int(size)
            };
            SDL_RenderFillRect(renderer, &r);
        }
}

void rectangleChangeOffset(Node* slf)
{
    auto offset = slf -> getComponent<double>("offset");
    auto size = *(slf -> getComponent<double>("size"));
    auto speed = *(slf -> getComponent<double>("speed"));
    *offset = *offset - GameManager::getDeltaTime() * speed;
    while(*offset <= -size)
        *offset = *offset + size;
}

scrollingRectangles::scrollingRectangles(scrollingRectanglesConfig config)
{
    this -> addComponent<double>(new double(0), "offset");
    this -> addComponent<double>(new double(config.speed), "speed");
    this -> addComponent<double>(new double(config.size), "size");
    this -> addComponent<SDL_Color>(new SDL_Color(config.primary), "primary_color");
    this -> addComponent<SDL_Color>(new SDL_Color(config.secondary), "secondary_color");
    this -> addFunction(rectangleDraw, "draw");
    this -> addFunction(rectangleChangeOffset, "update");
}

#undef window
