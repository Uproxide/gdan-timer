#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class GDANTimer : public CCNode {
public:
    static GDANTimer* create() {
        GDANTimer* pRet = new GDANTimer();
        if (pRet && pRet->init()) {
            pRet->autorelease();
            return pRet;
        } else {
            delete pRet;
            return nullptr;
        }
    }

    CCLabelBMFont* timerLabel = nullptr;
    long long startTime = 1781366400000;
    long long endTime = 1781452800000;

    bool gdanIsStarted = false;
    bool gdanIsFinished = false;

    ~GDANTimer();

protected:
    bool init();

    void update(float dt);
    void doCountdownThing();
    // johnathan gdan in this gdland @rozer
};