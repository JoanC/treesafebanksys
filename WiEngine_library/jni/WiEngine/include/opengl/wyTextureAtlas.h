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
#ifndef __wyTextureAtlas_h__
#define __wyTextureAtlas_h__

#include "wyTexture2D.h"
#include <stdbool.h>
#include <GLES/gl.h>
#include "wyTypes.h"

#define ATLAS_DEFAULT_CAPACITY 29

class wyTextureAtlas : public wyObject {
protected:
	// related texture
	wyTexture2D* tex;

	// number of quadratic
	int totalQuads;

	// how many quadratic can be hold by buffer
	int capacity;

	// flag indicating use my color buffer to render vertex
	bool withColorArray;

	// buffers
	GLfloat* vertices;
	GLfloat* texCoords;
	GLubyte* colors;
	GLushort* indices;

private:
	void putColor(wyColor4B* color, int index);
	void putVertex(wyQuad3D* quadV, int index);
	void putTexCoords(wyQuad2D* quadT, int index);
	void initColorArray();
	void initIndices();

public:
	static wyTextureAtlas* make(wyTexture2D* tex);

	wyTextureAtlas(wyTexture2D* tex, int capacity = ATLAS_DEFAULT_CAPACITY);
	virtual ~wyTextureAtlas();

	// set texture
	void setTexture(wyTexture2D* tex);
	wyTexture2D* getTexture() { return tex; }

	// resize capacity
	void resizeCapacity(int newCapacity);

	// remove all quad
	void removeAllQuads() { totalQuads = 0; }

	// get next available quad index
	int getNextAvailableIndex();

	// update quad
	void updateQuad(wyQuad2D quadT, wyQuad3D quadV, int index);

	// update color
	void updateColor(wyColor4B color, int index);

	// append quad
	void appendQuad(wyQuad2D quadT, wyQuad3D quadV);

	// insert quad
	void insertQuad(wyQuad2D quadT, wyQuad3D quadV, int index);

	// remove quad
	void removeQuad(int index);

	// draw one quad
	void drawOne(int index);

	// draw quads
	void draw(int numOfQuads);

	// draw all quads
	void drawAll();

	// getter/setters
	int getTotalQuads() { return totalQuads; }
	bool isWithColorArray() { return withColorArray; }
	int getCapacity() { return capacity; }
	int getPixelHeight() { return tex->getPixelHeight(); }
	int getPixelWidth() { return tex->getPixelWidth(); }
	float getWidth() { return tex->getWidth(); }
	float getHeight() { return tex->getHeight(); }
	float getWidthScale() { return tex->getWidthScale(); }
	float getHeightScale() { return tex->getHeightScale(); }
};

#endif // __wyTextureAtlas_h__
