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

// rename namespace cocos2d to cc
namespace cc = cocos2d;

// project namespace
#define NAMESPACE_G1_BEGIN namespace g1 {
#define NAMESPACE_G1_END }

// a more simple callback
#define HANDLER(func) (CC_CALLBACK_1(func, this))

#endif // _G1_COMMON_H_
