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
#ifndef __wyProgressTimer_h__
#define __wyProgressTimer_h__

#include "wyNode.h"
#include "wySprite.h"
#include <GLES/gl.h>

typedef enum {
	/**
	 * 扇形，逆时针
	 */
	RADIAL_CCW = 1,

	/**
	 * 扇形，顺时针
	 */
	RADIAL_CW,

	/**
	 * 水平条形，从左到右
	 */
	HORIZONTAL_BAR_LR,

	/**
	 * 水平条形，从右到左
	 */
	HORIZONTAL_BAR_RL,

	/**
	 * 垂直条形，从下到上
	 */
	VERTICAL_BAR_BT,

	/**
	 * 垂直条形，从上到下
	 */
	VERTICAL_BAR_TB
} wyProgressTimerStyle;

class wyProgressTimer : public wyNode {
protected:
	// type
	wyProgressTimerStyle style;

	// percentage, from 0 to 100
	float percentage;

	// sprite
	wySprite* sprite;

	// buffers
	GLfloat* vertices;
	GLfloat* texCoords;
	GLfloat* colors;
	int vertexCount;

private:
	void updateProgress();
	void updateBar();
	void updateRadial();
	void updateColor();
	void resetCapacity(int c);
	wyPoint boundaryTexCoord(int index);
	wyPoint vertexFromTexCoord(float u, float v);

public:
	wyProgressTimer(wyTexture2D* tex);
	virtual ~wyProgressTimer();

	// node
	virtual void draw();

	// set percentage
	void setPercentage(float percentage);
	float getPercentage() { return percentage; }

	// set sprite
	void setSprite(wySprite* sprite);

	// set style
	void setStyle(wyProgressTimerStyle style);
};

#endif // __wyProgressTimer_h__
