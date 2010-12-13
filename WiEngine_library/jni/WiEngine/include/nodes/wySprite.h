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
#ifndef __wySprite_h__
#define __wySprite_h__

#include "wyHashSet.h"
#include "wyTextureNode.h"
#include "wyTextureFrame.h"

class wySprite : public wyTextureNode {
protected:
	// current frame
	wyTextureFrame* currentFrame;

	// animation hashset
	wyHashSet* animations;

private:
	static int animHashEquals(void *ptr, void *elt);
	static void* buildAnimHash(void *ptr, void *data);
	static bool releaseHash(void *elt, void *data);

public:
	static wySprite* make(wyTexture2D* tex);

	wySprite(wyTexture2D* tex);
	virtual ~wySprite();

	// 添加一个动画
	virtual void addAnimation(wyObject* animation);

	// 通过id获得动画对象
	virtual wyObject* getAnimationById(int id);

	// 获得当前帧
	virtual wyFrame* getDisplayFrame();

	// 检查某帧是否现在正在显示
	virtual bool isFrameDisplayed(wyFrame* frame) { return currentFrame == frame; }

	// 设置当前帧
	virtual void setDisplayFrame(wyFrame* newFrame);

	// 通过动画id和帧索引设置当前帧
	virtual void setDisplayFrameById(int id, int frameIndex);

	// set frame
	void setFrame(wyTextureFrame* frame);
	void setFrame(int id, int frameIndex);
};

#endif // __wySprite_h__
