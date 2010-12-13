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
#ifndef __wyButton_h__
#define __wyButton_h__

#include "wyNode.h"
#include "wySprite.h"

/**
 * @class wyButton
 *
 * 按钮的封装
 */
class wyButton : public wyNode {
protected:
	/// 正常状态的\link wySprite wySprite对象指针 \endlink
	wySprite* m_normalState;

	/// 被选中状态的\link wySprite wySprite对象指针 \endlink
	wySprite* m_selectedState;

	/// 禁用状态的\link wySprite wySprite对象指针 \endlink
	wySprite* m_disabledState;

public:
	/**
	 * 构造函数
	 *
	 * @param normal 正常状态的\link wySprite wySprite对象指针 \endlink
	 * @param selected 被选中状态的\link wySprite wySprite对象指针 \endlink
	 * @param disabled 禁用状态的\link wySprite wySprite对象指针 \endlink
	 * @param downSelector 按下按钮的\link wyTargetSelector wyTargetSelector对象指针 \endlink
	 * @param upSelector 松开按钮的\link wyTargetSelector wyTargetSelector对象指针 \endlink
	 */
	wyButton(wySprite* normal, wySprite* selected, wySprite* disabled, wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	/**
	 * 析构函数
	 */
	virtual ~wyButton();

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::setRotation
	virtual void setRotation(float rot);

	/// @see wyNode::setScale
	virtual void setScale(float scale);

	/// @see wyNode::setScaleX
	virtual void setScaleX(float scaleX);

	/// @see wyNode::setScaleY
	virtual void setScaleY(float scaleY);

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::getAlpha
	virtual int getAlpha();

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/**
	 * 设置正常状态的\link wySprite wySprite对象指针 \endlink
	 *
	 * @param normal 正常状态的\link wySprite wySprite对象指针 \endlink
	 */
	void setNormalSprite(wySprite* normal);

	/**
	 * 设置选中状态的\link wySprite wySprite对象指针 \endlink
	 *
	 * @param selected 正常状态的\link wySprite wySprite对象指针 \endlink
	 */
	void setSelectedSprite(wySprite* selected);

	/**
	 * 设置禁用状态的\link wySprite wySprite对象指针 \endlink
	 *
	 * @param disabled 正常状态的\link wySprite wySprite对象指针 \endlink
	 */
	void setDisabledSprite(wySprite* disabled);
};

#endif // __wyButton_h__
