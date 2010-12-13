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
#ifndef __wyTileSetInfo_h__
#define __wyTileSetInfo_h__

#include "wyTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wyTileSetInfo {
	/**
	 * tileset的名称
	 */
	char* name;

	/**
	 * tileset的起始网格id，网格id是按照行的顺序依次递增的，比如
	 * gid为1, 表示第一行第二列的网格
	 */
	int firstGid;

	/**
	 * 单个瓦片的宽度，单位是像素
	 */
	float tileWidth;

	/**
	 * 单个瓦片的高度，单位是像素
	 */
	float tileHeight;

	/**
	 * 瓦片在图片集中的间隔 ，单位是像素
	 */
	float spacing;

	/**
	 * 图片集的边缘宽度，单位是像素
	 */
	float margin;

	/**
	 * 图片集的资源id
	 */
	int sourceImageId;

	/**
	 * 图片集像素宽度
	 */
	float imageWidth;

	/**
	 * 图片集像素高度
	 */
	float imageHeight;
} wyTileSetInfo;

// create/destroy
wyTileSetInfo* wyTileSetInfoNew();
void wyTileSetInfoDestroy(wyTileSetInfo* info);

// 根据网格id得到相应的矩形，origin表示矩形的左上角
wyRect wyTileSetInfoGetRect(wyTileSetInfo* info, int gid);

// copy
wyTileSetInfo* wyTileSetInfoCopy(wyTileSetInfo* info);

#ifdef __cplusplus
}
#endif

#endif // __wyTileSetInfo_h__
