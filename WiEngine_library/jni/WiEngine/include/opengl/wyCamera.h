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
#ifndef __wyCamera_h__
#define __wyCamera_h__

#include <GLES/gl.h>
#include <stdbool.h>
#include "wyObject.h"

class wyCamera : public wyObject {
private:
	GLfloat eyeX;
	GLfloat eyeY;
	GLfloat eyeZ;

	GLfloat centerX;
	GLfloat centerY;
	GLfloat centerZ;

	GLfloat upX;
	GLfloat upY;
	GLfloat upZ;

	bool dirty;

public:
	// create wyCamera
	wyCamera();
	virtual ~wyCamera();

	// restore to original setting
	void restore();

	// locate camera
	void locate();

	// set eye
	void setEye(float x, float y, float z);

	// set center
	void setCenter(float x, float y, float z);

	// set up
	void setUp(float x, float y, float z);

	// getter
	void getEye(float* eye);
	void getCenter(float* center);
	void getUp(float* up);
	bool isDirty() { return dirty; }
	void setDirty(bool dirty) { this->dirty = dirty; }
};

#endif // __wyCamera_h__
