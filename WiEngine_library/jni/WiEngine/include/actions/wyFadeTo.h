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
#ifndef __wyFadeTo_h__
#define __wyFadeTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyFadeTo
 *
 * 节点透明度变化效果的动作封装
 */
class wyFadeTo : public wyIntervalAction {
protected:
	/// 目标透明度，取值0到255，255为透明，0为不透明
	int m_toAlpha;

	/// 起始透明度，取值0到255，255为透明，0为不透明
	int m_fromAlpha;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param fromAlpha 起始透明度，取值0到255，255为透明，0为不透明
	 * @param toAlpha 目标透明度，取值0到255，255为透明，0为不透明
	 */
	wyFadeTo(float duration, int fromAlpha, int toAlpha);
	/**
	 * 析构函数
	 */
	virtual ~wyFadeTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyFadeTo_h__
