#include "GameOverLayer.h"
#include "Helper.h"
#include "Resolution.h"
#include "HomeLayer.h"

NAMESPACE_G1_BEGIN

using namespace cc;

GameOverLayer::GameOverLayer() {
}

GameOverLayer::~GameOverLayer() {
}

GameOverLayer* GameOverLayer::create() {
    auto layer = new GameOverLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    } else {
        delete layer;
        layer = nullptr;
        return nullptr;
    }
}

bool GameOverLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    // dark
    auto dark = LayerColor::create(Color4B(0, 0, 0, 210));
    this->addChild(dark);

    // game over label
    auto label = Label::createWithSystemFont("Game Over", "", 40);
    Resolution::adapt(label, WIDTH/2, 800);
    this->addChild(label);

    // back 
    auto backButton = MenuItemFont::create("BACK", HANDLER1(GameOverLayer::onBack));
    Resolution::adapt(backButton, WIDTH/2, HEIGHT/2);
    auto backMenu = Menu::create(backButton, nullptr);
    backMenu->setPosition(0, 0);
    this->addChild(backMenu);

    // touch
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = HANDLER2(GameOverLayer::onTouchBegan);
    listener->onTouchMoved = HANDLER2(GameOverLayer::onTouchMoved);
    listener->onTouchEnded = HANDLER2(GameOverLayer::onTouchEnded);
    listener->onTouchCancelled = HANDLER2(GameOverLayer::onTouchCancelled);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void GameOverLayer::onBack(Ref* sender) {
    ReplaceLayer(HomeLayer::create());
}

bool GameOverLayer::onTouchBegan(Touch* touch, Event* event) {
    return true;
}

void GameOverLayer::onTouchMoved(Touch* touch, Event* event) {
}

void GameOverLayer::onTouchEnded(Touch* touch, Event* event) {
}

void GameOverLayer::onTouchCancelled(Touch* touch, Event* event) {
    onTouchEnded(touch, event);
}

NAMESPACE_G1_END

