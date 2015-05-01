#ifndef _G1_FORM_H_
#define _G1_FORM_H_

#include "Common.h"

#include <vector>
#include <initializer_list>

NAMESPACE_G1_BEGIN

// Each Shape has several Form. Shape can transform from one Form to another.
class Form {
public:
    Form(std::initializer_list<bool> matrix);
    virtual ~Form() {}

    int minX() const { return _minX; }
    int minY() const { return _minY; }
    int maxX() const { return _maxX; }
    int maxY() const { return _maxY; }
    int width() const { return _maxX - _minX + 1; }
    int height() const { return _maxY - _minY + 1; }
    bool exists(int x, int y) const { return _matrix[x][y]; }

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
    bool _matrix[TETRIS_SIZE][TETRIS_SIZE];
    int _minX;
    int _minY;
    int _maxX;
    int _maxY;

    CC_DISALLOW_COPY_AND_ASSIGN(Form);
};

NAMESPACE_G1_END

#endif // _G1_FORM_H_
