#include "fpsText.hpp"

void fpsTextUpdate(Node* slf)
{
    auto updateTimer = slf -> getComponent<double>("update_timer");
    auto updateFreq = *(slf -> getComponent<double>("update_freq"));
    *updateTimer += GameManager::getDeltaTime();
    if(*updateTimer > updateFreq)
    {
        // Update text and frame count
        auto text = slf -> getComponent<std::string>("text");
        auto frameCount = slf -> getComponent<size_t>("frame_count");
        *text = Utils::to_string<size_t>(*frameCount) + " fps";
        *frameCount = 0;

        // Force the redrawing
        fpsText::redrawTextNode(slf);

        // Clear the timings
        while(*updateTimer >= updateFreq)
            *updateTimer = *updateTimer - updateFreq;
    }
}

void fpsTextDraw(Node* slf)
{
    auto frameCount = slf -> getComponent<size_t>("frame_count");
    *frameCount = *frameCount + 1;
    fpsText::textNodeDraw(slf);
}

fpsText::fpsText(fpsTextConfig config) : TextNode(config.textcfg)
{
    this -> addComponent<size_t>(new size_t(0), "frame_count");
    this -> addComponent<double>(new double(0.0), "update_timer");
    this -> addComponent<double>(new double(config.update_rate), "update_freq");
    this -> addFunction(fpsTextDraw, "draw");
    this -> addFunction(fpsTextUpdate, "update");
}