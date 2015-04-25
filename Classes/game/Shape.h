// Definition of struct Coordinate, class Form, class Shape.
// There are 7 kinds of Shape: I, O, J, L, S, Z, T.
// Each Shape has several Form. Shape can transform from one Form to another.
// Each Form has an array of Coordinate, which means the valid points in a tetris matrix.
// The width and height of tetris matrix is [TETRIS_SIZE*TETRIS_SIZE].

#ifndef _G1_SHAPE_H_
#define _G1_SHAPE_H_

#include "Common.h"

#include <vector>
#include <initializer_list>

NAMESPACE_G1_BEGIN

struct Coordinate {
    int x;
    int y;
};

class Form {
public:
    Form(std::initializer_list<Coordinate> points);
    virtual ~Form() {}

    inline int minX() const { return _minX; }
    inline int minY() const { return _minY; }
    inline int maxX() const { return _maxX; }
    inline int maxY() const { return _maxY; }
    inline const std::vector<Coordinate>& points() const { return _points; }

    static const Form I0;
    static const Form I1;
    static const Form O;
    static const Form J0;
    static const Form J1;
    static const Form J2;
    static const Form J3;
    static const Form L0;
    static const Form L1;
    static const Form L2;
    static const Form L3;
    static const Form S0;
    static const Form S1;
    static const Form Z0;
    static const Form Z1;
    static const Form T0;
    static const Form T1;
    static const Form T2;
    static const Form T3;

private:
    std::vector<Coordinate> _points;
    int _minX;
    int _minY;
    int _maxX;
    int _maxY;

    CC_DISALLOW_COPY_AND_ASSIGN(Form);
};

class Shape {
public:
    Shape(std::initializer_list<const Form*> forms);
    virtual ~Shape() {}

    inline const std::vector<const Form*>& forms() const { return _forms; };

    static const Shape I;
    static const Shape O;
    static const Shape J;
    static const Shape L;
    static const Shape S;
    static const Shape Z;
    static const Shape T;

private:
    std::vector<const Form*> _forms;

    CC_DISALLOW_COPY_AND_ASSIGN(Shape);
};

NAMESPACE_G1_END

#endif // _G1_SHAPE_H_
