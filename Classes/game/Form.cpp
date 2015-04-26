#include "Form.h"

NAMESPACE_G1_BEGIN

Form::Form(std::initializer_list<bool> matrix) 
: _minX(TETRIS_SIZE), _minY(TETRIS_SIZE) , _maxX(-1), _maxY(-1) {
    int count = -1;
    for (auto b : matrix) {
        count++;
        if (count < TETRIS_SIZE * TETRIS_SIZE) {
            int x = count / TETRIS_SIZE;
            int y = count % TETRIS_SIZE;
            _matrix[x][y] = b;
            if (b && x < _minX) {
                _minX = x;
            }
            if (b && y < _minY) {
                _minY = y;
            }
            if (b && x > _maxX) {
                _maxX = x;
            }
            if (b && y > _maxY) {
                _maxY = y;
            }
        } else {
            break;
        }
    }
}

//  - O - -
//  - O - -
//  - O - -
//  - O - -
const Form Form::I0 = { 0,0,0,0, 1,1,1,1, 0,0,0,0, 0,0,0,0, };

//  - - - -
//  - - - -
//  - - - -
//  O O O O
const Form Form::I1 = { 1,0,0,0,  1,0,0,0,  1,0,0,0,  1,0,0,0, };

//  - - - -
//  - - - -
//  O O - -
//  O O - -
const Form Form::O = { 1,1,0,0,  1,1,0,0,  0,0,0,0,  0,0,0,0, };

//  - - - -
//  - O - -
//  - O - -
//  O O - -
const Form Form::J0 = { 1,0,0,0,  1,1,1,0,  0,0,0,0,  0,0,0,0, };

//  - - - -
//  - - - -
//  O - - -
//  O O O -
const Form Form::J1 = { 1,1,0,0,  1,0,0,0,  1,0,0,0,  0,0,0,0, };

//  - - - -
//  O O - -
//  O - - -
//  O - - -
const Form Form::J2 = { 1,1,1,0,  0,0,1,0,  0,0,0,0,  0,0,0,0, };

//  - - - -
//  - - - -
//  O O O -
//  - - O -
const Form Form::J3 = { 0,1,0,0,  0,1,0,0,  1,1,0,0,  0,0,0,0, };

//  - - - -
//  O - - -
//  O - - -
//  O O - -
const Form Form::L0 = { 1,1,1,0,  1,0,0,0,  0,0,0,0,  0,0,0,0, };

//  - - - -
//  - - - -
//  O O O -
//  O - - -
const Form Form::L1 = { 1,1,0,0,  0,1,0,0,  0,1,0,0,  0,0,0,0, };

//  - - - -
//  O O - -
//  - O - -
//  - O - -
const Form Form::L2 = { 0,0,1,0,  1,1,1,0,  0,0,0,0,  0,0,0,0, };

//  - - - -
//  - - - -
//  - - O -
//  O O O -
const Form Form::L3 = { 1,0,0,0,  1,0,0,0,  1,1,0,0,  0,0,0,0, };

//  - - - -
//  - - - -
//  - O O -
//  O O - -
const Form Form::S0 = { 1,0,0,0,  1,1,0,0,  0,1,0,0,  0,0,0,0, };

//  - - - -
//  - O - -
//  - O O -
//  - - O -
const Form Form::S1 = { 0,0,0,0,  0,1,1,0,  1,1,0,0,  0,0,0,0, };

//  - - - -
//  - - - -
//  O O - -
//  - O O -
const Form Form::Z0 = { 0,1,0,0,  1,1,0,0,  1,0,0,0,  0,0,0,0, };

//  - - - -
//  - O - -
//  O O - -
//  O - - -
const Form Form::Z1 = { 1,1,0,0,  0,1,1,0,  0,0,0,0,  0,0,0,0, };

//  - - - -
//  - - - -
//  O O O -
//  - O - -
const Form Form::T0 = { 0,1,0,0,  1,1,0,0,  0,1,0,0,  0,0,0,0, };

//  - - - -
//  - O - -
//  O O - -
//  - O - -
const Form Form::T1 = { 0,1,0,0,  1,1,1,0,  0,0,0,0,  0,0,0,0, };

//  - - - -
//  - - - -
//  - O - -
//  O O O -
const Form Form::T2 = { 1,0,0,0,  1,1,0,0,  1,0,0,0,  0,0,0,0, };

//  - - - -
//  - O - -
//  - O O -
//  - O - -
const Form Form::T3 = { 0,0,0,0,  1,1,1,0,  0,1,0,0,  0,0,0,0, };

NAMESPACE_G1_END


