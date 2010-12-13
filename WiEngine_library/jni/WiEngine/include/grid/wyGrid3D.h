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
#ifndef __wyGrid3D_h__
#define __wyGrid3D_h__

#include "wyBaseGrid.h"
#include "wyTypes.h"

class wyGrid3D : public wyBaseGrid {
private:
	void calculateVertexPoints();

public:
	wyGrid3D(int x, int y);
	virtual ~wyGrid3D();

	// grid impl
	virtual void blit();
	virtual void reuse();

	// set vertex at specified position
	void setVertex(wyDimension pos, wyVertex3D vertex);

	// get vertex at specified position
	wyVertex3D getVertex(wyDimension pos);

	// get original vertex at specified position
	wyVertex3D getOriginalVertex(wyDimension pos);
};


#endif // __wyGrid3D_h__
