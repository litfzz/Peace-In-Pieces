#ifndef SEGMENTATION_SCENE_H
#define SEGMENTATION_SCENE_H

#include "cocos2d.h"

class SegmentationScene : public cocos2d::Scene {
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(SegmentationScene);
};

#endif // SEGMENTATION_SCENE_H