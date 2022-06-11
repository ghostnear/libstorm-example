#include "mainstate.hpp"

void mainState::onInit()
{
    offset = 0;

    auto entity = w.createEntity();

    TTF_Font* font = TTF_OpenFont("assets/fonts/SourceCodePro-Light.otf", 32);

    w.addComponent(
        entity,
        Text{
            .tr{
                .pos {
                    .x = 0,
                    .y = 0
                }
            },
            .font = font,
            .str = "Hello World!"
        }
    );
}

void mainState::onDestroy()
{

}

void mainState::draw(GameManager* gm)
{
    Graphics::clear(50, 100, 155);

    SDL_Rect r;
    r.w = 54;
    r.h = 54;
    auto size = Window::getSize();

    // Draw checkerboard pattern in the background
    for(int32_t i = 0; i <= size.first / 54 + 1; i++)
        for(int32_t j = 0; j <= size.second / 54 + 1; j++)
            if(i % 2 == j % 2)
            {
                Graphics::setColor(50, 130, 155);
                r.x = i * 54 + offset;
                r.y = j * 54 + offset;
                SDL_RenderFillRect(Graphics::getSDL(), &r);
            }

    for(auto x : sys)
        x -> draw(&w);

    Graphics::update();
}

void mainState::update(GameManager* gm, double dt)
{
    // Offset clamping
    offset -= 54 * dt;
    if(offset < -54)
        offset += 54;
    
    Window::setName("Example " + std::to_string(GameManager::getFPS()) + " fps");

    for(auto x : sys)
        x -> update(&w, dt);

    // Press escape to close window
    if(Input::isReleased(SDLK_ESCAPE))
        Window::close();

    // Toggle fullscreen
    if(Input::isPressed(SDLK_F11))
    {
        if(!Window::isFullscreen())
            Window::setFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
        else
            Window::setFullscreen(0);
    }       
}