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
#ifndef __wyBaseGrid_h__
#define __wyBaseGrid_h__

#include <GLES/gl.h>
#include "wyGrabber.h"
#include <stdbool.h>

class wyNode;

class wyBaseGrid : public wyObject {
protected:
	// grid dimension
	int gridX;
	int gridY;

	// single block size
	float stepWidth;
	float stepHeight;

	// active or not
	bool active;

	// reuse count
	int reuseGrid;

	// grabber
	wyGrabber* grabber;

	// buffers
	GLfloat* vertices;
	GLfloat* texCoords;
	GLfloat* originalVertices;
	GLushort* indices;

public:
	wyBaseGrid(int x, int y);
	virtual ~wyBaseGrid();

	// grid impl
	virtual void blit() = 0;
	virtual void reuse() = 0;

	// called before render a frame
	virtual void beforeDraw();

	// called after render a frame
	virtual void afterDraw(wyNode* node);

	// add reuse count
	void addReuseCount(int add) { reuseGrid += add; }

	// is grid reusable?
	bool isReuseGrid() { return reuseGrid > 0; }

	// getter/setter
	void setActive(bool flag);
	bool isActive() { return active; }
	float getStepWidth() { return stepWidth; }
	float getStepHeight() { return stepHeight; }
	int getGridX() { return gridX; }
	int getGridY() { return gridY; }
	void setGridX(int x) { gridX = x; }
	void setGridY(int y) { gridY = y; }
};

#endif // __wyBaseGrid_h__
