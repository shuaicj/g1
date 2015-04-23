#include "HomeLayer.h"

NAMESPACE_GG_BEGIN

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
    if (!cc::Layer::init()) {
        return false;
    }
    
    return true;
}

NAMESPACE_GG_END

