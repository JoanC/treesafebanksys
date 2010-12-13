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
#ifndef __wyTextureNode_h__
#define __wyTextureNode_h__

#include "wyNode.h"
#include "wyTypes.h"
#include "wyTexture2D.h"
#include <stdbool.h>

class wyTextureNode : public wyNode {
protected:
    /**
     * The texture that is rendered
     */
    wyTexture2D* tex;

    // blend
    wyBlendFunc blendFunc;

	// texture color
	wyColor4B color;

	// flag indicating draw a X-flipped image
	bool flipX;

	// flag indicating draw a Y-flipped image
	bool flipY;

public:
	wyTextureNode();
	wyTextureNode(wyTexture2D* tex);
	virtual ~wyTextureNode();

	// from node
	virtual void draw();

	// 得到当前alpha值
	virtual int getAlpha() { return color.a; }

	// 设置alpha值
	virtual void setAlpha(int alpha) { color.a = alpha; }

	// 得到当前颜色
	virtual wyColor3B getColor();

	// 设置颜色
	virtual void setColor(wyColor3B color);

	// get blend func
	virtual wyBlendFunc getBlendFunc() { return blendFunc; }

	// set blend func
	virtual void setBlendFunc(wyBlendFunc func) { blendFunc = func; }

	// get texture
	virtual wyTexture2D* getTexture() { return tex; }

	// set texture
	virtual void setTexture(wyTexture2D* tex);

	// flip
	void setFlipX(bool flipX) { this->flipX = flipX; }
	bool isFlipX() { return flipX; }
	void setFlipY(bool flipY) { this->flipY = flipY; }
	bool isFlipY() { return flipY; }
};

#endif // __wyTextureNode_h__
