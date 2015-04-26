#include "TestShapeLayer.h"
#include "Helper.h"
#include "Resolution.h"
#include "TestsLayer.h"
#include "Shape.h"
#include "Form.h"
#include "Tetris.h"

NAMESPACE_G1_BEGIN

using namespace cc;

TestShapeLayer::TestShapeLayer() {
    for (int i = 0; i < TETRIS_NUM; ++i) {
        for (int x = 0; x < TETRIS_SIZE; ++x) {
            for (int y = 0; y < TETRIS_SIZE; ++y) {
                _bgGrids[i][x][y] = nullptr;
                _fgGrids[i][x][y] = nullptr;
            }
        }
        _labels[i] = nullptr;
    }

    // tetrises
    _tetrises[0] = new Tetris(Shape::I);
    _tetrises[1] = new Tetris(Shape::O);
    _tetrises[2] = new Tetris(Shape::J);
    _tetrises[3] = new Tetris(Shape::L);
    _tetrises[4] = new Tetris(Shape::S);
    _tetrises[5] = new Tetris(Shape::Z);
    _tetrises[6] = new Tetris(Shape::T);
}

TestShapeLayer::~TestShapeLayer() {
    for (int i = 0; i < TETRIS_NUM; ++i) {
        if (_tetrises[i]) {
            delete _tetrises[i];
            _tetrises[i] = nullptr;
        }
    }
}

TestShapeLayer* TestShapeLayer::create() {
    auto layer = new TestShapeLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    } else {
        delete layer;
        layer = nullptr;
        return nullptr;
    }
}

bool TestShapeLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    // add bg grids, labels, buttons
    for (int i = 0; i < TETRIS_NUM; ++i) {
        for (int x = 0; x < TETRIS_SIZE; ++x) {
            for (int y = 0; y < TETRIS_SIZE; ++y) {
                // bg grids
                _bgGrids[i][x][y] = LayerColor::create(Color4B(100, 100, 10, 255), 35, 35);
                Resolution::adapt(_bgGrids[i][x][y], 100+x*37, 1170-i*180+y*37);
                this->addChild(_bgGrids[i][x][y]);
            }
        }

        // label
        _labels[i] = Label::createWithSystemFont("", "", 26);
        Resolution::adapt(_labels[i], 500, 1270-i*180);
        this->addChild(_labels[i]);

        // next 
        auto next = MenuItemFont::create("Next", HANDLER(TestShapeLayer::onNext));
        next->setTag(i);
        Resolution::adapt(next, 500, 1200-i*180);
        auto nextMenu = Menu::create(next, nullptr);
        nextMenu->setPosition(0, 0);
        this->addChild(nextMenu);

        // show tetris
        showNextTetris(i);
    }
    
    // back to HomeLayer
    auto backButton = MenuItemFont::create("BACK", HANDLER(TestShapeLayer::onBack));
    Resolution::adapt(backButton, WIDTH/2, 30);
    auto backMenu = Menu::create(backButton, nullptr);
    backMenu->setPosition(0, 0);
    this->addChild(backMenu);

    return true;
}

void TestShapeLayer::showNextTetris(int index) {
    // clear old
    for (int x = 0; x < TETRIS_SIZE; ++x) {
        for (int y = 0; y < TETRIS_SIZE; ++y) {
            if (_fgGrids[index][x][y]) {
                _fgGrids[index][x][y]->removeFromParent();
                _fgGrids[index][x][y] = nullptr;
            }
        }
    }
    // add new
    //auto form = _tetrises[index]->transform();
    //auto points = form->points();
    //for (auto p : points) {
    //    _fgGrids[index][p.x][p.y] = LayerColor::create(Color4B(200, 0, 0, 255), 35, 35);
    //    _fgGrids[index][p.x][p.y]->setPosition(_bgGrids[index][p.x][p.y]->getPosition());
    //    Resolution::adapt(_fgGrids[index][p.x][p.y]);
    //    this->addChild(_fgGrids[index][p.x][p.y]);
    //}
    auto form = _tetrises[index]->transform();
    for (int x = 0; x < TETRIS_SIZE; ++x) {
        for (int y = 0; y < TETRIS_SIZE; ++y) {
            if (form->exists(x, y)) {
                _fgGrids[index][x][y] = LayerColor::create(Color4B(200, 0, 0, 255), 35, 35);
                _fgGrids[index][x][y]->setPosition(_bgGrids[index][x][y]->getPosition());
                Resolution::adapt(_fgGrids[index][x][y]);
                this->addChild(_fgGrids[index][x][y]);
            }
        }
    }
    // set label
    char buffer[128] = {0};
    sprintf(buffer, "minX:%d minY:%d maxX:%d maxY:%d", form->minX(), form->minY(),
            form->maxX(), form->maxY());
    _labels[index]->setString(buffer);
}

void TestShapeLayer::onNext(Ref* sender) {
    auto button = (MenuItem*) sender;
    auto index = button->getTag();
    showNextTetris(index);
}

void TestShapeLayer::onBack(Ref* sender) {
    ReplaceLayer(TestsLayer::create());
}

NAMESPACE_G1_END

