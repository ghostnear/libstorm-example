#include "FPSText.hpp"

void fpsTextUpdate(Node* slf)
{
    auto updateTimer = slf->getComponent<double>("update_timer");
    auto updateFreq = *(slf->getComponent<double>("update_freq"));
    *updateTimer += GameManager::getDeltaTime();
    if(*updateTimer > updateFreq)
    {
        // Update text and frame count
        auto text = slf->getComponent<std::string>("text");
        auto frameCount = slf->getComponent<size_t>("frame_count");
        *text = Utils::to_string<size_t>(*frameCount) + " fps";
        *frameCount = 0;

        // Force the redrawing
        FPSText::redrawTextNode(slf);

        // Clear the timings
        while(*updateTimer >= updateFreq)
            *updateTimer = *updateTimer - updateFreq;
    }
}

void fpsTextDraw(Node* slf)
{
    auto frameCount = slf->getComponent<size_t>("frame_count");
    *frameCount = *frameCount + 1;
    FPSText::textNodeDraw(slf);
}

FPSText::FPSText(FPSTextConfig config) : TextNode(config.textcfg)
{
    addComponent<size_t>(
        "frame_count",
        new size_t(0)
    );
    addComponent<double>(
        "update_timer",
        new double(0)
    );
    addComponent<double>(
        "update_freq",
        new double(config.update_rate)
    );
    addFunction(fpsTextDraw, "draw");
    addFunction(fpsTextUpdate, "update");
}