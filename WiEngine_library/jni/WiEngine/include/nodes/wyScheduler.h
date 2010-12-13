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
#ifndef __wyScheduler_h__
#define __wyScheduler_h__

#include <stdbool.h>
#include "wyArray.h"
#include "wyObject.h"
#include "wyTargetSelector.h"

#ifdef __cplusplus
extern "C" {
#endif

// equal function
bool wyTimerEquals(void* ptr1, void* ptr2, void* data);

#ifdef __cplusplus
}
#endif

class wyScheduler;
class wyTimer : public wyObject {
	friend class wyScheduler;

private:
	// c callback, if it is null, it will try to access java callback
	wyTargetSelector* targetSelector;

	// schedule interval, if not specified, use zero
	// zero means schedule it every frame
	float interval;

	// time elapsed since last calling
	float elapsed;

	// frame step, 0 means use time mode
	int frame;

	// frame counter
	int counter;

	// flag indicating this method is only scheduled for once
	bool oneShot;

public:
	// create new timer
	wyTimer(wyTargetSelector* ts);
	wyTimer(wyTargetSelector* ts, float interval);
	wyTimer(wyTargetSelector* ts, int frame);
	virtual ~wyTimer();

	// set interval, if timer is in frame mode, then set a non-zero interval will change it to time mode
	void setInterval(float interval);
	float getInterval() { return interval; }

	// frame
	void setFrame(int frame) { this->frame = frame; }
	int getFrame() { return frame; }

	// fire timer
	void fire(float delta);

	// one shot
	void setOneShot(bool flag) { oneShot = flag; }
	bool isOneShot() { return oneShot; }

	// elapsed
	float getElapsed() { return elapsed; }

	// get target selector
	wyTargetSelector* getTargetSelector() { return targetSelector; }
};

class wyScheduler : public wyObject {
	friend class wyDirector;
	friend bool removeTimers(wyArray* arr, void* ptr, int index, void* data);

private:
	// queue
	wyArray* scheduledTimers;
	wyArray* timersToAdd;
	wyArray* timersToRemove;

	// time scale rate
	float timeScale;

private:
	wyScheduler();

	// array callback
	static bool removeTimers(wyArray* arr, void* ptr, int index, void* data);
	static bool addTimers(wyArray* arr, void* ptr, int index, void* data);
	static bool releaseTimer(wyArray* arr, void* ptr, int index, void* data);
	static bool fire(wyArray* arr, void* ptr, int index, void* data);

protected:
	// tick
	void tickLocked(float delta);

	// get arrays
	wyArray* getScheduledTimers() { return scheduledTimers; }
	wyArray* getTimersToAdd() { return timersToAdd; }
	wyArray* getTimersToRemove() { return timersToRemove; }

public:
	// create scheduler, singleton pattern
	static wyScheduler* getInstance();
	virtual ~wyScheduler();

	// schedule a timer
	void scheduleLocked(wyTimer* t);
	void unscheduleLocked(wyTimer* t);

	// time scale
	void setTimeScale(float scale) { timeScale = scale; }
	float getTimeScale() { return timeScale; }
};

#endif //__wyScheduler_h__
