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
#ifndef __wySequence_h__
#define __wySequence_h__

#include "wyIntervalAction.h"
#include "wyArray.h"

/**
 * @class wySequence
 *
 * 按顺序执行一组动作的封装
 */
class wySequence : public wyIntervalAction {
protected:
	/// 所有动作的\link wyArray wyArray对象 \endlink指针
	wyArray* m_actions;

	/// 两个动作的时间区分点
	float m_split;

	/// 当前执行的动作index
	int m_last;

private:
	/**
	 * 释放动作资源，枚举函数指针
	 *
	 * @param arr 帧列表的\link wyArray wyArray对象 \endlink 指针
	 * @param ptr 某一动作的指针
	 * @param index 该动作在wyArray中的索引位置
	 * @param data参数
	 */
	static bool releaseAction(wyArray* arr, void* ptr, int index, void* data);

	/**
	 * 停止动作，枚举函数指针
	 *
	 * @param arr 帧列表的\link wyArray wyArray对象 \endlink 指针
	 * @param ptr 某一动作的指针
	 * @param index 该动作在wyArray中的索引位置
	 * @param data参数
	 */
	static bool stopAction(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * 构造\link wySequence wySequence对象 \endlink 指针
	 *
	 * @param action1 要执行的动作\link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	 * @param action2 要执行的动作\link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针，
	 * 后面还可以添加多个\link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针，参数以NULL结束
	 * @return \link wySequence wySequence对象 \endlink 指针
	 */
	static wySequence* make(wyFiniteTimeAction* action1, wyFiniteTimeAction* action2, ...);

	/**
	 * 构造函数
	 *
	 * @param action1 要执行的第一个动作
	 * @param action2 要执行的第二个动作
	 */
	wySequence(wyFiniteTimeAction* action1, wyFiniteTimeAction* action2);

	/**
	 * 析构函数
	 */
	virtual ~wySequence();

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

#endif // __wySequence_h__
