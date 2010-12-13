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
#ifndef __wyOrbitCamera_h__
#define __wyOrbitCamera_h__

#include "wyCameraAction.h"

class wyOrbitCamera : public wyCameraAction {
protected:
	float radius;
	float deltaRadius;
	float angleZ;
	float deltaAngleZ;
	float angleX;
	float deltaAngleX;

	float radianZ;
	float deltaRadianZ;
	float radianX;
	float deltaRadianX;

private:
	void spherical(float* newRadius, float* zenith, float* azimuth);

public:
	wyOrbitCamera(float duration, float r, float dr, float z, float dz, float x, float dx);
	virtual ~wyOrbitCamera();

	virtual wyAction* copy();
	virtual void start(wyNode* target);
	virtual void update(float t);
};

#endif // __wyOrbitCamera_h__
