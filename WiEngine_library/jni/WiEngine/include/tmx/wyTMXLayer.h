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
#ifndef __wyTMXLayer_h__
#define __wyTMXLayer_h__

#include "wyNode.h"
#include "wyMapInfo.h"
#include "wyLayerInfo.h"
#include "wyTileSetInfo.h"
#include "wyHashSet.h"
#include "wyTextureAtlas.h"

/**
 * @class wyTMXLayer
 *
 * 代表了TMX地图中的一个层, 提供了获取层信息的各种方法. 层是可写的, 可以通过相应方法
 * 动态的修改瓦片.
 */
class wyTMXLayer : public wyNode {
protected:
	/**
	 * layer的名称
	 */
	char* name;

	/**
	 * 层的横向瓦片数
	 */
	int layerWidth;

	/**
	 * 层的纵向瓦片数
	 */
	int layerHeight;

	/**
	 * 瓦片的像素宽度
	 */
	float tileWidth;

	/**
	 * 瓦片的像素高度
	 */
	float tileHeight;

	/**
	 * 瓦片id数组
	 */
	int* tiles;

	/**
	 * 透明度，从0到255
	 */
	int alpha;

	/**
	 * 最小的瓦片id
	 */
	int minGid;

	/**
	 * 最大的瓦片id
	 */
	int maxGid;

	/**
	 * 地图朝向
	 */
	wyTMXOrientation orientation;

	/**
	 * 相关的tileset信息对象
	 */
	wyTileSetInfo* tileset;

	/**
	 * 层附加属性
	 */
	wyHashSet* properties;

	// atlas
	wyTextureAtlas* atlas;

	// row-column and index map
	int* atlasIndices;

	// vertex Z
	bool useAutomaticVertexZ;
	float vertexZ;

	// alpha func value
	float alphaFuncValue;

protected:
	wyPoint getPositionForOrthoAt(int posX, int posY);
	wyPoint getPositionForIsoAt(int posX, int posY);
	wyPoint getPositionForHexAt(int posX, int posY);
	wyPoint getPositionAt(int x, int y);
	float getVertexZAt(int x, int y);
	void appendTileForGid(int gid, int x, int y);
	void parseInternalProperties();
	wyPoint calculateLayerOffset(float x, float y);
	void setupTiles();

public:
	wyTMXLayer(wyTileSetInfo* tileset, wyLayerInfo* layerInfo, wyMapInfo* mapInfo);
	virtual ~wyTMXLayer();

	/// @see wyNode::draw
	virtual void draw();

	/**
	 * 获得层属性
	 *
	 * @param key 属性关键字
	 * @return 属性值
	 */
	char* getProperty(const char* key);

	/**
	 * 获得层名称
	 *
	 * @return 层名称
	 */
	char* getName() { return name; }

	/**
	 * 得到层水平方向上的瓦片个数
	 *
	 * @return 层水平方向上的瓦片个数
	 */
	int getLayerWidth() { return layerWidth; }

	/**
	 * 得到层垂直方向上的瓦片个数
	 *
	 * @return 层垂直方向上的瓦片个数
	 */
	int getLayerHeight() { return layerHeight; }

	/**
	 * 得到瓦片的像素宽度
	 *
	 * @return 瓦片的像素宽度
	 */
	int getTileWidth() { return tileWidth; }

	/**
	 * 得到瓦片的像素高度
	 *
	 * @return 瓦片的像素高度
	 */
	int getTileHeight() { return tileHeight; }

	/**
	 * 获得指定行列的瓦片id
	 *
	 * @param x 行位置
	 * @param y 列位置
	 * @return 瓦片id
	 */
	int getGidAt(int x, int y);

	/**
	 * 得到该层所有的瓦片id数组
	 *
	 * @param copy 可选参数, true表示返回一份瓦片id数组的拷贝, 缺省为false
	 * @return 瓦片id数组, 数组的长度是layerWidth * layerHeight.
	 * 		如果想得到某行列的瓦片id, 位置的计算方式是: pos = x + layerWidth * y.
	 * 		如果copy是true, 则调用者要负责释放数组.
	 */
	int* getGids(bool copy = false);

	/**
	 * 删除指定行列的瓦片
	 *
	 * @param x 行位置
	 * @param y 列位置
	 */
	void removeTileAt(int x, int y);

	/**
	 * 在指定行列位置插入瓦片
	 *
	 * @param gid 瓦片id
	 * @param x 行位置
	 * @param y 列位置
	 */
	void insertTileAt(int gid, int x, int y);

	/**
	 * 更新某行列位置的瓦片
	 *
	 * @param gid 瓦片id
	 * @param x 行位置
	 * @param y 列位置
	 */
	void updateTileAt(int gid, int x, int y);
};

#endif // __wyTMXLayer_h__
