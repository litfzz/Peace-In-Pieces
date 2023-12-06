//
// Created by oisha on 12/6/2023.
//

#ifndef MYCPPGAME_PUZZLEPIECE_H
#define MYCPPGAME_PUZZLEPIECE_H

#include "cocos2d.h"

class PuzzlePiece : public cocos2d::Sprite {

    cocos2d::Vec2 originalPosition;

public:
    PuzzlePiece(cocos2d::Vec2 origPos, cocos2d::Texture2D* tex, cocos2d::Rect shape);

    PuzzlePiece(cocos2d::Vec2 origPos, const cocos2d::Texture2D* tex);

    virtual void onEnter() override;
    virtual void onExit() override;
    bool containsTouchLocation(cocos2d::Touch* touch);
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void setPosition(cocos2d::Vec2&);
    cocos2d::Vec2 getOriginalPosition();

private:
    cocos2d::Texture2D* tex;
    cocos2d::Rect* r;
};

#endif //MYCPPGAME_PUZZLEPIECE_H
