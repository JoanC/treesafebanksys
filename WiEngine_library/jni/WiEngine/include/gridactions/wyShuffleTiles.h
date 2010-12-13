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
#ifndef __wyShuffleTiles_h__
#define __wyShuffleTiles_h__

#include "wyTiledGrid3DAction.h"
#include "wyTypes.h"

typedef struct wyTile {
	/**
	 * 网格的行列坐标
	 */
	wyPoint position;

	/**
	 * 起始位置，用在某些特效中。
	 */
	wyPoint startPosition;

	/**
	 * 位置变化量，用在某些特效中。
	 */
	wyDimension delta;
} wyTile;

class wyShuffleTiles : public wyTiledGrid3DAction {
protected:
	int* tilesOrder;
	wyTile* tiles;

private:
	void shuffle(int* array);
	wyDimension getDelta(wyDimension pos);
	void placeTile(wyDimension pos, wyTile* t);

public:
	wyShuffleTiles(float duration, int gridX, int gridY);
	virtual ~wyShuffleTiles();

	virtual wyAction* copy();
	virtual void update(float t);
	virtual void start(wyNode* target);
};

#endif // __wyShuffleTiles_h__
