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
#ifndef __wyShapeAnimation_h__
#define __wyShapeAnimation_h__

#include "wyObject.h"
#include "chipmunk.h"
#include "cpShape.h"
#include "wyArray.h"
#include "wyScheduler.h"
#include "wyTexture2D.h"
#include <stdbool.h>

#include <jni.h>

typedef struct wyShapeAnimationCallback {
	void (*onAnimationEnd)(cpShape* shape);
	void (*onAnimationAborted)(cpShape* shape);
} wyShapeAnimationCallback;

class wyShapeAnimation : public wyObject {
protected:
	// frame list
	wyArray* frames;

	// shape
	cpShape* shape;

	// animation timer
	wyTimer* timer;

	// total duration
	float duration;

	// sum of frame duration
	float frameTotalDuration;

	// loop or not
	bool loop;

	// elapsed time
	float elapsed;

	// callback
	wyShapeAnimationCallback* callback;

	// java side callback
	jobject j_callback;

	// flag indicating auto size shape or not
	bool autoSize;

private:
	static bool releaseFrame(wyArray* arr, void* ptr, int index, void* data);

protected:
	void invokeOnEnd();
	void invokeOnAborted();

public:
	static wyShapeAnimation* make(float duration, ...);

	wyShapeAnimation();
	virtual ~wyShapeAnimation();

	// for target selector
	virtual void onTargetSelectorInvoked(wyTargetSelector* ts);

	// update animation
	void update(float delta);

	// add frame
	void addFrame(float duration, wyTexture2D* tex);

	// start/stop
	void start(cpShape* shape);
	void stop();

	// loop
	void setLoop(bool loop);
	bool isLoop() { return loop; }

	// getter/setter
	void setJavaCallback(jobject callback);
	jobject getJavaCallback() { return j_callback; }
	void setAutoSize(bool autoSize) { this->autoSize = autoSize; }
	bool isAutoSize() { return autoSize; }
	void setDuration(float duration) { this->duration = duration; }
	float getDuration() { return duration; }
};

#endif // __wyShapeAnimation_h__
