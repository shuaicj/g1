#ifndef _G1_TETRIS_H_
#define _G1_TETRIS_H_

#include "Common.h"

#include <vector>

NAMESPACE_G1_BEGIN

class Shape;
class Form;

// A Tetris is a Shape with states.
class Tetris {
public:
    Tetris(const Shape& shape);
    virtual ~Tetris() {}

    // move to next form
    const Form* transform();

private:
    const Shape& _shape;
    int _index; // form index

    CC_DISALLOW_COPY_AND_ASSIGN(Tetris);
};

NAMESPACE_G1_END

#endif // _G1_TETRIS_H_
