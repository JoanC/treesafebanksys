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
#ifndef __wyChipmunk_h__
#define __wyChipmunk_h__

#include "wyNode.h"
#include "chipmunk.h"
#include "chipmunk_unsafe.h"
#include "drawSpace.h"

class wyChipmunk : public wyNode {
private:
	// space
	cpSpace* space;

	// draw options
	drawSpaceOptions options;

public:
	wyChipmunk();
	virtual ~wyChipmunk();

	// node
	virtual void draw();

	// getter/setter
	void setDebugDraw(bool debugDraw) { options.debugDraw = debugDraw ? 1 : 0; }
	bool isDebugDraw() { return options.debugDraw == 1; }
	cpSpace* getSpace() { return space; }

	// helper methods
	static void applyDampedSpring(cpBody* a, cpBody* b, wyPoint anchor1, wyPoint anchor2, float rlen, float k, float dmp, float dt);
};

#endif // __wyChipmunk_h__
