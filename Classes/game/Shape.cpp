#include "Shape.h"
#include "Form.h"

NAMESPACE_G1_BEGIN

const Shape Shape::I = { &Form::I0, &Form::I1 };
const Shape Shape::O = { &Form::O };
const Shape Shape::J = { &Form::J0, &Form::J1, &Form::J2, &Form::J3 };
const Shape Shape::L = { &Form::L0, &Form::L1, &Form::L2, &Form::L3 };
const Shape Shape::S = { &Form::S0, &Form::S1 };
const Shape Shape::Z = { &Form::Z0, &Form::Z1 };
const Shape Shape::T = { &Form::T0, &Form::T1, &Form::T2, &Form::T3 };

const std::vector<const Shape*> Shape::ALL = { 
    &Shape::I, &Shape::O, &Shape::J, &Shape::L, &Shape::S, &Shape::Z, &Shape::T
};

NAMESPACE_G1_END


