#ifndef RockerPro_HRocker_h
#define RockerPro_HRocker_h

#ifndef HRocker_H
#define HRocker_H
#include "cocos2d.h"

using namespace cocos2d;

class HRocker :public CCLayer 
{

public :
	//初始化 aPoint是摇杆中心 aRadius是摇杆半径 aJsSprite是摇杆控制点 aJsBg是摇杆背景
	static HRocker*  HRockerWithCenter(CCPoint aPoint ,float aRadius ,
		CCSprite* aJsSprite,CCSprite* aJsBg,bool _isFollowRole);

	//启动摇杆
	void Active();

	//解除摇杆
	void Inactive();

	CCPoint getDirection();

	float getVelocity();

	bool isAttack;

private:
	HRocker * initWithCenter(CCPoint aPoint ,float aRadius ,
		CCSprite* aJsSprite,CCSprite* aJsBg,bool _isFollowRole);

	CCPoint centerPoint;//摇杆中心

	CCPoint currentPoint;//摇杆当前位置

	bool active;//是否激活摇杆

	float radius;//摇杆半径

	CCSprite *jsSprite;

	bool isFollowRole;//是否跟随用户点击

	void  updatePos(float dt);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	CREATE_FUNC(HRocker);
};
#endif

#endif