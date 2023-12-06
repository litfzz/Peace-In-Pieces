#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include <cocos2d.h>
#include <imgui.h>

class AppManager : public cocos2d::Scene
{
public:
    virtual bool init();
    static AppManager* create();

private:
    // Cocos2d-x callbacks
    void update(float dt) override;
    void onEnter() override;
    void onExit() override;

    // Dear ImGui callbacks
    void drawImGui();
};

#endif // APP_MANAGER_H