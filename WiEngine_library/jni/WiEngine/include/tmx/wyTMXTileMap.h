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
#ifndef __wyTMXTileMap_h__
#define __wyTMXTileMap_h__

#include "wyNode.h"
#include "wyMapInfo.h"
#include "wyHashSet.h"
#include "wyArray.h"
#include "wyTMXLayer.h"
#include "wyObjectGroup.h"

class wyTMXTileMap : public wyNode {
protected:
	// map width & height in tiles
	int mapWidth;
	int mapHeight;

	// tiles width & height in pixels
	float tileWidth;
	float tileHeight;

	// map orientation
	wyTMXOrientation orientation;

	// ObjectGroups
	wyArray* objectGroups;

	// properties
	wyHashSet* properties;

	// tile properties
	wyHashSet* tileProperties;

	wyTMXLayer* createLayer(wyLayerInfo* layerInfo, wyMapInfo* map);
	wyTileSetInfo* getTileSet(wyLayerInfo* layerInfo, wyMapInfo* map);

public:
	wyTMXTileMap(int resId, float resScale);
	virtual ~wyTMXTileMap();

	// get layer
	wyTMXLayer* getLayer(const char* name);
	wyObjectGroup* getObjectGroup(const char* name);

	// property
	char* getProperty(const char* name);
	char* getTileProperty(int gid, const char* name);

	// size
	int getMapWidth() { return mapWidth; }
	int getMapHeight() { return mapHeight; }
	float getTileWidth() { return tileWidth; }
	float getTileHeight() { return tileHeight; }
	wyTMXOrientation getOrientation() { return orientation; }
};

#endif // __wyTMXTileMap_h__
