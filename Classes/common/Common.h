#ifndef _G1_COMMON_H_
#define _G1_COMMON_H_

// design resolution
#define WIDTH  750
#define HEIGHT 1334

// tetris num: seven shapes I,O,J,L,S,Z,T
#define TETRIS_NUM 7

// tetris matrix size
#define TETRIS_SIZE  4

// board width and height
#define BOARD_WIDTH  10
#define BOARD_HEIGHT 20

// tetris falling interval
#define FALL_INTERVAL 1.1f

// the grid num of fall
#define DISTANCE_OF_SLOW_FALL 3
#define DISTANCE_OF_FAST_FALL (2 * BOARD_HEIGHT)

// scores
#define SCORE_LINE_1 10
#define SCORE_LINE_2 30
#define SCORE_LINE_3 60
#define SCORE_LINE_4 100

// rename namespace cocos2d to cc
namespace cc = cocos2d;

// project namespace
#define NAMESPACE_G1_BEGIN namespace g1 {
#define NAMESPACE_G1_END }

// more simple callback
#define HANDLER0(func) (CC_CALLBACK_0(func, this))
#define HANDLER1(func) (CC_CALLBACK_1(func, this))
#define HANDLER2(func) (CC_CALLBACK_2(func, this))

// safe delete 
#define SAFE_DELETE(p) do { if (p) { delete(p); (p) = nullptr; } } while(0)

#endif // _G1_COMMON_H_
