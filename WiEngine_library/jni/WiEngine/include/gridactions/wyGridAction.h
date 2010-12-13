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
#ifndef __wyGridAction_h__
#define __wyGridAction_h__

#include "wyIntervalAction.h"
#include "wyBaseGrid.h"

class wyGridAction : public wyIntervalAction {
protected:
	// grid horizontal/vertical tiles
	int gridX;
	int gridY;

	// amplitude
	float amplitude;

	// amplitude rate
	float amplitudeRate;

public:
	wyGridAction(float duration, int gridX, int gridY);
	virtual ~wyGridAction();

	virtual wyBaseGrid* makeGrid() = 0;
	virtual wyObjectType getGridClass() = 0;

	virtual wyAction* reverse();
	virtual void start(wyNode* target);

	// setter
	void setAmplitude(float amp) { amplitude = amp; }
	void setAmplitudeRate(float ar) { amplitudeRate = ar; }

	// getter
	float getAmplitude() { return amplitude; }
	float getAmplitudeRate() { return amplitudeRate; }
	float getGridX() { return gridX; }
	float getGridY() { return gridY; }
};

#endif // __wyGridAction_h__
