#include "LoadingBar.hpp"

#define renderer Graphics::getSDL()

void loadingBarDraw(Node* slf)
{
    auto primary_color = *(slf->getComponent<SDL_Color>("primary_color"));
    auto secondary_color = *(slf->getComponent<SDL_Color>("secondary_color"));
    auto padding = *(slf->getComponent<double>("padding"));
    auto w_size = Window::getSize();
    
    Graphics::setColor(secondary_color);
    // TODO: stop using the stack
    SDL_Rect r = {
        .x = int(padding * w_size.x),
        .y = int((1 - 3 * padding) * w_size.y),
        .w = int(w_size.x * (1 - 2 * padding)),
        .h = int(std::min(w_size.x, w_size.y) * padding)
    };
    SDL_RenderFillRect(renderer, &r);

    Graphics::setColor(primary_color);
    r.w = int(w_size.x * (1 - 2 * padding) * AssetLoader::getPercentage());
    SDL_RenderFillRect(renderer, &r);
}

LoadingBar::LoadingBar(LoadingBarConfig config)
{
    addComponent<double>(
        "padding",
        new double(config.padding)
    );
    addComponent<SDL_Color>(
        "primary_color",
        new SDL_Color(config.primary)
    );
    addComponent<SDL_Color>(
        "secondary_color",
        new SDL_Color(config.secondary)
    );
    addFunction(loadingBarDraw, "draw");
}

#undef renderer