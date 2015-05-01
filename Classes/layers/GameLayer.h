#ifndef _G1_GAME_LAYER_H_
#define _G1_GAME_LAYER_H_

#include "Common.h"
#include "cocos2d.h"
#include "GameState.h"

NAMESPACE_G1_BEGIN

class Shape;
class Tetris;
class Board;

// This is wher you play this game.
class GameLayer : public cc::Layer {
public:
    GameLayer();
    virtual ~GameLayer();
    static GameLayer* create();
    virtual bool init() override;
    virtual void update(float dt) override;

private:
    cc::Vec2 getPositionForBoardGrid(int boardX, int boardY);

    void drawBoardGrids();
    void drawTetris();
    void drawShadow();
    void drawNextTetris();
    cc::Node* createTetrisGrid(const Tetris* tetris);
    cc::Node* createShadowGrid(const Tetris* tetris);
    void setPositionForTetris();
    void setPositionForShadow();

    void showBoardLabels();
    void showLineCountLabel();
    void showScoreLabel();

    void moveDown(int step);
    void moveLeft(int step);
    void moveRight(int step);
    void rotate();

    int getScore(int line);
    void clearScoreLines();

    bool isGameOver();

    void onLeft(cc::Ref* sender);
    void onRight(cc::Ref* sender);
    void onSlowDown(cc::Ref* sender);
    void onFastDown(cc::Ref* sender);
    void onRotate(cc::Ref* sender);

    void onBack(cc::Ref* sender);

private:
    cc::Node* _bgGrids[BOARD_WIDTH][BOARD_HEIGHT]; // board bg grids
    cc::Node* _fgGrids[BOARD_WIDTH][BOARD_HEIGHT]; // board fg grids
    cc::Label* _fgLabels[BOARD_WIDTH][BOARD_HEIGHT]; // board fg labels for debug
    cc::Node* _tetrisGrids[TETRIS_SIZE][TETRIS_SIZE]; // tetris on board
    cc::Node* _shadowGrids[TETRIS_SIZE][TETRIS_SIZE]; // tetris shadow on board
    cc::Node* _nextTetrisGrids[TETRIS_SIZE][TETRIS_SIZE]; // hint of next tetris

    cc::Label* _lineCountLabel;
    cc::Label* _scoreLabel;

    GameState _state;

    Board* _board;

    Tetris* _tetris;
    Tetris* _nextTetris;

    float _timer;

    int _lineCount;
    int _score;

    std::vector<int> _scoreLines;

    CC_DISALLOW_COPY_AND_ASSIGN(GameLayer);
};

NAMESPACE_G1_END

#endif // _G1_GAME_LAYER_H_
