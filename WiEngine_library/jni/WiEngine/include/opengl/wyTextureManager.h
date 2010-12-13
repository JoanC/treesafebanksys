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
#ifndef __wyTextureManager_h__
#define __wyTextureManager_h__

#include "wyHashSet.h"
#include "wyTextureAtlas.h"

typedef struct wyTextureHash {
	// pool id, used to group texture
	int poolId;

	// real reference
	wyTexture2D* tex;
} wyTextureHash;

class wyTextureManager : public wyObject {
	friend class wyTexture2D;

private:
	wyHashSet* textures;

	// current pool id
	int currentPoolId;

private:
	wyTextureManager();

	static int texHashEquals(void *ptr, void *elt);
	static void* buildTexHash(void *ptr, void *data);
	static bool releaseHash(void *elt, void *data);
	static void invalidateTex(void *elt, void *data);
	static bool releaseTexturesInPool(void *elt, void *data);

protected:
	void cacheTexture(wyTexture2D* tex);

public:
	// create
	static wyTextureManager* getInstance();
	virtual ~wyTextureManager();

	// get texture
	wyTexture2D* getTexture(int64_t texId);

	// remove texture
	void removeTexture(int64_t texId);
	void removeTexture(wyTexture2D* tex);
	void removeAllTextures();

	// invalidate all texture
	void invalidateAllTextures();

	// get textures
	wyHashSet* getTextures();

	// pool
	void switchPool(int poolId);
	void releasePool(int poolId);
	void releaseCurrentPool();
	int getCurrentPoolId() { return currentPoolId; }
};

#endif // __wyTextureManager_h__
