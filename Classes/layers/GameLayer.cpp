#include "GameLayer.h"
#include "Helper.h"
#include "Resolution.h"
#include "HomeLayer.h"
#include "GameOverLayer.h"
#include "Shape.h"
#include "Form.h"
#include "Tetris.h"
#include "Board.h"

NAMESPACE_G1_BEGIN

using namespace cc;

GameLayer::GameLayer() : _state(GameState::START), _board(nullptr)
, _tetris(nullptr), _nextTetris(nullptr), _timer(0.0f)
, _lineCountLabel(nullptr), _scoreLabel(nullptr), _lineCount(0), _score(0) {
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            _bgGrids[x][y] = nullptr;
            _fgGrids[x][y] = nullptr;
            _fgLabels[x][y] = nullptr;
        }
    }
    for (int x = 0; x < TETRIS_SIZE; ++x) {
        for (int y = 0; y < TETRIS_SIZE; ++y) {
            _tetrisGrids[x][y] = nullptr;
            _nextTetrisGrids[x][y] = nullptr;
        }
    }
}

GameLayer::~GameLayer() {
    SAFE_DELETE(_board);
    SAFE_DELETE(_tetris);
    SAFE_DELETE(_nextTetris);
}

GameLayer* GameLayer::create() {
    auto layer = new GameLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    } else {
        delete layer;
        layer = nullptr;
        return nullptr;
    }
}

bool GameLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    // board bg grids
    drawBoardGrids();

    // line count and score
    showLineCountLabel();
    showScoreLabel();

    // button to left
    auto leftButton = MenuItemFont::create("Left", HANDLER1(GameLayer::onLeft));
    Resolution::adapt(leftButton, 150, 350);
    auto leftMenu = Menu::create(leftButton, nullptr);
    leftMenu->setPosition(0, 0);
    this->addChild(leftMenu);

    // button to right
    auto rightButton = MenuItemFont::create("Right", HANDLER1(GameLayer::onRight));
    Resolution::adapt(rightButton, 250, 350);
    auto rightMenu = Menu::create(rightButton, nullptr);
    rightMenu->setPosition(0, 0);
    this->addChild(rightMenu);

    // button to slow down
    auto slowButton = MenuItemFont::create("SlowDown", HANDLER1(GameLayer::onSlowDown));
    Resolution::adapt(slowButton, 400, 400);
    auto slowMenu = Menu::create(slowButton, nullptr);
    slowMenu->setPosition(0, 0);
    this->addChild(slowMenu);

    // button to fast down
    auto fastButton = MenuItemFont::create("FastDown", HANDLER1(GameLayer::onFastDown));
    Resolution::adapt(fastButton, 400, 300);
    auto fastMenu = Menu::create(fastButton, nullptr);
    fastMenu->setPosition(0, 0);
    this->addChild(fastMenu);

    // button to rotate
    auto rotateButton = MenuItemFont::create("Rotate", HANDLER1(GameLayer::onRotate));
    Resolution::adapt(rotateButton, 550, 350);
    auto rotateMenu = Menu::create(rotateButton, nullptr);
    rotateMenu->setPosition(0, 0);
    this->addChild(rotateMenu);

    // back to HomeLayer
    auto backButton = MenuItemFont::create("BACK", HANDLER1(GameLayer::onBack));
    Resolution::adapt(backButton, WIDTH/2, 30);
    auto backMenu = Menu::create(backButton, nullptr);
    backMenu->setPosition(0, 0);
    this->addChild(backMenu);

    // call update
    scheduleUpdate();

    return true;
}

void GameLayer::update(float dt) {
    if (_state == GameState::START) {
        _board = new Board();
        _tetris = new Tetris(_board);
        _nextTetris = new Tetris(_board);
        showBoardLabels();
        drawTetris();
        drawNextTetris();

        // start to fall
        _timer = 0.0f;
        _state = GameState::FALL;
    } else if (_state == GameState::FALL) {
        _timer += dt;
        if (_timer > FALL_INTERVAL) {
            _timer = 0;
            moveDown(1);
        }
    }
}

Vec2 GameLayer::getPositionForBoardGrid(int boardX, int boardY) {
    return Resolution::xy(100+boardX*37, 500+boardY*37);
}

void GameLayer::drawBoardGrids() {
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            _bgGrids[x][y] = LayerColor::create(Color4B(100, 100, 10, 255), 35, 35);
            _bgGrids[x][y]->ignoreAnchorPointForPosition(false);
            _bgGrids[x][y]->setPosition(getPositionForBoardGrid(x, y));
            Resolution::adapt(_bgGrids[x][y]);
            this->addChild(_bgGrids[x][y]);
        }
    }
}

void GameLayer::drawTetris() {
    for (int x = 0; x < TETRIS_SIZE; ++x) {
        for (int y = 0; y < TETRIS_SIZE; ++y) {
            if (_tetrisGrids[x][y]) {
                _tetrisGrids[x][y]->removeFromParent();
                _tetrisGrids[x][y] = nullptr;
            }
            if (_tetris->exists(x, y)) {
                _tetrisGrids[x][y] = createTetrisGrid(_tetris);
                Resolution::adapt(_tetrisGrids[x][y]);
                this->addChild(_tetrisGrids[x][y]);
            }
        }
    }
    setPostionForTetris();
}

