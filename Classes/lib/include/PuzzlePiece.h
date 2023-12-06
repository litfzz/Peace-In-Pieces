//
// Created by oisha on 12/6/2023.
//

#ifndef MYCPPGAME_PUZZLEPIECE_H
#define MYCPPGAME_PUZZLEPIECE_H

#include "cocos2d.h"

class PuzzlePiece : public cocos2d::Sprite {

    cocos2d::Vec2 originalPosition;

public:
    PuzzlePiece(cocos2d::Vec2 origPos, cocos2d::Texture2D tex, cocos2d::Rect shape);
};

#endif //MYCPPGAME_PUZZLEPIECE_H
