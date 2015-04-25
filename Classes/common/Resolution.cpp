#include "Resolution.h"

NAMESPACE_G1_BEGIN

using namespace cc;

static float minScale = 0.f;
static float maxScale = 0.f;
static float minX = 0.f;
static float minY = 0.f;

static void lazyInit() {
    if (minScale == 0.f) {
        auto size = Director::getInstance()->getOpenGLView()->getFrameSize();
        auto scaleX = size.width / WIDTH;
        auto scaleY = size.height / HEIGHT;
        minScale = scaleX < scaleY ? scaleX : scaleY;
        maxScale = scaleX > scaleY ? scaleX : scaleY;
        minX = (size.width - WIDTH * minScale) / 2;
        minY = (size.height - HEIGHT * minScale) / 2;
    }
}

float Resolution::x(float x) {
    lazyInit();
    return minX + x * minScale;
}

float Resolution::y(float y) {
    lazyInit();
    return minY + y * minScale;
}

Vec2 Resolution::xy(float x, float y) {
    return Vec2(Resolution::x(x), Resolution::y(y));
}

Vec2 Resolution::xy(const cc::Vec2& v) {
    return Resolution::xy(v.x, v.y);
}

float Resolution::distance(float distance) {
    return distance * minScale;
}

void Resolution::adapt(Node* node, float x, float y) {
    lazyInit();
    node->setScale(node->getScale() * minScale);
    node->setPosition(Resolution::xy(x, y));
}

void Resolution::adaptBackground(Node* node) {
    lazyInit();
    node->setScale(maxScale);
    node->setPosition(Resolution::xy(WIDTH/2, HEIGHT/2));
}

NAMESPACE_G1_END

