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
#ifndef __wyQuadParticleSystem_h__
#define __wyQuadParticleSystem_h__

#include "wyParticleSystem.h"
#include "wyTypes.h"

class wyQuadParticleSystem : public wyParticleSystem {
protected:
	// buffers
	GLfloat* vertices;
	GLfloat* colors;
	GLfloat* texCoords;
	GLushort* indices;

	virtual void postStep();
	virtual void updateQuadWithParticle(wyParticle* particle, wyPoint newPosition);

	void initTexCoordsWithRect(wyRect rect);
	void initIndices();

public:
	wyQuadParticleSystem(int numberOfParticles);
	virtual ~wyQuadParticleSystem();

	// node
	virtual void draw();

	// set texture
	virtual void setTexture(wyTexture2D* tex);

	// set texture
	void setTexture(wyTexture2D* tex, wyRect rect);
};


#endif // __wyQuadParticleSystem_h__
