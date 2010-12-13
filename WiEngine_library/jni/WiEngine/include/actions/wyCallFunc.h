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
#ifndef __wyCallFunc_h__
#define __wyCallFunc_h__

#include "wyInstantAction.h"
#include "wyTargetSelector.h"

/**
 * @class wyCallFunc
 *
 * 节点调用\link wyTargetSelector wyTargetSelector \endlink的动作封装
 */
class wyCallFunc : public wyInstantAction {
protected:
	/// 动作要执行的\link wyTargetSelector wyTargetSelector对象 \endlink指针
	wyTargetSelector* m_targetSelector;

public:
	/**
	 * 构造函数
	 *
	 * @param ts 动作要执行的\link wyTargetSelector wyTargetSelector对象 \endlink指针
	 */
	wyCallFunc(wyTargetSelector* ts);

	/**
	 * 析构函数
	 */
	virtual ~wyCallFunc();

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

#endif // __wyCallFunc_h__
