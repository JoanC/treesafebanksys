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
#ifndef __wyRepeatForever_h__
#define __wyRepeatForever_h__

#include "wyIntervalAction.h"

/**
 * @class wyRepeatForever
 *
 * 不断重复执行某个动作的封装
 */
class wyRepeatForever : public wyAction {
protected:
	///  具体要执行的\link wyIntervalAction wyIntervalAction对象 \endlink指针
	wyIntervalAction* m_other;

public:
	/**
	 * 构造函数
	 *
	 * @param other 具体执行的 \link wyIntervalAction wyIntervalAction对象 \endlink指针
	 */
	wyRepeatForever(wyIntervalAction* other);

	/**
	 * 析构函数
	 */
	virtual ~wyRepeatForever();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::step
	virtual void step(float t);

	/// @see wyAction::update
	virtual void update(float t);

	/// @see wyAction::isDone
	virtual bool isDone();
};

#endif // __wyRepeatForever_h__
