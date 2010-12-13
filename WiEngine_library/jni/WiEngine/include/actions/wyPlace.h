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
#ifndef __wyPlace_h__
#define __wyPlace_h__

#include "wyInstantAction.h"
#include "wyTypes.h"

/**
 * @class wyPlace
 *
 * 节点位置变化的动作封装,根据设置点进行移动
 */
class wyPlace : public wyInstantAction {
protected:
	/// 设置的移动点的位置 \link wyPoint wyPoint对象 \endlink
	wyPoint m_position;

public:
	/**
	 * 构造函数
	 *
	 * @param x 目标位置x轴距离
	 * @param y 目标位置y轴距离
	 */
	wyPlace(float x, float y);

	/**
	 * 析构函数
	 */
	virtual ~wyPlace();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/**
	 * 此动作不支持反转，返回为NULL
	 *
	 * @return NULL
	 */
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);
};

#endif // __wyPlace_h__
