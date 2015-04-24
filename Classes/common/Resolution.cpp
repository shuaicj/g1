#include "Resolution.h"

NAMESPACE_G1_BEGIN

using namespace cc;

static float scale = 0.f;
static float minX = 0.f;
static float minY = 0.f;

static void lazyInit() {
    if (scale == 0.f) {
        auto size = Director::getInstance()->getOpenGLView()->getFrameSize();
        auto scaleX = size.width / WIDTH;
        auto scaleY = size.height / HEIGHT;
        scale = scaleX < scaleY ? scaleX : scaleY;
        minX = (size.width - WIDTH * scale) / 2;
        minY = (size.height - HEIGHT * scale) / 2;
    }
}

float Resolution::x(float x) {
    lazyInit();
    return minX + x * scale;
}

float Resolution::y(float y) {
    lazyInit();
    return minY + y * scale;
}

Vec2 Resolution::xy(float x, float y) {
    return Vec2(Resolution::x(x), Resolution::y(y));
}

Vec2 Resolution::xy(const cc::Vec2& v) {
    return Resolution::xy(v.x, v.y);
}

NAMESPACE_G1_END

