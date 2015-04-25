#ifndef _G1_COMMON_H_
#define _G1_COMMON_H_

// rename namespace cocos2d to cc
namespace cc = cocos2d;

// project namespace
#define NAMESPACE_G1_BEGIN namespace g1 {
#define NAMESPACE_G1_END }

// a more simple callback
#define HANDLER(func) (CC_CALLBACK_1(func, this))

#endif // _G1_COMMON_H_
