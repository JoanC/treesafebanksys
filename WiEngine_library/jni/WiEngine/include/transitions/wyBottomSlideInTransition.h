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
#ifndef __wyBottomSlideInTransition_h__
#define __wyBottomSlideInTransition_h__

#include "wyTransitionScene.h"

/**
 * @class wyBottomSlideInTransition
 *
 * 场景切换效果,载入场景从底部出现覆盖载出场景,载出场景不会移动,效果类似被载入场景逐渐覆盖
 */
class wyBottomSlideInTransition : public wyTransitionScene {
protected:
	/// @see wyTransitionScene::initScenes
	virtual void initScenes();

	/// @see wyTransitionScene::getInAction
	virtual wyIntervalAction* getInAction();

public:
	/**
	 * 构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 载入场景的\link wyScene wyScene对象指针 \endlink
	 */
	wyBottomSlideInTransition(float duration, wyScene* inScene);

	/**
	 * 析构函数
	 */
	virtual ~wyBottomSlideInTransition();
};

#endif // __wyBottomSlideInTransition_h__