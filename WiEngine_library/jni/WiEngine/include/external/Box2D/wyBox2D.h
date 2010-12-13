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
#ifndef __wyBox2D_h__
#define __wyBox2D_h__

#include "wyNode.h"
#include <Box2D/Box2D.h>

class wyBox2DDebugDraw;

/**
 * @class wyBox2D
 *
 * 对Box2D进行了一个节点形式的封装，wyBox2D是wyNode的子类，因此可以被添加到场景中。
 */
class wyBox2D : public wyNode {
private:
	/// Box2D的World对象
	b2World* m_world;

	/// b2DebugDraw实现, 仅用于debug draw模式
	wyBox2DDebugDraw* m_ddImpl;

	/// true表示使用debug draw模式渲染World
	bool m_debugDraw;

public:
	wyBox2D();
	virtual ~wyBox2D();

	/// @see wyNode::draw
	virtual void draw();

	/**
	 * 得到世界对象指针，世界对象在wyBox2D对象初始化时被创建
	 *
	 * @return b2World对象指针
	 */
	b2World* getWorld() { return m_world; }

	/**
	 * 得到是否是debug draw模式的标志
	 *
	 * @return debug draw模式的标志, true表示是debug draw模式
	 */
	bool isDebugDraw() { return m_debugDraw; }

	/**
	 * 设置是否debug draw. Debug draw模式下使用简单的线条和色块渲染物体。
	 *
	 * @param flag true表示使用debug draw
	 */
	void setDebugDraw(bool flag) { m_debugDraw = flag; }

	/**
	 * 根据当前的box2d放缩比例，把像素数转换成米数
	 *
	 * @param pixel 像素数
	 * @return 米数
	 */
	float pixel2Meter(int pixel);

	/**
	 * 根据当前的box2d放缩比例, 把米数转换成像素数
	 *
	 * @param meter 米数
	 * @return 像素数
	 */
	int meter2Pixel(float meter);

	/**
	 * 得到1米对应的像素数
	 *
	 * @return 1米对应的像素数
	 */
	int getMeterPixels();

	/**
	 * 设置1米对应的像素数
	 *
	 * @param mp 1米对应的像素数
	 */
	void setMeterPixels(int mp);

	/**
	 * 得到b2DebugDraw接口的实现类指针
	 */
	b2DebugDraw* getDebugDrawImpl() { return (b2DebugDraw*)m_ddImpl; }
};

#endif // __wyBox2D_h__
