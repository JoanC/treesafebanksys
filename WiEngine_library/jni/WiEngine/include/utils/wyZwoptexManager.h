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
#ifndef __wyZwoptexManager_h__
#define __wyZwoptexManager_h__

#include "wyObject.h"
#include "wyHashSet.h"
#include "wyZwoptexLoader.h"
#include "wyAtlasSprite.h"

class wyZwoptexManager : public wyObject {
private:
	wyHashSet* cache;

private:
	wyZwoptexManager();

	static int zwoptexHashEquals(void *ptr, void *elt);
	static void* buildZwoptexHash(void *ptr, void *data);
	static bool releaseHash(void *elt, void *data);

public:
	static wyZwoptexManager* getInstance();
	virtual ~wyZwoptexManager();

	void addZwoptex(const char* name, int resId);
	void addZwoptex(const char* name, const char* path, bool isFile = false);
	wyZwoptex* getZwoptex(const char* name);
	void removeZwoptex(const char* name);

	/**
	 * 检查某个名称的Zwoptex是否存在
	 *
	 * @param name Zwoptex名称
	 * @return true表示这个Zwoptex已经载入了
	 */
	bool hasZwoptex(const char* name);

	/**
	 * 得到某个Zwoptex里面的所有frame名称
	 *
	 * @param name Zwoptex名称
	 * @param count 返回frame的个数
	 * @return frame名称的指针数组, 如果name代表的Zwoptex不存在, 则返回NULL. 调用者要负责释放返回的指针数组.
	 */
	const char** getFrames(const char* name, int* count);

	// create altas sprite
	wyAtlasSprite* makeAtlasSprite(const char* zwoptexName, const char* frameName, wyTextureAtlas* atlas);
};

#endif // __wyZwoptexManager_h__
