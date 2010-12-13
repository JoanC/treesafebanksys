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
#ifndef __wyScaleBy_h__
#define __wyScaleBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyScaleBy
 *
 * 节点缩放的动作封装,根据设置缩放比例进行节点缩放
 */
class wyScaleBy : public wyIntervalAction {
protected:
	/// 初始x轴缩放比，取值大于0
	float m_startScaleX;

	/// 初始y轴缩放比，取值大于0
	float m_startScaleY;

	/// 目标x轴缩放比，取值大于0
	float m_endScaleX;

	/// 目标y轴缩放比，取值大于0
	float m_endScaleY;

	/// 缩放变化的x轴缩比例
	float m_deltaX;

	/// 缩放变化的y轴缩比例
	float m_deltaY;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param scaleX 缩放变化的x轴缩放比
	 * @param scaleY 缩放变化的y轴缩放比
	 */
	wyScaleBy(float duration, float scaleX, float scaleY);

	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param scale 缩放变化的缩放比
	 */
	wyScaleBy(float duration, float scale);

	/**
	 * 析构函数
	 */
	virtual ~wyScaleBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyScaleBy_h__
