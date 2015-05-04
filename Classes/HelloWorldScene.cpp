#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0,-200));
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance


bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    winSize = Director::getInstance()->getVisibleSize();
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);
    addEdges();
    //auto listener1 = EventListenerTouchOneByOne::create();
    //listener1->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan1,this);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
////        HelloWorld::addBall(touch->getLocation().x, touch->getLocation().y);
////        Vec2 touchLocation = touch->getLocation();
////        addBall(;, float positionY)
////        addBall(touchLocation.x, touchLocation.y,rootNode);
//        return  false;
//    };
    //addBall(winSize.width/2, winSize.height/2);
    testAddBalls();
    //
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->onTouchBegan = CC_CALLBACK_2(HelloWorld::touchIt,this);
        listener1->onTouchMoved = [](Touch* touch, Event* event){
        // your code
    };
    
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        // your code
    };
    
    // Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
    
    return true;
}
bool HelloWorld::touchIt(Touch* touch,Event* event){
    Vec2 position = touch->getLocation();
    HelloWorld::addBall(position.x ,position.y);
    //log(ballList);
    return false;
}

void HelloWorld::testAddBalls(){
    int positionX = 80;
    int positionY = 930;
    
    for (int y = 0; y<11; y++) {
        for (int x = 0; x<9; x++) {
            HelloWorld::addBall(positionX+60*x, positionY-60*y);
            
        }
    }
}

void HelloWorld::addBall(float positionX, float positionY){
    auto newBall = Sprite::create("ball.png");
    newBall->setPosition(positionX,positionY);
    auto ballBody = PhysicsBody::createCircle(newBall->getContentSize().width/2);
    ballBody->setVelocity(Vec2(0.0f,-200.0f));
        newBall->setPhysicsBody(ballBody);
    
    ballList.pushBack(newBall);
    //log(ballList.size());
    addChild(newBall);
    
}


void HelloWorld::clickItEnd(cocos2d::Touch *touch, cocos2d::Event* event){
    log("good");
}
void HelloWorld::addEdges(){
    //auto winSize = Director::getInstance()->getVisibleSize();
    
    auto edges = PhysicsBody::createEdgeBox(winSize);
    auto node = Node::create();
    node->setPhysicsBody(edges);
    node->setPosition(winSize/2);
    
    auto edges2 = PhysicsBody::createEdgeSegment(Vec2(winSize.width/2, 50), Vec2(0, 350));
    auto node2 = Node::create();
    node2->setPhysicsBody(edges2);
    
    auto edges3 = PhysicsBody::createEdgeSegment(Vec2(winSize.width/2, 50), Vec2(winSize.width, 350));
    auto node3 = Node::create();
    node3->setPhysicsBody(edges3);
    
    auto edgeLeft  = PhysicsBody::createEdgeSegment(Vec2(50,0), Vec2(50,winSize.height));
    auto node4 = Node::create();
    node4->setPhysicsBody(edgeLeft);
    
    auto edgeRight  = PhysicsBody::createEdgeSegment(Vec2(winSize.width-50,0), Vec2(winSize.width-50,winSize.height));
    auto node5 = Node::create();
    node5->setPhysicsBody(edgeRight);

    addChild(node);
    addChild(node2);
    addChild(node3);
    addChild(node4);
    addChild(node5);
    
}





