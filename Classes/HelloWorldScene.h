#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::Scene
{
private:
	bool istouch;
	Sprite * sprite_;
	Size visibleSize;
	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	void CallFunctionrun(float location);

	bool touchBegan(cocos2d::Touch * touch, cocos2d::Event * event);
	void touchEnd(cocos2d::Touch *touch, cocos2d::Event * event);
	
	void update(float dt);
	

	float t = 0;
	float dr = 0;
	void Generate(float);// set location stop
};

#endif // __HELLOWORLD_SCENE_H__
