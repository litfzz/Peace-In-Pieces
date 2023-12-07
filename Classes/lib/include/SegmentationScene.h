#ifndef SEGMENTATION_SCENE_H
#define SEGMENTATION_SCENE_H

#include "cocos2d.h"

class SegmentationScene : public cocos2d::Scene {
public:
    static Scene* createScene();
    virtual bool init();

//    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
//    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
//    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
//    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

    CREATE_FUNC(SegmentationScene);
};

#endif // SEGMENTATION_SCENE_H