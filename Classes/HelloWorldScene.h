#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
    
    
public:
    Vector<Sprite*> ballList;
    std::vector<std::string> imageNames;
    cocos2d::Size winSize;
    void addEdges();
    void testAddBalls();
    void addBall(float positionX,float positionY);
    void clickItEnd(Touch* touch,Event* event);
    static cocos2d::Scene* createScene();
    virtual bool init();
    bool touchIt(Touch* touch,Event* event);
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
