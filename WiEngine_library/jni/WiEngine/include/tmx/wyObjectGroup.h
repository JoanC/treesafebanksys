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
#ifndef __wyObjectGroup_h__
#define __wyObjectGroup_h__

#include "wyArray.h"
#include "wyHashSet.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wyObjectGroup {
	/**
	 * 对象组的名称
	 */
	char* name;

	/**
	 * 对象组在地图中的像素偏移x值
	 */
	float offsetX;

	/**
	 * 对象组在地图中的像素偏移y值
	 */
	float offsetY;

	/**
	 * 对象数组，每个对象被一个属性map所描述
	 */
	wyArray* objects;

	/**
	 * 对象组自身的属性map
	 */
	wyHashSet* properties;
} wyObjectGroup;

// create/destroy
wyObjectGroup* wyObjectGroupNew();
void wyObjectGroupDestroy(wyObjectGroup* group);

// property
void wyObjectGroupAddProperty(wyObjectGroup* group, const char* key, const char* value);
char* wyObjectGroupGetProperty(wyObjectGroup* group, const char* name);

// object
wyHashSet* wyObjectGroupNewObject(wyObjectGroup* group);
wyHashSet* wyObjectGroupGetObject(wyObjectGroup* group, const char* name);
void wyObjectAddProperty(wyHashSet* object, const char* key, const char* value);
char* wyObjectGetProperty(wyHashSet* object, const char* key);

#ifdef __cplusplus
}
#endif

#endif // __wyObjectGroup_h__
