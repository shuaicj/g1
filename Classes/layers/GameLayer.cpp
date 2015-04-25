#include "GameLayer.h"
#include "Helper.h"
#include "Resolution.h"
#include "HomeLayer.h"

NAMESPACE_G1_BEGIN

using namespace cc;

GameLayer::GameLayer() {
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            _bgGrids[x][y] = nullptr;
            _fgGrids[x][y] = nullptr;
        }
    }
    for (int x = 0; x < TETRIS_SIZE; ++x) {
        for (int y = 0; y < TETRIS_SIZE; ++y) {
            _tetrisGrids[x][y] = nullptr;
        }
    }
}

GameLayer::~GameLayer() {
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
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            _bgGrids[x][y] = LayerColor::create(Color4B(100, 100, 10, 255), 35, 35);
            Resolution::adapt(_bgGrids[x][y], 100+x*37, 500+y*37);
            this->addChild(_bgGrids[x][y]);
        }
    }

    // back to HomeLayer
    auto backButton = MenuItemFont::create("BACK", HANDLER(GameLayer::onBack));
    Resolution::adapt(backButton, WIDTH/2, 30);
    auto backMenu = Menu::create(backButton, nullptr);
    backMenu->setPosition(0, 0);
    this->addChild(backMenu);

    return true;
}

void GameLayer::onBack(Ref* sender) {
    ReplaceLayer(HomeLayer::create());
}

NAMESPACE_G1_END

