#include "HomeLayer.h"
#include "Helper.h"
#include "Resolution.h"
#include "GameLayer.h"
#include "TestsLayer.h"

NAMESPACE_G1_BEGIN

using namespace cc;

HomeLayer::HomeLayer() {
}

HomeLayer::~HomeLayer() {
}

HomeLayer* HomeLayer::create() {
    auto layer = new HomeLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    } else {
        delete layer;
        layer = nullptr;
        return nullptr;
    }
}

bool HomeLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    // start button
    auto startButton = MenuItemFont::create("Start", HANDLER1(HomeLayer::onStart));
    Resolution::adapt(startButton, WIDTH/2, HEIGHT/2);
    auto startMenu = Menu::create(startButton, nullptr);
    startMenu->setPosition(0, 0);
    this->addChild(startMenu);

    // test button
    auto testButton = MenuItemFont::create("TESTS", HANDLER1(HomeLayer::onTest));
    Resolution::adapt(testButton, WIDTH/2, 30);
    auto testMenu = Menu::create(testButton, nullptr);
    testMenu->setPosition(0, 0);
    this->addChild(testMenu);

    return true;
}

void HomeLayer::onStart(Ref* sender) {
    ReplaceLayer(GameLayer::create());
}

void HomeLayer::onTest(Ref* sender) {
    ReplaceLayer(TestsLayer::create());
}

NAMESPACE_G1_END

