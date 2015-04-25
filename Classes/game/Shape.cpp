#include "Shape.h"

NAMESPACE_G1_BEGIN

Shape::Shape(std::initializer_list<Grid> grids) : _grids(grids) 
, _minX(TETRIS_SIZE), _minY(TETRIS_SIZE) , _maxX(-1), _maxY(-1) {
}

Shape::~Shape() {
}

int Shape::minX() {
    if (_minX >= TETRIS_SIZE) {
        for (auto grid : _grids) {
            if (grid.x < _minX) {
                _minX = grid.x;
            }
        }
        CCASSERT(_minX >= 0 && _minX < TETRIS_SIZE, "Invalid shape!");
    }
    return _minX;
}

int Shape::minY() {
    if (_minY >= TETRIS_SIZE) {
        for (auto grid : _grids) {
            if (grid.y < _minY) {
                _minY = grid.y;
            }
        }
        CCASSERT(_minY >= 0 && _minY < TETRIS_SIZE, "Invalid shape!");
    }
    return _minY;
}

int Shape::maxX() {
    if (_maxX < 0) {
        for (auto grid : _grids) {
            if (grid.x > _maxX) {
                _maxX = grid.x;
            }
        }
        CCASSERT(_maxX >= 0 && _maxX < TETRIS_SIZE, "Invalid shape!");
    }
    return _maxX;
}

int Shape::maxY() {
    if (_maxY < 0) {
        for (auto grid : _grids) {
            if (grid.y > _maxY) {
                _maxY = grid.y;
            }
        }
        CCASSERT(_maxY >= 0 && _maxY < TETRIS_SIZE, "Invalid shape!");
    }
    return _maxY;
}

NAMESPACE_G1_END


