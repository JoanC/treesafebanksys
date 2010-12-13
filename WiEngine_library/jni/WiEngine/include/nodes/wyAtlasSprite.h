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
#ifndef __wyAtlasSprite_h__
#define __wyAtlasSprite_h__

#include "wyHashSet.h"
#include "wyNode.h"
#include "wyTextureAtlas.h"
#include "wyAtlasFrame.h"

class wyAtlasSprite : public wyNode {
protected:
	// texture pixels rectangle, it should be resolution independent
	// so it means the rectangle already converted
	wyRect rect;

	// atlas
	wyTextureAtlas* atlas;

	// animation hashset
	wyHashSet* animations;

	// current frame, or if null no frame added
	wyAtlasFrame* currentFrame;

    // blend
    wyBlendFunc blendFunc;

	// color
	wyColor4B color;

	// dirty flags
	bool colorDirty;
	bool positionDirty;

	// image is flipped
	bool flipX;
	bool flipY;

	// atlas index
	int atlasIndex;

	// gl drawing
	wyQuad2D texCoords;
	wyQuad3D vertices;

private:
	bool isDirty();
	void updateTextureCoords();
	void updateAtlas();
	void insertInAtlas(int index);
	void updateColor();
	void updatePosition();

protected:
	// set atlas
	void setTextureAtlas(wyTextureAtlas* atlas);

public:
	wyAtlasSprite(wyRect rect, wyTextureAtlas* atlas);
	virtual ~wyAtlasSprite();

	// from node
	virtual void draw();
	virtual void onEnter();
	virtual void cleanup();
	virtual void setAnchorPercent(float x, float y);
	virtual void setAnchorPercentX(float x);
	virtual void setAnchorPercentY(float y);
	virtual void setPosition(float x, float y);
	virtual void setVertexZ(float vertexZ);
	virtual void setVisible(bool visible);

	/**
	 * 切换atlas sprite所属的atlas图片集, 因为atlas一旦改变, 原来的矩形
	 * 也要失效, 因此这两个参数要一起改变
	 *
	 * @param atlas \link wyTextureAtlas wyTextureAtlas \endlink
	 * @param rect \link wyRect wyRect \endlink
	 */
	void switchAtlas(wyTextureAtlas* atlas, wyRect rect);

	// 添加一个动画
	virtual void addAnimation(wyObject* animation);

	// 通过id获得动画对象
	virtual wyObject* getAnimationById(int id);

	// 获得当前帧
	virtual wyFrame* getDisplayFrame();

	// 检查某帧是否现在正在显示
	virtual bool isFrameDisplayed(wyFrame* frame);

	// 设置当前帧
	virtual void setDisplayFrame(wyFrame* newFrame);

	// 通过动画id和帧索引设置当前帧
	virtual void setDisplayFrameById(int id, int frameIndex);

	// 得到当前alpha值
	virtual int getAlpha() { return color.a; }

	// 设置alpha值
	virtual void setAlpha(int alpha);

	// 得到当前颜色
	virtual wyColor3B getColor();

	// 设置颜色
	virtual void setColor(wyColor3B color);

	// get blend func
	virtual wyBlendFunc getBlendFunc() { return blendFunc; }

	// set blend func
	virtual void setBlendFunc(wyBlendFunc func) { blendFunc = func; }

	// set frame
	void setFrame(wyAtlasFrame* frame);
	void setFrame(int id, int frameIndex);

	// set flip flag
	void setFlipX(bool flipX);
	void setFlipY(bool flipY);

	// set rect
	void setRect(wyRect rect);
	wyRect getRect() { return rect; }

	// other getter/setters
	bool isColorDirty() { return colorDirty; }
	bool isPositionDirty() { return positionDirty; }
	void setPositionDirty(bool dirty) { positionDirty = dirty; }
	bool isFlipX() { return flipX; }
	bool isFlipY() { return flipY; }
	int getAtlasIndex() { return atlasIndex; }
	void setAtlasIndex(int i) { atlasIndex = i; }
};

#endif // __wyAtlasSprite_h__
