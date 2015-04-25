#ifndef _G1_RESOLUTION_H_
#define _G1_RESOLUTION_H_

#include "Common.h"

NAMESPACE_G1_BEGIN

// design resolution
#define WIDTH  750
#define HEIGHT 1334

// resolution adapt
class Resolution {
public:
    // adapt x
    static float x(float x);

    // adapt y
    static float y(float y);
    
    // adapt xy
    static cc::Vec2 xy(float x, float y);

    // adapt Vec2
    static cc::Vec2 xy(const cc::Vec2& v);

    // adapt distance
    static float distance(float distance);

    // adapt Node
    static void adapt(cc::Node* node, float x, float y);

    // adapt background
    static void adaptBackground(cc::Node* node);
};

NAMESPACE_G1_END

#endif // _G1_RESOLUTION_H_
