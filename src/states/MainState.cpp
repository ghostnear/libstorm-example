#include "MainState.hpp"

using namespace Storm;

void MainState::on_init()
{
    root->add_child(new MainText({}), "main_text");
}