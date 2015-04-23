#ifndef _G1_HOME_LAYER_H_
#define _G1_HOME_LAYER_H_

#include "Common.h"
#include "cocos2d.h"

NAMESPACE_G1_BEGIN

// This is the first UI you'll see when entering the game.
class HomeLayer : public cc::Layer {
public:
    HomeLayer();
    virtual ~HomeLayer();
    static HomeLayer* create();
    virtual bool init();

    void onTest(cc::Ref* sender);
};

NAMESPACE_G1_END

#endif // _G1_HOME_LAYER_H_
