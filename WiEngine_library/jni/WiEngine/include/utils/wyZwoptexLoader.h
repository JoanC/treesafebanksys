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
#ifndef __wyZwoptexLoader_h__
#define __wyZwoptexLoader_h__

#include "wyObject.h"
#include "wyTypes.h"
#include "wyHashSet.h"

typedef unsigned char xmlChar;

class wyZwoptexFrame : public wyObject {
public:
	const char* key;
	wyRect rect;
	wyPoint offset;
	wySize sourceSize;

	wyZwoptexFrame();
	virtual ~wyZwoptexFrame();
};

class wyZwoptex : public wyObject {
private:
	// zwoptex file format version
	int format;

	// atlas size
	wySize size;

	// frames dict
	wyHashSet* frames;

private:
	static int frameHashEquals(void *ptr, void *elt);
	static void* buildFrameHash(void *ptr, void *data);
	static bool releaseHash(void *elt, void *data);
	static void collectFrameName(void *elt, void *data);

	static void startElement(void *ctx, const xmlChar *name, const xmlChar **atts);
	static void endElement(void *ctx, const xmlChar *name);
	static void characters(void *ctx, const xmlChar *ch, int len);
	static void warning(void *ctx, const char *msg, ...);
	static void error(void *ctx, const char *msg, ...);

	static wySize parseSize(const char* v);
	static wyPoint parsePoint(const char* v);
	static wyRect parseRect(const char* v);

protected:
	void load(int resId);
	void load(const char* path, bool isFile = false);
	void load(const char* data, int length);

public:
	wyZwoptex(int resId);
	wyZwoptex(const char* path, bool isFile = false);
	virtual ~wyZwoptex();

	// getter/setter
	void setFormat(int format) { this->format = format; }
	int getFormat() { return format; }
	void setSize(wySize size) { this->size = size; }
	wySize getSize() { return size; }

	// frames
	void addFrame(wyZwoptexFrame* frame);
	wyZwoptexFrame* getFrame(const char* key);
	wyRect getFrameRect(const char* key);

	/**
	 * 得到所有frame名称的列表
	 *
	 * @param count 返回frame个数
	 * @return 所有frame名称的指针数组
	 */
	const char** getFrames(int* count);
};

#endif // __wyZwoptexLoader_h__
