#include "../include/PuzzlePiece.h"

USING_NS_CC;

PuzzlePiece::PuzzlePiece(Vec2 origPos, Texture2D* tex, Rect shape) {
    originalPosition = origPos;
    this->createWithTexture(tex, shape);
    this->setPosition(origPos);
}

void PuzzlePiece::setPosition(Vec2& v) {
    this->setPosition(v);
}

Vec2 PuzzlePiece::getOriginalPosition() {
    return originalPosition;
}
