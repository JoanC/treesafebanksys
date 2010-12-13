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
#ifndef __wyMoveBy_h__
#define __wyMoveBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyMoveBy
 *
 * 节点移动的动作封装,根据设置偏移量进行移动
 */
class wyMoveBy : public wyIntervalAction {
protected:
	/// 节点的起始x轴位置
	float m_startPositionX;

	/// 节点的起始y轴位置
	float m_startPositionY;

	/// 节点的偏移x轴距离
	float m_deltaX;

	/// 节点的偏移y轴距离
	float m_deltaY;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param x 节点偏移x轴距离
	 * @param y 节点偏移y轴距离
	 */
	wyMoveBy(float duration, float x, float y);

	/**
	 * 析构函数
	 */
	virtual ~wyMoveBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyMoveBy_h__
