#include "Board.h"

NAMESPACE_G1_BEGIN

Board::Board() {
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            _matrix[x][y] = 0;
        }
    }
}

NAMESPACE_G1_END


