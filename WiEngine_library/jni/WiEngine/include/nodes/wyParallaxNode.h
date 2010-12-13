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
#ifndef __wyParallaxNode_h__
#define __wyParallaxNode_h__

#include "wyNode.h"
#include "wyArray.h"

class wyParallaxNode : public wyNode {
protected:
	wyArray* parallaxObjects;
	wyPoint lastPosition;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

public:
	wyParallaxNode();
	virtual ~wyParallaxNode();

	// node
	virtual void visit();
	virtual void addChild(wyNode* child, int z, int tag);
	virtual void removeAllChildren(bool cleanup);
	virtual void removeChild(wyNode* child, bool cleanup);

	// size to fit
	void sizeToFit();

	// add child
	void addChild(wyNode* child, int z, float ratioX, float ratioY, float offsetX, float offsetY);
};

#endif // __wyParallaxNode_h__
