#include "Helper.h"
#include "Common.h"
#include "cocos2d.h"

NAMESPACE_GG_BEGIN

void RunWithLayer(cc::Layer* layer) {
    auto scene = cc::Scene::create();
    scene->addChild(layer);
    cc::Director::getInstance()->runWithScene(scene);
}

void ReplaceLayer(cc::Layer* layer) {
    auto scene = cc::Scene::create();
    scene->addChild(layer);
    cc::Director::getInstance()->replaceScene(scene);
}

NAMESPACE_GG_END


