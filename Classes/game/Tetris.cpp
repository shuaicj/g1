#include "Tetris.h"
#include "Shape.h"

NAMESPACE_G1_BEGIN

Tetris::Tetris(const Shape& shape) : _shape(shape), _index(-1) {
}

const Form* Tetris::transform() {
    _index++;
    auto forms = _shape.forms();
    if (_index >= forms.size()) {
        _index = 0;
    }
    return forms[_index];
}

NAMESPACE_G1_END
