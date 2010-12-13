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
#ifndef __wyArrayTileMapAtlas_h__
#define __wyArrayTileMapAtlas_h__

#include "wyTileMapAtlas.h"

class wyArrayTileMapAtlas : public wyTileMapAtlas {
protected:
	int* tiles;
	int xTiles;
	int yTiles;

public:
	wyArrayTileMapAtlas(wyTexture2D* tex, int tileWidth, int tileHeight, int xTiles, int yTiles, int* tiles);
	virtual ~wyArrayTileMapAtlas();

	// update tile values
	// need call this method if tile value array is batch set
	void refreshTileValues();

    virtual bool hasTileAt(int x, int y);
    virtual int getHorizontalTileCount() { return xTiles; }
    virtual int getVerticalTileCount() { return yTiles; }
    virtual int tileValueAt(int x, int y);

    // getter
    int* getTiles() { return tiles; }
};


#endif // __wyArrayTileMapAtlas_h__
