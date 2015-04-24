#include "TestsLayer.h"
#include "Helper.h"
#include "Resolution.h"
#include "HomeLayer.h"

NAMESPACE_G1_BEGIN

using namespace cc;

TestsLayer::TestsLayer() {
}

TestsLayer::~TestsLayer() {
}

TestsLayer* TestsLayer::create() {
    TestsLayer* layer = new TestsLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    } else {
        delete layer;
        layer = nullptr;
        return nullptr;
    }
}

bool TestsLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    // back to HomeLayer
    auto backButton = MenuItemFont::create("BACK", CC_CALLBACK_1(TestsLayer::onBack, this));
    backButton->setPosition(Resolution::xy(WIDTH/2, 200));
    auto backMenu = Menu::create(backButton, nullptr);
    backMenu->setPosition(Resolution::xy(0, 0));
    this->addChild(backMenu);
    
    return true;
}

void TestsLayer::onBack(Ref* sender) {
    ReplaceLayer(HomeLayer::create());
}

NAMESPACE_G1_END

