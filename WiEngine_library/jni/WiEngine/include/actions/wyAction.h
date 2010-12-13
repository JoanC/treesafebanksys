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
#ifndef __wyAction_h__
#define __wyAction_h__

#include <stdbool.h>
#include "wyObject.h"
#include <jni.h>

#define WY_ACTION_INVALID_TAG -1

class wyAction;

/// wyAction的回调函数结构定义
typedef struct wyActionCallback {
	/**
	 * 当动作开始执行时被调用
	 *
	 * @param action \link wyAction wyAction对象\endlink
	 * @param data 附加数据指针
	 */
	void (*onStart)(wyAction* action, void* data);

	/**
	 * 当动作结束时被调用, 可以通过isDone来判断是否是正常结束
	 *
	 * @param action \link wyAction wyAction对象\endlink
	 * @param data 附加数据指针
	 */
	void (*onStop)(wyAction* action, void* data);

	/**
	 * 在动作执行了update时被调用
	 *
	 * @param action \link wyAction wyAction对象\endlink
	 * @param t 当前时间点，从0到1
	 * @param data 附加数据指针
	 */
	void (*onUpdate)(wyAction* action, float t, void* data);

	/// 附加数据指针，wyAction不会负责释放该指针
	void* data;
} wyActionCallback;

class wyNode;

/**
 * @class wyAction
 *
 * 动作的封装, 是所有动作的基类
 */
class wyAction : public wyObject {
private:
	/// true表示动作正在运行
	bool m_running;

protected:
	/// 执行动作\link wyNode wyNode对象 \endlink 的指针
	wyNode* m_target;

	/// 动作的标签
	int m_tag;

	/// 动作执行的回调函数指针
	wyActionCallback* m_callback;

	/// 动作执行的java回调函数对象,调用java层的setCallback设置
	jobject j_callback;

protected:
	/**
	 * 当动作开始执行时的回调函数
	 */
	virtual void invokeOnStart();

	/**
	 * 当动作结束执行时的回调函数
	 */
	virtual void invokeOnStop();

	/**
	 * 当动作执行过程中时的回调函数
	 *
	 * @param t 动作执行的相对时间，取值从0到1
	 */
	virtual void invokeOnUpdate(float t);

public:
	/**
	 * 构造函数
	 */
	wyAction();

	/**
	 * 析构函数
	 */
	virtual ~wyAction();

	/**
	 * 获得当前动作的复制
	 *
	 * @return \link wyAction wyAction对象 \endlink 的指针
	 */
	virtual wyAction* copy();

	/**
	 * 获得动作反转后的指针
	 *
	 * @return \link wyAction wyAction对象 \endlink 的指针
	 */
	virtual wyAction* reverse();

	/**
	 * 开始执行动作，如果动作有回调，会触发onStart回调函数
	 *
	 * @param target 执行动作\link wyNode wyNode对象 \endlink 的指针
	 */
	virtual void start(wyNode* target);

	/**
	 * 停止动作，如果动作有回调，会触发onStop回调函数
	 */
	virtual void stop();

	/**
	 * 执行当前动作距离上次执行的时间差
	 *
	 * @param t 动作执行的时间
	 */
	virtual void step(float t);

	/**
	 * 更新动作执行的百分比，如果动作有回调，会触发onUpdate回调函数
	 *
	 * @param t 动作执行的相对时间，取值从0到1
	 */
	virtual void update(float t);

	/**
	 * 判断动作是否结束
	 *
	 * @return 动作是否结束
	 */
	virtual bool isDone();

	// setter
	/**
	 * 设置动作执行的回调函数引用
	 *
	 * @param callback 回调函数\link wyActionCallback wyActionCallback对象 \endlink 的引用
	 */
	void setCallback(wyActionCallback& callback);

	/**
	 * 设置动作执行的java回调函数引用
	 *
	 * @param jcallback java回调函数对象
	 */
	void setJavaCallback(jobject jcallback);

	/**
	 * 设置动作标签
	 *
	 * @param tag 动作标签
	 */
	void setTag(int tag);

	// getter
	/**
	 * 获得动作java回调函数对象
	 *
	 * @return java回调函数对象
	 */
	jobject getJavaCallback();

	/**
	 * 获得动作标签
	 *
	 * @return 动作标签
	 */
	int getTag();

	/**
	 * 获得执行动作的\link wyNode wyNode对象 \endlink 指针
	 *
	 * @return 执行动作的\link wyNode wyNode对象 \endlink 指针
	 */
	wyNode* getTarget();
};

#endif // __wyAction_h__
