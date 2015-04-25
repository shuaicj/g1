#ifndef _G1_SHAPE_H_
#define _G1_SHAPE_H_

#include "Common.h"

#include <vector>
#include <initializer_list>

NAMESPACE_G1_BEGIN

struct Grid {
    int x;
    int y;
};

class Shape {
public:
    Shape(std::initializer_list<Grid> grids);
    virtual ~Shape();

    int minX();
    int minY();
    int maxX();
    int maxY();

private:
    std::vector<Grid> _grids;
    int _minX;
    int _minY;
    int _maxX;
    int _maxY;
};

NAMESPACE_G1_END

#endif // _G1_SHAPE_H_
