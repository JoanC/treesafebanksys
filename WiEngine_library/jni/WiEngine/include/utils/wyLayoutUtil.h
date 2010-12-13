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
#ifndef __wyLayoutUtil_h__
#define __wyLayoutUtil_h__

#include "wyNode.h"

#define LAYOUT_LEFT 3
#define LAYOUT_RIGHT 5
#define LAYOUT_CENTER 17
#define LAYOUT_TOP 48
#define LAYOUT_BOTTOM 80

class wyLayoutUtil {
public:
	static void loadLayout(int resId);
	static void bindNode(wyNode* node, int viewId);
	static void bindNode(wyNode* node, int viewId, bool relativeToParent);
	static void bindNode(wyNode* node, int viewId, int gravity, bool relativeToParent);
	static void releaseView();
};

#endif // __wyLayoutUtil_h__
