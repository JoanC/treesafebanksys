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
#ifndef __wyJumpTo_h__
#define __wyJumpTo_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * @class wyJumpTo
 *
 * 节点跳跃的动作封装,根据设置起始点，结束点，高度，跳跃次数进行移动
 */
class wyJumpTo : public wyIntervalAction {
protected:
	/// 起始点x轴坐标
	float m_startX;

	/// 起始点y轴坐标
	float m_startY;

	/// 结束点x轴坐标
	float m_endX;

	/// 结束点y轴坐标
	float m_endY;

	/// 偏移x距离
	float m_deltaX;

	/// 偏移y距离
	float m_deltaY;

	/// 节点跳跃的高度
	float m_height;

	/// 节点跳跃的次数
	int m_jumps;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startX 起始点x轴坐标
	 * @param startY 起始点y轴坐标
	 * @param endX 结束点y轴坐标
	 * @param endY 结束点y轴坐标
	 * @param height 节点跳跃的高度
	 * @param jumps 节点跳跃的次数
	 */
	wyJumpTo(float duration, float startX, float startY, float endX, float endY, float height, int jumps);

	/**
	 * 析构函数
	 */
	virtual ~wyJumpTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyJumpTo_h__
