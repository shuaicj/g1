#ifndef _G1_TETRIS_H_
#define _G1_TETRIS_H_

#include "Common.h"

#include <vector>

NAMESPACE_G1_BEGIN

class Shape;
class Form;
class Board;

// A Tetris is a Shape with states.
class Tetris {
public:
    Tetris(const Board* board);
    Tetris(const Shape* shape);
    virtual ~Tetris() {}

    const Shape* shape() const { return _shape; }
    const Board* board() const { return _board; }

    // current form
    const Form* form() const;

    // move to next form
    const Form* transform();

    // the bottom left corner of the tetris on board
    const int boardX() const { return _x; }
    const int boardY() const { return _y; }

    // convert to coordnate on board
    const int boardX(int x) const { return _x + x; }
    const int boardY(int y) const { return _y + y; }

    // consider board boundary
    bool isInBoard(int x, int y) const;
    bool exists(int x, int y) const;

    // move some step as it can.
    // return the real step it moved.
    int moveDown(int step);
    int moveLeft(int step);
    int moveRight(int step);

private:
    void init();

    // if the board and the tetris need to occupy at least one same point, return true.
    bool conflicts(int index, int boardX, int boardY) const;
    bool conflicts(int index) { return conflicts(index, _x, _y); }

private:
    const Shape* _shape;
    const Board* _board;
    int _index; // form index
    int _x, _y; // the coordnateof this tetris (the bottom left corner) on board

    CC_DISALLOW_COPY_AND_ASSIGN(Tetris);
};

NAMESPACE_G1_END

#endif // _G1_TETRIS_H_
