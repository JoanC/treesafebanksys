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
#ifndef __wyIntervalAction_h__
#define __wyIntervalAction_h__

#include "wyFiniteTimeAction.h"
#include <stdbool.h>

/**
 * @class wyIntervalAction
 *
 * 非瞬间动作的封装, 是所有非瞬间动作的基类
 */
class wyIntervalAction : public wyFiniteTimeAction {
public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 */
	wyIntervalAction(float duration);

	/**
	 * 析构函数
	 */
	virtual ~wyIntervalAction();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::step
	virtual void step(float t);

	/// @see wyAction::isDone
	virtual bool isDone();
};

#endif // __wyIntervalAction_h__
