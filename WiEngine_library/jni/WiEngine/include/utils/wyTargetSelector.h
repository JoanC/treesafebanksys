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
#ifndef __wyTargetSelector_h__
#define __wyTargetSelector_h__

#include "wyObject.h"
#include <stdbool.h>
#include <jni.h>

class wyTargetSelector;

#ifdef __cplusplus
extern "C" {
#endif

bool wyTargetSelectorEquals(wyTargetSelector* ts1, wyTargetSelector* ts2);

#ifdef __cplusplus
}
#endif

class wyTargetSelector : public wyObject {
private:
	// native callback
	wyObject* callback;

	// target selector id to identify this target selector
	int id;

	// delta time since last calling
	// only used for scheduler
	float delta;

	// custom data for native callback
	// target selector won't release it
	void* data;

	// java callback, target selector reference
	// if it is null, it will try to access native callback
	jobject j_callback;

public:
	// new
	wyTargetSelector(wyObject* callback, int id, void* data);
	wyTargetSelector(jobject callback);
	virtual ~wyTargetSelector();

	// set elapsed time since last calling
	void setDelta(float delta);

	// invoke
	void invoke();

	// getter
	wyObject* getCallback() { return callback; }
	jobject getJavaCallback() { return j_callback; }
	int getId() { return id; }
	float getDelta() { return delta; }
	void* getData() { return data; }
};

#endif // __wyTargetSelector_h__
