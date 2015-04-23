#ifndef _GG_HOME_LAYER_H_
#define _GG_HOME_LAYER_H_

#include "Common.h"
#include "cocos2d.h"

NAMESPACE_GG_BEGIN

class HomeLayer : public cc::Layer {
public:
    HomeLayer();
    virtual ~HomeLayer();
    static HomeLayer* create();
    virtual bool init();
};

NAMESPACE_GG_END

#endif // _GG_HOME_LAYER_H_