void GameLayer::drawNextTetris() {
    for (int x = 0; x < TETRIS_SIZE; ++x) {
        for (int y = 0; y < TETRIS_SIZE; ++y) {
            if (_nextTetrisGrids[x][y]) {
                _nextTetrisGrids[x][y]->removeFromParent();
                _nextTetrisGrids[x][y] = nullptr;
            }
            if (_nextTetris->exists(x, y)) {
                _nextTetrisGrids[x][y] = createTetrisGrid(_nextTetris);
                Resolution::adapt(_nextTetrisGrids[x][y], 550+x*37, 1100+y*37);
                this->addChild(_nextTetrisGrids[x][y]);
            }
        }
    }
}

Node* GameLayer::createTetrisGrid(const Tetris* tetris) {
    Node* rt = nullptr;
    auto shape = tetris->shape();
    if (shape == &Shape::I) {
        rt = LayerColor::create(Color4B(200, 0, 0, 255), 35, 35);
    } else if (shape == &Shape::O) {
        rt = LayerColor::create(Color4B(0, 200, 0, 255), 35, 35);
    } else if (shape == &Shape::J) {
        rt = LayerColor::create(Color4B(0, 0, 200, 255), 35, 35);
    } else if (shape == &Shape::L) {
        rt = LayerColor::create(Color4B(200, 200, 0, 255), 35, 35);
    } else if (shape == &Shape::S) {
        rt = LayerColor::create(Color4B(200, 0, 200, 255), 35, 35);
    } else if (shape == &Shape::Z) {
        rt = LayerColor::create(Color4B(0, 200, 200, 255), 35, 35);
    } else if (shape == &Shape::T) {
        rt = LayerColor::create(Color4B(200, 200, 200, 255), 35, 35);
    }

    assert(rt);
    rt->ignoreAnchorPointForPosition(false);

    return rt;
}

void GameLayer::setPostionForTetris() {
    for (int x = 0; x < TETRIS_SIZE; ++x) {
        for (int y = 0; y < TETRIS_SIZE; ++y) {
            if (_tetrisGrids[x][y]) {
                int boardX = _tetris->boardX(x);
                int boardY = _tetris->boardY(y);
                _tetrisGrids[x][y]->setPosition(getPositionForBoardGrid(boardX, boardY));
                //_tetrisGrids[x][y]->setVisible(_tetris->isInBoard(x, y));
            }
        }
    }
}

void GameLayer::showBoardLabels() {
    for (int boardX = 0; boardX < BOARD_WIDTH; ++boardX) {
        for (int boardY = 0; boardY < BOARD_HEIGHT; ++boardY) {
            if (!_fgLabels[boardX][boardY]) {
                _fgLabels[boardX][boardY] = Label::createWithSystemFont("", "", 24);
                _fgLabels[boardX][boardY]->setPosition(getPositionForBoardGrid(boardX, boardY));
                Resolution::adapt(_fgLabels[boardX][boardY]);
                this->addChild(_fgLabels[boardX][boardY], 1);
            }
            _fgLabels[boardX][boardY]->setString(_board->exists(boardX, boardY) ? "1" : "0");
            if (_board->exists(boardX, boardY)) {
                assert(_fgGrids[boardX][boardY]);
            } else {
                assert(!_fgGrids[boardX][boardY]);
            }
        }
    }
}

void GameLayer::showLineCountLabel() {
    char buffer[128] = {0};
    sprintf(buffer, "Line: %d", _lineCount);
    if (!_lineCountLabel) {
        _lineCountLabel = Label::createWithSystemFont(buffer, "", 26);
        _lineCountLabel->setHorizontalAlignment(TextHAlignment::LEFT);
        Resolution::adapt(_lineCountLabel, 580, 950);
        this->addChild(_lineCountLabel);
    } else {
        _lineCountLabel->setString(buffer);
    }
}

void GameLayer::showScoreLabel() {
    char buffer[128] = {0};
    sprintf(buffer, "Score: %d", _score);
    if (!_scoreLabel) {
        _scoreLabel = Label::createWithSystemFont(buffer, "", 26);
        _scoreLabel->setHorizontalAlignment(TextHAlignment::LEFT);
        Resolution::adapt(_scoreLabel, 580, 900);
        this->addChild(_scoreLabel);
    } else {
        _scoreLabel->setString(buffer);
    }
}

