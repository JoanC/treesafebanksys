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
#ifndef __wyAtlasNode_h__
#define __wyAtlasNode_h__

#include "wyNode.h"
#include "wyTextureAtlas.h"

class wyAtlasNode : public wyNode {
protected:
    // texture atlas
    wyTextureAtlas* atlas;

    // chars per row
    int itemsPerRow;

    // chars per column
    int itemsPerColumn;

    // texture coordinate x increment
    float texStepX;

    // texture coordinate y increment
    float texStepY;

    // width of each char
    int itemWidth;

    // height of each char
    int itemHeight;

    // blend function
    wyBlendFunc blendFunc;

    // color
    wyColor4B color;

protected:
    void init(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity);
    wyAtlasNode();

public:
    wyAtlasNode(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity);
    virtual ~wyAtlasNode();

    // draw altas node
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
	virtual wyTexture2D* getTexture() { return atlas->getTexture(); }

	// set texture
	virtual void setTexture(wyTexture2D* tex) { atlas->setTexture(tex); }

	// set atlas
	void setAtlas(wyTextureAtlas* atlas);
	wyTextureAtlas* getAtlas() { return atlas; }
};

#endif // __wyAtlasNode_h__
