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
#ifndef __wyRepeat_h__
#define __wyRepeat_h__

#include "wyIntervalAction.h"

/**
 * @class wyRepeat
 *
 * 根据设置重复次数，重复执行动作的封装
 */
class wyRepeat : public wyIntervalAction {
protected:
	/// 动作重复的次数
	int m_times;

	/// 已经执行的次数
	int m_total;

	/// 具体要执行的\link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	wyFiniteTimeAction* m_other;

public:
	/**
	 * 构造函数
	 *
	 * @param other 具体要执行的\link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	 * @param times 动作重复的次数
	 */
	wyRepeat(wyFiniteTimeAction* other, int times);

	/**
	 * 析构函数
	 */
	virtual ~wyRepeat();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();

	/// @see wyAction::update
	virtual void update(float t);

	/// @see wyAction::isDone
	virtual bool isDone();
};

#endif // __wyRepeat_h__
