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
#ifndef __wyTiledSprite_h__
#define __wyTiledSprite_h__

#include "wyNode.h"
#include "wyTextureAtlas.h"
#include "wyScroller.h"

/**
 * @class wyTiledSprite
 *
 * 对一个贴图进行平铺, 可以用来做游戏背景。wyTiledSprite支持在水平方向或者垂直方向
 * 平铺一个贴图，也支持滚动。
 */
class wyTiledSprite : public wyNode {
private:
	/// 封装贴图的图片集对象
	wyTextureAtlas* m_atlas;

	/**
	 * 如果这个贴图是一个图片集中的某帧，则可以设置矩形参数，缺省情况下
	 * 这个矩形是{0, 0, m_tex->getWidth(), m_tex->getHeight() }，即贴图
	 * 对象的有效区域大小
	 */
	wyRect m_rect;

	/// 表示平铺的方向，true表示垂直方向上平铺， false表示水平方向上平铺
	bool m_vertical;

	/**
	 * 表示贴图是否需要拉伸，如果是在垂直方向上平铺，则表示是否需要在水平方向上拉伸，
	 * 如果是在水平方向上平铺，则表示是否需要在垂直方向上拉伸。如果为false，表示
	 * 不拉伸，贴图将居中显示
	 */
	bool m_stretch;

	/// 左边界(水平平铺时)或者上边界(垂直平铺时)的偏移值，为正时相当于把贴图向左移动，为负时相当于向右移动
	int m_offset;

	/// 表示需要更新顶点数组
	bool m_dirty;

	/// true表示打开缺省的滚动支持
	bool m_scrollable;

	/// true表示打开缺省的fling支持
	bool m_flingable;

	/// 最大的offset，缺省是整数的最大值
	int m_maxOffset;

	/// 最小的offset，缺省是整数的最小值
	int m_minOffset;

	/// 记录上一次touch事件的x位置
	float m_lastX;

	/// 记录上一次touch事件的y位置
	float m_lastY;

	/// true表示当前正在滚动
	bool m_scrolling;

	/// true表示当前正在fling
	bool m_flinging;

	/// scroller
	wyScroller* m_scroller;

	// texture color
	wyColor4B m_color;

    // blend
    wyBlendFunc m_blendFunc;

private:
	/**
	 * 更新atlas中的四边形
	 */
	void updateQuads();

public:
	/**
	 * 构造函数。缺省情况下，wyTiledSprite节点和Surface一样大。
	 *
	 * @param tex 贴图对象，可以为NULL，之后可以通过setTexture再设置
	 */
	wyTiledSprite(wyTexture2D* tex = NULL);

	/**
	 * 析构函数
	 */
	virtual ~wyTiledSprite();

	/**
	 * 得到平铺方向标志
	 *
	 * @return true表示垂直方向上平铺， false表示水平方向上平铺
	 */
	bool isVertical() { return m_vertical; }

	/**
	 * 设置平铺方向标志
	 *
	 * @param flag true表示垂直方向上平铺， false表示水平方向上平铺
	 */
	void setVertical(bool flag);

	/**
	 * 获得是否拉伸贴图标志
	 *
	 * @return true表示贴图会在不平铺的方向上拉伸, false表示在不平铺的方向上居中显示
	 */
	bool isStretch() { return m_stretch; }

	/**
	 * 设置是否拉伸贴图标志
	 *
	 * @param flag true表示贴图会在不平铺的方向上拉伸, false表示在不平铺的方向上居中显示
	 */
	void setStretch(bool flag);

	/**
	 * 如果贴图代表了一个图片集，则可以设置要平铺的贴图在图片集中的矩形位置
	 *
	 * @param r 要平铺的贴图在图片集中的矩形位置，(x, y)代表贴图的左上角坐标
	 */
	void setTextureRect(wyRect r);

	/**
	 * 获得贴图的矩形，如果贴图是一个图片集，则这个方法可以获得实际绘制帧的矩形
	 *
	 * @return 贴图的矩形位置，对于图片集时有意义
	 */
	wyRect getTextureRect() { return m_rect; }

	/**
	 * 设置偏移量，为正时相当于把贴图向左移动，为负时相当于向右移动
	 *
	 * @param offset 偏移量
	 */
	void setOffset(int offset);

	/**
	 * 调整偏移量
	 *
	 * @param delta 偏移量的调整值，会添加到现有偏移量上
	 */
	void offsetBy(int delta);

	/**
	 * 设置是否可以滚动，如果为true，将打开缺省的手势处理逻辑，将会自动
	 * 处理滚动，fling等事件。
	 *
	 * @param flag true表示可以滚动
	 */
	void setScrollable(bool flag);

	/**
	 * 是否wyTiledSprite可以滚动，如果不能滚动，则不处理手势事件
	 *
	 * @return true表示可以滚动
	 */
	bool isScrollable() { return m_scrollable; }

	/**
	 * 设置是否支持fling, fling表示支持手势事件中的fling事件，即手指离开屏幕后仍然根据
	 * 惯性移动，知道速度变为0
	 *
	 * @param flag true表示支持fling
	 */
	void setFlingable(bool flag);

	/**
	 * 是否支持fling
	 *
	 * @return true表示支持fling
	 */
	bool isFlingable() { return m_flingable; }

	/**
	 * 是否正在惯性移动中
	 *
	 * @return true表示正在惯性移动中
	 */
	bool isFlinging() { return m_flinging; }

	/**
	 * 设置最大的偏移量
	 *
	 * @param max 最大偏移量
	 */
	void setMaxOffset(int max) { m_maxOffset = max; }

	/**
	 * 得到最大偏移量
	 *
	 * @return 最大偏移量
	 */
	int getMaxOffset() { return m_maxOffset; }

	/**
	 * 设置最小的偏移量
	 *
	 * @param min 最小偏移量
	 */
	void setMinOffset(int min) { m_minOffset = min; }

	/**
	 * 得到最小偏移量
	 *
	 * @return 最小偏移量
	 */
	int getMinOffset() { return m_minOffset; }

	/// @see wyObject::onTargetSelectorInvoked
	virtual void onTargetSelectorInvoked(wyTargetSelector* ts);

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::setContentSize
	virtual void setContentSize(float w, float h);

	/// @see wyNode::getTexture
	virtual wyTexture2D* getTexture() { return m_atlas->getTexture(); }

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex);

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_color.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha) { m_color.a = alpha; }

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_blendFunc; }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_blendFunc = func; }

	/// @see wyNode::touchesBegan
	virtual bool touchesBegan(wyMotionEvent& e);

	/// @see wyNode::touchesMoved
	virtual bool touchesMoved(wyMotionEvent& e);

	/// @see wyNode::touchesEnded
	virtual bool touchesEnded(wyMotionEvent& e);

	/// @see wyNode::touchesCancelled
	virtual bool touchesCancelled(wyMotionEvent& e);

	/// @see wyNode::onFling
	virtual bool onFling(wyMotionEvent& e1, wyMotionEvent& e2, float velocityX, float velocityY);
};

#endif // __wyTiledSprite_h__
