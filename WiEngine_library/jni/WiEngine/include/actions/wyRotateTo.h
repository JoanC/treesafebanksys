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
#ifndef __wyRotateTo_h__
#define __wyRotateTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyRotateTo
 *
 * 节点旋转的动作封装,根据设置旋转起始度数进行节点旋转
 */
class wyRotateTo : public wyIntervalAction {
protected:
	/// 节点在动作内要旋转的角度
	float m_delta;

	/// 节点初始的角度
	float m_startAngle;

	/// 节点目标的角度
	float m_endAngle;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startAngle 节点初始的角度
	 * @param endAngle 节点目标的角度
	 */
	wyRotateTo(float duration, float startAngle, float endAngle);

	/**
	 * 析构函数
	 */
	virtual ~wyRotateTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyRotateTo_h__
