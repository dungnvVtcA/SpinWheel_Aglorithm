

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto  node = Node::create();
	auto background = Sprite::create("background.jpg");
	sprite_ = Sprite::create("wheel.png");
	node->setPosition(visibleSize / 2);
	sprite_->setScale(0.5);

	auto label = Label::createWithTTF("Xoay", "fonts/Marker Felt.ttf", 10);
	label->setColor(Color3B::BLACK);
	node->addChild(label, 3);
	node->addChild(sprite_, 2);
	node->addChild(background, 1);
	this->addChild(node);

	auto eventlis = EventListenerTouchOneByOne::create();
	eventlis->onTouchBegan = CC_CALLBACK_2(HelloWorld::touchBegan, this);
	eventlis->onTouchEnded = CC_CALLBACK_2(HelloWorld::touchEnd, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(eventlis, this);

	schedule(schedule_selector(HelloWorld::update));
	
	return true;
}

bool HelloWorld::touchBegan(Touch *touch, Event *event)
{
	this->CallFunctionrun(touch->getLocation().y);
	return true;
}

void HelloWorld::touchEnd(Touch *touch, Event *event)
{
	//this->CallFunctionrun(touch->getLocation().y);

}

void HelloWorld::CallFunctionrun(float location)
{
	if (location > visibleSize.height - 10 || location < visibleSize.height / 2 + 10)
	{
		//this->runRotate();
		Generate(0);
	}
}

void HelloWorld:: update(float dt)
{
		this->sprite_->setRotation(this->sprite_->getRotation() + t);
		t -= dr;
		if (t < 0)
		{
			t = 0;
			this->sprite_->setRotation(this->sprite_->getRotation() - int(this->sprite_->getRotation() / 360) * 360);
		}
		CCLOG("%f", t);
}

void HelloWorld::Generate(float r)
{
	float d = 360 * 5 * 1 + r - this->sprite_->getRotation();
	float f = 0;
	for (int i = 1; i <= 5*60; ++i)
	{
		f += i;
	}
	dr = d / f;
	t = 300 * dr;
	CCLOG("%f", d);
	CCLOG("%f", t);
	CCLOG("%f", dr);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