void GameLayer::moveDown(int step) {
    int realStep = _tetris->moveDown(step);
    if (realStep > 0) {
        setPostionForTetris();
    }
    if (realStep < step) {
        for (int x = 0; x < TETRIS_SIZE; ++x) {
            for (int y = 0; y < TETRIS_SIZE; ++y) {
                int boardX = _tetris->boardX(x);
                int boardY = _tetris->boardY(y);
                // make tetris grids become board fg grids
                if (_tetrisGrids[x][y]) {
                    _fgGrids[boardX][boardY] = _tetrisGrids[x][y];
                    _tetrisGrids[x][y] = nullptr;
                    _board->set(boardX, boardY, true);
                }
                // make next tetris grids become the current tetris grids
                if (_nextTetrisGrids[x][y]) {
                    _tetrisGrids[x][y] = _nextTetrisGrids[x][y];
                    _nextTetrisGrids[x][y] = nullptr;
                }
            }
        }
        // debug labels
        showBoardLabels();
        // check game over
        if (isGameOver()) {
            auto gameover = GameOverLayer::create();
            this->addChild(gameover, 100);
            _state = GameState::END;
            return;
        }
        // make next tetris become the current tetris, and create new next tetris
        _tetris = _nextTetris;
        setPostionForTetris();
        _nextTetris = new Tetris(_board);
        drawNextTetris();
        // check score
        for (int boardY = 0; boardY < BOARD_HEIGHT; ++boardY) {
            for (int boardX = 0; boardX < BOARD_WIDTH; ++boardX) {
                if (!_board->exists(boardX, boardY)) {
                    break;
                } else if (boardX == BOARD_WIDTH - 1) {
                    _scoreLines.push_back(boardY);
                }
            }
        }
        if (!_scoreLines.empty()) {
            // calculate the score
            _state = GameState::SCORE;
            int line = (int) _scoreLines.size();
            _lineCount += line;
            showLineCountLabel();
            _score += getScore(line);
            showScoreLabel();
            // fade out the completed line
            for (int boardY : _scoreLines) {
                for (int boardX = 0; boardX < BOARD_WIDTH; ++boardX) {
                    _fgGrids[boardX][boardY]->runAction(Sequence::create(
                                FadeOut::create(0.2f),
                                RemoveSelf::create(),
                                nullptr));
                    _fgGrids[boardX][boardY] = nullptr;
                    _board->set(boardX, boardY, false);
                }
            }
            // clear the score lines
            this->runAction(Sequence::create(
                        DelayTime::create(0.2f),
                        CallFunc::create(HANDLER0(GameLayer::clearScoreLines)),
                        nullptr));
        }
    }
}

void GameLayer::moveLeft(int step) {
    int realStep = _tetris->moveLeft(step);
    if (realStep > 0) {
        setPostionForTetris();
    }
}

void GameLayer::moveRight(int step) {
    int realStep = _tetris->moveRight(step);
    if (realStep > 0) {
        setPostionForTetris();
    }
}

void GameLayer::rotate() {
    auto form = _tetris->transform();
    if (form) {
        drawTetris();
    }
}

int GameLayer::getScore(int line) {
    if (line == 1) { return SCORE_LINE_1; }
    if (line == 2) { return SCORE_LINE_2; }
    if (line == 3) { return SCORE_LINE_3; }
    if (line == 4) { return SCORE_LINE_4; }
    assert(0);
}

void GameLayer::clearScoreLines() {
    for (int i = (int) _scoreLines.size() - 1; i >= 0; --i) {
        int line = _scoreLines[i];
        for (int boardY = line; boardY < BOARD_HEIGHT; ++boardY) {
            for (int boardX = 0; boardX < BOARD_WIDTH; ++boardX) {
                if (boardY + 1 < BOARD_HEIGHT) {
                    _board->set(boardX, boardY, _board->exists(boardX, boardY+1));
                    _fgGrids[boardX][boardY] = _fgGrids[boardX][boardY+1];
                } else {
                    _board->set(boardX, boardY, false);
                    _fgGrids[boardX][boardY] = nullptr;
                }
                if (_fgGrids[boardX][boardY]) {
                    _fgGrids[boardX][boardY]->setPosition(getPositionForBoardGrid(boardX, boardY));
                }
            }
        }
    }
    _scoreLines.clear();
    _state = GameState::FALL;
}

bool GameLayer::isGameOver() {
    for (int boardX = 0; boardX < BOARD_WIDTH; ++boardX) {
        if (_board->exists(boardX, BOARD_HEIGHT-1)) {
            return true;
        }
    }
    return false;
}

void GameLayer::onLeft(Ref* sender) {
    if (_state == GameState::FALL) {
        moveLeft(1);
    }
}

void GameLayer::onRight(Ref* sender) {
    if (_state == GameState::FALL) {
        moveRight(1);
    }
}

void GameLayer::onSlowDown(Ref* sender) {
    if (_state == GameState::FALL) {
        moveDown(DISTANCE_OF_SLOW_FALL);
    }
}

void GameLayer::onFastDown(Ref* sender) {
    if (_state == GameState::FALL) {
        moveDown(DISTANCE_OF_FAST_FALL);
    }
}

void GameLayer::onRotate(Ref* sender) {
    if (_state == GameState::FALL) {
        rotate();
    }
}

void GameLayer::onBack(Ref* sender) {
    ReplaceLayer(HomeLayer::create());
}

NAMESPACE_G1_END

