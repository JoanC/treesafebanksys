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
#ifndef __wyZoomFlipXTransition_h__
#define __wyZoomFlipXTransition_h__

#include "wyTransitionScene.h"

class wyZoomFlipXTransition : public wyTransitionScene {
protected:
	// flag indicating the front face flip to left or right
	bool m_toLeft;

	// end scale of out scene, also the start scale of in scene
	float m_scale;

	/// @see wyTransitionScene::initScenes
	virtual void initScenes();

	/// @see wyTransitionScene::getInAction
	virtual wyIntervalAction* getInAction();

	/// @see wyTransitionScene::getOutAction
	virtual wyIntervalAction* getOutAction();

public:
	wyZoomFlipXTransition(float duration, wyScene* inScene, bool toLeft, float scale);
	virtual ~wyZoomFlipXTransition();
};

#endif // __wyZoomFlipXTransition_h__
