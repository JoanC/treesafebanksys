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
#ifndef __wySpawn_h__
#define __wySpawn_h__

#include "wyIntervalAction.h"

/**
 * @class wySpawn
 *
 * 同时执行两个动作的封装
 */
class wySpawn : public wyIntervalAction {
protected:
	/// 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	wyFiniteTimeAction* m_one;

	/// 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	wyFiniteTimeAction* m_two;

public:
	/**
	 * 构造函数
	 *
	 * @param one 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	 * @param two 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	 */
	wySpawn(wyFiniteTimeAction* one, wyFiniteTimeAction* two);

	/**
	 * 析构函数
	 */
	virtual ~wySpawn();

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
};

#endif // __wySpawn_h__
