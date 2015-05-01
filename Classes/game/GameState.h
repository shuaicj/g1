#ifndef _G1_GAME_STATE_H_
#define _G1_GAME_STATE_H_

#include "Common.h"

NAMESPACE_G1_BEGIN

// The game machine.
enum class GameState {
    // Init state. 
    // When game begins, START -> FALL.
    START,

    // In game playing and a tetris is falling.
    // When a tetris falls to the bottom and causes a score increase, FALL -> SCORE.
    FALL,

    // In game playing and the score animation is playing.
    // When animation is over and score is increased, SCORE -> FALL.
    SCORE,

    // End state.
    // Game over.
    END,
};

NAMESPACE_G1_END

#endif // _G1_GAME_STATE_H_
