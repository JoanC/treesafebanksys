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
#ifndef __wyMotionStreak_h__
#define __wyMotionStreak_h__

#include "wyNode.h"
#include "wyRibbon.h"

class wyMotionStreak : public wyNode {
protected:
	wyRibbon* ribbon;
	float segThreshold;
	float width;
	wyPoint lastLocation;

public:
	wyMotionStreak(float fade, float segmentThreshold, wyTexture2D* tex, float width, float length, wyColor4B color);
	virtual ~wyMotionStreak();

	/* target method for native target selector */
	virtual void onTargetSelectorInvoked(wyTargetSelector* ts);

	// node
	virtual void setPosition(float x, float y);

	// get blend func
	virtual wyBlendFunc getBlendFunc() { return ribbon->getBlendFunc(); }

	// set blend func
	virtual void setBlendFunc(wyBlendFunc func) { ribbon->setBlendFunc(func); }

	// get texture
	virtual wyTexture2D* getTexture() { return ribbon->getTexture(); }

	// set texture
	virtual void setTexture(wyTexture2D* tex) { ribbon->setTexture(tex); }

	// update
	void update(float delta);

	// set position
	void setPosition(float x, float y, bool newSegment);

	// ribbon
	wyRibbon* getRibbon() { return ribbon; }
};

#endif // __wyMotionStreak_h__
