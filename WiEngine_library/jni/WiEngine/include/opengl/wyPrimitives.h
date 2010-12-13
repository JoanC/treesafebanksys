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
#ifndef __wyPrimitives_h__
#define __wyPrimitives_h__

#include "wyTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

// draw point
void wyDrawPoint(float x, float y);

// draw points
void wyDrawPoints(float* p, int length);

// draw line
void wyDrawLine(float x1, float y1, float x2, float y2);

// draw poly
void wyDrawPoly(float* p, int length, bool close);

// draw rect
void wyDrawRect(float* p);

// draw circle
void wyDrawCircle(float centerX, float centerY, float r, float radiusLineAngle, int segments, bool drawLineToCenter);

// draw quad bezier
void wyDrawQuadBezier(float originX, float originY, float controlX, float controlY, float destinationX, float destinationY, int segments);

// draw cubic bezier
void wyDrawCubicBezier(float originX, float originY, float control1X, float control1Y, float control2X, float control2Y,
		float destinationX, float destinationY, int segments);

// draw a texture
void wyDrawTexture(int texture, float w, float h, float x, float y, bool flipX, bool flipY);

#ifdef __cplusplus
}
#endif

#endif // __wyPrimitives_h__
