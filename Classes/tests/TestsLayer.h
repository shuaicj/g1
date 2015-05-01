#ifndef _G1_TESTS_LAYER_H_
#define _G1_TESTS_LAYER_H_

#include "Common.h"
#include "cocos2d.h"

NAMESPACE_G1_BEGIN

// This is the entry to all tests.
class TestsLayer : public cc::Layer {
public:
    TestsLayer();
    virtual ~TestsLayer();
    static TestsLayer* create();
    virtual bool init() override;

private:
    void onBack(cc::Ref* sender);
    void onTestShape(cc::Ref* sender);

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TestsLayer);
};

NAMESPACE_G1_END

#endif // _G1_TESTS_LAYER_H_
