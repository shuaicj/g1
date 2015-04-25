#include "TestShapeLayer.h"
#include "Helper.h"
#include "Resolution.h"
#include "TestsLayer.h"
#include "Shape.h"

NAMESPACE_G1_BEGIN

using namespace cc;

TestShapeLayer::TestShapeLayer() {
}

TestShapeLayer::~TestShapeLayer() {
}

TestShapeLayer* TestShapeLayer::create() {
    auto layer = new TestShapeLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    } else {
        delete layer;
        layer = nullptr;
        return nullptr;
    }
}

bool TestShapeLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    // back to HomeLayer
    auto backButton = MenuItemFont::create("BACK", HANDLER(TestShapeLayer::onBack));
    Resolution::adapt(backButton, WIDTH/2, 200);
    auto backMenu = Menu::create(backButton, nullptr);
    backMenu->setPosition(0, 0);
    this->addChild(backMenu);

    Grid s = { 1, 2 };
    CCLOG("Grid x:%d y:%d", s.x, s.y);


    Shape ss = {
        { 1, 2 },
        { 3, 4 },
    };
    
    return true;
}

void TestShapeLayer::onBack(Ref* sender) {
    ReplaceLayer(TestsLayer::create());
}

NAMESPACE_G1_END

