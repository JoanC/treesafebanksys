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
#ifndef __wyProgressBy_h__
#define __wyProgressBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyProgressBy
 *
 * 使节点称为进度条显示的动作封装，根据指定变化的百分比执行动作
 */
class wyProgressBy : public wyIntervalAction {
protected:
	/// 节点显示变化的百分比，取值0到100
	float m_delta;

	/// 节点起始显示百分比，取值0到100
	float m_from;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param deltaPercents 节点变化的百分比，取值0到100
	 */
	wyProgressBy(float duration, float deltaPercents);

	/**
	 * 析构函数
	 */
	virtual ~wyProgressBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyProgressBy_h__
