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
#ifndef __wyMenuItemSprite_h__
#define __wyMenuItemSprite_h__

#include "wyMenuItem.h"
#include "wySprite.h"

class wyMenuItemSprite : public wyMenuItem {
protected:
	// state sprite
	wySprite* normalState;
	wySprite* selectedState;
	wySprite* disabledState;

public:
	wyMenuItemSprite(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled);
	virtual ~wyMenuItemSprite();

	// from node
	virtual void draw();
	virtual void setRotation(float rot);
	virtual void setScale(float scale);
	virtual void setScaleX(float scaleX);
	virtual void setScaleY(float scaleY);

	// 得到当前alpha值
	virtual int getAlpha() { return normalState->getAlpha(); }

	// 设置alpha值
	virtual void setAlpha(int alpha);

	// 得到当前颜色
	virtual wyColor3B getColor() { return normalState->getColor(); }

	// 设置颜色
	virtual void setColor(wyColor3B color);

	// get blend func
	virtual wyBlendFunc getBlendFunc() { return normalState->getBlendFunc(); }

	// set blend func
	virtual void setBlendFunc(wyBlendFunc func);

	// set state
	void setNormalSprite(wySprite* normal);
	void setSelectedSprite(wySprite* selected);
	void setDisabledSprite(wySprite* disabled);
};

#endif // __wyMenuItemSprite_h__
