#include "Tetris.h"
#include "Shape.h"
#include "Form.h"
#include "Board.h"

NAMESPACE_G1_BEGIN

Tetris::Tetris(const Board* board) : _board(board), _shape(nullptr) {
    init();
}

Tetris::Tetris(const Shape* shape) : _shape(shape), _board(nullptr) {
    init();
}

void Tetris::init() {
    if (!_shape) {
        _shape = Shape::ALL[rand()%TETRIS_NUM];
    }
    _index = rand() % _shape->forms().size();
    if (_board) {
        auto form = _shape->forms()[_index];
        _x = (BOARD_WIDTH-1)/2 - (form->minX()+form->maxX())/2;
        _y = BOARD_HEIGHT - form->minY();
    } else {
        _x = 0;
        _y = 0;
    }
}

const Form* Tetris::form() const {
    return _shape->forms()[_index];
}

const Form* Tetris::transform() {
    int temp = _index + 1;
    if (temp >= _shape->forms().size()) {
        temp = 0;
    }
    if (!conflicts(temp)) {
        auto form = _shape->forms()[temp];
        if (boardX(form->minX()) >= 0 && boardX(form->maxX()) < BOARD_WIDTH) {
            _index = temp;
            return form;
        }
        // when transforming at the left side of the board
        if (boardX(form->minX()) < 0) {
            int offset = - boardX(form->minX());
            if (!conflicts(temp, _x+offset, _y)) {
                _x += offset;
                _index = temp;
                return form;
            }
        }
        // when transforming at the right side of the board
        if (boardX(form->maxX()) >= BOARD_WIDTH) {
            int offset = boardX(form->maxX()) - (BOARD_WIDTH - 1);
            if (!conflicts(temp, _x-offset, _y)) {
                _x -= offset;
                _index = temp;
                return form;
            }
        }
    }
    return nullptr;
}

int Tetris::boardYForShadow() const {
    assert(_board);
    int rt = BOARD_HEIGHT;
    int minBoardY = - form()->minY();
    for (int boardY = BOARD_HEIGHT; boardY >= minBoardY; --boardY) {
        if (conflicts(_index, _x, boardY)) {
            return rt;
        } else {
            rt = boardY;
        }
    }

    // impossible to be here
    return 0;
}

int Tetris::minX() const { 
    return form()->minX(); 
}

int Tetris::minY() const { 
    return form()->minY(); 
}

int Tetris::maxX() const { 
    return form()->maxX(); 
}

int Tetris::maxY() const {
    return form()->maxY(); 
}

int Tetris::width() const {
    return form()->width();
}

int Tetris::height() const { 
    return form()->height();
}

bool Tetris::isInBoard(int x, int y) const {
    return _x + x >= 0 && _x + x < BOARD_WIDTH && _y + y >= 0 && _y + y < BOARD_HEIGHT;
}

bool Tetris::exists(int x, int y) const { 
    return form()->exists(x, y); 
}

int Tetris::moveDown(int step) {
    int rt = 0;
    for (int i = 1; i <= step; ++i) {
        if (_y - i + form()->minY() < 0 || conflicts(_index, _x, _y - i)) {
            break;
        }
        rt = i;
    }

    _y -= rt;

    return rt;
}

int Tetris::moveLeft(int step) {
    int rt = 0;
    for (int i = 1; i <= step; ++i) {
        if (_x - i + form()->minX() < 0 || conflicts(_index, _x - i, _y)) {
            break;
        }
        rt = i;
    }

    _x -= rt;

    return rt;
}

int Tetris::moveRight(int step) {
    int rt = 0;
    for (int i = 1; i <= step; ++i) {
        if (_x + i + form()->maxX() >= BOARD_WIDTH || conflicts(_index, _x + i, _y)) {
            break;
        }
        rt = i;
    }

    _x += rt;

    return rt;
}

bool Tetris::conflicts(int index, int boardX, int boardY) const {
    assert(index >= 0 && index < _shape->forms().size());
    if (_board) {
        auto form = _shape->forms()[index];
        for (int x = 0; x < TETRIS_SIZE; ++x) {
            for (int y = 0; y < TETRIS_SIZE; ++y) {
                if (form->exists(x, y) 
                        && boardX + x >= 0 && boardX + x < BOARD_WIDTH 
                        && boardY + y >= 0 && boardY + y < BOARD_HEIGHT 
                        && _board->exists(boardX+x, boardY+y)) {
                    return true;
                }
            }
        }
    }

    return false;
}

NAMESPACE_G1_END
