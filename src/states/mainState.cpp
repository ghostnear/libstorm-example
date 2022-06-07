#include "mainstate.hpp"

void mainState::onInit()
{
    w.registerComponent<FRect>();

    drawSystem = w.registerSystem<RectDrawSystem>();

	Signature signature;
	signature.set(w.getComponentType<FRect>());
    w.setSystemSignature<RectDrawSystem>(signature);

    for(int i = 0; i <= 11; i++)
    {
        for(int j = 0; j <= 11; j++)
        {
            auto entity = w.createEntity();

            if(i % 2 != j % 2)
                w.addComponent(
                    entity,
                    FRect{
                        .pos{
                            .x = (i - 1) * 54.0,
                            .y = (j - 1) * 54.0
                        },
                        .size{
                            .x = 54.0,
                            .y = 54.0
                        }
                    }
                );
        }
    }
}

void mainState::onDestroy()
{

}

void mainState::draw(GameManager* gm)
{
    Graphics::clear(50, 100, 155);
    drawSystem -> draw(&w);
    Graphics::update();
}

void mainState::update(GameManager* gm, double dt)
{
    drawSystem -> update(&w, dt);

    Window::setName("Example " + std::to_string((int)GameManager::getFPS()) + " fps");

    // Press escape to close window
    if(Input::isReleased(SDLK_ESCAPE))
        Window::close();
}