#ifndef GAME_OBJ_BACKGROUND_HPP
#define GAME_OBJ_BACKGROUND_HPP

#include <libstorm.hpp>

using namespace Storm;

class obj_background : public BaseClass
{
public:
    void onInit() override
    {
        offset = 0;
    }

    void onDestroy() override
    {

    }

    void draw(OOPState* gm) override
    {
        SDL_Rect r;
        r.w = 54;
        r.h = 54;
        auto size = Window::getSize();

        // Draw checkerboard pattern in the background
        for(int32_t i = 0; i <= size.x / 54 + 1; i++)
            for(int32_t j = 0; j <= size.y / 54 + 1; j++)
                if(i % 2 == j % 2)
                {
                    Graphics::setColor(50, 130, 155);
                    r.x = i * 54 + offset;
                    r.y = j * 54 + offset;
                    SDL_RenderFillRect(Graphics::getSDL(), &r);
                }
    }

    void update(OOPState* gm, double dt) override
    {
        // Offset clamping
        offset -= 54 * dt;
        if(offset < -54)
            offset += 54;
    }

private:
    double offset;
};

#endif