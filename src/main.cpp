#include <libStorm.hpp>
#include "states/all.hpp"
#include "system/Graphics.hpp"

using namespace Storm;

// The role of this example is mostly to show how to make a window and manage states.
// It is also used as a base for anything else.

int main(int argc, char* argv[])
{
    // Init and quit on fail
    if(StormInit() == EXIT_FAILURE)
        return EXIT_FAILURE;

    // Set metadata.
    Window::set_name("libStorm Example");
    Graphics::toggle_vsync();

    // Push the default state to the manager
    GameManager::push_state(new LoadingState());

    // Main loop
    while(!Window::should_close() && GameManager::is_running())
    {
        // Poll events
        Input::pollEvents();

        // Update
        GameManager::update();

        // Draw
        if(!Window::is_minimized())
            GameManager::draw();
    }

    // Quit and return the quit result
    return StormQuit(EXIT_SUCCESS);
}
