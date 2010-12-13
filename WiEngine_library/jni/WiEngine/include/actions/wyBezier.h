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
#ifndef __wyBezier_h__
#define __wyBezier_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * @class wyBezier
 *
 * 节点按照贝塞尔曲线轨迹运动的动作封装
 */
class wyBezier : public wyIntervalAction {
protected:
	// 贝塞尔曲线关键点的结构
	wyBezierConfig m_config;

	/// 起始点x坐标
	float m_startX;

	/// 起始点y坐标
	float m_startY;

public:
	/**
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param config 贝塞尔曲线关键点的结构\link wyBezierConfig wyBezierConfig结构 \endlink
	 */
	wyBezier(float duration, wyBezierConfig config);

	/**
	 * 析构函数
	 */
	virtual ~wyBezier();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyBezier_h__
