#ifndef _G1_GAME_OVER_LAYER_H_
#define _G1_GAME_OVER_LAYER_H_

#include "Common.h"
#include "cocos2d.h"

NAMESPACE_G1_BEGIN

// The layer when game is over.
class GameOverLayer : public cc::Layer {
public:
    GameOverLayer();
    virtual ~GameOverLayer();
    static GameOverLayer* create();
    virtual bool init() override;

private:
    void onBack(cc::Ref* sender);

    bool onTouchBegan(cc::Touch* touch, cc::Event* event);
    void onTouchMoved(cc::Touch* touch, cc::Event* event);
    void onTouchEnded(cc::Touch* touch, cc::Event* event);
    void onTouchCancelled(cc::Touch* touch, cc::Event* event);

private:
    CC_DISALLOW_COPY_AND_ASSIGN(GameOverLayer);
};

NAMESPACE_G1_END

#endif // _G1_GAME_OVER_LAYER_H_
