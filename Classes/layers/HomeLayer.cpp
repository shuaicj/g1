#include "HomeLayer.h"
#include "Helper.h"
#include "TestsLayer.h"

NAMESPACE_G1_BEGIN

using namespace cc;

HomeLayer::HomeLayer() {
}

HomeLayer::~HomeLayer() {
}

HomeLayer* HomeLayer::create() {
    HomeLayer* layer = new HomeLayer();
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

    // show test
    auto testButton = MenuItemFont::create("TESTS", CC_CALLBACK_1(HomeLayer::onTest, this));
    testButton->setPosition(Vec2(WIDTH/2, HEIGHT/2));
    auto testMenu = Menu::create(testButton, nullptr);
    testMenu->setPosition(Vec2(0, 0));
    this->addChild(testMenu);
    
    return true;
}

void HomeLayer::onTest(Ref* sender) {
    ReplaceLayer(TestsLayer::create());
}

NAMESPACE_G1_END

