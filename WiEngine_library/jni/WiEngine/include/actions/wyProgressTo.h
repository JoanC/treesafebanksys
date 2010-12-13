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
#ifndef __wyProgressTo_h__
#define __wyProgressTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyProgressTo
 *
 * 使节点称为进度条显示的动作封装，根据指定变化到的百分比执行动作
 */
class wyProgressTo : public wyIntervalAction {
protected:

	/// 节点起始显示百分比，取值0到100
	float m_from;

	/// 节点结束显示百分比，取值0到100
	float m_to;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param from 节点起始显示百分比，取值0到100
	 * @param to 节点结束显示百分比，取值0到100
	 */
	wyProgressTo(float duration, float from, float to);

	/**
	 * 析构函数
	 */
	virtual ~wyProgressTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyProgressTo_h__
