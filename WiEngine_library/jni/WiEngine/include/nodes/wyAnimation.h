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
#ifndef __wyAnimation_h__
#define __wyAnimation_h__

#include "wyNode.h"
#include "wyTextureFrame.h"
#include "wyArray.h"

/**
 * @class wyAnimation
 *
 * 动画的封装, 设置动画的帧和持续时间
 */
class wyAnimation : public wyObject {
private:
	/// 动画id
	int id;

	/// 帧列表的\link wyArray wyArray对象 \endlink 指针
	wyArray* frames;

	/// 动画持续的时间
	float duration;

private:
	/**
	 * 释放某一帧动画资源，枚举函数指针
	 *
	 * @param arr 帧列表的\link wyArray wyArray对象 \endlink 指针
	 * @param ptr 当前帧的指针
	 * @param index 该帧在wyArray中的索引位置
	 * @param data参数
	 */
	static bool releaseFrame(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * 构造函数
	 *
	 * @param id 动画id
	 */
	wyAnimation(int id);

	/**
	 * 析构函数
	 */
	virtual ~wyAnimation();

	/**
	 * 得到动画总持续时间
	 *
	 * @return 动画总持续时间
	 */
	virtual float getDuration() { return duration; }

	/**
	 * 得到帧列表的\link wyArray wyArray对象 \endlink 指针
	 *
	 * @return 帧列表的\link wyArray wyArray对象 \endlink 指针
	 */
	virtual wyArray* getFrames() { return frames; }

	/**
	 * 得到动画id
	 *
	 * @return 动画id
	 */
	virtual int getId() { return id; }

	/**
	 * 添加一帧动画
	 *
	 * @param frameDuration 所添加的帧持续的时间
	 * @param tex \link wyTexture2D wyTexture2D对象 \endlink 指针
	 */
	void addFrame(float frameDuration, wyTexture2D* tex);
};


#endif //__wyAnimation_h__
