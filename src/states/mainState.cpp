#include "mainstate.hpp"

void mainState::onInit()
{

}

void mainState::onDestroy()
{

}

void mainState::draw(GameManager* gm)
{
    Graphics::clear(50, 100, 155);

    Graphics::update();
}

void mainState::update(GameManager* gm, double dt)
{
    // Press escape to close window
    if(Input::isReleased(SDLK_ESCAPE))
        Window::close();
}