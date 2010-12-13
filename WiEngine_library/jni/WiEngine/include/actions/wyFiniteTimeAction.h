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
#ifndef __wyFiniteTimeAction_h__
#define __wyFiniteTimeAction_h__

#include "wyAction.h"
/**
 * @class wyFiniteTimeAction
 *
 * 执行动作的封装, 是大部分动作基类
 */
class wyFiniteTimeAction : public wyAction {
	friend class wyRepeat;
	friend class wyRepeatForever;

protected:
	/// 动作已经持续的时间
	float elapsed;

	/// 动作持续的时间
	float duration;

	/// true表示是第一次更新, 用于设置初始状态，保证动作从初始状态开始执行
	bool firstTick;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 */
	wyFiniteTimeAction(float duration);

	/**
	 * 虚析构
	 */
	virtual ~wyFiniteTimeAction();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/**
	 * 获得动作持续时间长度
	 *
	 * @return 动作持续时间长度
	 */
	float getDuration();

	/**
	 * 设置动作持续时间长度
	 *
	 * @param duration 动作持续时间长度
	 */
	void setDuration(float duration);

	/**
	 * 获得动作已经持续的时间
	 *
	 * return 动作已经持续的时间
	 */
	float getElapsed() { return elapsed; }

	/**
	 * 设置动作已经持续的时间，只应在一些特殊情况下调用该方法
	 */
	void setElapsed(float e) { elapsed = e; }
};

#endif // __wyFiniteTimeAction_h__
