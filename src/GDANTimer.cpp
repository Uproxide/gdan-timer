#include "headers/GDANTimer.hpp"

bool GDANTimer::init() {
    if (!CCNode::init()) {
        return false;
    }

    timerLabel = CCLabelBMFont::create("999:999:999.999", "bigFont.fnt");
    this->addChild(timerLabel);

    this->schedule(schedule_selector(GDANTimer::update));

    return true;
}

void GDANTimer::doCountdownThing() {
    if (timerLabel) {
        if (!gdanIsFinished) {
            auto now = std::chrono::system_clock::now();
            auto timeSinceEpoch = now.time_since_epoch();

            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceEpoch).count(); // should equal to the epoch time in   mili seconds as of RIGHT FUCKING NOW

            long totalMs = startTime - milliseconds;
            if (gdanIsStarted) {
                totalMs = endTime - milliseconds;
            }
            auto totalSec = totalMs / 1000;
            auto seconds = totalSec % 60;
            auto minutes = (totalSec / 60) % 60;
            auto hours = totalSec / 3600;

            if (totalMs <= 0) {
                if (gdanIsStarted) {
                    gdanIsFinished = true;
                }
                gdanIsStarted = true; 
            }

            std::string formattedCountdown = fmt::format("{:02}:{:02}:{:02}", hours, minutes, seconds);

            timerLabel->setString(formattedCountdown.c_str());
            // im so fucking scared            
        } else {
            timerLabel->setString("GDAN 3 is over - Submit Now!");
        }

    }
}

void GDANTimer::update(float dt) {
    doCountdownThing();
}