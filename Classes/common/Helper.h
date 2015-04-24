#ifndef _G1_HELPER_H_
#define _G1_HELPER_H_

#include "Common.h"
#include "cocos2d.h"

NAMESPACE_G1_BEGIN

// use a layer to call Director::runWithScene
void RunWithLayer(cc::Layer* layer);

// use a layer to call Director::replaceScene
void ReplaceLayer(cc::Layer* layer);

NAMESPACE_G1_END

#endif // _G1_HELPER_H_
