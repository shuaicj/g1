#include "Helper.h"
#include "Common.h"

NAMESPACE_G1_BEGIN

using namespace cc;

void RunWithLayer(Layer* layer) {
    auto scene = Scene::create();
    scene->addChild(layer);
    Director::getInstance()->runWithScene(scene);
}

void ReplaceLayer(Layer* layer) {
    auto scene = Scene::create();
    scene->addChild(layer);
    Director::getInstance()->replaceScene(scene);
}

NAMESPACE_G1_END


