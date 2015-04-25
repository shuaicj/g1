#ifndef _G1_TEST_SHAPE_LAYER_H_
#define _G1_TEST_SHAPE_LAYER_H_

#include "Common.h"
#include "cocos2d.h"

NAMESPACE_G1_BEGIN

class Tetris;

// This is where to test Shape
class TestShapeLayer : public cc::Layer {
public:
    TestShapeLayer();
    virtual ~TestShapeLayer();
    static TestShapeLayer* create();
    virtual bool init();

    void showNextTetris(int index);

    void onNext(cc::Ref* sender);
    void onBack(cc::Ref* sender);

private:
    cc::Node* _bgGrids[TETRIS_NUM][TETRIS_SIZE][TETRIS_SIZE];
    cc::Node* _fgGrids[TETRIS_NUM][TETRIS_SIZE][TETRIS_SIZE];
    cc::Label* _labels[TETRIS_NUM];

    Tetris* _tetrises[TETRIS_NUM];

    CC_DISALLOW_COPY_AND_ASSIGN(TestShapeLayer);
};

NAMESPACE_G1_END

#endif // _G1_TEST_SHAPE_LAYER_H_
