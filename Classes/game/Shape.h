#ifndef _G1_SHAPE_H_
#define _G1_SHAPE_H_

#include "Common.h"

#include <vector>
#include <initializer_list>

NAMESPACE_G1_BEGIN

class Form;

// There are 7 kinds of Shape: I, O, J, L, S, Z, T.
// Each Shape has several Form. Shape can transform from one Form to another.
class Shape {
public:
    Shape(std::initializer_list<const Form*> forms) : _forms(forms) {}
    virtual ~Shape() {}

    const std::vector<const Form*>& forms() const { return _forms; }

    static const Shape I;
    static const Shape O;
    static const Shape J;
    static const Shape L;
    static const Shape S;
    static const Shape Z;
    static const Shape T;
    static const std::vector<const Shape*> ALL;

private:
    std::vector<const Form*> _forms;

    CC_DISALLOW_COPY_AND_ASSIGN(Shape);
};

NAMESPACE_G1_END

#endif // _G1_SHAPE_H_
