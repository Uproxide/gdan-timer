#include <Geode/Geode.hpp>
#include "headers/GDANTimer.hpp"

using namespace geode::prelude;

#include <Geode/modify/LevelEditorLayer.hpp>
class $modify(GDANLevelEditorLayer, LevelEditorLayer) {
	struct Fields {
        GDANTimer* m_timer;
    };

	bool init(GJGameLevel* level, bool noUI) {
		if (!LevelEditorLayer::init(level, noUI)) {
			return false;
		}
		auto director = CCDirector::sharedDirector();
    	auto winSize = director->getWinSize();

		m_fields->m_timer = GDANTimer::create();
		this->addChild(m_fields->m_timer);
	
		m_fields->m_timer->setPosition(winSize.width / 2, director->getScreenTop() - 45);
		m_fields->m_timer->setScale(0.5);

		return true;
	}

	void onPlaytest() {
		LevelEditorLayer::onPlaytest();

		m_fields->m_timer->setVisible(false);
	}

	void onStopPlaytest() {
		LevelEditorLayer::onStopPlaytest();

		m_fields->m_timer->setVisible(true);
	}
};