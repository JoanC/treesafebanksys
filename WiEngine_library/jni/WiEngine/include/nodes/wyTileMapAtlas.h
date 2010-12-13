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
#ifndef __wyTileMapAtlas_h__
#define __wyTileMapAtlas_h__

#include "wyAtlasNode.h"
#include <stdbool.h>

class wyTileMapAtlas : public wyAtlasNode {
protected:
    // x,y to atlas map
	// TODO 后期使用两个有序数组，二分搜索进行改进，应该可以节省一些内存
	int* atlasIndices;

    // numbers of tiles to render
    int itemsToRender;

private:
    void calculateItemsToRender();
    float mapTileCol(int value);
    float mapTileRow(int value);
    void updateAtlas(wyPoint pos, int tileValue, int idx);
    void updateAtlasValues();

protected:
    void initTileValues();

public:
    wyTileMapAtlas(wyTexture2D* tex, int tileWidth, int tileHeight);
    virtual ~wyTileMapAtlas();

    // subclass need implement it
    virtual bool hasTileAt(int x, int y) = 0;
    virtual int getHorizontalTileCount() = 0;
    virtual int getVerticalTileCount() = 0;
    virtual int tileValueAt(int x, int y) = 0;

    // release some resources
    virtual void releaseAuxiliaryResources();

	/**
	 * returns a tile value from position x,y.
	 * Tile value is an integer which should be mapped
	 */
	int getTile(int x, int y);
	void setTile(int tileValue, int x, int y);
};

#endif // __wyTileMapAtlas_h__
