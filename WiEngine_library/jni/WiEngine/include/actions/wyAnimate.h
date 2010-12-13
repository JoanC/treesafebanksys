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
#ifndef __wyAnimate_h__
#define __wyAnimate_h__

#include "wyIntervalAction.h"
#include "wyFrame.h"

/**
 * @class wyAnimate
 *
 * 动画播放动作的封装
 */
class wyAnimate : public wyIntervalAction {
protected:
	/// 动画 \link wyObject wyObject对象 \endlink 指针
	wyObject* m_anim;

	/// 起始帧 \link wyFrame wyFrame对象 \endlink 指针
	wyFrame* m_originFrame;

	/// 动作停止后是否覆盖起始帧，true为覆盖
	bool m_fillAfter;

public:
	/**
	 * 构造函数
	 *
	 * @param anim 动画 \link wyObject wyObject对象 \endlink 指针
	 * @param fillAfter 动作停止后是否覆盖起始帧，true为覆盖
	 */
	wyAnimate(wyObject* anim, float fillAfter);

	/**
	 * 析构函数
	 */
	virtual ~wyAnimate();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyAnimate_h__
