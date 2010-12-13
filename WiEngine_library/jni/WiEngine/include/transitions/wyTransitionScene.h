/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyTransitionScene_h__
#define __wyTransitionScene_h__

#include "wyScene.h"
#include "wyIntervalAction.h"
#include <stdbool.h>
#include "wyGlobal.h"

#define TS_FINISH -9000
#define TS_SET_NEW_SCENE -9001
#define TS_HIDE_OUT_SHOW_IN -9002

/**
 * @class wyTransitionScene
 *
 * 场景切换效果的封装, 是所有场景切换的基类
 */
class wyTransitionScene : public wyScene {
protected:
	/// 准备载入的\link wyScene wyScene对象指针\endlink
	wyScene* m_inScene;

	/// 准备载出的\link wyScene wyScene对象指针\endlink，一般为wyDirector::getRunningScene
	wyScene* m_outScene;

	/// 场景切换的持续时间
	float m_duration;

protected:
	/**
	 * 获得是否准备载入的场景在当前场景的上层
	 *
	 * @return true为是
	 */
	virtual bool shouldInSceneOnTop();

	/**
	 * 当完成场景切换后调用此方法，可以在子类重载该方法
	 */
	virtual void postFinish();

	/**
	 * 对场景准备开始切换做准备工作，可以在子类重载该方法
	 */
	virtual void initScenes();

	/**
	 * 返回载入场景效果的\link wyNode wyNode对象指针\endlink
	 *
	 * @return 载入场景效果的\link wyNode wyNode对象指针\endlink
	 */
	virtual wyNode* getInActionTarget();

	/**
	 * 返回载出场景效果的\link wyNode wyNode对象指针\endlink
	 *
	 * @return 载出场景效果的\link wyNode wyNode对象指针\endlink
	 */
	virtual wyNode* getOutActionTarget();

	/**
	 * 返回载入场景动作\link wyIntervalAction wyIntervalAction对象指针\endlink
	 *
	 * @return 载入场景动作\link wyIntervalAction wyIntervalAction对象指针\endlink
	 */
	virtual wyIntervalAction* getInAction();

	/**
	 * 返回载出场景动作\link wyIntervalAction wyIntervalAction对象指针\endlink
	 *
	 * @return 载出场景动作\link wyIntervalAction wyIntervalAction对象指针\endlink
	 */
	virtual wyIntervalAction* getOutAction();

public:

	/**
	 * 构造函数
	 *
	 * @param duration 场景切换的持续时间
	 * @param inScene 准备载入的\link wyScene wyScene对象指针\endlink
	 */
	wyTransitionScene(float duration, wyScene* inScene);

	/**
	 * 析构函数
	 */
	virtual ~wyTransitionScene();

	/// @see wyObject::onTargetSelectorInvoked
	virtual void onTargetSelectorInvoked(wyTargetSelector* ts);

	/**
	 * 当场景切换完成后调用该方法
	 */
	void finish();

	/**
	 * 隐藏载出场景并可见载入场景
	 */
	void hideOutShowIn();

	/**
	 * 设置wyDirector的当前场景为inScene,并激活事件派发机制
	 */
	void setNewScene(float dt);

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::onEnter
	virtual void onEnter();

	/// @see wyNode::onExit
	virtual void onExit();

	/**
	 * 获得载入的\link wyScene wyScene对象指针\endlink
	 *
	 * @return 载入的\link wyScene wyScene对象指针\endlink
	 */
	wyScene* getInScene() { return m_inScene; }

	/**
	 * 获得载出的\link wyScene wyScene对象指针\endlink
	 *
	 * @return 载出的\link wyScene wyScene对象指针\endlink
	 */
	wyScene* getOutScene() { return m_outScene; }

	/**
	 * 获得场景切换设置的时间
	 *
	 * @return 场景切换设置的时间
	 */
	float getDuration() { return m_duration; }
};

#endif // __wyTransitionScene_h__
