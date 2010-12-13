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
#ifndef __wyMenuItemToggle_h__
#define __wyMenuItemToggle_h__

#include "wyMenuItem.h"
#include "wyArray.h"

class wyMenuItemToggle : public wyMenuItem {
protected:
	int selectedIndex;
	wyArray* items;
	wyColor4B color;

private:
	static bool releaseItem(wyArray* arr, void* ptr, int index, void* data);

public:
	wyMenuItemToggle(wyTargetSelector* downSelector, wyTargetSelector* upSelector, int count, ...);
	virtual ~wyMenuItemToggle();

	// node
	virtual void setSelected(bool selected);
	virtual void setEnabled(bool enabled);

	// item
	virtual void beforeInvoke(wyTargetSelector* ts);

	// 得到当前alpha值
	virtual int getAlpha() { return color.a; }

	// 设置alpha值
	virtual void setAlpha(int alpha);

	// 得到当前颜色
	virtual wyColor3B getColor();

	// 设置颜色
	virtual void setColor(wyColor3B color);

	// set selected index
	void setSelectedIndex(int index);
	int getSelectedIndex() { return selectedIndex; }

	// add item
	void addMenuItem(wyMenuItem* item);
};

#endif // __wyMenuItemToggle_h__
