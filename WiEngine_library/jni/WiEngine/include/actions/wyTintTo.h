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
#ifndef __wyTintTo_h__
#define __wyTintTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyTintTo
 *
 * 节点染色的动作封装,根据设置起始染色量进行移动
 */
class wyTintTo : public wyIntervalAction {
protected:
	/// 目标红色值, 0到255
	int m_toR;

	/// 目标绿色值, 0到255
	int m_toG;

	/// 目标蓝色值, 0到255
	int m_toB;

	/// 红色值变化值
	int m_deltaR;

	/// 绿色值变化值
	int m_deltaG;

	/// 蓝色值变化值
	int m_deltaB;

	/// 初始红色值, 0到255
	int m_fromR;

	/// 初始绿色值, 0到255
	int m_fromG;

	/// 初始蓝色值, 0到255
	int m_fromB;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param fromR 初始红色值, 0到255
	 * @param fromG 初始绿色值, 0到255
	 * @param fromB 初始蓝色值, 0到255
	 * @param toR 目标红色值, 0到255
	 * @param toG 目标绿色值, 0到255
	 * @param toB 目标蓝色值, 0到255
	 */
	wyTintTo(float duration, int fromR, int fromG, int fromB, int toR, int toG, int toB);

	/**
	 * 析构函数
	 */
	virtual ~wyTintTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyTintTo_h__
