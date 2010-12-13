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
#ifndef __wyActionManager_h__
#define __wyActionManager_h__

#include "wyNode.h"
#include "wyAction.h"
#include "wyHashSet.h"
#include <stdbool.h>

/**
 * @class wyActionManager
 *
 * 正在执行的动作管理类
 */
class wyActionManager : public wyObject {
private:
	/// 保存正在执行动作的节点 \link wyHashSet wyHashSet对象 \endlink 的指针
	wyHashSet* m_targets;

	/// true表示removeAllActions正在被执行
	bool m_removingAll;

private:
	wyActionManager();

	static int actionHashEquals(void *ptr, void *elt);
	static void* buildActionHash(void *ptr, void *data);
	static bool execAction(wyArray* arr, void* ptr, int index, void* data);
	static bool removeActions(wyArray* arr, void* ptr, int index, void* data);
	static bool sResumeActions(wyArray* arr, void* ptr, int index, void* data);
	static bool sPauseActions(wyArray* arr, void* ptr, int index, void* data);
	static void tick(void *elt, void *data);
	static bool deleteEmtpyTarget(void *elt, void *data);
	static bool findActionByTag(void* elementPtr, void* ptr2, void* data);
	static bool releaseHash(void *elt, void *data);

public:
	// create action manager, singleton
	static wyActionManager* getInstance();
	virtual ~wyActionManager();

	// add/remove actions
	void addActionLocked(wyAction* action, wyNode* target, bool paused);
	void removeActionLocked(wyAction* action);
	void removeActionByTagLocked(wyNode* target, int tag);
	void removeActionsLocked(wyNode* target, bool includeChildren);
	void removeAllActionsLocked();

	// pause/resume actions
	void resumeActions(wyNode* target, bool includeChildren);
	void pauseActions(wyNode* target, bool includeChildren);

	// get action count
	int getRunningActionCount(wyNode* target);

	// get action
	wyAction* getAction(wyNode* target, int tag);

	// tick
	void tickLocked(float delta);
};

#endif // __wyActionManager_h__
