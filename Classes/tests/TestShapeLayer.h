#ifndef _G1_TEST_SHAPE_LAYER_H_
#define _G1_TEST_SHAPE_LAYER_H_

#include "Common.h"
#include "cocos2d.h"

NAMESPACE_G1_BEGIN

// This is where to test Shape
class TestShapeLayer : public cc::Layer {
public:
    TestShapeLayer();
    virtual ~TestShapeLayer();
    static TestShapeLayer* create();
    virtual bool init();

    void onBack(cc::Ref* sender);
};

NAMESPACE_G1_END

#endif // _G1_TEST_SHAPE_LAYER_H_
