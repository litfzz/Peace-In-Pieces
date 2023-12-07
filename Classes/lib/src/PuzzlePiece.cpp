#include "../include/PuzzlePiece.h"

USING_NS_CC;

PuzzlePiece::PuzzlePiece() {

}

PuzzlePiece::~PuzzlePiece() {

}
//PuzzlePiece::PuzzlePiece(Vec2 origPos, Texture2D* tex, Rect shape) {
//    originalPosition = origPos;
//    this->createWithTexture(tex, shape);
//    this->setPosition(origPos);
//}

//void PuzzlePiece::setPosition(Vec2& v) {
//    this->setPosition(v);
//}

Vec2 PuzzlePiece::getOriginalPosition() {
    return originalPosition;
}

PuzzlePiece* PuzzlePiece::createWithTexture(Vec2 origPos, Texture2D* tex, Rect shape) {
    PuzzlePiece* pPaddle = new (std::nothrow) PuzzlePiece();
    pPaddle->initWithTexture(tex, shape);
    pPaddle->autorelease();

    return pPaddle;

}

void PuzzlePiece::onEnter() {

}

void PuzzlePiece::onExit() {

}

bool PuzzlePiece::containsTouchLocation(cocos2d::Touch* touch) {
    return true;
}

bool PuzzlePiece::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
    return true;
}

void PuzzlePiece::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {

}

void PuzzlePiece::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {

}
