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
#ifndef __wyTwirl_h__
#define __wyTwirl_h__

#include "wyGrid3DAction.h"

class wyTwirl : public wyGrid3DAction {
protected:
	// twirl center point
	float centerX;
	float centerY;
	float deltaX;
	float deltaY;

	// twirls
	float twirls;

	// delta amplitude
	float deltaAmplitude;

	// last values
	float lastX;
	float lastY;
	float lastAmplitude;

public:
	wyTwirl(float duration, int gridX, int gridY, float centerX, float centerY, float deltaX, float deltaY, float amplitude,
	        float deltaAmplitude, float twirls);
	virtual ~wyTwirl();

	virtual wyAction* copy();
	virtual void update(float t);
};

#endif // __wyTwirl_h__
