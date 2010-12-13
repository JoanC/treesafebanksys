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
#ifndef __wyMenu_h__
#define __wyMenu_h__

#include "wyLayer.h"
#include "wyMenuItem.h"

#define DEFAULT_PADDING 5

class wyMenu : public wyLayer {
protected:
	// selected item
	wyMenuItem* selectedItem;

private:
	wyMenuItem* itemForTouch(wyMotionEvent& event);

public:
	wyMenu();
	wyMenu(wyMenuItem* item1, ...);
	virtual ~wyMenu();

	/// @see wyNode::touchesBegan
	virtual bool touchesBegan(wyMotionEvent& e);

	/// @see wyNode::touchesMoved
	virtual bool touchesMoved(wyMotionEvent& e);

	/// @see wyNode::touchesEnded
	virtual bool touchesEnded(wyMotionEvent& e);

	/// @see wyNode::touchesCancelled
	virtual bool touchesCancelled(wyMotionEvent& e);

	/// @see wyNode::hitTest
	virtual bool hitTest(float x, float y);

	// align
	void alignItemsVertically(float padding = DEFAULT_PADDING);
	void alignItemsHorizontally(float padding = DEFAULT_PADDING);
	void alignItemsInColumns(int count, int* columns);
	void alignItemsInRows(int count, int* rows);


	// add menu item
	void addMenuItem(wyMenuItem* item);
};

#endif // __wyMenu_h__
