#include "Shape.h"

NAMESPACE_G1_BEGIN

Form::Form(std::initializer_list<Coordinate> points) : _points(points) 
, _minX(TETRIS_SIZE), _minY(TETRIS_SIZE) , _maxX(-1), _maxY(-1) {
    for (auto p : _points) {
        if (p.x < _minX) {
            _minX = p.x;
        }
        if (p.y < _minY) {
            _minY = p.y;
        }
        if (p.x > _maxX) {
            _maxX = p.x;
        }
        if (p.y > _maxY) {
            _maxY = p.y;
        }
    }
}

Shape::Shape(std::initializer_list<const Form*> forms) : _forms(forms) {
}

//  - O - -
//  - O - -
//  - O - -
//  - O - -
const Form Form::I0 = { {1,0}, {1,1}, {1,2}, {1,3} };

//  - - - -
//  - - - -
//  - - - -
//  O O O O
const Form Form::I1 = { {0,0}, {1,0}, {2,0}, {3,0} };

//  - - - -
//  - - - -
//  O O - -
//  O O - -
const Form Form::O = { {0,0}, {0,1}, {1,0}, {1,1} };

//  - - - -
//  - O - -
//  - O - -
//  O O - -
const Form Form::J0 = { {0,0}, {1,0}, {1,1}, {1,2} };

//  - - - -
//  - - - -
//  O - - -
//  O O O -
const Form Form::J1 = { {0,0}, {0,1}, {1,0}, {2,0} };

//  - - - -
//  O O - -
//  O - - -
//  O - - -
const Form Form::J2 = { {0,0}, {0,1}, {0,2}, {1,2} };

//  - - - -
//  - - - -
//  O O O -
//  - - O -
const Form Form::J3 = { {0,1}, {1,1}, {2,0}, {2,1} };

//  - - - -
//  O - - -
//  O - - -
//  O O - -
const Form Form::L0 = { {0,0}, {0,1}, {0,2}, {1,0} };

//  - - - -
//  - - - -
//  O O O -
//  O - - -
const Form Form::L1 = { {0,0}, {0,1}, {1,1}, {2,1} };

//  - - - -
//  O O - -
//  - O - -
//  - O - -
const Form Form::L2 = { {0,2}, {1,0}, {1,1}, {1,2} };

//  - - - -
//  - - - -
//  - - O -
//  O O O -
const Form Form::L3 = { {0,0}, {1,0}, {2,0}, {2,1} };

//  - - - -
//  - - - -
//  - O O -
//  O O - -
const Form Form::S0 = { {0,0}, {1,0}, {1,1}, {2,1} };

//  - - - -
//  - O - -
//  - O O -
//  - - O -
const Form Form::S1 = { {1,1}, {1,2}, {2,0}, {2,1} };

//  - - - -
//  - - - -
//  O O - -
//  - O O -
const Form Form::Z0 = { {0,1}, {1,0}, {1,1}, {2,0} };

//  - - - -
//  - O - -
//  O O - -
//  O - - -
const Form Form::Z1 = { {0,0}, {0,1}, {1,1}, {1,2} };

//  - - - -
//  - - - -
//  O O O -
//  - O - -
const Form Form::T0 = { {0,1}, {1,0}, {1,1}, {2,1} };

//  - - - -
//  - O - -
//  O O - -
//  - O - -
const Form Form::T1 = { {0,1}, {1,0}, {1,1}, {1,2} };

//  - - - -
//  - - - -
//  - O - -
//  O O O -
const Form Form::T2 = { {0,0}, {1,0}, {1,1}, {2,0} };

//  - - - -
//  - O - -
//  - O O -
//  - O - -
const Form Form::T3 = { {1,0}, {1,1}, {1,2}, {2,1} };

const Shape Shape::I = { &Form::I0, &Form::I1 };
const Shape Shape::O = { &Form::O };
const Shape Shape::J = { &Form::J0, &Form::J1, &Form::J2, &Form::J3 };
const Shape Shape::L = { &Form::L0, &Form::L1, &Form::L2, &Form::L3 };
const Shape Shape::S = { &Form::S0, &Form::S1 };
const Shape Shape::Z = { &Form::Z0, &Form::Z1 };
const Shape Shape::T = { &Form::T0, &Form::T1, &Form::T2, &Form::T3 };

NAMESPACE_G1_END


