#ifndef _G1_BOARD_H_
#define _G1_BOARD_H_

#include "Common.h"

NAMESPACE_G1_BEGIN

// The game board.
class Board {
public:
    Board();
    virtual ~Board() {}

    bool exists(int x, int y) const { return _matrix[x][y]; }
    void set(int x, int y, bool b) { _matrix[x][y] = b; }

private:
    bool _matrix[BOARD_WIDTH][BOARD_HEIGHT];

    CC_DISALLOW_COPY_AND_ASSIGN(Board);
};

NAMESPACE_G1_END

#endif // _G1_BOARD_H_
