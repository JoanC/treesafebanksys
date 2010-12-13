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
#ifndef __wyRibbon_h__
#define __wyRibbon_h__

#include "wyNode.h"
#include <GLES/gl.h>

class wyRibbon : public wyNode {
protected:
    wyArray* segments;
    wyArray* segmentPool;

    wyPoint lastLocation;
    float texVPos;
    float curTime;
    float fadeTime;
    float delta;
    float lastWidth;
    bool firstPoint;

    // flag indicating we need create a new segment
    bool forceNewSegment;

    // Texture used
    wyTexture2D* tex;

    // texture length
    float textureLength;

    // mFadeColor protocol
    wyColor4B color;

    // blend func
    wyBlendFunc blendFunc;

private:
    static bool releaseSegment(wyArray* arr, void* ptr, int index, void* data);

public:
    wyRibbon(float ribbonWidth, wyTexture2D* tex, float textureLength, wyColor4B color, float fade);
    virtual ~wyRibbon();

    // node
    virtual void draw();

	// get blend func
	virtual wyBlendFunc getBlendFunc() { return blendFunc; }

	// set blend func
	virtual void setBlendFunc(wyBlendFunc func) { blendFunc = func; }

	// get texture
	virtual wyTexture2D* getTexture() { return tex; }

	// set texture
	virtual void setTexture(wyTexture2D* tex);

	// first point
	void forceFirstPoint() { firstPoint = true; }

	// update
	void update(float delta);

	// add point
	void addPoint(wyPoint location, float ribbonWidth);
};

#endif // __wyRibbon_h__
