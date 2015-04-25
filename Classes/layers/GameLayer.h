#ifndef _G1_GAME_LAYER_H_
#define _G1_GAME_LAYER_H_

#include "Common.h"
#include "cocos2d.h"

NAMESPACE_G1_BEGIN

// This is wher you play this game.
class GameLayer : public cc::Layer {
public:
    GameLayer();
    virtual ~GameLayer();
    static GameLayer* create();
    virtual bool init();

    void onBack(cc::Ref* sender);

private:
    cc::Node* _bgGrids[BOARD_WIDTH][BOARD_HEIGHT]; // board bg grids
    cc::Node* _fgGrids[BOARD_WIDTH][BOARD_HEIGHT]; // board fg grids
    cc::Node* _tetrisGrids[TETRIS_SIZE][TETRIS_SIZE]; 

    CC_DISALLOW_COPY_AND_ASSIGN(GameLayer);
};

NAMESPACE_G1_END

#endif // _G1_GAME_LAYER_H_
