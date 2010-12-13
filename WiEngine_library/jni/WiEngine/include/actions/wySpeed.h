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
#ifndef __wySpeed_h__
#define __wySpeed_h__

#include "wyIntervalAction.h"

/**
 * @class wySpeed
 *
 * 加速或减速的动作的封装
 */
class wySpeed : public wyAction {
protected:
	/// 具体执行的\link wyAction wyAction对象\endlink指针
	wyAction* m_other;

	/// 加速或减速的速率，大于1为加速，取值必须大于0
	float m_speed;

public:
	/**
	 * 构造函数
	 *
	 * @param other 具体执行的 \link wyAction wyAction对象 \endlink指针
	 * @param speed 加速或减速的速率，大于1为加速，取值必须大于0
	 */
	wySpeed(wyAction* other, float speed);

	/**
	 * 析构函数
	 */
	virtual ~wySpeed();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();

	/// @see wyAction::step
	virtual void step(float t);

	/// @see wyAction::update
	virtual void update(float t);

	/// @see wyAction::isDone
	virtual bool isDone();

	/**
	 * 获得加速或减速的速率
	 *
	 * @return 加速或减速的速率
	 */
	float getSpeed() { return m_speed; }

	/**
	 * 设置加速或减速的速率
	 *
	 * @param speed 加速或减速的速率，大于1为加速
	 */
	void setSpeed(float speed) { this->m_speed = speed; }
};

#endif // __wySpeed_h__
