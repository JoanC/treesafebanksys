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
#ifndef __wyCrossFadeTransition_h__
#define __wyCrossFadeTransition_h__

#include "wyTransitionScene.h"
#include "wyRenderTexture.h"

class wyCrossFadeTransition : public wyTransitionScene {
protected:
	wyRenderTexture* m_inTexture;
	wyRenderTexture* m_outTexture;

	/// @see wyTransitionScene::postFinish
	virtual bool shouldInSceneOnTop();

	/// @see wyTransitionScene::postFinish
	virtual void postFinish();

	/// @see wyTransitionScene::initScenes
	virtual void initScenes();

	/// @see wyTransitionScene::getInActionTarget
	virtual wyNode* getInActionTarget();

	/// @see wyTransitionScene::getOutActionTarget
	virtual wyNode* getOutActionTarget();

	/// @see wyTransitionScene::getInAction
	virtual wyIntervalAction* getInAction();

	/// @see wyTransitionScene::getOutAction
	virtual wyIntervalAction* getOutAction();

public:
	wyCrossFadeTransition(float duration, wyScene* inScene);
	virtual ~wyCrossFadeTransition();
};

#endif // __wyCrossFadeTransition_h__
