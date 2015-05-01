#include "TestsLayer.h"
#include "Helper.h"
#include "Resolution.h"
#include "HomeLayer.h"
#include "TestShapeLayer.h"

NAMESPACE_G1_BEGIN

using namespace cc;

TestsLayer::TestsLayer() {
}

TestsLayer::~TestsLayer() {
}

TestsLayer* TestsLayer::create() {
    auto layer = new TestsLayer();
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
    auto backButton = MenuItemFont::create("BACK", HANDLER1(TestsLayer::onBack));
    Resolution::adapt(backButton, WIDTH/2, 30);
    auto backMenu = Menu::create(backButton, nullptr);
    backMenu->setPosition(0, 0);
    this->addChild(backMenu);
    
    // test Shape
    auto shapeButton = MenuItemFont::create("Shape", HANDLER1(TestsLayer::onTestShape));
    Resolution::adapt(shapeButton, WIDTH/2, 1000);
    auto shapeMenu = Menu::create(shapeButton, nullptr);
    shapeMenu->setPosition(0, 0);
    this->addChild(shapeMenu);

    return true;
}

void TestsLayer::onBack(Ref* sender) {
    ReplaceLayer(HomeLayer::create());
}

void TestsLayer::onTestShape(Ref* sender) {
    ReplaceLayer(TestShapeLayer::create());
}

NAMESPACE_G1_END

