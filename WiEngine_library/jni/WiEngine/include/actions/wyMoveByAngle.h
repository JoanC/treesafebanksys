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
#ifndef __wyMoveByAngle_h__
#define __wyMoveByAngle_h__

#include "wyIntervalAction.h"

/**
 * @class wyMoveByAngle
 *
 * 根据角度和速度移动的动作封装
 */
class wyMoveByAngle : public wyIntervalAction {
private:
	/// 起始x坐标
	float m_startX;

    /// 起始y坐标
	float m_startY;

	/// 动作执行速度
	int m_velocity;

	/// 移动的角度
	int m_degree;

	/// 移动的弧度, 通过(degree * M_PI / 180)计算获得
	float m_radian;

	/// cos(m_radian)值
	float m_cosRadian;

	/// -sin(m_radian)值
	float m_sinRadian;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param degree   节点移动的角度
	 * @param velocity 节点移动的速度
	 */
	wyMoveByAngle(float duration, int degree, int velocity);

	/**
	 * 析构函数
	 */
	virtual ~wyMoveByAngle();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyMoveByAngle_h__
